##pragma once
#include <string>
#include <thread>
#include <iostream>
#include <windows.h>
#include <time.h>

#include "Note.hpp"
#include "Timer.hpp"
#include "Control.hpp"
#include "Dairy.hpp"
#include "ControlTime.hpp"
#include "Game.hpp"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// НАЧАЛО МЕДИТАЦИИ

namespace mt
{
	class Meditation
	{
		sf::Texture m_backgroundTexture;
		sf::Sprite m_backgroundSprite;

		sf::Image BackI, StartI;
		sf::Texture BackT, StartT;
		sf::Sprite BackS, StartS;

		sf::Font m_font;
		sf::Text m_text;

	public:
		Meditation(int width, int height)
		{
			if (!m_backgroundTexture.loadFromFile("flower.png")) {
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

			sf::Vector2f targetSizeS(50.0f, 50.0f); //целевой размер

			BackS.setScale(
				targetSizeS.x / BackS.getLocalBounds().width,
				targetSizeS.y / BackS.getLocalBounds().height);

			StartS.setScale(
				targetSizeS.x / BackS.getLocalBounds().width,
				targetSizeS.y / BackS.getLocalBounds().height);
		}

		void Time(sf::RenderWindow& window)
		{
			
			m_font.loadFromFile("arial.ttf");
			sf::Text m_text("", m_font, 20);
			m_text.setFillColor(sf::Color::Black);

			int hour = 00;
			int minute = 00;
			int second = 00;
			std::string time;

			window.draw(m_text);
		}

		void LifeCycleMeditation(sf::RenderWindow& window)
		{
			window.draw(m_backgroundSprite);
			window.draw(BackS);
			window.draw(StartS);
		}
	};
}
