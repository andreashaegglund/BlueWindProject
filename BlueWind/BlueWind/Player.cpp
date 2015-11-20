#include "Player.h"
#include "World.h"
#include "Universe.h"
#include "Game.h"
#include "Frame.h"
#include "Application.h"
#include "Input.h"
#include <map>

using namespace std;


Player::Player(World * worldPtr, sf::Texture& texture)
	: Entity(1, 100, 10, 0, "Kalle", sf::Vector2f(2 * 16, 2 * 16), worldPtr)
{
	sprite_.setOrigin(sf::Vector2f(0.0f, 0.0f));
	sprite_.setTexture(texture);
}

int Player::getExperience() const
{
	return experience_;
}

void Player::addExperience(int value)
{
	experience_ += value;
}

void Player::update()
{
	if (worldPointer_->getUniverse()->getGame()->getApp()->getInput().pressedButtons_.at('a'))
		move(-1, 0);
	if (worldPointer_->getUniverse()->getGame()->getApp()->getInput().pressedButtons_.at('d'))
		move(1, 0);
	if (worldPointer_->getUniverse()->getGame()->getApp()->getInput().pressedButtons_.at('s'))
		move(0, 1);
	if (worldPointer_->getUniverse()->getGame()->getApp()->getInput().pressedButtons_.at('w'))
		move(0, -1);
}

void Player::render(GameWindow & window)
{
	sprite_.setPosition(position_);
	window.draw(sprite_);
}

const int Player::getAttackCooldown() const
{
	return attackCooldown_;
}

