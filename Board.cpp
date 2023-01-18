#include "Board.h"
using namespace std;
using namespace sf;

Board::Board()
{
	row = 11;
	col = 11;
	sizeOfSpace.x = 72;
	sizeOfSpace.y = 54;
}

bool Board::checkMouse(Vector2i mouse)
{
	for (int i = 0; i < boardVec.size(); i++)
	{
		for(int j = 0; j < boardVec[i].size(); j++)
		if (mouse.x > boardVec[i][j].getPosition().x && mouse.y > boardVec[i][j].getPosition().y && mouse.x < boardVec[i][j].getPosition().x + sizeOfSpace.x && mouse.y < boardVec[i][j].getPosition().y + sizeOfSpace.y)
		{
			return true;
		}
	}

	return false;
}

Vector2i Board::curSpace(Vector2i mouse)
{
		Vector2i t;

		t.x = mouse.x/sizeOfSpace.x;
		t.y = mouse.y/sizeOfSpace.y;
		return t;

		
}

void Board::load()
{
	for (int i = 0; i < row; i++)
	{
		vector<RectangleShape> temp;
		for (int j = 0; j < col; j++)
		{
			RectangleShape rt;
			rt.setSize(Vector2f(72, 54));
			rt.setFillColor(Color::White);
			rt.setOutlineColor(Color::Black);
			rt.setOutlineThickness(8.f);
			rt.setPosition(Vector2f((i * 72.72) + 25, (j * 54.54) + 25));
			temp.push_back(rt);
		}
		boardVec.push_back(temp);
	}
}

void Board::setSpaceColor(int i, int j,sf::Color c)
{
	boardVec[i][j].setFillColor(c);
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < boardVec.size(); i++)
	{
		for (int j = 0; j < boardVec[i].size(); j++)
		{
			target.draw(boardVec[i][j]);
		}
	}

}