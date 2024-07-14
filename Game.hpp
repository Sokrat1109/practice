#pragma once
#include <string>
#include <thread>
#include <iostream>
#include <windows.h>
#include <time.h>

#include "Meditation.hpp"
#include "Note.hpp"
#include "Timer.hpp"
#include "Control.hpp"
#include "Dairy.hpp"
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
		
		
		sf::Font m_font;
		sf::Text m_text;

		Dairy* launch_dairy;
		Meditation* launch_meditation;
		Control* launch_control;
		Note* launch_note;
		Timer* launch_timer;
		Controltime* launch_controltime;

		int m_state = 0;

		sf::Sprite m_backgroundSprite;
		sf::Texture m_backgroundTexture;

		const int MAIN_WINDOW = 0;
		const int DAIRY = 1;
		const int MEDITATION = 2;
		const int CONTROL = 3;
		const int NOTE = 11;
		const int TIMER = 21;
		const int CONTROLTIME = 31;


	public:

		Game(int width, int height, const std::string& capture)
		{
			m_width = width;
			m_height = height;
			m_capture = capture;

			launch_dairy = new Dairy(m_width, m_height);
			launch_meditation = new Meditation(m_width, m_height); // m_capture
			launch_control = new Control(m_width, m_height);
			launch_note = new Note(m_width, m_height);
			launch_timer = new Timer(m_width, m_height);
			launch_controltime = new Controltime(m_width, m_height);
		}

		~Game()
		{
			delete launch_dairy;
			delete launch_meditation;
			delete launch_control;
			delete launch_timer;
			delete launch_note;
			delete launch_controltime;
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

			m_font.loadFromFile("arial.ttf");
			m_text.setFillColor(sf::Color::Black);

			/*sf::Text text("welcome", m_font, 50);

			text.setCharacterSize(50);
			
			text.setPosition(100, 100);
			m_window.draw(text);*/

			if (!m_font.loadFromFile("arial.ttf"))
			{
				std::cerr << "Error in font loading" << std::endl;
			}

			
			m_text.setString("welcome");
			m_text.setCharacterSize(20);
			m_text.setFillColor(sf::Color::Green);
			m_text.setPosition(0, 0);
			
			// НАПЕЧАТАТЬ САМ ТЕКСТ

			
			if (!m_backgroundTexture.loadFromFile("kaplya.png")) {
				std::cerr << "Error in loading background image" << std::endl;
				return; // ошибка загрузки картинки
			}
			m_backgroundSprite.setTexture(m_backgroundTexture);

			sf::Vector2f targetSize(m_width, m_height); //целевой размер

			m_backgroundSprite.setScale(
				targetSize.x / m_backgroundSprite.getLocalBounds().width,
				targetSize.y / m_backgroundSprite.getLocalBounds().height);

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

		}

		void LifeCycle()
		{
			sf::Clock clock;

			while (m_window.isOpen())
			{
				sf::Event event;
				while (m_window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
					{
						// сохранить результат работы в приложении
						m_window.close();
					}

					if (event.type == sf::Event::MouseButtonPressed)
					{
						int x = sf::Mouse::getPosition(m_window).x;
						int y = sf::Mouse::getPosition(m_window).y;

						if (m_state == MAIN_WINDOW)
						{
							std::cout << x << " " << y << std::endl;
							if ((x > 200 && x < 500) && (y > 430 && y < 530)) //дневник
							{
								std::cout << "1" << std::endl;
								m_state = DAIRY;
							}
							if ((x > 820 && x < 1120) && (y > 550 && y < 650)) // медитация
							{
								std::cout << "1" << std::endl;
								m_state = MEDITATION;
							}
							if ((x > 1450 && x < 1750) && (y > 430 && y < 530)) //дневник
							{
								std::cout << "1" << std::endl;
								m_state = CONTROL;
							}
						}
						else if (m_state == DAIRY)
						{
							// ПЕРЕДЕЛАТЬ КООРДИНАТЫ
							std::cout << x << " " << y << std::endl;
							if ((x > 0 && x < 200) && (y > 0 && y < 200)) // назад
							{
								std::cout << "1" << std::endl;
								m_state = MAIN_WINDOW;
							}
							// ПЕРЕДЕЛАТЬ КООРДИНАТЫ
							if ((x > 0 && x < 200) && (y > 550 && y < 650)) // записка
							{
								std::cout << "1" << std::endl;
								m_state = NOTE;
							}
						}
						else if (m_state == MEDITATION)
						{
							// ПЕРЕДЕЛАТЬ КООРДИНАТЫ
							std::cout << x << " " << y << std::endl;
							/*if ((x > 0 && x < 200) && (y > 0 && y < 200)) // назад
							{
								std::cout << "1" << std::endl;
								m_state = MAIN_WINDOW;
							}*/
							// ПЕРЕДЕЛАТЬ КООРДИНАТЫ
							if ((x > 0 && x < 200) && (y > 0 && y < 200)) // таймер старт
							{
								std::cout << "1" << std::endl;
								m_state = TIMER;
							}
						}
						else if (m_state == CONTROL)
						{
							// ПЕРЕДЕЛАТЬ КООРДИНАТЫ
							std::cout << x << " " << y << std::endl;
							if ((x > 20 && x < 100) && (y > 20 && y < 100)) // назад
							{
								std::cout << "1" << std::endl;
								m_state = MAIN_WINDOW;
							}
							// ПЕРЕДЕЛАТЬ КООРДИНАТЫ
							if ((x > 820 && x < 1120) && (y > 550 && y < 650)) // дыхание старт
							{
								std::cout << "1" << std::endl;
								m_state = CONTROLTIME;
							}
						}
						else if (m_state == CONTROLTIME)
						{
							// ПЕРЕДЕЛАТЬ КООРДИНАТЫ
							std::cout << x << " " << y << std::endl;
							if ((x > 20 && x < 100) && (y > 20 && y < 100)) // назад
							{
								std::cout << "1" << std::endl;
								launch_controltime->Flag(true);
								m_state = CONTROL;
							}
						}
						else if (m_state == TIMER)
						{
							// ПЕРЕДЕЛАТЬ КООРДИНАТЫ
							std::cout << x << " " << y << std::endl;
							if ((x > 20 && x < 100) && (y > 20 && y < 100)) // назад
							{
								std::cout << "1" << std::endl;
								m_state = MEDITATION;
							}
						}
						else if (m_state == NOTE)
						{
							// ПЕРЕДЕЛАТЬ КООРДИНАТЫ
							std::cout << x << " " << y << std::endl;
							if ((x > 20 && x < 100) && (y > 20 && y < 100)) // назад
							{
								std::cout << "1" << std::endl;
								m_state = DAIRY;
							}
						}
					}
						
					
				}


				float dt = clock.getElapsedTime().asSeconds();
				clock.restart();

				m_window.clear();

				if (m_state == MAIN_WINDOW)
				{
					m_window.draw(m_backgroundSprite);
					m_window.draw(MeditationS);
					m_window.draw(DairyS);
					m_window.draw(ControlS);
					m_window.draw(m_text);
				}
				else if (m_state == DAIRY)
				{
					launch_dairy->LifeCycleDairy(m_window);
				}
				else if (m_state == MEDITATION)
				{
					launch_meditation->LifeCycleMeditation(m_window);
				}
				else if (m_state == CONTROL)
				{
					launch_control->LifeCycleControl(m_window);
				}
				else if (m_state == NOTE)
				{
					launch_note->LifeCycleNote(m_window);
				}
				else if (m_state == TIMER)
				{
					launch_timer->LifeCycleTimer(m_window);
				}
				else if (m_state == CONTROLTIME)
				{
					launch_controltime->LifeCycleControltime(m_window);
				}

				m_window.display();
			}
		}
	};
}
