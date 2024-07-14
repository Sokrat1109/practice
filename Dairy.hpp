#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Meditation.hpp"
#include "Timer.hpp"
#include "Control.hpp"
#include "Note.hpp"
#include "ControlTime.hpp"
#include "Game.hpp"

// ДНЕВНИК СПИСОК

namespace mt
{
	class Dairy
	{
		sf::Texture m_backgroundTexture;
		sf::Sprite m_backgroundSprite;

		sf::Image BackI, NoteI;
		sf::Texture BackT, NoteT;
		sf::Sprite BackS, NoteS;

		// не нужно ли все это засунуть в сэтап и сделать конструктор по умолчанию?

	public:
		Dairy(int width, int height)
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

			BackI.loadFromFile("Back.png");
			BackT.loadFromImage(BackI);
			BackS.setTexture(BackT);
			BackS.setPosition(20, 20);

			NoteI.loadFromFile("note.png");
			NoteT.loadFromImage(NoteI);
			NoteS.setTexture(NoteT);
			NoteS.setPosition(50, 20);

			sf::Vector2f targetSizeS(50.0f, 50.0f); //целевой размер
			BackS.setScale(
				targetSizeS.x / BackS.getLocalBounds().width,
				targetSizeS.y / BackS.getLocalBounds().height);


			sf::Vector2f targetSizeN(500.0f, 500.0f); //целевой размер
			NoteS.setScale(
				targetSizeN.x / NoteS.getLocalBounds().width,
				targetSizeN.y / NoteS.getLocalBounds().height);
		}

		void LifeCycleDairy(sf::RenderWindow& window)
		{
			window.draw(m_backgroundSprite);
			window.draw(NoteS);
			window.draw(BackS);
		}
	};
}

