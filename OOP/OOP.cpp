
#include <SFML/Graphics.hpp>
#include "OOP.h"

int main()
{
	window.setFramerateLimit(140);
	InstantiateGrid(window, Tile, rect, TileBuf);
	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();

		sf::Time elapsed = clock.getElapsedTime();
		
		if (elapsed.asSeconds() >= sf::seconds(0.001f).asSeconds())
		{
			clock.restart();
		//	std::cout << elapsed.asMicroseconds() << std::endl;
			UpdatePositions(window, Tile, rect, TileBuf);
		}
			

		for (int x = 0; x < GridSizeX; x++)
		{
			for (int y = 0; y < GridSizeY; y++)
			{
				window.draw(Tile[x][y]);
			}
		}
		window.display();
	}
}
