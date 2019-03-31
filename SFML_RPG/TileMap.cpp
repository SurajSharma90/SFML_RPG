#include "stdafx.h"
#include "TileMap.h"

void TileMap::clear()
{
	for (int x = 0; x < this->maxSizeWorldGrid.x; x++)
	{
		for (int y = 0; y < this->maxSizeWorldGrid.y; y++)
		{
			for (int z = 0; z < this->layers; z++)
			{
				delete this->map[x][y][z];
				this->map[x][y][z] = NULL;
			}
			this->map[x][y].clear();
		}
		this->map[x].clear();
	}
	this->map.clear();

	//std::cout << this->map.size() << "\n";
}

TileMap::TileMap(float gridSize, int width, int height, std::string texture_file)
{
	this->gridSizeF = gridSize;
	this->gridSizeI = static_cast<int>(this->gridSizeF);
	this->maxSizeWorldGrid.x = width;
	this->maxSizeWorldGrid.y = height;
	this->maxSizeWorldF.x = static_cast<float>(width) * gridSize;
	this->maxSizeWorldF.y = static_cast<float>(height) * gridSize;
	this->layers = 1;
	this->textureFile = texture_file;

	this->fromX = 0;
	this->toX = 0;
	this->fromY = 0;
	this->toY = 0;
	this->layer = 0;

	this->map.resize(this->maxSizeWorldGrid.x, std::vector< std::vector<Tile*> >());
	for (int x = 0; x < this->maxSizeWorldGrid.x; x++)
	{
		for (int y = 0; y < this->maxSizeWorldGrid.y; y++)
		{
			this->map[x].resize(this->maxSizeWorldGrid.y, std::vector<Tile*>());

			for (int z = 0; z < this->layers; z++)
			{
				this->map[x][y].resize(this->layers, NULL);
			}
		}
	}

	if (!this->tileSheet.loadFromFile(texture_file))
		std::cout << "ERROR::TILEMAP::FAILED TO LOAD TILETEXTURESHEET::FILENAME: " << texture_file << "\n";

	this->collisionBox.setSize(sf::Vector2f(gridSize, gridSize));
	this->collisionBox.setFillColor(sf::Color(255, 0, 0, 50));
	this->collisionBox.setOutlineColor(sf::Color::Red);
	this->collisionBox.setOutlineThickness(1.f);
}

TileMap::~TileMap()
{
	this->clear();
}

//Accessors
const sf::Texture * TileMap::getTileSheet() const
{
	return &this->tileSheet;
}

//Functions
void TileMap::addTile(const int x, const int y, const int z, const sf::IntRect& texture_rect, const bool& collision, const short& type)
{
	/* Take three indicies from the mouse position in the grid and add a tile to that position if the internal tilemap array allows it. */

	if (x < this->maxSizeWorldGrid.x && x >= 0 &&
		y < this->maxSizeWorldGrid.y && y >= 0 &&
		z < this->layers && z >= 0)
	{
		if (this->map[x][y][z] == NULL)
		{
			/* OK To add tile. */
			this->map[x][y][z] = new Tile(x, y, this->gridSizeF, this->tileSheet, texture_rect, collision, type);
			std::cout << "DEGBUG: ADDED TILE!" << "\n";
		}	
	}
}

void TileMap::removeTile(const int x, const int y, const int z)
{
	/* Take three indicies from the mouse position in the grid and remove a tile at that position if the internal tilemap array allows it. */

	if (x < this->maxSizeWorldGrid.x && x >= 0 &&
		y < this->maxSizeWorldGrid.y && y >= 0 &&
		z < this->layers && z >= 0)
	{
		if (this->map[x][y][z] != NULL)
		{
			/* OK To remove tile. */
			delete this->map[x][y][z];
			this->map[x][y][z] = NULL;
			std::cout << "DEGBUG: REMOVED TILE!" << "\n";
		}
	}
}

void TileMap::saveToFile(const std::string file_name)
{
	/*Saves the entire tilemap to a text-file.
	Format: 
	Basic:
	Size x y
	gridSize
	layers
	texture file

	All tiles:
	gridPos x y layer 
	Texture rect x y 
	collision 
	type
	*/

	std::ofstream out_file;
	
	out_file.open(file_name);

	if (out_file.is_open())
	{
		out_file << this->maxSizeWorldGrid.x << " " << this->maxSizeWorldGrid.y << "\n"
			<< this->gridSizeI << "\n"
			<< this->layers << "\n"
			<< this->textureFile << "\n";

		for (int x = 0; x < this->maxSizeWorldGrid.x; x++)
		{
			for (int y = 0; y < this->maxSizeWorldGrid.y; y++)
			{
				for (int z = 0; z < this->layers; z++)
				{
					if(this->map[x][y][z])
						out_file << x << " " << y << " " << z << " " << 
						this->map[x][y][z]->getAsString() 
						<< " "; //MAKE SURE THIS LAST SPACE IS NOT SAVED!!!!
				}
			}
		}
	}
	else
	{
		std::cout << "ERROR::TILEMAP::COULD NOT SAVE TO FILE::FILENAME: " << file_name << "\n";
	}

	out_file.close();
}

