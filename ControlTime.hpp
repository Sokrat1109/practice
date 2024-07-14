#pragma once
#include <string>
#include <thread>
#include <iostream>
#include <windows.h>
#include <time.h>
#include <chrono>
#include <thread>

#include "Meditation.hpp"
#include "Timer.hpp"
#include "Control.hpp"
#include "Dairy.hpp"
#include "Note.hpp"
#include "Game.hpp"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


// ТАЙМЕР МЕДИТАЦИИ

namespace mt
{
	class Controltime
	{
		sf::Texture m_backgroundTexture;
		sf::Sprite m_backgroundSprite;

		sf::Font font;
		sf::Text text;
		sf::SoundBuffer buffer;
		sf::Sound sound;

		sf::Image BackI, SquareI, vdohI, vydohI, zaderjkaI;
		sf::Texture BackT, SquareT, vdohT, vydohT, zaderjkaT;
		sf::Sprite BackS, SquareS, vdohS, vydohS, zaderjkaS;

	public:
		Controltime(int width, int height)
		{
			if (!m_backgroundTexture.loadFromFile("fon_dairy.png")) {
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
			BackS.setPosition(20, 20);

			SquareI.loadFromFile("Square.png");
			SquareT.loadFromImage(SquareI);
			SquareS.setTexture(SquareT);
			SquareS.setPosition(600, 400);

			vdohI.loadFromFile("vdoh.png");
			vdohT.loadFromImage(vdohI);
			vdohS.setTexture(vdohT);
			vdohS.setPosition(300, 400);

			vydohI.loadFromFile("vydoh.png");
			vydohT.loadFromImage(vydohI);
			vydohS.setTexture(vydohT);
			vydohS.setPosition(300, 400);

			zaderjkaI.loadFromFile("zaderjka.png");
			zaderjkaT.loadFromImage(zaderjkaI);
			zaderjkaS.setTexture(zaderjkaT);
			zaderjkaS.setPosition(300, 400);

			// ПОМЕНЯТЬ РАЗМЕР

			sf::Vector2f targetSizeB(50.0f, 50.0f); //целевой размер

			BackS.setScale(
				targetSizeB.x / BackS.getLocalBounds().width,
				targetSizeB.y / BackS.getLocalBounds().height);

			sf::Vector2f targetSizeS(100.0f, 100.0f);

			SquareS.setScale(
				targetSizeS.x / SquareS.getLocalBounds().width,
				targetSizeS.y / SquareS.getLocalBounds().height);

			sf::Vector2f targetSizeV(100.0f, 100.0f);

			vdohS.setScale(
				targetSizeV.x / vdohS.getLocalBounds().width,
				targetSizeV.y / vdohS.getLocalBounds().height);

			vydohS.setScale(
				targetSizeV.x / vydohS.getLocalBounds().width,
				targetSizeV.y / vydohS.getLocalBounds().height);

			zaderjkaS.setScale(
				targetSizeV.x / zaderjkaS.getLocalBounds().width,
				targetSizeV.y / zaderjkaS.getLocalBounds().height);
		}

		// как сделать, чтобы таймер увеличивал значение ровно +1 в секунду

		bool flag = 0;

		void Flag(bool f)
		{
			flag = f;
		}
		bool Flag()
		{
			return flag;
		}

		void TimerBreathe(sf::RenderWindow& window) // int n
		{
			sf::Font font;
			sf::Text text("", font, 20);
			font.loadFromFile("arial.ttf");
			text.setFillColor(sf::Color::Black);

			int count = 0;
			int banner = 0;

			std::string time;
			std::string stop;
			
			while (banner < 4)
			{
				window.clear();

				window.draw(m_backgroundSprite);
				window.draw(BackS);
				window.draw(SquareS);

				time = count + 1;
				//sf::Text text(time, font, 20);
				window.draw(text);
				//window.display();
				std::this_thread::sleep_for(std::chrono::seconds(1));
				system("cls");

				if (flag = 1)
				{
					flag = 0;
					break;
				}

				if (count < 4)
				{
					count++;
				}

				if (count == 4)
				{
					count = 0;
					banner++;
				}

				if (banner == 0)
				{
					//window.clear();
					window.draw(vdohS);
					//window.display();
				}
				if (banner == 1 || banner == 3)
				{
					//window.clear();
					window.draw(zaderjkaS);
					//window.display();
				}
				if (banner == 2)
				{
					//window.clear();
					window.draw(vydohS);
					//window.display();
				}
				window.display();
			}
		}

		void LifeCycleControltime(sf::RenderWindow& window)
		{
			//window.clear();

			TimerBreathe(window);
			window.draw(m_backgroundSprite);
			window.draw(BackS);
			window.draw(SquareS);
			window.display();

			// + вдох выдох задержка

			//sf::SoundBuffer buffer;
			buffer.loadFromFile("Sound.wav");
			//sf::Sound sound;
			sound.setBuffer(buffer);
			sound.play();

			TimerBreathe(window); 
		}
	};
}
