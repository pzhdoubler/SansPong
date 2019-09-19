#include <SingleRandom.h>

int SingleRandom::seed = 0;

/*
Sets the static seed for the class. If the seed is already set nothing happens.
int new_seed : seed to be assigned
*/
bool SingleRandom::setSeed(int new_seed)
{
	if (seed) {
		//Seed already assigned
		return false;
	}
	else {
		seed = new_seed;
		return true;
	}
}


/*
Returns random int in range [lower, upper).
int lower : lower bound on random selection
int upper : upper bound on random selection
*/
int SingleRandom::getRand(int lower, int upper)
{
	srand(seed);
	int result = rand() % (upper - lower) + lower;
	seed = rand() % 100 + 1;
	return result;
}


/*
Randomly chooses one of the two parameters and returns it.
int choice1, choice2 : the two integers to randomly choose from
*/
int SingleRandom::getRandChoice(int choice1, int choice2)
{
	srand(seed);
	int choice = rand() % 2;
	seed = rand() % 100 + 1;
	if (choice == 0)
		return choice1;
	else
		return choice2;
}