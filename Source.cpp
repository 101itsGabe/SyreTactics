#include "Board.h"

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(850, 650), "SFML works!");
	Vector2i localPos,lastSpot(-1,-1),curSpot;
	Board board;
	board.load();
	bool chooseMode = false;
	Entity me,en;
	en.setTexture("./Cats/SpriteSheets/Seal_Point_001.png");
	en.setAt(9, 7);
	me.setAt(0, 0);

	while (window.isOpen())
	{
		sf::Event event;
		localPos = sf::Mouse::getPosition(window);

		while (window.pollEvent(event))
		{
			//close window
			if (event.type == sf::Event::Closed)
				window.close();

			else if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Escape)
					window.close();

			
				
			}

			else if (event.type == Event::MouseButtonPressed && board.checkPlayer(localPos, me))		//if mouse has been clicked on player
			{
				chooseMode = true;
				cout << "YUH BITCH" << endl;
				me.setMenuState(true);
			}

			
			if (chooseMode)
			{
				//cout << "Mode On" << endl;
				
				if (!board.checkMouse(localPos))
				{
					Vector2i t = board.getBoardSize();
					for (int i = 0; i < t.x; i++)
					{
						for (int j = 0; j < t.y; j++)
						{
							board.setSpaceColor(i, j, Color::White);
						}
					}
					chooseMode = false;
				}
				else 
				{
					curSpot = board.curSpace(localPos);

					if (lastSpot.x == -1 || lastSpot.y == -1)
						lastSpot = curSpot;


					if (curSpot == lastSpot)
					{
						board.setSpaceColor(curSpot.x, curSpot.y, Color(88, 88, 88));
						//cout << "The if" << endl;
					}
					else
					{
						board.setSpaceColor(lastSpot.x, lastSpot.y, Color::White);
						lastSpot = curSpot;
					}

					if (event.type == Event::MouseButtonPressed && me.getAt() != board.curSpace(localPos))	//clicked the space wnated
					{
						me.setAt(board.curSpace(localPos).x, board.curSpace(localPos).y);
						board.setSpaceColor(curSpot.x, curSpot.y, Color::White);
						lastSpot = curSpot;
						chooseMode = false;
						me.setMenuState(false);
					}
					
				}
			}


			window.clear();
			window.draw(board);
			board.drawPiece(window,me,me.getMenuState());
			board.drawPiece(window, en,en.getMenuState());

			window.display();
		}


	}
	return 0;
}