void TileMap::loadFromFile(const std::string file_name)
{
	std::ifstream in_file;

	in_file.open(file_name);

	if (in_file.is_open())
	{
		sf::Vector2i size;
		int gridSize = 0;
		int layers = 0;
		std::string texture_file = "";
		int x = 0;
		int y = 0;
		int z = 0;
		int trX = 0;
		int trY = 0;
		bool collision = false;
		short type = 0;

		//Basics
		in_file >> size.x >> size.y >> gridSize >> layers >> texture_file;

		//Tiles
		this->gridSizeF = static_cast<float>(gridSize);
		this->gridSizeI = gridSize;
		this->maxSizeWorldGrid.x = size.x;
		this->maxSizeWorldGrid.y = size.y;
		this->layers = layers;
		this->textureFile = texture_file;

		this->clear();

		this->map.resize(this->maxSizeWorldGrid.x, std::vector< std::vector<Tile*> >());
		for (int x = 0; x < this->maxSizeWorldGrid.x; x++)
		{
			for (int y = 0; y < this->maxSizeWorldGrid.y; y++)
			{
				this->map[x].resize(this->maxSizeWorldGrid.y, std::vector<Tile*>());

				for (int z = 0; z < this->layers; z++)
				{
					this->map[x][y].resize(this->layers, NULL);
				}
			}
		}

		if (!this->tileSheet.loadFromFile(texture_file))
			std::cout << "ERROR::TILEMAP::FAILED TO LOAD TILETEXTURESHEET::FILENAME: " << texture_file << "\n";

		//Load all tiles
		while (in_file >> x >> y >> z >> trX >> trY >> collision >> type)
		{
			this->map[x][y][z] = new Tile(
				x, y,
				this->gridSizeF, 
				this->tileSheet, 
				sf::IntRect(trX, trY, this->gridSizeI, this->gridSizeI), 
				collision, 
				type
			);
		}
	}
	else
	{
		std::cout << "ERROR::TILEMAP::COULD NOT LOAD FROM FILE::FILENAME: " << file_name << "\n";
	}

	in_file.close();
}

