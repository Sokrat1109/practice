#pragma once
#include <string>
#include <thread>
#include <iostream>
#include <windows.h>
#include <time.h>

#include "Ship.hpp"
#include "Bullet.hpp"
#include "Timer.hpp"
#include "Control.hpp"
#include "Circle.hpp"
#include "ControlTime.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace mt  // пространство имен
{

	const float pi = acos(-1); // для более точного значения

	class Game
	{
		int m_width;
		int m_height;
		std::string m_capture;

		sf::RenderWindow m_window;
		sf::Image MeditationI, DairyI, ControlI;
		sf::Texture MeditationT, DairyT, ControlT;
		sf::Sprite MeditationS, DairyS, ControlS;
		
		sf::Font font;
		sf::Text text;

		Dairy launch_dairy;
		Meditation launch_meditation;
		Control launch_control;
		



	public:

		Game(int width, int height, const std::string& capture)
		{
			m_width = width;
			m_height = height;
			m_capture = capture;
		}

		void Setup(int n)
		{
			m_window.create(sf::VideoMode(m_width, m_height), m_capture);

			DairyI.loadFromFile("Dairy.png");
			DairyT.loadFromImage(DairyI);
			DairyS.setTexture(DairyT);
			DairyS.setPosition(150, 350);

			MeditationI.loadFromFile("Meditation.png");
			MeditationT.loadFromImage(MeditationI);
			MeditationS.setTexture(MeditationT);
			MeditationS.setPosition(770, 470); 

			ControlI.loadFromFile("Control.png");
			ControlT.loadFromImage(ControlI);
			ControlS.setTexture(ControlT);
			ControlS.setPosition(1400, 350);

			sf::Text text("Welcome", font, 20);
			font.loadFromFile("arial.ttf");
			text.setColor(sf::Color::Black);

		}

		void LifeCycle()
		{
			sf::Clock clock;

			while (m_window.isOpen())
			{
				sf::Texture backgroundTexture;
				if (!backgroundTexture.loadFromFile("kaplya.png")) {
					return; // ошибка загрузки картинки
				}

				sf::Sprite backgroundSprite;
				backgroundSprite.setTexture(backgroundTexture);

				sf::Vector2f targetSize(m_width, m_height); //целевой размер

				backgroundSprite.setScale(
					targetSize.x / backgroundSprite.getLocalBounds().width,
					targetSize.y / backgroundSprite.getLocalBounds().height);

				sf::Vector2f targetSizeS(400.0f, 240.0f); //целевой размер

				MeditationS.setScale(
					targetSizeS.x / MeditationS.getLocalBounds().width,
					targetSizeS.y / MeditationS.getLocalBounds().height);

				DairyS.setScale(
					targetSizeS.x / DairyS.getLocalBounds().width,
					targetSizeS.y / DairyS.getLocalBounds().height);

				ControlS.setScale(
					targetSizeS.x / ControlS.getLocalBounds().width,
					targetSizeS.y / ControlS.getLocalBounds().height);

				

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
								if ((event.mouseMove.x > 150 & event.mouseMove.x < 170) &(event.mouseMove.y > 350 & event.mouseMove.y < 360)) // координаты на кнопке
								{
									launch_dairy.LifeCycleDairy();
								}
								if ((event.mouseMove.x > 770 & event.mouseMove.x < 790) & (event.mouseMove.y > 470 & event.mouseMove.y < 480)) // координаты на кнопке
								{
									launch_meditation.LifeCycleMeditation();
								}
								if ((event.mouseMove.x > 1400 & event.mouseMove.x < 1420) & (event.mouseMove.y > 350 & event.mouseMove.y < 360)) // координаты на кнопке
								{
									launch_control.LifeCycleControl();
								}
							}
						}
					}
				}


				float dt = clock.getElapsedTime().asSeconds();
				clock.restart();

				m_window.clear();
				m_window.draw(backgroundSprite);

				m_window.draw(text);

				m_window.draw(MeditationS);
				m_window.draw(DairyS);
				m_window.draw(ControlS);
				m_window.display();
			}
		}
	};
}
