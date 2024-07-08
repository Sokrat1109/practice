#pragma once
#include <string>
#include <thread>
#include <iostream>
#include "Ship.hpp"
#include "Bullet.hpp"
#include <windows.h>
#include <time.h>

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

		Dairy comeback;


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

		void Timer()
		{
			sf::Font font;
			sf::Text text("", font, 20);
			font.loadFromFile("arial.ttf");
			text.setColor(sf::Color::Black);

			int hour = 00;
			int minute = 00;
			int second = 00;
			std::string time;

			/*if (hour == 00 & minute == 00 & second == 00)
			{
				time = hour, ".", minute, ".", second;
				text = time;
				second++;

				if (hour == 00 & minute == 00 & second > 59)
				{
					second == 00;
					minute++;
				}
			}
			if (second == 60)
			{
				second = 00;
				minute++;
			}*/
			while (hour < 3)
			{
				while (minute < 60)
				{
					while (second < 60)
					{
						sf::Text text(time, font, 20);
						time = hour, ".", minute, ".", second;
						sf::Text text(time, font, 20);
						m_window.draw(text);
						second++;
					}
					minute++;
					second = 00;
					time = hour, ".", minute, ".", second;
					sf::Text text(time, font, 20);
					m_window.draw(text);
				}
				hour++;
				minute = 00;
				second = 00;
				time = hour, ".", minute, ".", second;
				sf::Text text(time, font, 20);
				m_window.draw(text);
			}

		}

		void LifeCycle()
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
								if ((event.mouseMove.x > 20 & event.mouseMove.x < 30) & (event.mouseMove.y > 20 & event.mouseMove.y < 30)) // координаты на кнопке
								{
									comeback.LifeCycleDairy();
								}
								if ((event.mouseMove.x > 770 & event.mouseMove.x < 790) & (event.mouseMove.y > 430 & event.mouseMove.y < 450)) // координаты на кнопке
								{

									sf::Texture backgroundTexture;
									if (!backgroundTexture.loadFromFile("flowertimer.png")) {
										return; // ошибка загрузки картинки
									}
									m_window.draw(backgroundSprite);

									StartI.loadFromFile("Pause.png");
									StartT.loadFromImage(StartI);
									StartS.setTexture(StartT);
									StartS.setPosition(770, 430);
									Timer();
									// как остановить таймер, нажав на стоп?
								}
								if ((event.mouseMove.x > 50 & event.mouseMove.x < 1480) & (event.mouseMove.y > 20)) // координаты на кнопке
								{

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
