#include "Card.hpp"
#include <algorithm>
#include <iomanip>

Card::Card(int size, int max){
	this->size = size;
	this->max = max;
	//Create an array of cards of size size
	theCards = new int*[size];
	for (int i = 0; i < size; i++) {// for each of those cards, create another set of cards size size
		theCards[i] = new int[size];
	}
	makeCard();
}

Card::~Card(){
	for (int i=0; i < size; i++){
		// delete[] and delete work but delete[] fixes the errors on valgrind
		 delete [] theCards[i];
	}
	delete [] theCards;
}

void Card::makeCard() {
	int count = 0;
	std::vector<int> randNums;
	randNums = randomNumGen(); // fill randNums with random numbers
	//Initially set all values to 0
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			theCards[i][j] = 0;
		}
	}
	//Add the random numbers in
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			theCards[i][j] = randNums[count];
			count++;
		}
	}
}

std::vector<int> Card::randomNumGen() {
	std::vector<int> randNums;
	//Numbers are in order
	for (int i = 0; i <= max; i++) {
		randNums.push_back(i);
	}
	// Put numbers in a random order
	for ( int i = randNums.size() - 1; i > 0; i--) {
		int r = rand() % (i + 1);
		//std::swap(randNums[i], randNums[r]);
		int temp = randNums[i];
		randNums[i] = randNums[r];
		randNums[r] = temp;
	}

	return randNums;
}
std::vector<int> Card::randNumGenTest() {
	std::vector<int> randNums;
	//Numbers are in order
	int maxTest = 5;
	for (int i = 0; i <= maxTest; i++) {
		randNums.push_back(i);
	}

	for (int i = randNums.size()-1; i > 0; i--) {
		int r = rand() % (i + 1);
		//std::swap(randNums[i], randNums[r]);
		int temp = randNums[i];
		randNums[i] = randNums[r];
		randNums[r] = temp;
	}

	for (unsigned int i = 0; i < randNums.size(); i++) {
		std::cout << randNums[i] << ",";
	}
	
	return randNums;
	
}
//print the cards
void Card::print(std::ostream& out) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			out << "| "<< std::setw(3) <<  theCards[i][j] << std::setw(3) << " |";
		}
		out << "\n";
		
	}
}


