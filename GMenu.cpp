#include "GMenu.h"
using namespace std;

GMenu::GMenu()
{
	if (!f.loadFromFile("arial.ttf"))
		cout << "Could not font" << endl;

	box.setSize(Vector2f(150,200));
	box.setFillColor(Color(169, 169, 169));
	attackString.setString("Attack");
	attackString.setFont(f);
	attackString.setFillColor(Color::Black);
	attackString.setCharacterSize(15);

}

void GMenu::setAt(Vector2i v)
{
	myPos = v;
	
}

void GMenu::setPos(Vector2i v)
{
	box.setPosition(v.x, v.y);
	attackString.setPosition(v.x + 10, v.y + 20);
}

void GMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(box);
	target.draw(attackString);
}