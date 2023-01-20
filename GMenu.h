#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

using namespace sf;

class GMenu : public Drawable
{
public:
	GMenu(Window);

	void setAt(Vector2i);
	void setPos(Vector2i);


private:
	RectangleShape box;
	Text attackString;
	Vector2i myPos;
	Font f;


	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

