/* 
 * File:   Card.cpp
 * Author: Nick Podsiadlo
 *
 * Created on November 28, 2018, 4:02 PM
 */

#include <cstdlib>
#include "card.h"
#include <sstream>
#include <stdexcept>
using namespace std;

//parameterized constructor
Card::Card(int r, char s)
{
    if(r <= 13 && r > 0)
        this->r = r;
    else
        throw std::invalid_argument("Rank must be valid (1-13)");

    if(s == 'd' || s == 'D')        //diamonds
        this->s = 'D';
    else if(s == 'h' || s == 'H')   //hearts
        this->s = 'H';
    else if(s == 's' || s == 'S')   //spades
        this->s = 'S';
    else if(s == 'c' || s == 'C')   //clubs
        this->s = 'C';
    else
        throw std::invalid_argument("Suit must be valid (H, S, C, D");
}

//copy constructor
Card::Card(const Card& old)
{
    r = old.r;
    s = old.s;
}

//function that sets the cards values
void Card::setCard(int r, char s)
{
    if(r <= 13 && r > 0)
        this->r = r;
    else
        throw std::invalid_argument("Rank must be valid (1-13)");

    if(s == 'd' || s == 'D')        //diamonds
        this->s = 'D';
    else if(s == 'h' || s == 'H')   //hearts
        this->s = 'H';
    else if(s == 's' || s == 'S')   //spades
        this->s = 'S';
    else if(s == 'c' || s == 'C')   //clubs
        this->s = 'C';
    else
        throw std::invalid_argument("Suit must be valid (H, S, C, D");
}

//function that returns a cards rank
int Card::getRank()
{
    return r;
}

//overloaded operator function that returns true of 2 cards are equal
 bool Card:: operator == (const Card c) const
 {
     if(r == c.r)
         return true;
     else
         return false;
 }
 
 //overloaded operator function that returns true if card1 > card2
 bool Card:: operator >(const Card c) const
 {
     if(r > c.r)
         return true;
     else
         return false;
 }
 
 //outputs the card
 ostream& operator << (ostream& out, const Card c)
 {
     if(c.r == 1)
         out << "A" << c.s;
     else if(c.r > 1 && c.r <= 10)
         out << c.r << c.s;
     else if(c.r == 11)
         out << "J" << c.s;
     else if(c.r == 12)
         out << "Q" << c.s;
     else      //must be king
         out << "K" << c.s;
     
     return out;
 }