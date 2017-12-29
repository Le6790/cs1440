//
// Created by Stephen Clyde on 2/16/17.
//

#ifndef BINGO_DECK_H
#define BINGO_DECK_H

#include <ostream>
#include <iostream>
#include "Card.hpp"
// TODO: Extend this definition as you see fit

class Deck {
private:
    int numberMax; //Holds numberMax
    int cardSize; //Holds cardSize
    int cardCount; //Holds cardCount
	bool isValidValue = true; // Checks to see if the passed in values are true
	int numOfCards =0; //Keep track of how many cards there are
    Card** theDeck; //Holds the deck
public:
    Deck(int cardSize, int cardCount, int numberMax);
    ~Deck();
	void createCards();
    void print(std::ostream& out) const; //print the deck
    void print(std::ostream& out, int cardIndex) const; //print the card

	void getIntsTest() { //Test to see if I set the values correctly
		std::cout << numberMax << "," << cardSize << "," << cardCount << std::endl;
	}
};

#endif //BINGO_DECK_H
