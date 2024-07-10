#pragma once
#include <string>
#include <thread>
#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>
#include <time.h>

#include "Ship.hpp"
#include "Bullet.hpp"
#include "Control.hpp"
#include "Circle.hpp"
#include "ControlTime.hpp"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


// ТАЙМЕР МЕДИТАЦИИ

namespace mt  // пространство имен
{

	const float pi = acos(-1); // для более точного значения

	class Timer
	{
		int m_width;
		int m_height;
		std::string m_capture;

		sf::RenderWindow m_window;
		sf::Image BackI, PauseI, SquareI;
		sf::Texture BackT, PauseT, SquareT;
		sf::Sprite BackS, PauseS, SquareS;

		sf::Font font;
		sf::Text text;
		sf::SoundBuffer buffer;
		sf::Sound sound;

		Meditation comebackMed;
		Game comebackGame;


	public:
		Timer(int width, int height, const std::string& capture)
		{
			m_width = width;
			m_height = height;
			m_capture = capture;
		}

		void Setup(int n)
		{

			m_window.create(sf::VideoMode(m_width, m_height), m_capture);

			BackI.loadFromFile("Back.png");
			BackT.loadFromImage(BackI);
			BackS.setTexture(BackT);
			BackS.setPosition(20, 20);

			PauseI.loadFromFile("Pause.png");
			PauseT.loadFromImage(PauseI);
			PauseS.setTexture(PauseT);
			PauseS.setPosition(770, 430);

			SquareI.loadFromFile("Square.png");
			SquareT.loadFromImage(SquareI);
			SquareS.setTexture(SquareT);
			SquareS.setPosition(20, 20);

		}

		// как сделать, чтобы таймер увеличивал значение ровно +1 в секунду
		void TimerStart() // int n
		{
			sf::Font font;
			sf::Text text("", font, 20);
			font.loadFromFile("arial.ttf");
			text.setColor(sf::Color::Black);

			int hour = 00;
			int minute = 00;
			int second = 00;
			std::string time;
			std::string stop;
			// if (n == 1) // if (n == 0)

			while (minute < 15)
			{
				while (second < 60)
				{
					sf::Text text(time, font, 20);
					time = hour, ".", minute, ".", second;
					stop = hour, ".", minute, ".", second;
					sf::Text text(time, font, 20);
					m_window.draw(text);
					second++;

					std::chrono::this_thread::sleep_for(0.999s);
					system("cls");
				}
				minute++;
				second = 00;
				time = hour, ".", minute, ".", second;
				stop = hour, ".", minute, ".", second;
				sf::Text text(time, font, 20);
				m_window.draw(text);

				std::chrono::this_thread::sleep_for(0.999s);
				system("cls");
			}

			if (minute >= 15)
			{
				minute = 00;
				second = 00;
				time = hour, ".", minute, ".", second;
				sf::Text text(time, font, 20);
				m_window.draw(text);
			}
		}

		void LifeCycleTimer()
		{
			sf::Clock clock;

			while (m_window.isOpen())
			{
				sf::Texture backgroundTexture;
				if (!backgroundTexture.loadFromFile("flowertimer.png")) {
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

				PauseS.setScale(
					targetSizeS.x / BackS.getLocalBounds().width,
					targetSizeS.y / BackS.getLocalBounds().height);

				SquareS.setScale(
					targetSizeS.x / BackS.getLocalBounds().width,
					targetSizeS.y / BackS.getLocalBounds().height);

				//sf::SoundBuffer buffer;
				buffer.loadFromFile("Sound.wav");
				//sf::Sound sound;
				sound.setBuffer(buffer);
				sound.play();

				TimerStart(); // 1


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
									comebackGame.LifeCycle();
								}
								// pause
								if ((event.mouseMove.x > 770 & event.mouseMove.x < 790) & (event.mouseMove.y > 430 & event.mouseMove.y < 450)) // координаты на кнопке
								{
									// TimerStart(0);
								}
								// square - stop
								if ((event.mouseMove.x > 50 & event.mouseMove.x < 1480) & (event.mouseMove.y > 20)) // координаты на кнопке
								{
									comebackMed.LifeCycleMeditation();
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
				m_window.draw(PauseS);
				m_window.draw(SquareS);
				m_window.display();
			}
		}
	};
}
