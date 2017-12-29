#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <vector>
#include <math.h>

class Card {
private: 
int number; //Number of the card
int max; //Max number of cards
int size; //size of card
int** theCards; // 2d pointer to hold all the numbers
int location; //knows the location of a given card

public:
	Card() {  }
Card(int cardSize, int max);
~Card();
void makeCard();
void print(std::ostream& out);
std::vector<int> randomNumGen(); //just a vector of random numbers. 
std::vector<int> randNumGenTest();

  
};

#endif