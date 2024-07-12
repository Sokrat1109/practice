#include <time.h>

#include "Meditation.hpp"
#include "Note.hpp"
#include "Control.hpp"
#include "Dairy.hpp"
#include "ControlTime.hpp"
#include "Game.hpp"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


// ТАЙМЕР МЕДИТАЦИИ


namespace mt
{
	class Timer
	{
		sf::Texture m_backgroundTexture;
		sf::Sprite m_backgroundSprite;

		sf::Font font;
		sf::Text text;
		sf::SoundBuffer buffer;
		sf::Sound sound;

		sf::Image BackI, PauseI, SquareI;
		sf::Texture BackT, PauseT, SquareT;
		sf::Sprite BackS, PauseS, SquareS;

	public:
		Timer(int width, int height)
		{
			if (!m_backgroundTexture.loadFromFile("flowertimer.png")) {
				std::cerr << "Error in loading fon_dairy" << std::endl;
				return; // ошибка загрузки картинки
			}
			m_backgroundSprite.setTexture(m_backgroundTexture);
			sf::Vector2f targetSize(width, height); //целевой размер
			m_backgroundSprite.setScale(
				targetSize.x / m_backgroundSprite.getLocalBounds().width,
				targetSize.y / m_backgroundSprite.getLocalBounds().height);

			// ПОМЕНЯТЬ КООРДИНАТЫ

			BackI.loadFromFile("Back.png");
			BackT.loadFromImage(BackI);
			BackS.setTexture(BackT);
			BackS.setPosition(20, 50);

			PauseI.loadFromFile("Pause.png");
			PauseT.loadFromImage(PauseI);
			PauseS.setTexture(PauseT);
			PauseS.setPosition(770, 430);

			SquareI.loadFromFile("Square.png");
			SquareT.loadFromImage(SquareI);
			SquareS.setTexture(SquareT);
			SquareS.setPosition(1400, 50);

			// ПОМЕНЯТЬ РАЗМЕР

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
		}

		// как сделать, чтобы таймер увеличивал значение ровно +1 в секунду
		/*void TimerStart(sf::RenderWindow& window) // int n
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
					window.draw(text);
					second++;

					std::chrono::this_thread::sleep_for(0.999s);
					system("cls");
				}
				minute++;
				second = 00;
				time = hour, ".", minute, ".", second;
				stop = hour, ".", minute, ".", second;
				sf::Text text(time, font, 20);
				window.draw(text);

				std::chrono::this_thread::sleep_for(0.999s);
				system("cls");
			}

			if (minute >= 15)
			{
				minute = 00;
				second = 00;
				time = hour, ".", minute, ".", second;
				sf::Text text(time, font, 20);
				window.draw(text);
			}
		}*/

		void LifeCycleTimer(sf::RenderWindow& window)
		{
			window.draw(m_backgroundSprite);
			window.draw(BackS);
			window.draw(PauseS);
			window.draw(SquareS);

			//sf::SoundBuffer buffer;
			buffer.loadFromFile("Sound.wav");
			//sf::Sound sound;
			sound.setBuffer(buffer);
			sound.play();

			//TimerStart(); // 1 ???????????
		}
	};
}
