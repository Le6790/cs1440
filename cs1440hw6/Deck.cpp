//
// Created by Stephen Clyde on 2/16/17.
//

#include "Deck.hpp"
#include <math.h>
Deck::Deck(int cardSize, int cardCount, int numberMax)
{
	this->numberMax = numberMax;
	this->cardCount = cardCount;
	this->cardSize = cardSize;

	getIntsTest();

    // TODO: Implement
	//Check to see if values passed in are legit/fit criteria
	if (cardSize < 3 || cardSize > 15) {
		isValidValue = false;
		return;
	}
	int maxNumberLow = 2 * (pow(cardSize,2));
	int maxNumberHigh = 4* (pow(cardSize,2));
	std::cout << "MaxLow: " << maxNumberLow << " MaxHigh" << maxNumberHigh << std::endl;
	if (numberMax < maxNumberLow || numberMax > maxNumberHigh) {
		isValidValue = false;
		return;
	}
	if (cardCount < 3 || cardCount >10000) {
		isValidValue = false;
		return;
	}
	//set of cards size cardCount
	theDeck = new Card *[cardCount];
	createCards();


}

Deck::~Deck()
{
    // TODO: Implement
	for (int i = 0; i < cardSize; i++) {
		delete theDeck[i];
	}
	
	delete[] theDeck;
}

void Deck::createCards() {
	for (int i = 0; i < cardCount; i++) {
		theDeck[numOfCards++] = new Card(cardSize, numberMax);
	}
}



void Deck::print(std::ostream& out) const
{
    //Prints out the entire bingo card
	for (int i = 1; i <= cardCount; i++) {
		print(out, i);
	}
}

void Deck::print(std::ostream& out, int cardIndex) const
{   //Prints out a bingo card
	out << "Card: #" << cardIndex << "\n";
	for (int i = 0; i < cardSize; i++)
	{
		out << "+------+";
	}
	out << "\n";
	//Call the print from cards to print out all the cards in the deck
	theDeck[cardIndex -1 ]->print(out);

	for (int i = 0; i < cardSize; i++)
	{
		out << "+------+";
	}
	out << "\n";
}



