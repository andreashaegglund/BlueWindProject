#include "Universe.h"
#include "Game.h"
#include "World.h" 
#include "Tile.h"
#include "Application.h"
#include "GameWon.h"
#include "NPC.h"
#include <iostream>

using namespace std;

Universe::Universe(Game * gamePtr)
	: gamePointer_{gamePtr}
{
	loadTiles();
	loadWorlds();
	populateWorlds();
}

Universe::~Universe()
{
	gamePointer_ = nullptr;
	currentWorld_ = nullptr;

	while (!worlds_.empty())
	{
		delete worlds_.back();
		worlds_.pop_back();
	}

	while (!tileAtlas_.empty())
	{
		auto it = tileAtlas_.begin();
		delete it->second;
		tileAtlas_.erase(it);
	}
}

void Universe::update()
{
	currentWorld_->update();
}

void Universe::render(GameWindow & window)
{
	currentWorld_->render(window);
}

World * Universe::getCurrentWorld()
{
	return currentWorld_;
}

World * Universe::getWorld(int ID)
{
	for (auto it : worlds_)
	{
		if (ID == it->getID())
		{
			return it;
		}
	}
	throw UniverseException("Kunde inte hitta v�rld med ID:" + ID);
}

void Universe::setCurrentWorld(int ID)
{
	for (auto it : worlds_)
	{
		if (ID == it->getID())
		{
			currentWorld_ = it;
		}
	}
}

void Universe::switchWorld(int ID, int x, int y)
{
	setCurrentWorld(ID);
	gamePointer_->getPlayer()->teleport(x, y);
	gamePointer_->getPlayer()->setCurrentWorld(currentWorld_);
	gamePointer_->getApp()->getSoundHandler().playMusic(currentWorld_->getMusic());
}

Tile& Universe::getTile(int i)
{
	return (*tileAtlas_.find(i)->second);
}

Game * Universe::getGame() const
{
	return gamePointer_;
}

void Universe::loadTiles()
{
	cout << "Laddar in Tiles" << endl;
	tileAtlas_.emplace(-1, new Tile(gamePointer_->getTexture("void"), true));
	tileAtlas_.emplace(0,new Tile(gamePointer_->getTexture("grass"), true));
	tileAtlas_.emplace(1,new Tile(gamePointer_->getTexture("grassTree"), false));
	tileAtlas_.emplace(2, new Tile(gamePointer_->getTexture("bridge"), true));
	tileAtlas_.emplace(3, new Tile(gamePointer_->getTexture("house00"), false));
	tileAtlas_.emplace(4, new Tile(gamePointer_->getTexture("house01"), false));
	tileAtlas_.emplace(5, new Tile(gamePointer_->getTexture("house02"), false));
	tileAtlas_.emplace(6, new Tile(gamePointer_->getTexture("house03"), false));
	tileAtlas_.emplace(7, new Tile(gamePointer_->getTexture("house10"), false));
	tileAtlas_.emplace(8, new Tile(gamePointer_->getTexture("house11"), false));
	tileAtlas_.emplace(9, new Tile(gamePointer_->getTexture("house12"), false));
	tileAtlas_.emplace(10, new Tile(gamePointer_->getTexture("house13"), false));
	tileAtlas_.emplace(11, new Tile(gamePointer_->getTexture("house20"), false));
	tileAtlas_.emplace(12, new Tile(gamePointer_->getTexture("house21"), false));
	tileAtlas_.emplace(13, new Tile(gamePointer_->getTexture("house22"), false));
	tileAtlas_.emplace(14, new Tile(gamePointer_->getTexture("house23"), false));
	tileAtlas_.emplace(15, new Tile(gamePointer_->getTexture("house30"), false));
	tileAtlas_.emplace(16, new Tile(gamePointer_->getTexture("house31"), false));
	tileAtlas_.emplace(17, new Tile(gamePointer_->getTexture("house32"), false));
	tileAtlas_.emplace(18, new Tile(gamePointer_->getTexture("house33"), false));
	tileAtlas_.emplace(19, new Tile(gamePointer_->getTexture("mountainGrass"), false));
	tileAtlas_.emplace(20, new Tile(gamePointer_->getTexture("water"), false));
	tileAtlas_.emplace(21, new Tile(gamePointer_->getTexture("grassStump"), true));
	tileAtlas_.emplace(22, new Tile(gamePointer_->getTexture("snow"), true));
	tileAtlas_.emplace(23, new Tile(gamePointer_->getTexture("snowTree"), false));
	tileAtlas_.emplace(24, new Tile(gamePointer_->getTexture("cactus"), false));
	tileAtlas_.emplace(25, new Tile(gamePointer_->getTexture("sand"), true));
	tileAtlas_.emplace(26, new Tile(gamePointer_->getTexture("palmtree"), false));
	tileAtlas_.emplace(100, new Tile(gamePointer_->getTexture("lava"), false));
	tileAtlas_.emplace(101, new Tile(gamePointer_->getTexture("lavastone"), true));
	tileAtlas_.emplace(102, new Tile(gamePointer_->getTexture("burnedTree"), false));
	
	cout << "Laddning av tiles klart" << endl;
}

