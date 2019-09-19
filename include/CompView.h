#ifndef _COMPVIEW_H_
#define _COMPVIEW_H_

#include <GameView.h>
#include <GameConstants.h>
#include <vector>

/*
CompView implements GameView. This view allows the computer to control one paddle. It queries
StatePlaying logic to make decisions about what input move it should make.
*/
class CompView : public GameView
{
	public:	
		CompView() : GameView() {};

		bool update(float deltaMs);

		bool setStrategy(GameConstants::Strategy s);

	private:
		GameConstants::Strategy strategy;

		bool runShortSighted(float deltaMs);

		bool runMirror(float deltaMs);

		std::vector<int> ball_pos;

		std::vector<int> ball_vel;

		std::vector<int> paddle_pos;

		int paddle_center;
};


#endif // _COMPVIEW_H_

