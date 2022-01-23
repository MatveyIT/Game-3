#pragma once
#include "beat.h"
#include "const.h"

class LeftBat : public Bat {
public:
	LeftBat() :Bat(float startx, float starty):Bat  {}
	void update() {
		int currentx = rect.getPosition().x;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			rect.move(0, -speedy);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			rect.move(0, speedy);
		}
		if (rect.getPosition().y <= 0) rect.setPosition(currentx,0);
		if (rect.getPosition().y + height >= SCREEN_HEIGHT - height) {
			rect.setPosition(currentx, SCREEN_HEIGHT - height);
		}
	}
};