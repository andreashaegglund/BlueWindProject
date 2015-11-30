#include "Game.h"
#include <iostream>
#include "Universe.h"
#include <fstream>
#include <sstream>

using namespace std;

Game::Game(Application * appPtr, bool loadSave)
	:Frame{appPtr}, universe_{this}, player_{universe_.getCurrentWorld(), textureHandler_.getTextureRef("player"), this }, ui_{&player_}
{
	cout << "Game startas!" << endl;
	if (loadSave)
	{
		loadGame();
	}
}

void Game::update()
{
	//cout << "Game uppdaterar" << endl;
	universe_.update();
	player_.update();
	ui_.update();
}

void Game::render(GameWindow & window)
{
	sf::View view2 = window.getView();
	view2.setCenter(player_.getPosition());
	window.setView(view2);
	//cout << "Game renderar" << endl;
	universe_.render(window);
	player_.render(window);
	ui_.render(window);
}

void Game::handleKeyEvent(sf::Event event)
{
	switch (event.key.code)
	{
	case sf::Keyboard::Space:
		player_.attack(universe_.getCurrentWorld()->getEnemyVector());
		
		break;
	case sf::Keyboard::I:

		//TODO flytta in i player kanske
		for (auto it : universe_.getCurrentWorld()->getNPCVector())
		{
			if (getDistance(player_.getPosition(), it.second->getPosition()) <= 32)
			{
				it.second->interact();
				break;
			}
		}
		break;
	case sf::Keyboard::U:
		cout << (int) player_.getPosition().x / 32 << "," << (int) player_.getPosition().y / 32 << endl;
		break;
	case sf::Keyboard::L:
		ui_.addStringToChatBox("Hejsan.!");
		break;
	case sf::Keyboard::E:
		saveGame();
		break;
	case sf::Keyboard::F:
		player_.getInventory()->addItem(0);
		cout << player_.getInventory()->toString() << endl;
		break;
	case sf::Keyboard::T:
		ui_.handleKeyEvent(event);
		break;
	default:
		break;
	}
	
}

void Game::handleMouseEvent(sf::Event)
{
}

vector<int> splitString(string s)
{
	stringstream ss(s);
	vector<int> IDs;
	string sub;

	while (ss >> sub)
		IDs.push_back(stoi(sub));
	return IDs;
}

void Game::saveGame()
{
	ofstream saveStream;
	saveStream.open("savefile.txt", std::ofstream::out | std::ofstream::trunc);
	if (saveStream.is_open())
	{
		saveStream << player_.getName() << endl;
		saveStream << player_.getMaxHealth() << endl;
		saveStream << player_.getMaxMana() << endl;
		saveStream << player_.getDamage() << endl;
		saveStream << player_.getLevel() << endl;
		saveStream << player_.getExperience() << endl;
		saveStream << universe_.getCurrentWorld()->getID() << endl;
		saveStream << player_.getPosition().x << endl;
		saveStream << player_.getPosition().y << endl;
		saveStream << player_.getInventory()->toString() << endl;
		saveStream.close();
		cout << "Game saved!" << endl;
	}
}

void Game::loadGame()
{
	string line;
	ifstream saveStream("savefile.txt");
	if (saveStream.is_open())
	{
		getline(saveStream, line); //name
		player_.setName(line);
		getline(saveStream, line); //maxHealth
		player_.setMaxHealth(stoi(line));
		getline(saveStream, line); //maxMana
		player_.setMaxMana(stoi(line));
		getline(saveStream, line); //damage
		player_.setDamage(stoi(line));
		getline(saveStream, line); //level
		player_.setLevel(stoi(line));
		getline(saveStream, line); //experience
		player_.setExperience(stoi(line));
		getline(saveStream, line); //currWorld
		int worldID = stoi(line);
		getline(saveStream, line); //pos x
		int posX = stoi(line);
		getline(saveStream, line); //pos y
		int posY = stoi(line);
		universe_.switchWorld(worldID, posX, posY);
		getline(saveStream, line); //inv
		vector<int> items = splitString(line);
		for (auto it : items)
		{
			player_.getInventory()->addItem(it);
		}
		saveStream.close();
	}
}

Player * Game::getPlayer()
{
	return &player_;
}

Application * Game::getApp()
{
	return appPointer_;
}

UserInterface * Game::getUserInterface()
{
	return &ui_;
}

sf::Texture & Game::getTexture(const std::string& ref)
{
	return textureHandler_.getTextureRef(ref);
}