void Universe::loadWorlds()
{
	cout << "Laddar in v�rldar" << endl;
	worlds_.push_back(new World(0, this, "res/worlds/world0.bmp", "world0Music"));
	worlds_.push_back(new World(1, this, "res/worlds/world1.bmp", "world1Music"));
	worlds_.push_back(new World(2, this, "res/worlds/world2.bmp", "world2Music"));
	worlds_.push_back(new World(3, this, "res/worlds/world3.bmp", "world3Music"));
	worlds_.push_back(new World(4, this, "res/worlds/world4.bmp", "world4Music"));

	cout << "Laddning av v�rldar klart" << endl;

	setCurrentWorld(0);
}

void Universe::populateWorlds() 
{
	void BridgeGuardInteract(NPC*);
	void ErwinInteract(NPC*);
	void JamesClerkInteract(NPC*);
	void CthuluInteract(NPC*);

	void treeInteract(NPC*);
	void World0_World1Interact(World*);
	void World1_World0Interact(World*);
	void World1_World2Interact(World*);
	void World2_World1Interact(World*);
	void World2_World3Interact(World*);
	void World3_World2Interact(World*);

	//OBS!!!!!!
	//UNIKA ID KR�VS

	//-----------------WORLD 0------------------------------------
	//NPC
	addNPC(0, new NPC(1, 100, 10, 0, "Bridge Guard", sf::Vector2f(42 * Tile::TILESIZE, 18 * Tile::TILESIZE), getWorld(0), gamePointer_->getTexture("NPC"), "", BridgeGuardInteract));
	addNPC(0, new NPC(1, 100, 10, 2, "James Clerk", sf::Vector2f(10 * Tile::TILESIZE, 3 * Tile::TILESIZE), getWorld(0), gamePointer_->getTexture("NPC"), "Hej, jag heter James Clerk!", JamesClerkInteract));
	
	//Tr�d
	addNPC(0, new NPC(1, 100, 10, 3, "Tree", sf::Vector2f(18 * Tile::TILESIZE, 36 * Tile::TILESIZE), getWorld(0), gamePointer_->getTexture("grassTreeChoppable"), "", treeInteract));
	addNPC(0, new NPC(1, 100, 10, 4, "Tree", sf::Vector2f(41 * Tile::TILESIZE, 28 * Tile::TILESIZE), getWorld(0), gamePointer_->getTexture("grassTreeChoppable"), "", treeInteract));
	addNPC(0, new NPC(1, 100, 10, 5, "Tree", sf::Vector2f(37 * Tile::TILESIZE, 31 * Tile::TILESIZE), getWorld(0), gamePointer_->getTexture("grassTreeChoppable"), "", treeInteract));
	addNPC(0, new NPC(1, 100, 10, 6, "Tree", sf::Vector2f(27 * Tile::TILESIZE, 38 * Tile::TILESIZE), getWorld(0), gamePointer_->getTexture("grassTreeChoppable"), "", treeInteract));
	addNPC(0, new NPC(1, 100, 10, 7, "Tree", sf::Vector2f(18 * Tile::TILESIZE, 32 * Tile::TILESIZE), getWorld(0), gamePointer_->getTexture("grassTreeChoppable"), "", treeInteract));
	addNPC(0, new NPC(1, 100, 10, 8, "Tree", sf::Vector2f(33 * Tile::TILESIZE, 39 * Tile::TILESIZE), getWorld(0), gamePointer_->getTexture("grassTreeChoppable"), "", treeInteract));
	addNPC(0, new NPC(1, 100, 10, 9, "Tree", sf::Vector2f(36 * Tile::TILESIZE, 36 * Tile::TILESIZE), getWorld(0), gamePointer_->getTexture("grassTreeChoppable"), "", treeInteract));
	addNPC(0, new NPC(1, 100, 10, 10, "Tree", sf::Vector2f(47 * Tile::TILESIZE, 36 * Tile::TILESIZE), getWorld(0), gamePointer_->getTexture("grassTreeChoppable"), "", treeInteract));
	addNPC(0, new NPC(1, 100, 10, 11, "Tree", sf::Vector2f(44 * Tile::TILESIZE, 39 * Tile::TILESIZE), getWorld(0), gamePointer_->getTexture("grassTreeChoppable"), "", treeInteract));
	addNPC(0, new NPC(1, 100, 10, 12, "Tree", sf::Vector2f(40 * Tile::TILESIZE, 46 * Tile::TILESIZE), getWorld(0), gamePointer_->getTexture("grassTreeChoppable"), "", treeInteract));
	addNPC(0, new NPC(1, 100, 10, 13, "Tree", sf::Vector2f(30 * Tile::TILESIZE, 47 * Tile::TILESIZE), getWorld(0), gamePointer_->getTexture("grassTreeChoppable"), "", treeInteract));
	addNPC(0, new NPC(1, 100, 10, 14, "Tree", sf::Vector2f(23 * Tile::TILESIZE, 45 * Tile::TILESIZE), getWorld(0), gamePointer_->getTexture("grassTreeChoppable"), "", treeInteract));
	
	//Enemies
	addEnemy(0, new Enemy(1, 100, 10, 0, "Pelle", sf::Vector2f(22 * Tile::TILESIZE, 31 * Tile::TILESIZE), getWorld(0), gamePointer_->getTexture("enemy4")));
	addEnemy(0, new Enemy(1, 100, 10, 1, "Pelle", sf::Vector2f(30 * Tile::TILESIZE, 42 * Tile::TILESIZE), getWorld(0), gamePointer_->getTexture("enemy4")));
	addEnemy(0, new Enemy(1, 100, 10, 2, "Pelle", sf::Vector2f(38 * Tile::TILESIZE, 37 * Tile::TILESIZE), getWorld(0), gamePointer_->getTexture("enemy4")));

	//Sensorer
	addSensor(0, new Sensor(0, "World0_World1", sf::Vector2f(66 * Tile::TILESIZE, 13 * Tile::TILESIZE), getWorld(1), World0_World1Interact, gamePointer_->getTexture("enemy")));

	//----------------------------WORLD 1-------------------------
	addSensor(1, new Sensor(0, "World1_World0", sf::Vector2f(12 * Tile::TILESIZE, 14 * Tile::TILESIZE), getWorld(1), World1_World0Interact, gamePointer_->getTexture("enemy")));
	addSensor(1, new Sensor(1, "World1_World2", sf::Vector2f(58 * Tile::TILESIZE, 9 * Tile::TILESIZE), getWorld(1), World1_World2Interact, gamePointer_->getTexture("NPC")));

	//----------------------------WORLD2--------------------------
	addSensor(2, new Sensor(0, "World2_World1", sf::Vector2f(41* Tile::TILESIZE, 64 * Tile::TILESIZE), getWorld(2), World2_World1Interact, gamePointer_->getTexture("enemy")));
	addSensor(2, new Sensor(1, "World2_World3", sf::Vector2f(70 * Tile::TILESIZE, 17 * Tile::TILESIZE), getWorld(2), World2_World3Interact, gamePointer_->getTexture("enemy")));

	//----------------------------WORLD3--------------------------
	addSensor(3, new Sensor(0, "World3_World2", sf::Vector2f(12 * Tile::TILESIZE, 17 * Tile::TILESIZE), getWorld(3), World3_World2Interact, gamePointer_->getTexture("enemy")));

	//NPC
	addNPC(3, new NPC(1, 100, 10, 1, "Cthulu", sf::Vector2f(58 * Tile::TILESIZE, 49 * Tile::TILESIZE), getWorld(3), gamePointer_->getTexture("NPC5"), "I AM CTHULU", CthuluInteract));

	//----------------------------WORLD4--------------------------
	
	addNPC(4, new NPC(1, 100, 10, 1, "Erwin", sf::Vector2f(49 * Tile::TILESIZE, 37 * Tile::TILESIZE), getWorld(4), gamePointer_->getTexture("NPC"), "Hej, jag heter Erwin!", ErwinInteract));

	//Enemy
	addEnemy(4, new Enemy(1, 300, 30, 0, "Bad Alloc", sf::Vector2f(46 * Tile::TILESIZE, 49 * Tile::TILESIZE), getWorld(4), gamePointer_->getTexture("enemy7")));
}

