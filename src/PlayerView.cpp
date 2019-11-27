#include <PlayerView.h>

#include <cstdio>
#include <string>

#define Const GameConstants

/*
Updates view's internal representation of the game state then updates all asthetics associated with
the paddles and ball. Also calls sendKeyInputs and updateMenu.
float deltaMs : time passed since last call of update
*/
bool PlayerView::update(float deltaMs)
{
	this->sendKeyInputs(deltaMs);

	ball_pos = game->getBallPosition();
	ball_vel = game->getBallVelocity();
	paddle_pos = game->getPaddlePositions();

	sf::Sprite ball(*ballTexture);
	ball.setPosition(ball_pos[0], ball_pos[1]);

	sf::Sprite lpaddle(*paddleTexture);
	lpaddle.setPosition(Const::X_MIN, paddle_pos[0]);

	sf::Sprite rpaddle(*paddleTexture);
	rpaddle.setPosition(Const::X_MAX - Const::PADDLE_WIDTH, paddle_pos[1]);

	screen->draw(lpaddle);
	screen->draw(rpaddle);
	screen->draw(ball);

	updateMenu();

	return true;
}

/*
Creates static references to loaded resource then passes them to internal resource pointers.
*/
bool PlayerView::loadResources()
{
	static sf::Font comicsans;
	comicsans.loadFromFile("..\\resources\\comicsans.ttf");
	font = &comicsans;

	static sf::Music mega;
	mega.openFromFile("..\\resources\\Undertale-Megalovania.ogg");
	mega.setLoop(true);
	music = &mega;

	static sf::Texture heart;
	heart.loadFromFile("..\\resources\\undertaleheart.png");
	ballTexture = &heart;

	static sf::Texture bone;
	bone.loadFromFile("..\\resources\\bonepaddle.png");
	paddleTexture = &bone;

	static sf::Texture sans;
	sans.loadFromFile("..\\resources\\sanssprite.png");
	AIBasicTexture = &sans;

	static sf::Texture sans_shrug;
	sans_shrug.loadFromFile("..\\resources\\sansshrugsprite.png");
	AIWonTexture = &sans_shrug;

	static sf::Texture sans_nervous;
	sans_nervous.loadFromFile("..\\resources\\sansnervoussprite.png");
	AILoseTexture = &sans_nervous;
}

/*
Updates the screen menu and other asthetic elements of game like music and sprites.
*/
bool PlayerView::updateMenu()
{
	if (!(music->getStatus() == sf::SoundSource::Playing) && game->isPlaying())
		music->play();

	std::vector<int> scores = game->getScore();
	lscore = scores[0];
	rscore = scores[1];

	sf::Text left_text("HP:", *font, 20);
	left_text.setPosition(15, 0);

	sf::Text left_score(std::to_string(lscore), *font, 30);
	left_score.setPosition(15, 20);
	left_score.setColor(sf::Color::Yellow);

	sf::Text right_text("Sans:", *font, 20);
	right_text.setPosition(730, 0);

	sf::Text right_score(std::to_string(rscore), *font, 30);
	right_score.setPosition(730, 20);
	right_score.setColor(sf::Color::Cyan);

	sf::Sprite Sans(*AIBasicTexture);
	Sans.setPosition(590, 0);

	std::string menu_text = "You feel like you're going to \nhave a bad time.";

	sf::Text message(menu_text, *font, 30);
	message.setStyle(sf::Text::Bold);
	message.setPosition(150, 0);

	//Logic for when game is paused.
	if (!game->isPlaying()) {
		if (ball_pos[0] <= Const::X_MIN + Const::PADDLE_WIDTH) {
			if (lscore == 0) {
				menu_text = "Game Over\nPress ENTER to restart\nPress ESCAPE to quit";
				music->stop();
			}
			else 
				menu_text = "what?\nyou think I'm just gonna\nstand there and take it?\nPress ENTER to continue";
			message.setString(menu_text);
			sf::Sprite SansWon(*AIWonTexture);
			Sans = SansWon;
			Sans.setPosition(560, 0);
		}
		else if (ball_pos[0] >= Const::X_MAX - Const::PADDLE_WIDTH - Const::BALL_RAD) {
			if (rscore == 0) {
				menu_text = "You beat Sans!\nPress ENTER to restart\nPress ESCAPE to quit";
				music->stop();
			}
			else
				menu_text = "You are filled\nwith determination.\nPress ENTER to continue";
			message.setString(menu_text);
			sf::Sprite SansLose(*AILoseTexture);
			Sans = SansLose;
			Sans.setPosition(560, 0);
		}
		else {
			menu_text = "PAUSED\nPress ENTER to resume\nPress ESCAPE to quit";
			message.setString(menu_text);
			music->pause();
		}
	}

	screen->draw(message);
	screen->draw(left_text);
	screen->draw(left_score);
	screen->draw(right_text);
	screen->draw(right_score);
	screen->draw(Sans);
}

/*
Checks for user input then sends proper information to StatePlaying.
float deltaMs : time length of key input
*/
bool PlayerView::sendKeyInputs(float deltaMs)
{
	if (game->isPlaying()) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			game->keyUpdate(Const::PADDLE_UP, side, deltaMs);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			game->keyUpdate(Const::PADDLE_DOWN, side, deltaMs);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
			game->keyUpdate(Const::PAUSE, side, deltaMs);
	}
	else {
		if (ball_pos[0] <= Const::X_MIN + Const::PADDLE_WIDTH || ball_pos[0] >= Const::X_MAX - Const::PADDLE_WIDTH - Const::BALL_RAD) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
				if (lscore == 0 || rscore == 0)
					game->init(11, 11);
				else
					game->init(lscore, rscore);
			}
		}
		else {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
				game->keyUpdate(Const::START, side, deltaMs);
		}
	}
}