#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include <ctime>    
#include <cstdlib>  
#include "String"
#include <iostream>

const int GridSizeX = 200;
const int GridSizeY = 200;

static int TileSize = 5;
static int TileBuf = 0;

static int offset = 5;

void InstantiateGrid(sf::RenderWindow &window, sf::RectangleShape Tile[GridSizeX][GridSizeY], sf::RectangleShape &rect, int buf);
void UpdatePositions(sf::RenderWindow &window, sf::RectangleShape Tile[GridSizeX][GridSizeY], sf::RectangleShape &rect, int buf);
class grid
{
public:
	sf::Color col;
	int status;
	int posx;
	int posy;

	int neighboursCell;

	std::string strcol;
};
class cell2
{
	public:
	sf::Color col;
	bool status;
};