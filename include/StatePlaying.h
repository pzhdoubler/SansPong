#ifndef _STATEPLAYING_H_
#define _STATEPLAYING_H_

#include <vector>
#include <SingleRandom.h>
#include <GameConstants.h>

/*
Manages the game's state and physics calcuations. Also accepts various key inputs from GameView classes
to update the state of the game.
*/
class StatePlaying
{
	public:
		StatePlaying() {};

		bool init(int lscore, int rscore);

		bool update(float deltaMs);

		bool keyUpdate(GameConstants::KeyInput key, GameConstants::Player p, float deltaMs);

		bool isPlaying();

		std::vector<int> getBallPosition();

		std::vector<int> getBallVelocity();

		std::vector<int> getPaddlePositions();

		std::vector<int> getScore();

	private:

		void movePaddle(GameConstants::KeyInput key, GameConstants::Player p, float deltaMs);

		float ball_xpos, ball_ypos, lpaddle_pos, rpaddle_pos;

		int lpaddle_move, rpaddle_move;

		int ball_xvel, ball_yvel;

		int lscore, rscore;

		bool playing;

};

#endif // !_STATEPLAYING_H_

