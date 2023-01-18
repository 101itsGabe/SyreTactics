#include "Entity.h"
using namespace std;

Entity::Entity()
{
	hp = 10;
	attackPower = 1;
	me.setSize(sf::Vector2f(55, 40));
	me.setFillColor(sf::Color::Green); 
	curX = -412;
	curY = -310;
	setMe(curX, curY);
	Name = "Nesha";
}

Entity::Entity(sf::RectangleShape r)
{
	hp = 10;
	attackPower = 1;
	curX = -412;
	curY = -310;
	me = r;
	Name = "Nesha";
}

Entity::~Entity()
{

}

void Entity::setMe(int x, int y)
{
	me.setOrigin(x,y);
	curX = x;
	curY = y;
}

void Entity::setName(string n)
{
	Name = n;
}

int Entity::getHP()
{ return hp; }

int Entity::getX()
{
	return curX;
}

int Entity::getY()
{
	return curY;
}

int Entity::getAttack()
{
	return attackPower;
}

string Entity::getName()
{
	return Name;
}

void Entity::setAttack(int a)
{
	attackPower = a;
}

void Entity::setHp(int h)
{
	hp = h;
}
void Entity::Attack(Entity& e)
{
	e.setHp(e.getHP() - getAttack());
}

void Entity::setMyColor(sf::Color c)
{
	me.setFillColor(c);
}


sf::RectangleShape Entity::getMe()
{
	return me;
}

bool Entity::isMouseTouching(sf::Vector2i localPos)
{
	if ((localPos.x > (-1 * getX()) && localPos.y > (-1 * getY())) && (localPos.x < (-1 * getX()) + 56 && localPos.y < (-1 * getY()) + 40))
	{
		return true;
	}
	return false;
}