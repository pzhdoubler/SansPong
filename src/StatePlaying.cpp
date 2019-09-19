#include <StatePlaying.h>

#include <stdlib.h>
#include <cstdio>
#include <SingleRandom.h>

#define Const GameConstants

/*
Resets the game board with a certain score. Moves the paddles to a starting position and the ball to the middle.
It assigns the ball a random direction to start moving and unpauses the game if it was paused.
int lscore : the left player's current score
int rscore : the right player's current score
*/
bool StatePlaying::init(int lscore, int rscore)
{
	int direction;
	
	ball_xpos = (Const::X_MAX + Const::X_MIN)/2;
	ball_ypos = (Const::Y_MAX + Const::Y_MIN) / 2;
	lpaddle_pos = (Const::Y_MAX + Const::Y_MIN) / 2;
	rpaddle_pos = (Const::Y_MAX + Const::Y_MIN) / 2;
	lpaddle_move = 0;
	rpaddle_move = 0;
	this->lscore = lscore;
	this->rscore = rscore;

	direction = SingleRandom::getRandChoice(-1,1);
	ball_xvel = Const::MIN_BALL_SPEED*Const::BALL_SPEED_MULTIPLIER*direction;

	direction = SingleRandom::getRandChoice(-1,1);
	ball_yvel = Const::MIN_BALL_SPEED*Const::BALL_SPEED_MULTIPLIER*direction;

	playing = true;

	//printf("Ball Position (x,y): %f, %f\n", ball_xpos, ball_ypos);
	//printf("Ball Velocity (vx,vy): %d, %d\n", ball_xvel, ball_yvel);
	//printf("Game initiallized\n");
	//printf("\n");

	return true;
}

/*
If the game is not paused this will move the game one step in time. Updates the ball's Y position and makes
changes if there is a collision with the top or the bottom. Then updates the ball's X position checking if the
ball is in a region where it could be hit by a paddle. If it is in a hit-able region, it checks if a paddle is
in range for a collision and makes changes if it is. Finally if the ball is about to leave the screen it pauses 
the game and updates the score.
float deltaMs : size of this time step
*/
bool StatePlaying::update(float deltaMs)
{
	if (!playing)
		return false;

	float seconds = deltaMs / 1000.0;

	float deltaY = ball_yvel*seconds;

	int Xdirection;
	if (ball_xvel > 0)
		Xdirection = 1;
	else
		Xdirection = -1;

	int Ydirection;
	if (ball_yvel > 0)
		Ydirection = 1;
	else
		Ydirection = -1;

	//Collision with bottom
	if (int(ball_ypos + deltaY) > Const::Y_MAX - Const::BALL_RAD) {
		ball_ypos = Const::Y_MAX - Const::BALL_RAD;
		ball_xvel = Xdirection * SingleRandom::getRand(Const::MIN_BALL_SPEED, Const::MAX_BALL_SPEED + 1) * Const::BALL_SPEED_MULTIPLIER;
		ball_yvel = -1 * SingleRandom::getRand(Const::MIN_BALL_SPEED, Const::MAX_BALL_SPEED + 1) * Const::BALL_SPEED_MULTIPLIER;
	}
	//Collision with top
	else if (int(ball_ypos + deltaY) < Const::Y_MIN) {
		ball_ypos = Const::Y_MIN;
		ball_xvel = Xdirection * SingleRandom::getRand(Const::MIN_BALL_SPEED, Const::MAX_BALL_SPEED + 1) * Const::BALL_SPEED_MULTIPLIER;
		ball_yvel = SingleRandom::getRand(Const::MIN_BALL_SPEED, Const::MAX_BALL_SPEED + 1) * Const::BALL_SPEED_MULTIPLIER;
	}
	//No Y Collision
	else {
		ball_ypos += deltaY;
	}


	float deltaX = ball_xvel*seconds;

	//In Hit-able Right Region
	if (int(ball_xpos + deltaX) > Const::X_MAX - Const::PADDLE_WIDTH - Const::BALL_RAD && int(ball_xpos + deltaX) < Const::X_MAX - Const::PADDLE_WIDTH + Const::BALL_RAD/2) {
		//Paddle hit ball
		if (int(ball_ypos + Const::BALL_RAD) >= int(rpaddle_pos) && int(ball_ypos) <= int(rpaddle_pos) + Const::PADDLE_HEIGHT) {
			ball_xpos = Const::X_MAX - Const::PADDLE_WIDTH - Const::BALL_RAD;
			deltaX = 0;
			ball_xvel *= -1;
			if (rpaddle_move != Ydirection && rpaddle_move != 0) {
				ball_yvel *= -1;
				ball_xvel *= 3;
			}
				
		}
	}
	//In Hit-able Left Region
	if (int(ball_xpos + deltaX) < Const::X_MIN + Const::PADDLE_WIDTH && int(ball_xpos + deltaX) > Const::X_MIN + Const::PADDLE_WIDTH - Const::BALL_RAD / 2) {
		//Paddle hit ball
		if (int(ball_ypos + Const::BALL_RAD) >= int(lpaddle_pos) && int(ball_ypos) <= int(lpaddle_pos) + Const::PADDLE_HEIGHT) {
			ball_xpos = Const::X_MIN + Const::PADDLE_WIDTH;
			deltaX = 0;
			ball_xvel *= -1;
			if (lpaddle_move != Ydirection && lpaddle_move != 0) {
				ball_yvel *= -1;
				ball_xvel *= 3;
			}
		}
	}
	//In Case of No Collision
	ball_xpos += deltaX;

	//Ball out of bounds
	if (ball_xpos < 0) {
		playing = false;
		lscore -= 1;
	}
	else if (ball_xpos > 800 - Const::BALL_RAD) {
		playing = false;
		rscore -= 1;
	}

	//printf("Time passed (sec): %f\n", seconds);
	//printf("Ball Position (x,y): %f, %f\n", ball_xpos, ball_ypos);
	//printf("Ball Velocity (vx,vy): %d, %d\n", ball_xvel, ball_yvel);
	//printf("\n");

	lpaddle_move = 0;
	rpaddle_move = 0;

	return true;
}

