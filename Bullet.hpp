#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>


// КОНКРЕТНАЯ ЗАМЕТКА

namespace mt
{

	class Note
	{

		int m_width;
		int m_height;
		std::string m_capture;

		sf::RenderWindow m_window;
		sf::Image SaveI, BackI;
		sf::Texture SaveT, BackT;
		sf::Sprite SaveS, BackS;

		std::string writes;

		Dairy comeback;
		Dairy vec;


	public:

		Note(int width, int height, const std::string& capture)
		{
			m_width = width;
			m_height = height;
			m_capture = capture;
		}

		void Setup(int n)
		{
			m_window.create(sf::VideoMode(m_width, m_height), m_capture);

			SaveI.loadFromFile("Save.png");
			SaveT.loadFromImage(SaveI);
			SaveS.setTexture(SaveT);
			SaveS.setPosition(1500, 20);

			BackI.loadFromFile("Back.png");
			BackT.loadFromImage(BackI);
			BackS.setTexture(BackT);
			BackS.setPosition(20, 20);
		}

		void WriteNote()
		{
			sf::Font font;
			sf::Text text("", font, 20);
			font.loadFromFile("arial.ttf");
			text.setColor(sf::Color::Black);

			getline(std::cin, writes);

			/*vector<char> arr;
			char c;

			sf::Event event;
			while (m_window.pollEvent(event))
			{
				if (event.type == sf::Event::MouseWheelMoved)
				{
					event.mouseWheel.delta;
					event.mouseWheel.x;
					event.mouseWheel.y;
				}
				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::Enter)
					{
						bool flag = true;
					}
					
				}
			}

			std::cin >> c;
			arr.push_back(c);
			int length = arr.size;*/

		}

		void LifeCycleNote(std::vector<char> arr)
		{
			sf::Clock clock;

			std::vector<char> array;
			array = arr;

			while (m_window.isOpen())
			{
				sf::Texture backgroundTexture;
				if (!backgroundTexture.loadFromFile("fon_dairy.png")) {
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

				SaveS.setScale(
					targetSizeS.x / SaveS.getLocalBounds().width,
					targetSizeS.y / SaveS.getLocalBounds().height);



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
									writes = {};
									comeback.LifeCycleDairy();
								}
								if ((event.mouseMove.x > 1500 & event.mouseMove.x < 1510) & (event.mouseMove.y > 20 & event.mouseMove.y < 30)) // координаты на кнопке
								{
									array.push_back(writes);
									comeback.LifeCycleDairy();
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

				m_window.draw(SaveS);
				m_window.draw(BackS);
				m_window.display();
			}
		}
		
	};
}
