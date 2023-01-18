#include "Entity.h"

using namespace std;
using namespace sf;

class Board : public Drawable
{
public:
	Board();

	//sets everything up for the board
	void load();
	void setSpaceColor(int, int,Color);

	bool checkMouse(Vector2i);
	

	//returns the x and y cord of cur vector of the position given
	Vector2i curSpace(Vector2i);
	Vector2f getPos();



private:
	vector<vector<RectangleShape>> boardVec;
	int row,col;
	Vector2f sizeOfSpace;


	// Draw class on SFML Window
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

