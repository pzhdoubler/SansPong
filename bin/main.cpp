#include <SFML/Graphics.hpp>
#include <StatePlaying.h>
#include <SingleRandom.h>
#include <GameConstants.h>
#include <GameView.h>
#include <PlayerView.h>
#include <CompView.h>

#define Const GameConstants

int main(int argc, char** argv)
{
	// create main window
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Sans Pong - SFML", sf::Style::Titlebar);

	sf::RectangleShape top_bar(sf::Vector2f(800, 10));
	top_bar.setPosition(0, Const::Y_MIN-10);

	sf::RectangleShape left_bar(sf::Vector2f(Const::X_MIN, Const::Y_MAX - Const::Y_MIN));
	left_bar.setFillColor(sf::Color::Blue);
	left_bar.setPosition(0, Const::Y_MIN);

	sf::RectangleShape right_bar(sf::Vector2f(Const::X_MIN, Const::Y_MAX - Const::Y_MIN));
	right_bar.setFillColor(sf::Color::Blue);
	right_bar.setPosition(Const::X_MAX, Const::Y_MIN);

	//SET RANDOM SEED
	SingleRandom::setSeed(time(NULL));

	StatePlaying game = StatePlaying();
	game.init(11, 11);

	PlayerView player = PlayerView();
	player.init(game, Const::L_PLAYER, App);
	player.loadResources();

	CompView AI = CompView();
	AI.init(game, Const::R_PLAYER, App);
	AI.setStrategy(Const::Strategy::shortSighted);

	int views_length = 2;
	GameView* views[views_length] = { &AI, &player };

	sf::Clock clock;

	// start main loop
	while (App.isOpen())
	{

		float deltaMs = clock.getElapsedTime().asSeconds();
		clock.restart();

		// process events
		sf::Event Event;
		while (App.pollEvent(Event))
		{
			switch (Event.type) {
			case sf::Event::LostFocus:
				game.keyUpdate(Const::PAUSE, Const::R_PLAYER, 0);
				break;
			default:
				break;
			}
		}

		if (!game.isPlaying() && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			App.close();

		App.clear(sf::Color::Black);

		App.draw(top_bar);
		App.draw(left_bar);
		App.draw(right_bar);

		//Update game state
		game.update(deltaMs);

		//Update views
		for (int i = 0; i < views_length; i++)
			views[i]->update(deltaMs);

		// display
		App.display();

	}

	// Done.
	return 0;
}