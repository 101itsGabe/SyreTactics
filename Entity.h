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
	void setMyColor(sf::Color);
	void setName(string);
	void setAt(int, int);
	void setPos(Vector2i);
	void setTexture(string);
	void drawGMenu(RenderTarget&);
	void setMenuState(bool);

	


	Vector2i getAt();
	Vector2i getPos();
	int getX();
	int getY();
	int getHP();
	int getAttack();
	bool getMenuState();
	string getName();



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
	GMenu myMenu;
	bool menuState;
	

	// Draw class on SFML Window
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

