/* 
 * File:   Pile.cpp
 * Author: Nick Podsiadlo
 * 
 * Created on November 28, 2018, 4:33 PM
 */

using namespace std;
#include "Pile.h"
#include <iomanip>
#include <algorithm>  //shuffle
#include <sstream>
#include <stdexcept>
#include <cstdlib>

Pile::Pile()
{
    //p is already defined as an empty vecotr so do nothing
}

//draws card from the top of the pile and removes it from the vector
Card Pile:: dealCard()
{
    if(p.size() > 0)
    {
        Card tempCard = p.front();
        p.erase(p.begin());
    
        return tempCard;
    }
    else
        throw std::length_error("Pile is empty");
   
        
}

// function that returns the amount of cards in a pile
int Pile:: getCount() const
{
    return p.size();
}

//function that shuffles the piles randomly
void Pile:: shuffle()
{
    random_shuffle(p.begin(), p.end());
}

//function that removes all elements from the pile
void Pile:: clear()
{
    p.clear();
}

//overloaded operator function that adds a card to the end of a pile
Pile Pile:: operator + (const Card& c) const
{
    Pile tempPile;       //make a copy of the pile to be returned
    tempPile.p = p;
    tempPile.p.push_back(c);  //push the new card onto the end of the pile
    return tempPile;        //return the new pile
}

//overloaded operator function that adds pile2 to the bottom of pile1
Pile Pile:: operator + (Pile& b)
{
    Pile tempPile;
    tempPile.p = p;
    
    while(b.p.size() > 0)
    {
        tempPile.p.push_back(b.p.front());
        b.p.erase(b.p.begin());
    }
    return tempPile;
}

//function that outputs the pile
ostream& operator << (ostream& out, const Pile& b)
{
    int count = 0;
    int index = 0;
    int const max = b.getCount();
    
    for(int i = 0; i < max; i++)
    {
        out << b.p[index];
        
        if(i != (max - 1) && count != 9) //so that it only sets width 2 if it is not the last Card.
           out << setw(2); 
        
        count++;
        index++;
        
        if(count == 10)
        {
            out << endl;
            count = 0;
        }
    }
    
    return out;
}