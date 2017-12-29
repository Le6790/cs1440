//
// Created by Stephen Clyde on 2/16/17.
//

#include "UserInterface.hpp"

#include <iostream>
#include <iomanip>
#include <fstream>

#include "Deck.hpp"
#include "Menu.hpp"

void UserInterface::run()
{
    std::cout << "Welcome to the Bingo Deck Generate" << std::endl << std::endl;

    Menu menu("Main");
    menu.addOption("C", "Create a new deck");
    menu.addOption("D", "Delete the current deck");

    bool keepGoing = true;
    while (keepGoing)
    {
        std::string command = menu.show();
        if (command=="C")
        {
            createDeck();
        }
        else if (command=="D")
        {
            if (currentDeck)
                delete currentDeck;
            currentDeck = nullptr;
        }
        else if (command=="X")
        {
            //When exiting, Delete the current deck if there is any
             //if (currentDeck)
             //   delete currentDeck;
            //currentDeck = nullptr;
            keepGoing = false;
        }
    }
    if (currentDeck)
                delete currentDeck;
            currentDeck = nullptr;
}

void UserInterface::createDeck()
{
    // Get the user to specify the card size, max number, and number of cards
    int cardSize = getNumberInput("Enter card size", 3, 15);
    if (cardSize < 0)
        return;

    int numberRangeMin = 2*cardSize*cardSize;
    int numberRangeMax = 2*numberRangeMin;
    int maxNumber = getNumberInput("Enter max number", numberRangeMin, numberRangeMax);
    if (maxNumber < 0)
        return;

    int cardCount = getNumberInput("Enter number of cards", 3, 10000);
    if (cardCount < 0)
        return;

    if (currentDeck!=nullptr)
        delete currentDeck;

    // Create a new deck;
    currentDeck = new Deck(cardSize, cardCount, maxNumber);

    // Display a deck menu and allow use to do things with the deck
    deckMenu();
}
// this does not add or destroy anything in the deck. Just prints/displays/saves it. Does not affect code I write now
void UserInterface::deckMenu()
{
    Menu menu("Deck");
    menu.addOption("P", "Print a card to the screen");
    menu.addOption("D", "Display the whole deck to the screen");
    menu.addOption("S", "Save the whole deck to a file");

    bool keepGoing = true;
    while (keepGoing)
    {
        std::string command = menu.show();
        if (command=="P")
        {
            printCard();
        }
        else if (command=="D")
        {
            std::cout << std::endl;
            currentDeck->print(std::cout);
        }
        else if (command=="S")
        {
            saveDeck();
        }
        else if (command=="X")
        {
             
            keepGoing = false;
        }
    }
    
    
}

void UserInterface::printCard()
{
    int cardToPrint = getNumberInput("Id of card to print", 1, 9999);
    if (cardToPrint>0)
    {
        std::cout << std::endl;
        currentDeck->print(std::cout, cardToPrint);
    }
}

void UserInterface::saveDeck()
{
    std::string fileName = getStringInput("Enter output file name");
    if (fileName!="")
    {
        std::ofstream outputStream(fileName);
        currentDeck->print(outputStream);
        std::cout << "Done!" << std::endl;
        outputStream.close();
    }
}

std::string UserInterface::getStringInput(std::string prompt)
{
    std::string userInput;

    std::cout << std::endl;
    std::cout << prompt
              << "(<enter> to go back): " << std::endl;
    std::getline(std::cin, userInput);

    return userInput;
}

int UserInterface::getNumberInput(std::string prompt, int rangeMin, int rangeMax)
{
    int result = -1;
    bool gotValidInput;
    std::string userInput;

    do {
        std::cout << std::endl;
        std::cout << prompt << " ("
                  << rangeMin << " - "
                  << rangeMax << " or <enter> to go back): " << std::endl;
        std::getline(std::cin, userInput, '\n');
        if (userInput == "")
        {
            gotValidInput = true;
        } else
        {
            result = std::stoi(userInput);
            gotValidInput = (rangeMin <= result && result <= rangeMax);
        }
    } while (!gotValidInput);
    return result;
}
