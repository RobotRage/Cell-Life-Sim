#include "Grid.h"
grid gridobj[GridSizeX][GridSizeY];
grid gridobj2[GridSizeX][GridSizeY];

void InstantiateGrid(sf::RenderWindow &window, sf::RectangleShape Tile[GridSizeX][GridSizeY], sf::RectangleShape &rect, int buf)
{
	/*
	gridobj[5][5].status = true;
	gridobj[6][5].status = true;
	gridobj[7][5].status = true;
	gridobj[5][5].col = sf::Color::Green;
	gridobj[6][5].col = sf::Color::Green;
	gridobj[7][5].col = sf::Color::Green;
	*/
	srand(time(0));

	for (int x = 0; x < GridSizeX; x++)
	{	
		for (int y = 0; y < GridSizeY; y++)
		{

			if (rand() % 7 == 2)
			{
				gridobj[x][y].status = 1;
			}
			else
			{
				gridobj[x][y].status = 0;
			}
			if (rand() % 20 == 2)
			{
				
				gridobj[x][y].status = 2;
				//std::cout << gridobj[x][y].status << std::endl;
			}
			if (gridobj[x][y].status == 1)
			{
				gridobj[x][y].col = sf::Color::Green;
				gridobj[x][y].strcol = "Green";
			}
			if (gridobj[x][y].status == 2)
			{
				//std::cout << "red" << std::endl;
				gridobj[x][y].col = sf::Color::Red;
				gridobj[x][y].strcol = "Green";
			}
			if (gridobj[x][y].status == 0)
			{
				gridobj[x][y].col = sf::Color::Black;
				gridobj[x][y].strcol = "Red";
			}
			rect.setPosition(sf::Vector2f(x * (offset + buf), y * (offset + buf)));
			rect.setFillColor(gridobj[x][y].col);
			gridobj[x][y].posx = x;
			gridobj[x][y].posy = y;




			Tile[x][y] = rect;

			//std::cout << gridobj[x][y].strcol << std::endl;
		}
	}
}

void UpdatePositions(sf::RenderWindow &window, sf::RectangleShape Tile[GridSizeX][GridSizeY], sf::RectangleShape &rect, int buf)
{

	for (int x = 0; x < GridSizeX; x++)
	{
		for (int y = 0; y < GridSizeY; y++)
		{
			bool notInf = false;
		/*	if (gridobj[x][y].status != 1)
			{
				if (rand() % 50 == 5)
				{
					gridobj[x][y].status = 1;
				}
			}
			*/

			if (rand() % 5000 == 5)
			{
				gridobj[x][y].status = 2;
			}

			if (gridobj[x][y].status == 2)
			{
				if (gridobj[x + 1][y].status == 1)
				{
					if (rand() % 7 == 2)
					{
						gridobj[x + 1][y].status = 2;
					}

					notInf = true;
				}
				if (gridobj[x - 1][y].status == 1)
				{
					if (rand() % 7 == 2)
					{
						gridobj[x - 1][y].status = 2;
					}
					notInf = true;
				}
				if (gridobj[x][y + 1].status == 1)
				{
					if (rand() % 7 == 2)
					{
						gridobj[x][y + 1].status = 2;
					}
					notInf = true;
				}
				if (gridobj[x][y - 1].status == 1)
				{
					if (rand() % 7 == 2)
					{
						gridobj[x][y - 1].status = 2;
					}
					notInf = true;
				}
				/*
				if (gridobj[x + 1][y + 1].status == 1)
				{
					gridobj[x + 1][y + 1].status;
					notInf = true;
				}
				if (gridobj[x - 1][y - 1].status == 1)
				{
					gridobj[x - 1][y - 1].status;
					notInf = true;
				}
				if (gridobj[x - 1][y + 1].status == 1)
				{
					gridobj[x - 1][y + 1].status = 2;
					notInf = true;
				}
				if (gridobj[x + 1][y - 1].status == 1)
				{
					gridobj[x + 1][y - 1].status = 2;
					notInf = true;
				}
				*/
				if (!notInf)
				{
					gridobj[x][y].status = 0;
				}
			}


			gridobj[x][y].neighboursCell = 0;
			int neighbours = 0;

			if (gridobj[x + 1][y].status == 1)
			{
				gridobj[x][y].neighboursCell++;
			}
			if (gridobj[x - 1][y].status == 1)
			{
				gridobj[x][y].neighboursCell++;
			}
			if (gridobj[x][y + 1].status == 1)
			{
				gridobj[x][y].neighboursCell++;
			}
			if (gridobj[x][y - 1].status == 1)
			{
				gridobj[x][y].neighboursCell++;
			}
			if (gridobj[x + 1][y + 1].status == 1)
			{
				gridobj[x][y].neighboursCell++;
			}
			if (gridobj[x - 1][y - 1].status == 1)
			{
				gridobj[x][y].neighboursCell++;
			}
			if (gridobj[x - 1][y + 1].status == 1)
			{
				gridobj[x][y].neighboursCell++;
			}
			if (gridobj[x + 1][y - 1].status == 1)
			{
				gridobj[x][y].neighboursCell++;
			}

			

			if (gridobj[x][y].status == 2)
			{
				gridobj[x][y].col = sf::Color::Red;
			}
			if (gridobj[x][y].status == 1)
			{
				gridobj[x][y].col = sf::Color::Green;
				gridobj[x][y].strcol = "Green";
			}
			if (gridobj[x][y].status == 0)
			
			{
				gridobj[x][y].col = sf::Color::Black;
				gridobj[x][y].strcol = "Red";
			}
			rect.setPosition(sf::Vector2f(x * (offset + buf), y * (offset + buf)));

			if (gridobj[x][y].neighboursCell == 0)
			{
				gridobj[x][y].col = sf::Color::Black;
			}
			rect.setFillColor(gridobj[x][y].col);



			Tile[x][y] = rect;

			if (gridobj[x][y].status != 1 )
			{
				if (rand() % 50 == 5)
				{
					gridobj[x][y].status = 1;

					
				}
			}
		}
	}
	for (int x = 0; x < GridSizeX; x++)
	{
		for (int y = 0; y < GridSizeY; y++)
		{
			if (gridobj[x][y].status == 1)
			{
				if (gridobj[x][y].neighboursCell < 1)
				{
					gridobj[x][y].status = 0;
					//std::cout << "died, not enough" << std::endl;
					//std::cout << gridobj[x][y].neighboursCell << std::endl;
				}
				else if (gridobj[x][y].neighboursCell > 3)
				{
					//gridobj[x][y].status = 0;
					//std::cout << "died, toomuch" << std::endl;
				}
				else if (gridobj[x][y].neighboursCell == 2 | gridobj[x][y].neighboursCell == 3)
				{
					//surfive
				}
			}
			if (!gridobj[x][y].status == 1)
			{
				if (gridobj[x][y].neighboursCell > 3)
				{
					gridobj[x][y].status = 1;
				//	std::cout << "live";
				}
			}
		}
	}
}