void Universe::addEnemy(int worldID, Enemy * enemyPtr)
{
	for (auto it : worlds_)
	{
		if (it->getID() == worldID)
		{
			it->addEnemy(enemyPtr);
			break;
		}
	}
}

void Universe::addNPC(int worldID, NPC * NPCPtr)
{
	for (auto it : worlds_)
	{
		if (it->getID() == worldID)
		{
			it->addNPC(NPCPtr);
			break;
		}
	}
}

void Universe::addSensor(int worldID, Sensor* sensorPtr)
{
	for (auto it : worlds_)
	{
		if (it->getID() == worldID)
		{
			it->addSensor(sensorPtr);
			break;
		}
	}
}

void BridgeGuardInteract(NPC* NPCPtr)
{
	int startposition{ 13 * NPCPtr->getWorld()->getMapWidth() + 40 };
	int bridgeLength{ 0 };

	while (NPCPtr->getWorld()->getTileVector().at(startposition) == 2)
	{
		++startposition;
		++bridgeLength;
	}

	while (NPCPtr->getWorld()->getUniverse()->getGame()->getPlayer()->getInventory()->hasItem(0))
	{
		NPCPtr->getWorld()->getUniverse()->getGame()->getPlayer()->getInventory()->removeItem(0);
		NPCPtr->getWorld()->changeTile(startposition, 2);
		++startposition;
		++bridgeLength;
	}

	switch (bridgeLength)
	{
	case 0:
		NPCPtr->getWorld()->getUniverse()->getGame()->getUserInterface()->addStringToChatBox("Bring me some wood and I could perhaps, possibly, but most likely not, help build you a bridge!");
		break;
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
	case 11:
		NPCPtr->getWorld()->getUniverse()->getGame()->getUserInterface()->addStringToChatBox("I still need some more wood in order to finish the bridge!");
		break;
	case 12:
		NPCPtr->getWorld()->getUniverse()->getGame()->getUserInterface()->addStringToChatBox("The bridge is finished!");
		break;
	default:
		break;
	}
}

