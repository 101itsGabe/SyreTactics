#include "Board.h"
using namespace std;
using namespace sf;

Board::Board()
{
	row = 11;
	col = 11;
	sizeOfSpace.x = 72;
	sizeOfSpace.y = 54;
	hColor = Color(88, 88, 88);
	
}

bool Board::checkMouse(Vector2i mouse)
{
	Vector2i curPos = curSpace(mouse);
	//cout << "X:" << curPos.x << endl;
	//cout << "Y: " << curPos.y << endl << endl;
	if (curPos.x < 0 || curPos.y < 0 || curPos.x >= row || curPos.y >= col)
	{
		cout << "FASLE" << endl;
		return false;
	}
	else
		return true;
}

Vector2i Board::curSpace(Vector2i mouse)
{
		Vector2i t;
		for (int i = 0; i < boardVec.size(); i++)
		{
			for (int j = 0; j < boardVec[i].size(); j++)
				if (mouse.x >= boardVec[i][j].getPosition().x && mouse.y >= boardVec[i][j].getPosition().y && mouse.x <= boardVec[i][j].getPosition().x + boardVec[i][j].getSize().x && mouse.y <= boardVec[i][j].getPosition().y + boardVec[i][j].getSize().y)
				{

					//cout << boardVec[i][j].getPosition().x << endl;
					//cout << boardVec[i][j].getSize().x << endl;
					t.x = i;
					t.y = j;
					return t;
				}

		}
		//t.x = mouse.x)/sizeOfSpace.x;
		//t.y = mouse.y)/sizeOfSpace.y;
		return Vector2i(-1,-1);

		
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
			rt.setPosition(Vector2f((i * 73) + 25, (j * 55) + 25));
			temp.push_back(rt);
		}
		boardVec.push_back(temp);
	}
}

void Board::setSpaceColor(int i, int j,sf::Color c)
{
	if(i < row && j < col)
		boardVec[i][j].setFillColor(c);
}

void Board::drawPiece(RenderTarget& target, Entity e)
{
	Vector2i curPos(e.getAt().x, e.getAt().y);
	for (int i = 0; i < boardVec.size(); i++)
	{
		for (int j = 0; j < boardVec[i].size(); j++)
		{
			if (i == curPos.x && j == curPos.y)
			{
				e.setPos(Vector2i(boardVec[i][j].getPosition().x, boardVec[i][j].getPosition().y));
				//cout << boardVec[i][j].getPosition().x << endl;
				//cout << boardVec[i][j].getPosition().y << endl;
				e.setAt(curSpace(Vector2i(boardVec[i][j].getPosition())).x, curSpace(Vector2i(boardVec[i][j].getPosition())).y);
			}
		}
	}
	target.draw(e);
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

Vector2i Board::getBoardSize()
{
	return Vector2i(row, col);
}

Vector2f Board::getShapeSize()
{
	return sizeOfSpace;
}

Color Board::getHColor()
{
	return hColor;
}

bool Board::checkPlayer(Vector2i mouse,Entity e)
{
	cout << e.getAt().x << endl;
	cout << e.getAt().y << endl;
	cout << "Mouse X: " << curSpace(mouse).x << endl;
	cout << "Mouse Y: " << curSpace(mouse).y << endl;
	if (e.getAt() == curSpace(mouse))
	{
		cout << true;
		return true;
	}
	return false;
	
}