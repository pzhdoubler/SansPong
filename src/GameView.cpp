#include <GameView.h>

#include <SFML/Graphics.hpp>
#include <StatePlaying.h>
#include <GameConstants.h>

/*
Initializes the GameView class with a reference to the game state, the side the view controls,
and a reference to the screen to update. The last two may not be used by certain implementations of
GameView.
*/
bool GameView::init(StatePlaying& game, GameConstants::Player side, sf::RenderWindow& screen)
{
	this->game = &game;
	this->side = side;
	this->screen = &screen;
}