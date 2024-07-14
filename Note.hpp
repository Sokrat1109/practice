#pragma once
#include <string>
#include <vector>
#include <iostream>

#include "Meditation.hpp"
#include "Timer.hpp"
#include "Control.hpp"
#include "Dairy.hpp"
#include "ControlTime.hpp"
#include "Game.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// КОНКРЕТНАЯ ЗАМЕТКА


namespace mt
{
	class Note
	{
		sf::Texture m_backgroundTexture;
		sf::Sprite m_backgroundSprite;

		sf::Image SaveI, BackI;
		sf::Texture SaveT, BackT;
		sf::Sprite SaveS, BackS;

		std::string writes;

	public:
		Note(int width, int height)
		{
			if (!m_backgroundTexture.loadFromFile("fon_dairy.png")) {
				std::cerr << "Error in loading fon_dairy" << std::endl;
				return; // ошибка загрузки картинки
			}
			m_backgroundSprite.setTexture(m_backgroundTexture);
			sf::Vector2f targetSize(width, height); //целевой размер
			m_backgroundSprite.setScale(
				targetSize.x / m_backgroundSprite.getLocalBounds().width,
				targetSize.y / m_backgroundSprite.getLocalBounds().height);

			SaveI.loadFromFile("Save.png");
			SaveT.loadFromImage(SaveI);
			SaveS.setTexture(SaveT);
			SaveS.setPosition(1500, 20);

			BackI.loadFromFile("Back.png");
			BackT.loadFromImage(BackI);
			BackS.setTexture(BackT);
			BackS.setPosition(20, 20);

			sf::Vector2f targetSizeS(50.0f, 50.0f); //целевой размер

			BackS.setScale(
				targetSizeS.x / BackS.getLocalBounds().width,
				targetSizeS.y / BackS.getLocalBounds().height);

			SaveS.setScale(
				targetSizeS.x / SaveS.getLocalBounds().width,
				targetSizeS.y / SaveS.getLocalBounds().height);
		}

		void WriteNote()
		{
			sf::Font font;
			font.loadFromFile("arial.ttf");
			sf::Text text("", font, 20);
			text.setFillColor(sf::Color::Black);

			getline(std::cin, writes);

		}

		void LifeCycleNote(sf::RenderWindow& window)
		{
			window.draw(m_backgroundSprite);
			window.draw(SaveS);
			window.draw(BackS);
			WriteNote();
		}
	};
}
