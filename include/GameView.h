#ifndef _GAMEVIEW_H_
#define _GAMEVIEW_H_

#include <SFML/Graphics.hpp>
#include <StatePlaying.h>
#include <GameConstants.h> 

/*
Abstract class to encapsulate all Views for the game state.
*/
class GameView
{
	public:
		GameView() {};

		bool init(StatePlaying& game, GameConstants::Player side, sf::RenderWindow& screen);

		virtual bool update(float deltaMs) = 0;

	protected:
		StatePlaying* game;

		GameConstants::Player side;

		sf::RenderWindow* screen;

};


#endif // !_GAMEVIEW_H_

