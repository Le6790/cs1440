#include <iostream>
#include <ctime>
#include <vector>
#include "UserInterface.hpp"


#include "Card.hpp"


int main()
{

    // Initialize the random number generator
    unsigned int seed = (unsigned int) time(NULL);
    srand(seed);
    // Create a UI object and run it
    UserInterface ui;
    ui.run();

	
	return 0;
}