void ErwinInteract(NPC* NPCPtr)
{
	Application* AppPtr{ NPCPtr->getWorld()->getUniverse()->getGame()->getApp() };
	AppPtr->setNextFrame(new GameWon(AppPtr));
}

void JamesClerkInteract(NPC* NPCPtr)
{
	NPCPtr->getWorld()->getUniverse()->switchWorld(1, 64, 64);
}

void treeInteract(NPC* NPCPtr) 
{
	if (!NPCPtr->getWorld()->getUniverse()->getGame()->getPlayer()->getInventory()->isFull())
	{
		NPCPtr->getWorld()->changeTile(((NPCPtr->getPosition().y / 32) * NPCPtr->getWorld()->getMapWidth() + NPCPtr->getPosition().x / 32), 21);
		NPCPtr->getWorld()->getUniverse()->getGame()->getPlayer()->getInventory()->addItem(0);
		NPCPtr->die();
	}
	else
	{
		NPCPtr->getWorld()->getUniverse()->getGame()->getUserInterface()->addStringToChatBox("Inventory is full.");
	}
}

void CthuluInteract(NPC* NPCPtr)
{
	NPCPtr->getWorld()->getUniverse()->switchWorld(4, 13 * Tile::TILESIZE, 37 * Tile::TILESIZE);
}

void World0_World1Interact(World* worldPtr)
{
	worldPtr->getUniverse()->switchWorld(1, 14 * Tile::TILESIZE, 14 * Tile::TILESIZE);
}

void World1_World0Interact(World* worldPtr)
{
	worldPtr->getUniverse()->switchWorld(0, 65 * Tile::TILESIZE, 13 * Tile::TILESIZE);
}

void World1_World2Interact(World* worldPtr)
{
	worldPtr->getUniverse()->switchWorld(2, 41 * Tile::TILESIZE, 63 * Tile::TILESIZE);
}

void World2_World1Interact(World* worldPtr)
{
	worldPtr->getUniverse()->switchWorld(1, 58 * Tile::TILESIZE, 10 * Tile::TILESIZE);
}

void World2_World3Interact(World* worldPtr)
{
	worldPtr->getUniverse()->switchWorld(3, 13 * Tile::TILESIZE, 17 * Tile::TILESIZE);
}

void World3_World2Interact(World* worldPtr)
{
	worldPtr->getUniverse()->switchWorld(2, 69 * Tile::TILESIZE, 17 * Tile::TILESIZE);
}
