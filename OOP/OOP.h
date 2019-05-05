#pragma once
#include "Grid.h";





sf::RenderWindow window(sf::VideoMode(1000, 1000), "OOP");

sf::RectangleShape Tile[GridSizeX][GridSizeY];
sf::RectangleShape rect(sf::Vector2f(TileSize, TileSize));
