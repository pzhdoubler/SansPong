#ifndef _GAMECONSTANTS_H_
#define _GAMECONSTANTS_H_

/*
List of important game constants and enums. All members are public to allow access for all classes.
*/
class GameConstants
{
	public:
		//Board Size Values
		static const int X_MIN = 50;
		static const int X_MAX = 750;
		static const int Y_MIN = 170;
		static const int Y_MAX = 600;
		static const int BALL_RAD = 25;
		static const int PADDLE_HEIGHT = 90;
		static const int PADDLE_WIDTH = 17;

		//Physics Constants
		static const int MIN_BALL_SPEED = 8;
		static const int MAX_BALL_SPEED = 12;
		static const int BALL_SPEED_MULTIPLIER = 30000;
		static const int PADDLE_SPEED = 600;

		//Key Inputs
		enum KeyInput
		{
			PADDLE_UP, PADDLE_DOWN, START, QUIT, PAUSE
		};

		enum Player
		{
			L_PLAYER, R_PLAYER
		};

		enum Strategy
		{
			shortSighted, mirror
		};
};

#endif // !_GAMECONSTANTS_H_