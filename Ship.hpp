#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bullet.hpp"

/*namespace mt
{

	class Ship
	{
		const int m_bulletR = 10;  // радиус пули
		float m_v_bullet = 200;  // скорость пули

		float m_x, m_y;
		float m_alpha;
		float m_v;
		float m_r;
		sf::Texture m_textureShip;
		sf::Sprite m_spriteShip;
		float m_scaleFactor = 0.2f;  // погрешность

		std::vector <Bullet> bullets;  // создание вектора-массива с множеством пуль класса Пуля

	public:
		Ship() = default;  // конструктор по умолчанию 
		
		Ship(float x, float y)  // местонахождение корабля
		{
			m_x = x;
			m_y = y;
		}

		bool Setup(float x, float y)
		{
			m_x = x;
			m_y = y;
			m_alpha = 0;
			m_v = 0;

			// 
			if (!m_textureShip.loadFromFile("falcon.png"))
			{
				std::cout << "Error while loading falcon.png" << std::endl;
				return false;
			}
			m_spriteShip.setTexture(m_textureShip);

			m_spriteShip.setScale(m_scaleFactor, m_scaleFactor);  // масштабирование кораблика
			m_spriteShip.setOrigin(m_textureShip.getSize().x / 2, m_textureShip.getSize().y / 2); // по умолчанию 
			m_spriteShip.setPosition(m_x, m_y);
			m_spriteShip.setRotation(m_alpha);

			if (m_textureShip.getSize().x > m_textureShip.getSize().y)  // при растягивании и сужении экрана
				m_r = m_scaleFactor * m_textureShip.getSize().x / 2;
			else
				m_r = m_scaleFactor * m_textureShip.getSize().y / 2;

			//bullet.Setup(100, 100, 20, 10, 10);
		}

		void Attack()
		{
			Bullet bullet; // пустая пуля
			
			float alphaRad = acos(-1) * m_alpha / 180;  // угол наклона для пули в радианах. переход от градусов к радианам
			// устанавливаем пулю и ее параметры

			bullet.Setup(m_x, m_y, m_bulletR, (m_v + m_v_bullet) * cos(alphaRad), (m_v + m_v_bullet) * sin(alphaRad));
			bullets.push_back(bullet);  // добавляем пулю в массив пуль
		}



		void setVelocity(float dv)  // скорость движения
		{
			m_v += dv;
		}

		float V() { return m_v; }  // геттеры корабля
		float R() { return m_r; }
		float X() { return m_x; }
		float Y() { return m_y; }

		float B_X(int i) { return bullets[i].X(); }  // геттеры пули
		float B_Y(int i) { return bullets[i].Y(); }
		float B_R(int i) { return bullets[i].R(); }


		void Move(float dt)
		{

			for (int i = 0; i < bullets.size(); i++)  // движение каждой пули
			{
				bullets[i].Move(dt);
			}

			float alphaRad = acos(-1) * m_alpha / 180;
			m_x += m_v * cos(alphaRad) * dt;  // определяем насколько подвинуться 
			m_y += m_v * sin(alphaRad) * dt;
			m_spriteShip.setPosition(m_x, m_y);
		}

		void Rotate(float dalpha)  // поворот
		{
			m_alpha += dalpha;
			m_spriteShip.setRotation(m_alpha);
		}

		sf::Sprite Get()  // сам объект для отрисовки
		{
			return m_spriteShip;
		}
		
		std::vector <Bullet> GetBullets()  // возвращаем сам объект пули, который надо нарисовать
		{
			return bullets;
		}

		int CountBullets() {
			return bullets.size();
		}

		void IsVisBullet(int i, bool value) {  // сеттер для видимости пули
			bullets[i].IsVis(value);
		}

	};

}*/