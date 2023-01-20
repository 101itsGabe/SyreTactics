#include "Board.h"

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(850, 650), "SFML works!");
	Vector2i localPos,lastSpot(-1,-1),curSpot;
	Board board;
	board.load();
	bool chooseMode = false;
	bool hasMoved = false;
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
				/*
				else if (event.key.code == Keyboard::L)
				{
					std::cout << "X: " << localPos.x << endl;
					cout << "Y: " << localPos.y << endl;
					cout << "R: " << board.curSpace(localPos).x << endl;
					cout << "C: " << board.curSpace(localPos).y << endl;
				} 
				
				
				else if (event.key.code == Keyboard::B)
				{
					cout << "X: " << me.getPos().x;
					cout << "\nY: " << me.getPos().y;
					cout << "\nMouse X: " << localPos.x;
					cout << "\nY: " << localPos.y << endl;
					chooseMode = true;

				}*/

			
				
			}

			else if (event.type == Event::MouseButtonPressed && board.checkPlayer(localPos, me))
			{
				chooseMode = true;
				cout << "YUH BITCH" << endl;
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
					cout << board.curSpace(localPos).x << endl;
					cout << board.curSpace(localPos).y << endl;
					cout << lastSpot.x << endl;
					cout << lastSpot.y << "\n\n";
					

					if (lastSpot.x == -1 || lastSpot.y == -1)
						lastSpot = curSpot;

					//std::cout << "temp x:" << curSpot.x << endl;
					//std::cout << "temp y:" << curSpot.y << endl;
					//std::cout << "ls x:" << lastSpot.x << endl;
					//std::cout << "ls y:" << lastSpot.y << endl;


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

					if (event.type == Event::MouseButtonPressed && me.getAt() != board.curSpace(localPos))
					{
						cout << "BLEEEEEEEEEEEEEEEP \n";
						me.setAt(board.curSpace(localPos).x, board.curSpace(localPos).y);
						board.setSpaceColor(curSpot.x, curSpot.y, Color::White);
						lastSpot = curSpot;
						chooseMode = false;
						hasMoved = true;
					}
					
				}
			}




			
			



			window.draw(board);
			board.drawPiece(window,me);
			board.drawPiece(window, en);

			window.display();
		}


	}
	return 0;
}