#include "Board.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(850, 650), "SFML works!");
	Vector2i localPos;
	Board board;
	board.load();
	bool chooseMode = false;

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
				else if (event.key.code == Keyboard::L)
				{
					cout << "X: " << localPos.x << endl;
					cout << "Y: " << localPos.y << endl;
				} 

				else if (event.key.code == Keyboard::B)
				{
					chooseMode = true;
				}
			}
			
			
			if (chooseMode)
			{
				cout << "Mode On" << endl;
				Vector2i temp(board.curSpace(localPos).x, board.curSpace(localPos).y);
					board.setSpaceColor(temp.x, temp.y, Color(88, 88, 88));

			}




			
			



			window.draw(board);
			window.display();
		}


	}
	return 0;
}