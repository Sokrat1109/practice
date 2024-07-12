#pragma once
#include <string>
#include <thread>
#include <iostream>
#include <windows.h>
#include <time.h>

#include "Meditation.hpp"
#include "Timer.hpp"
#include "Note.hpp"
#include "Dairy.hpp"
#include "ControlTime.hpp"
#include "Game.hpp"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

namespace mt
{
	class Control
	{
		sf::Texture m_backgroundTexture;
		sf::Sprite m_backgroundSprite;

		sf::Image StartI, BackI;
		sf::Texture StartT, BackT;
		sf::Sprite StartS, BackS;

		sf::Font font;
		sf::Text text;

	public:
		Control(int width, int height)
		{
			if (!m_backgroundTexture.loadFromFile("Breathe.png")) {
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

			StartI.loadFromFile("Start.png");
			StartT.loadFromImage(StartI);
			StartS.setTexture(StartT);
			StartS.setPosition(770, 470);

			sf::Vector2f targetSizeS(400.0f, 240.0f); //целевой размер
			StartS.setScale(
				targetSizeS.x / StartS.getLocalBounds().width,
				targetSizeS.y / StartS.getLocalBounds().height);

			sf::Vector2f targetSizeB(50.0f, 50.0f); //целевой размер
			BackS.setScale(
				targetSizeB.x / BackS.getLocalBounds().width,
				targetSizeB.y / BackS.getLocalBounds().height);
		}

		// ПРОПИСАТЬ ТЕКСТ

		void LifeCycleControl(sf::RenderWindow& window)
		{
			window.draw(m_backgroundSprite);
			window.draw(StartS);
			window.draw(BackS);

			window.draw(text);
		}
	};
}
