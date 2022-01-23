#include "SFML/Graphics.hpp"
#include "const.h"
#include"ball.h"
#include "beat.h"
#include "left Bat.h"

using namespace sf;

int main()
{
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML Works!");
	window.setFramerateLimit(60);
	Ball ball;
	LeftBat lef_tbat(20,SCREEN_HEIGHT/2 - 50)
	
	while (window.isOpen())
	{
		// 1 Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}// 2 update
		ball.update();
		left_bat.update();
		//  3 Отрисовка окна
		window.clear();
		window.draw(ball.getShape());
		window.draw(left_bat.getShape)
		window.display();
	}

	return 0;
}