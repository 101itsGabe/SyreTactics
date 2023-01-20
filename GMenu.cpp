#include "GMenu.h"
using namespace std;

GMenu::GMenu(Window w)
{
	if (!f.loadFromFile("arial.ttf"))
		cout << "Could not font" << endl;

	box.setSize(Vector2f(w.getSize().x * 0.15,w.getSize().y * 0.20));
	attackString.setString("Attack");
	attackString.setFont(f);
	attackString.setCharacterSize(15);

}

void GMenu::setAt(Vector2i v)
{
	myPos = v;
	
}

void GMenu::setPos(Vector2i v)
{
	box.setPosition(v.x, v.y);
}

void GMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(box);
}