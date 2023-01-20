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
	void drawPiece(RenderTarget&, Entity);

	bool checkMouse(Vector2i);
	bool checkPlayer(Vector2i mouse,Entity e);
	

	//returns the x and y cord of cur vector of the position given
	Vector2i curSpace(Vector2i);
	Vector2f getPos();
	Vector2i getBoardSize();			//returns size of board
	Vector2f getShapeSize();	//Returns both width and height
	Color getHColor();		//get Highlited Color



private:
	vector<vector<RectangleShape>> boardVec;
	int row,col, wid, h;
	Vector2f sizeOfSpace;
	Color hColor;




	// Draw class on SFML Window
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

