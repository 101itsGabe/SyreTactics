
#include <iostream>


using namespace std;

class Background
{
public:
	Background(string s);

	sf::Sprite getSprtie();

private:
	sf::Texture texture;
	sf::Sprite sprite;

};

