#pragma once
#include "GMenu.h"


using namespace std;
using namespace sf;

class Entity : public Drawable
{
public:

	Entity();
	Entity(string s, int x, int y, int w, int h);
	~Entity();
	void Attack(Entity&);
	void setHp(int h);
	void setAttack(int a);
	//void setMe(int,int);
	void setMyColor(sf::Color);
	void setName(string);
	void setAt(int, int);
	void setPos(Vector2i);
	void setTexture(string);

	Vector2i getAt();
	Vector2i getPos();
	int getX();
	int getY();
	int getHP();
	int getAttack();
	string getName();
	bool isMouseTouching(const sf::Vector2i&);

	void drawGMenu(RenderTarget&, GMenu);

	sf::RectangleShape getMe();



private:
	int hp;
	int attackPower;
	sf::RectangleShape me;
	Texture text;
	Sprite sprite;
	int curX, curY, pixelH;
	Vector2i myPos;
	string Name;
	

	// Draw class on SFML Window
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

