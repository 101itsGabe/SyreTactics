#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

using namespace std;

class Entity
{
public:

	Entity();
	Entity(sf::RectangleShape);
	~Entity();
	void Attack(Entity&);
	void setHp(int h);
	void setAttack(int a);
	void setMe(int,int);
	void setMyColor(sf::Color);
	void setName(string);
	int getX();
	int getY();
	int getHP();
	int getAttack();
	string getName();
	bool isMouseTouching(sf::Vector2i);

	sf::RectangleShape getMe();



private:
	int hp;
	int attackPower;
	sf::RectangleShape me;
	int curX, curY;
	string Name;
};

