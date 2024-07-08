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

			text.setFont(font);
			text.setPosition(350, 100);
			text.setString("Welcome");
			text.setCharacterSize(500);
			//text.setColor(sf::Color::Red);
			text.setStyle(sf::Text::Bold);

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
									//запуск медитации
								}
								if ((event.mouseMove.x > 1400 & event.mouseMove.x < 1420) & (event.mouseMove.y > 350 & event.mouseMove.y < 360)) // координаты на кнопке
								{
									//запуск контроля самочувствия
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

	/*class Game
	{
		int m_width;
		int m_height;
		std::string m_capture;  // название диалогового окна
		mt::Circle* m_c;  // массив шариков
		int m_n;
		sf::RenderWindow m_window;   // объекты библиотеки сфмл
		sf::Texture m_textureBackground;
		sf::Sprite m_spriteBackground;
		sf::Font m_font;  // шрифт
		sf::Text m_fpsText;  // текст
		Ship m_ship;
		time_t t = 0;


	public:
		Game(int width, int height, const std::string& capture)  // конструктор
		{
			m_width = width;
			m_height = height;
			m_capture = capture;
		}

		bool Setup(int n)  // создание всего
		{
			m_n = n;

			//устанавливаем длину и ширину, название
			m_window.create(sf::VideoMode(m_width, m_height), m_capture);

			// если не прогрузилась картинка на фон
			if (!m_textureBackground.loadFromFile("background.jpg"))
			{
				std::cout << "Error while loading background.jpg" << std::endl;
				return false;
			}
			m_spriteBackground.setTexture(m_textureBackground);  // на спрайт устанавливаем текстуру

			if (!m_font.loadFromFile("arial.ttf"))
			{
				std::cout << "Error while loading arial.ttf" << std::endl;
				return false;
			}
			m_fpsText.setFont(m_font); // частота кадров

			// если не подгрузился корабль
			if (!m_ship.Setup(100, 100))
				return false;

			srand(time(0)); // для рандомайзера. начальное состояние генератора случайных чисел

			m_c = new mt::Circle[m_n];  // массив динамический кругов
			for (int i = 0; i < m_n; i++)  // для каждого круга данные и создание
			{
				int r = rand() % 100 + 10;
				int x = rand() % (1000 - 2 * r) + r;
				int y = rand() % (600 - 2 * r) + r;
				int v = rand() % 50 + 100;
				float alfa = rand() % 7;
				m_c[i].Setup(x, y, r, v, alfa);
			}
		}

		void TouchBorder(Circle& obj)
		{
			float x = obj.X(); // геттер. берем значение
			float y = obj.Y();
			float r = obj.R();

			//std::cout << x << " " << y << std::endl;

			if (isTouchBorder) // сравниваем границы кружочка с полями. если шарики касаются
			{
				isTouchBorder = false; // шарики не касаются

				if (x + r >= m_width || x - r <= 0) // если касаются
				{
					obj.Alfa(pi - obj.Alfa());  // меняем угол движения если выходит за границу
				}

				if (y + r >= m_height || y - r <= 0)
				{
					obj.Alfa(2 * pi - obj.Alfa());
				}

			}
			else
			{
				if (x + r + 20 <= m_width || x - r - 20 >= 0) // если не выходим за границы
				{
					isTouchBorder = true; // шарики на проверку
				}

				if (y + r + 20 <= m_height || y - r - 20 >= 0)
				{
					isTouchBorder = true;
				}
			}

		}

		void Collision(int i)  // попадение пулей в шарик. и - индекс для очередного шарика
		{
			Circle& c = m_c[i];  // создаем пустой шарик и присваиваем значения рассматриваемого, чтобы сравнить. так быстрее
			// но это плохо по памяти. тк каждый раз создается новый объект. зато мы не изменим шарик случайно
			if (c.isVisible() == false) {  // если шарик уже невидимый
				return;
			}

			for (int j = 0; j < m_ship.CountBullets(); j++) { // до  конца количества пуль
				// теорема пифагора
				float dist = sqrt(pow(m_ship.B_X(j) - c.X(), 2) + pow(m_ship.B_Y(j) - c.Y(), 2));
				// расстояние от корабля до кружочка

				if (m_ship.B_R(j) + c.R() >= dist) // радиус корабля + радиус кружочка
				{
					m_c[i].isVisible(false); // мы попали, выключаем видимость
					m_ship.IsVisBullet(j, false);
				}
			}
		}

		void LifeCycle()
		{
			sf::Clock clock;


			while (m_window.isOpen())
			{
				// 
				sf::Event event;  // создаем событие
				while (m_window.pollEvent(event))  // пока хоть какое-то событие происходит
				{
					if (event.type == sf::Event::Closed)  // тип события - крестик(закрыть)
						m_window.close();  // то закрываем окно
				}

				// 
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))  // нажатие клавиши - двигаем корабль
				{
					m_ship.setVelocity(1);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					m_ship.setVelocity(-1);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					m_ship.Rotate(-0.5);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					m_ship.Rotate(0.5);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) // на пробел стреляем
				{
					time_t t_new;
					time(&t_new);
					if (t_new - t >= 0.05)
						m_ship.Attack();  // атакует
					t = t_new;

				}



				float dt = clock.getElapsedTime().asSeconds();
				clock.restart();

				for (int i = 0; i < m_n; i++)  // вызов функции проверки границ, чтобы шарики не вылезали
					TouchBorder(m_c[i]);
				
				for (int i = 0; i < m_n; i++)
				{
					float x = m_c[i].X(); // геттеры. вытаскиваем значение
					float y = m_c[i].Y();
					float r = m_c[i].R();
					float v = m_c[i].V();  // скорость
					float alfa = m_c[i].Alfa();

					float x_s = x + v * cos(alfa) * dt;  // на сколько мы должны сдвинуть шарик по осям
					float y_s = y + v * sin(alfa) * dt;


					bool collision = false;
					if (x_s + r >= m_width)  // проверяем можем ли мы сдвинуть этот шарик по осям, чтобы не выходил за границы
					{
						m_c[i].Alfa(pi - m_c[i].Alfa());
						m_c[i].X(m_width - r);
						collision = true;
					}

					if (x_s - r <= 0)
					{
						m_c[i].Alfa(pi - m_c[i].Alfa());
						m_c[i].X(r);
						collision = true;
					}

					if (y_s + r >= m_height)
					{
						m_c[i].Alfa(2 * pi - m_c[i].Alfa());
						m_c[i].Y(m_height - r);
						collision = true;
					}

					if (y_s - r <= 0)
					{
						m_c[i].Alfa(2 * pi - m_c[i].Alfa());
						m_c[i].Y(r);
						collision = true;
					}

					if (!collision)  // если столкновения со стенками нет, то шарики двигаем
					{
						m_c[i].X(x_s);
						m_c[i].Y(y_s);
					}
				}

				std::vector <Bullet> b = m_ship.GetBullets();

				for (int i = 0; i < m_n; i++)   // столкновение с шариком. вызываем функцию проверки
					Collision(i);

				m_ship.Move(dt); // двигаем кораблик
				

				m_fpsText.setString(std::to_string(1 / dt));


				m_window.clear();  // очищаем окошко
				m_window.draw(m_spriteBackground);  // отрисовываем бэк
				m_window.draw(m_fpsText);  // отрисовываем текст
				for (int i = 0; i < m_n; i++) {
					if (m_c[i].isVisible() == true) // если шарик видимый  
						m_window.draw(m_c[i].Get());  // то отрисовываем
				}

				for (Bullet n : b) {
					if(n.IsVis() == true)
						m_window.draw(n.Get());
				}



				m_window.draw(m_ship.Get());  // отрисовка
				m_window.display();  // дисплей чтобы показать
			}
		}
	};*/

}