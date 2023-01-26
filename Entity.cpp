#include "Entity.h"



using namespace std;

Entity::Entity()
{
	hp = 10;
	attackPower = 1;
	if (!text.loadFromFile("./Cats/SpriteSheets/black_001.png", sf::IntRect(-4, -5, 32, 26)))
	{
		cout << "did not load swiffer" << endl;
	}
	sprite.setTexture(text);
	sprite.setScale(Vector2f(1.75, 1.75));

	setAt(0, 0);
	Name = "Nesha";
	menuState = false;
}

Entity::Entity(string s,int x,int y,int w,int h)
{
	hp = 10;
	attackPower = 1;
	pixelH = h;
	if (!text.loadFromFile(s, sf::IntRect(x, y, w, h)))
		cout << "Could not get mate" << endl;
	Name = "Nesha";
}

Entity::~Entity()
{

}

void Entity::setPos(Vector2i v)
{
	//me.setPosition(v.x,v.y);
	//cout << v.x << endl;
	//cout << v.y << endl;
	//cout << "Inside setPos\n\n\n";
	sprite.setPosition(v.x, v.y);

}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite);
}

void Entity::setTexture(string s)
{
	if (!text.loadFromFile(s, sf::IntRect(-4, -5, 32, 26)))
		cout << "Could not load file" << endl;
	sprite.setTexture(text);

}


void Entity::setAt(int x, int y)
{
	myPos.x = x;
	myPos.y = y;
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

Vector2i Entity::getAt()
{
	return myPos;
}

Vector2i Entity::getPos()
{
	//cout << "Inside: " << sprite.getPosition().x << endl;
	//cout << "Inside: " << sprite.getPosition().y << endl;
	return Vector2i(sprite.getPosition().x,sprite.getPosition().y);
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

void Entity::setMenuState(bool t)
{
	menuState = t;
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



void Entity::drawGMenu(RenderTarget& target)
{
	
	Vector2i v;
	if(getAt().x < 5)
		v.x = sprite.getPosition().x + 120;
	else
		v.x = sprite.getPosition().x - 200;
	if(getAt().y < 5)
		v.y = sprite.getPosition().y + 120;
	else
		v.y = sprite.getPosition().y - 180;
	myMenu.setPos(v);
	target.draw(myMenu);
}

bool Entity::getMenuState()
{
	return menuState;
}