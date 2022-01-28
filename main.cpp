#include <SFML/Graphics.hpp>
#include "const.h"
#include "ball.h"
#include "beat.h"
#include"left Bat.h"
#include "righ Bat.h"
#include"obg.h"
//#include "left_bat.h"

using namespace sf;
int main()
{
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML Works!");
	window.setFramerateLimit(FPS);
	//Создание игровых объектов
	Ball ball;
	LeftBat left_bat(20, SCREEN_HEIGHT / 2 - 50);
	RighBat righ_bat(SCREEN_WIDTH - 40,SCREEN_HEIGHT / 2 - 50);
	TextObj left_score(SCREEN_WIDTH * 1/5, 20);
	TextObj righ_score(SCREEN_HEIGHT * 4/5 , 20);
	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		//1 Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
		//2 update
		ball.update();
		left_bat.update();
		righ_bat.update();
		left_score.update(std::to_string(ball.getLeftScore()));
		righ_score.update(std::to_string(ball.getRighScore()));
		//обработка столкновений
		if (ball.getHitBox().intersects(left_bat.getHitBox())) {
			ball.reboundHorizontal();
		}
		if (ball.getHitBox().intersects(righ_bat.getHitBox())) {
			ball.reboundHorizontal();
		}
		// Отрисовка окна
		window.clear(Color(0, 0, 0));
		window.draw(ball.getShape());
		window.draw(left_bat.getShape());
		window.draw(righ_bat.getShape());
		window.draw(left_score.getText());
		window.draw(righ_score.getText());
		window.display();
	}
	return 0;
}