/*
Public method to recieve all key inputs and process accordingly.
Const::KeyInput key : the key that was pressed
Const::Player p : which side pressed the key
float deltaMs : time length of key input
*/
bool StatePlaying::keyUpdate(Const::KeyInput key, Const::Player p, float deltaMs)
{
	switch (key) {
		case Const::PADDLE_UP:
		case Const::PADDLE_DOWN:
			if (!playing)
				return true;
			this->movePaddle(key, p, deltaMs);
			return true;
		case Const::PAUSE:
			playing = false;
			return true;
		case Const::START:
			playing = true;
			return true;
		default:
			return false;
	}
}

/*
Returns the state of playing attribute
*/
bool StatePlaying::isPlaying()
{
	return playing;
}

/*
Returns the ball's position vector
*/
std::vector<int> StatePlaying::getBallPosition()
{
	std::vector<int> ballPos = { int(ball_xpos), int(ball_ypos) };
	return ballPos;
}

/*
Returns the ball's velocity vector
*/
std::vector<int> StatePlaying::getBallVelocity()
{
	std::vector<int> ballVel = { ball_xvel, ball_yvel };
	return ballVel;
}

/*
Returns vector of paddle positions { left_paddle, right_paddle }
*/
std::vector<int> StatePlaying::getPaddlePositions()
{
	std::vector<int> paddlePos = { int(lpaddle_pos), int(rpaddle_pos) };
	return paddlePos;
}

/*
Returns vector of scores { left_score, right_score }
*/
std::vector<int> StatePlaying::getScore()
{
	std::vector<int> scores = { lscore, rscore };
	return scores;
}

/*
Moves the requested paddle in the requested direction for the given time change.
Const::KeyInput key : the direction the paddle should move
Const::Player p : which paddle to move
float deltaMs : the time the paddle should move
*/
void StatePlaying::movePaddle(Const::KeyInput key, Const::Player p, float deltaMs)
{
	float deltaY = Const::PADDLE_SPEED * deltaMs;

	if (p == Const::L_PLAYER) {
		if (key == Const::PADDLE_UP && lpaddle_pos >= Const::Y_MIN) {
			lpaddle_pos -= deltaY;
			lpaddle_move = -1;
		}
		if (key == Const::PADDLE_DOWN && lpaddle_pos + Const::PADDLE_HEIGHT <= Const::Y_MAX) {
			lpaddle_pos += deltaY;
			lpaddle_move = 1;
		}	
	}
	else {
		if (key == Const::PADDLE_UP && rpaddle_pos >= Const::Y_MIN) {
			rpaddle_pos -= deltaY;
			rpaddle_move = -1;
		}
		if (key == Const::PADDLE_DOWN && rpaddle_pos + Const::PADDLE_HEIGHT <= Const::Y_MAX) {
			rpaddle_pos += deltaY;
			rpaddle_move = 1;
		}
	}
}