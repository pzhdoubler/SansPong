#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_

#include <SFML/Graphics.hpp>
#include <GameConstants.h>


/*
GameState interface class to encapsulate all states of the game.
*/
class GameState
{
	public:
		GameState() {};

		virtual bool init(int lscore, int rscore) = 0;

		virtual bool update(int deltaMs, sf::RenderWindow& screen) = 0;

		virtual bool keyUpdate(KeyInput key, Player p) = 0;

		virtual int[] getState() = 0;

		virtual int[] getScore() = 0;

};

#endif // !_GAMESTATE_H_