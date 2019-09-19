#include <CompView.h>

#include <cstdlib>
#include <cstdio>

#define Const GameConstants

/*
Updates internal representation of game state and chooses which game strategy it should use.
float deltaMs : time since last update
*/
bool CompView::update(float deltaMs)
{
	ball_pos = game->getBallPosition();
	ball_vel = game->getBallVelocity();
	paddle_pos = game->getPaddlePositions();

	paddle_center = paddle_pos[1] + (Const::PADDLE_HEIGHT / 2);

	switch(strategy){
		case Const::Strategy::shortSighted:
			runShortSighted(deltaMs);
			break;
		case Const::Strategy::mirror:
			break;
		default:
			break;
	}
}

/*
Sets the game strategy the computer will use.
Strategy s : the game strategy the computer should use
*/
bool CompView::setStrategy(Const::Strategy s)
{
	strategy = s;
}

/*
The ShortSighted strategy will not move the paddle when the ball is moving away from the computer's side or if it
is too far away. Once the ball is in range, the computer attempts to move the center of the paddle to the location
of the ball.
float deltaMs : time change for the input
*/
bool CompView::runShortSighted(float deltaMs)
{
	//Don't follow if going away
	if (ball_vel[0] < 0)
		return false;

	//Don't follow if too far away
	if (abs((Const::X_MAX - Const::PADDLE_WIDTH) - ball_pos[0]) > (Const::X_MAX - Const::X_MIN) / 8)
		return false;

	if (ball_pos[1] < paddle_center)
		game->keyUpdate(Const::PADDLE_UP, side, deltaMs);
	else
		game->keyUpdate(Const::PADDLE_DOWN, side, deltaMs);

	return true;
}