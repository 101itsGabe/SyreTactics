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
	/*FIND OUT WHERE
	Sprite setPositions() is cause
	its probably why this is 0  it dont make sense
	AND GABE RE FUCKING LAX AND READ THIS!!!!!!!!!!!
	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
	//cout << "BLEHHH\n\n";
	//cout << "X: " << sprite.getPosition().x << endl;
	//cout << "Y: " << sprite.getPosition().y << endl << endl;

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

bool Entity::isMouseTouching(const sf::Vector2i& localPos)
{
	
	cout << "LocalPos X: " << localPos.x << endl;
	cout << "LocalPos y: " << localPos.y << endl;
	cout << "sprte X: " << sprite.getPosition().x << endl;
	cout << "sprte y: " << getPos().y << endl;

	if(getAt().x == 10000)
	{
		cout << "TRUE" << endl;
		return true;
	}
	cout << "FALSE" << endl;
	return false;
}

void Entity::drawGMenu(RenderTarget& target, GMenu g)
{
	g.setPos(getAt());
	target.draw(g);
}
