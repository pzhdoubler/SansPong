#ifndef _PLAYERVIEW_H_
#define _PLAYERVIEW_H_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <GameView.h>
#include <vector>

/*
PlayerView implements GameView. This view draws a visual representation of the game and accepts user input to
control one paddle. It queries the StatePlaying logic to update the screen.
*/
class PlayerView : public GameView
{
	public:
		PlayerView() : GameView() {};

		bool update(float deltaMs);

		bool loadResources();

		sf::Font* font;

		sf::Music* music;

		sf::Texture* ballTexture;

		sf::Texture* paddleTexture;

		sf::Texture* AIBasicTexture;

		sf::Texture* AIWonTexture;

		sf::Texture* AILoseTexture;

	private:
		bool updateMenu();

		bool sendKeyInputs(float deltaMs);

		std::vector<int> ball_pos;

		std::vector<int> ball_vel;

		std::vector<int> paddle_pos;

		int lscore, rscore;

};

#endif // !_PLAYERVIEW_H_

