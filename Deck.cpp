/* 
 * File:   Deck.cpp
 * Author: Nick Podsiadlo
 * 
 * Created on November 29, 2018, 10:44 PM
 */

#include "Deck.h"
#include <cstdlib>
#include <vector>
using namespace std;

//function that creates a deck of standard playing cards
Deck:: Deck()
{
    char currentSuit = 'H';
    Card newCard(1, 'D');
    
    //deck of cards has 4 cards of each rank in each suit. (4 Aces in hearts, spaces, clubs, diamonds,...etc)
    //All ranks in hearts
    for(int i = 1;i <= 13; i++ )
    {
        newCard.setCard(i, currentSuit);
        p.push_back(newCard);
    }
    
    //All ranks in clubs
    currentSuit = 'C';
    
    for(int i = 1;i <= 13; i++ )
    {
        newCard.setCard(i, currentSuit);
        p.push_back(newCard);
    }
    
    //All ranks in spades
    currentSuit = 'S';
    
    for(int i = 1;i <= 13; i++ )
    {
        newCard.setCard(i, currentSuit);
        p.push_back(newCard);
    }
    
    //All ranks in diamonds
    currentSuit = 'D';
    
    for(int i = 1;i <= 13; i++ )
    {
        newCard.setCard(i, currentSuit);
        p.push_back(newCard);
    }
    
}

//reset function that calls the default constructor to rebuild deck incase player wants to play again
Deck Deck:: reset()
{
    Deck tempDeck;       //make a copy of the pile to be returned
    return tempDeck;
}