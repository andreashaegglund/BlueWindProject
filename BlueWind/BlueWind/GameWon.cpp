#include "GameWon.h"
#include "Application.h"
#include <iostream>

using namespace std;

GameWon::GameWon(Application * appPtr)
	: Frame{ appPtr }
{
	void mainMenuCallback(Application*);
	addButton(sf::Vector2f(400 - 175, 350), sf::Vector2f(350, 100), "res/textures/menuButton.png", "res/textures/menuButtonHover.png", mainMenuCallback);
	appPtr->getSoundHandler().playMusic("gameWonMusic");
}



void GameWon::handleKeyEvent(sf::Event event)
{
}

void GameWon::handleMouseEvent(sf::Event event)
{
	switch (event.mouseButton.button)
	{
	case sf::Mouse::Left:
	{
		sf::Vector2i mousePosition{ sf::Mouse::getPosition(appPointer_->getGameWindow()) };

		for (auto it : buttons_)
		{
			if (it->mouseOnButton(mousePosition))
			{
				it->clicked();
				break;
			}
		}
	}
	default:
		break;
	}
}

void GameWon::update()
{
	for (auto it : buttons_)
	{
		it->update();
	}
}

void GameWon::render(GameWindow & window)
{
	//TODO Detta kan g�ras i konstruktorn.
	sf::Texture bTexture;
	if (!bTexture.loadFromFile("res/textures/GameWon.png"))
		cout << "Could not load gameOver" << endl;

	background_.setTexture(bTexture);
	window.draw(background_);

	for (auto it : buttons_)
	{
		it->render(window);
	}
}

void mainMenuCallback(Application* ptr)
{
	ptr->getSoundHandler().stopMusic("gameWonMusic");
	ptr->setNextFrame(new Menu(ptr));
}
