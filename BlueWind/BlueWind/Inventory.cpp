#include "Inventory.h"
#include "Player.h"
#include <iostream>
#include "Game.h"
#include "Application.h"

using namespace std;

Inventory::Inventory(Player * player, Game* game)
	: playerPointer_{ player }, 
	gamePointer_{game}
{
	items_.reserve(maxSize_);
	populateItemList();
}

Inventory::~Inventory()
{
	while (!allItems_.empty())
	{
		delete allItems_.back();
		allItems_.pop_back();
	}
	items_.clear();
}

void Inventory::addItem(int ID)
{
	if (isFull())
	{
		gamePointer_->getUserInterface()->addStringToChatBox("Inventory is full");
		return;
	}
	for (auto it : allItems_)
	{
		if (it->getID() == ID)
		{
			items_.push_back(it);
		}
	}
}

void Inventory::removeItem(int ID)
{
	cout << "Removing item :" + ID << endl;
	auto it = items_.begin();

	while (it != items_.end())
	{
		cout << "Iterating :" + ID << endl;
		if ((*it)->getID() == ID)
		{
			items_.erase(it);
			break;
		}
		++it;
	}
}

bool Inventory::hasItem(int ID)
{
	for (auto it : items_)
	{
		if (it->getID() == ID)
		{
			return true;
		}
	}
	return false;
}

bool Inventory::isFull()
{
	return (items_.size() >= maxSize_);
}

int Inventory::getCount(int ID)
{
	int count{ 0 };

	for (auto it : items_)
	{
		if (it->getID() == ID)
		{
			count++;
		}
	}

	return count;
}

Item * Inventory::at(int pos)
{
	if (pos >= 0 && pos <= items_.size())
		return items_.at(pos);
	else
		throw InventoryException("Kan ej h�mta element p� angiven position:" + pos);
}

int Inventory::getSize()
{
	return items_.size();
}

const unsigned int Inventory::getMaxSize()
{
	return maxSize_;
}

std::string Inventory::toString()
{
	string s;
	for (auto it : items_)
	{
		s = s + to_string(it->getID()) + " ";
	}
	return s;
}

void Inventory::populateItemList()
{
	//							ID	Namn		Textur
	allItems_.push_back(new Item{ 0,"Tree",gamePointer_->getTexture("grassTreeChoppable") });
	allItems_.push_back(new Item{ 1,"Axe",gamePointer_->getTexture("pickAxe") });
	allItems_.push_back(new Item{ 2,"Energy Ring",gamePointer_->getTexture("energyRing") });
	allItems_.push_back(new Item{ 3,"Armour",gamePointer_->getTexture("armour") });
	allItems_.push_back(new Item{ 4,"Amulet of Power",gamePointer_->getTexture("amulet") });
	allItems_.push_back(new Item{ 5,"Magic Orb of Fire",gamePointer_->getTexture("magicFireOrb") });
	allItems_.push_back(new Item{ 6,"Magic Wet Calice",gamePointer_->getTexture("magicWaterCalice") });

}
