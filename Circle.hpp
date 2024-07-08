#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <ctime>
#include <vector>

namespace mt
{
	class Dairy
	{
		std::string text;
		std::string name;

		int m_width;
		int m_height;
		std::string m_capture;

		sf::RenderWindow m_window;
		sf::Image SaveI, BackI, NoteI;
		sf::Texture SaveT, BackT, NoteT;
		sf::Sprite SaveS, BackS, NoteS;

		Game comeback;
		Note write;

		std::vector <char> arr;

	public:

		std::vector <char> arr;

		time_t date = time(NULL);
		tm t = *localtime(&date);

		name = "%.2d:%.2d:%2d", t.tm_day, t.tm_month, t.tm_year;

		Dairy(int width, int height, const std::string& capture)
		{
			m_width = width;
			m_height = height;
			m_capture = capture;
		}

		void Setup(int n)
		{
			m_window.create(sf::VideoMode(m_width, m_height), m_capture);

			/*SaveI.loadFromFile("Save.png");
			SaveT.loadFromImage(SaveI);
			SaveS.setTexture(SaveT);
			SaveS.setPosition(1500, 20);*/

			BackI.loadFromFile("Back.png");
			BackT.loadFromImage(BackI);
			BackS.setTexture(BackT);
			BackS.setPosition(20, 20);

			NoteI.loadFromFile("note.png");
			NoteT.loadFromImage(NoteI);
			NoteS.setTexture(NoteT);
			NoteS.setPosition(50, 20);
		}

		void LifeCycleDairy()
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

				/*SaveS.setScale(
					targetSizeS.x / SaveS.getLocalBounds().width,
					targetSizeS.y / SaveS.getLocalBounds().height);*/

				sf::Vector2f targetSizeN(500.0f, 500.0f); //целевой размер

				NoteS.setScale(
					targetSizeN.x / NoteS.getLocalBounds().width,
					targetSizeN.y / NoteS.getLocalBounds().height);



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
									comeback.LifeCycle();
								}
								if ((event.mouseMove.x > 1500 & event.mouseMove.x < 1510) & (event.mouseMove.y > 20 & event.mouseMove.y < 30)) // координаты на кнопке
								{
									//сохранить ??
								}
								if ((event.mouseMove.x > 1400 & event.mouseMove.x < 1420) & (event.mouseMove.y > 350 & event.mouseMove.y < 360)) // координаты на кнопке
								{
									write.LifeCycleNote(arr);
								}
							}
						}
					}
				}


				float dt = clock.getElapsedTime().asSeconds();
				clock.restart();

				m_window.clear();
				m_window.draw(backgroundSprite);

				//m_window.draw(SaveS);
				m_window.draw(NoteS);
				m_window.draw(BackS);
				m_window.display();
			}
		}

	};
}