void TileMap::updateCollision(Entity * entity, const float& dt)
{
	//WORLD BOUNDS
	if (entity->getPosition().x < 0.f)
	{
		entity->setPosition(0.f, entity->getPosition().y);
		entity->stopVelocityX();
	}
	else if (entity->getPosition().x + entity->getGlobalBounds().width > this->maxSizeWorldF.x)
	{
		entity->setPosition(this->maxSizeWorldF.x - entity->getGlobalBounds().width, entity->getPosition().y);
		entity->stopVelocityX();
	}
	if (entity->getPosition().y < 0.f)
	{
		entity->setPosition(entity->getPosition().x, 0.f);
		entity->stopVelocityY();
	}
	else if (entity->getPosition().y + entity->getGlobalBounds().height > this->maxSizeWorldF.y)
	{
		entity->setPosition(entity->getPosition().x, this->maxSizeWorldF.y - entity->getGlobalBounds().height);
		entity->stopVelocityY();
	}

	//TILES
	this->layer = 0;

	this->fromX = entity->getGridPosition(this->gridSizeI).x - 1;
	if (this->fromX < 0)
		this->fromX = 0;
	else if (this->fromX > this->maxSizeWorldGrid.x)
		this->fromX = this->maxSizeWorldGrid.x;

	this->toX = entity->getGridPosition(this->gridSizeI).x + 3;
	if (this->toX < 0)
		this->toX = 0;
	else if (this->toX > this->maxSizeWorldGrid.x)
		this->toX = this->maxSizeWorldGrid.x;

	this->fromY = entity->getGridPosition(this->gridSizeI).y - 1;
	if (this->fromY < 0)
		this->fromY = 0;
	else if (this->fromY > this->maxSizeWorldGrid.y)
		this->fromY = this->maxSizeWorldGrid.y;

	this->toY = entity->getGridPosition(this->gridSizeI).y + 3;
	if (this->toY < 0)
		this->toY = 0;
	else if (this->toY > this->maxSizeWorldGrid.y)
		this->toY = this->maxSizeWorldGrid.y;

	for (int x = this->fromX; x < this->toX; x++)
	{
		for (int y = this->fromY; y < this->toY; y++)
		{	
			sf::FloatRect playerBounds = entity->getGlobalBounds();
			sf::FloatRect wallBounds = this->map[x][y][this->layer]->getGlobalBounds();
			sf::FloatRect nextPositionBounds = entity->getNextPositionBounds(dt);

			if (this->map[x][y][this->layer]->getCollision() && 
				this->map[x][y][this->layer]->intersects(nextPositionBounds)
				)
			{
				//Bottom collision
				if (playerBounds.top < wallBounds.top
					&& playerBounds.top + playerBounds.height < wallBounds.top + wallBounds.height
					&& playerBounds.left < wallBounds.left + wallBounds.width
					&& playerBounds.left + playerBounds.width > wallBounds.left
					)
				{
					entity->stopVelocityY();
					entity->setPosition(playerBounds.left, wallBounds.top - playerBounds.height);
				}

				//Top collision
				else if (playerBounds.top > wallBounds.top
					&& playerBounds.top + playerBounds.height > wallBounds.top + wallBounds.height
					&& playerBounds.left < wallBounds.left + wallBounds.width
					&& playerBounds.left + playerBounds.width > wallBounds.left
					)
				{
					entity->stopVelocityY();
					entity->setPosition(playerBounds.left, wallBounds.top + wallBounds.height);
				}
					
				//Right collision
				if (playerBounds.left < wallBounds.left
					&& playerBounds.left + playerBounds.width < wallBounds.left + wallBounds.width
					&& playerBounds.top < wallBounds.top + wallBounds.height
					&& playerBounds.top + playerBounds.height > wallBounds.top
					)
				{
					entity->stopVelocityX();
					entity->setPosition(wallBounds.left - playerBounds.width, playerBounds.top);
				}
									
				//Left collision
				else if (playerBounds.left > wallBounds.left
					&& playerBounds.left + playerBounds.width > wallBounds.left + wallBounds.width
					&& playerBounds.top < wallBounds.top + wallBounds.height
					&& playerBounds.top + playerBounds.height > wallBounds.top
					)
				{
					entity->stopVelocityX();
					entity->setPosition(wallBounds.left + wallBounds.width, playerBounds.top);
				}
			}
		}
	}
}

void TileMap::update()
{

}

void TileMap::render(sf::RenderTarget & target, Entity* entity)
{
	if (entity)
	{
		this->layer = 0;

		this->fromX = entity->getGridPosition(this->gridSizeI).x - 5;
		if (this->fromX < 0)
			this->fromX = 0;
		else if (this->fromX > this->maxSizeWorldGrid.x)
			this->fromX = this->maxSizeWorldGrid.x;

		this->toX = entity->getGridPosition(this->gridSizeI).x + 8;
		if (this->toX < 0)
			this->toX = 0;
		else if (this->toX > this->maxSizeWorldGrid.x)
			this->toX = this->maxSizeWorldGrid.x;

		this->fromY = entity->getGridPosition(this->gridSizeI).y - 5;
		if (this->fromY < 0)
			this->fromY = 0;
		else if (this->fromY > this->maxSizeWorldGrid.y)
			this->fromY = this->maxSizeWorldGrid.y;

		this->toY = entity->getGridPosition(this->gridSizeI).y + 8;
		if (this->toY < 0)
			this->toY = 0;
		else if (this->toY > this->maxSizeWorldGrid.y)
			this->toY = this->maxSizeWorldGrid.y;

		for (int x = this->fromX; x < this->toX; x++)
		{
			for (int y = this->fromY; y < this->toY; y++)
			{
				this->map[x][y][this->layer]->render(target);
				if (this->map[x][y][this->layer]->getCollision())
				{
					this->collisionBox.setPosition(this->map[x][y][this->layer]->getPosition());
					target.draw(this->collisionBox);
				}
			}
		}
	}
	else
	{
		for (auto &x : this->map)
		{
			for (auto &y : x)
			{
				for (auto *z : y)
				{
					if (z != NULL)
					{
						z->render(target);
						if (z->getCollision())
						{
							this->collisionBox.setPosition(z->getPosition());
							target.draw(this->collisionBox);
						}
					}
				}
			}
		}
	}
}
