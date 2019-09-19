#ifndef _SINGLERANDOM_H_
#define _SINGLERANDOM_H_

#include <random>

/*
Static class to localize all calls for a random value.
*/
class SingleRandom
{
	public:
		SingleRandom() {};

		static bool setSeed(int seed);

		static int getRand(int lower, int upper);

		static int getRandChoice(int choice1, int choice2);

	private:
		static int seed;

};


#endif // !_SINGLERANDOM_H_

