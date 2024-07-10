#pragma once
#include <string>
#include <thread>
#include <iostream>
#include <windows.h>
#include <time.h>

#include "Bullet.hpp"
#include "Timer.hpp"
#include "Control.hpp"
#include "Circle.hpp"
#include "ControlTime.hpp"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// НАЧАЛО МЕДИТАЦИИ


namespace mt  // пространство имен
{

	const float pi = acos(-1); // для более точного значения

	class Meditation
	{
		int m_width;
		int m_height;
		std::string m_capture;

		sf::RenderWindow m_window;
		sf::Image BackI, StartI;
		sf::Texture BackT, StartT;
		sf::Sprite BackS, StartS;

		sf::Font font;
		sf::Text text;

		Game comeback;
		Timer play;


	public:
		Meditation(int width, int height, const std::string& capture)
		{
			m_width = width;
			m_height = height;
			m_capture = capture;
		}

		void Setup(int n)
		{
			std::string name;

			m_window.create(sf::VideoMode(m_width, m_height), m_capture);

			BackI.loadFromFile("Back.png");
			BackT.loadFromImage(BackI);
			BackS.setTexture(BackT);
			BackS.setPosition(20, 20);

			StartI.loadFromFile("Start.png");
			StartT.loadFromImage(StartI);
			StartS.setTexture(StartT);
			StartS.setPosition(770, 430);

		}

		void Time()
		{
			sf::Font font;
			sf::Text text("", font, 20);
			font.loadFromFile("arial.ttf");
			text.setColor(sf::Color::Black);

			int hour = 00;
			int minute = 00;
			int second = 00;
			std::string time;

			m_window.draw(text);
		}

		void LifeCycleMeditation()
		{
			sf::Clock clock;

			while (m_window.isOpen())
			{
				sf::Texture backgroundTexture;
				if (!backgroundTexture.loadFromFile("flower.png")) {
					return; // ошибка загрузки картинки
				}

				sf::Sprite backgroundSprite;
				backgroundSprite.setTexture(backgroundTexture);

				sf::Vector2f targetSize(m_width, m_height); //целевой размер

				backgroundSprite.setScale(
					targetSize.x / backgroundSprite.getLocalBounds().width,
					targetSize.y / backgroundSprite.getLocalBounds().height);

				sf::Vector2f targetSizeS(50.0f, 50.0f); //целевой размер

				BackS.setScale(
					targetSizeS.x / BackS.getLocalBounds().width,
					targetSizeS.y / BackS.getLocalBounds().height);

				StartS.setScale(
					targetSizeS.x / BackS.getLocalBounds().width,
					targetSizeS.y / BackS.getLocalBounds().height);

				Time();


				sf::Event event;
				while (m_window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						// сохранить результат работы в приложении
						m_window.close();

					if (event.type == sf::Event::MouseWheelMoved)
					{
						event.mouseWheel.delta;
						event.mouseWheel.x;
						event.mouseWheel.y;
					}


					if (event.type == sf::Event::MouseButtonPressed)
					{
						if (event.type == sf::Event::MouseMoved)
						{
							if (event.mouseButton.button == sf::Mouse::Left)// левая кнопка мыши нажата
							{
								// back
								if ((event.mouseMove.x > 20 & event.mouseMove.x < 30) & (event.mouseMove.y > 20 & event.mouseMove.y < 30)) // координаты на кнопке
								{
									comeback.LifeCycle();
								}
								// start
								if ((event.mouseMove.x > 770 & event.mouseMove.x < 790) & (event.mouseMove.y > 430 & event.mouseMove.y < 450)) // координаты на кнопке
								{
									play.LifeCycleTimer();
								}
							}
						}
					}
				}


				float dt = clock.getElapsedTime().asSeconds();
				clock.restart();

				m_window.clear();
				m_window.draw(backgroundSprite);

				m_window.draw(BackS);
				m_window.draw(StartS);
				m_window.display();
			}
		}
	};
}
