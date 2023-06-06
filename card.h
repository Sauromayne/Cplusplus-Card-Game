/* 
 * File:   card.h
 * Author: Nick Podsiadlo
 *
 * Created on November 28, 2018, 3:50 PM
 */

#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>
using namespace std;

class Card
{
private:
    int r;      
    char s;
    
public:
    
    Card(int r, char s); //parameterized constructor
    Card(const Card& old);     //copy constructor
    
    void setCard(int r, char s);
    int getRank();
    bool operator ==(const Card c) const;
    bool operator >(const Card c) const;
    friend ostream& operator << (ostream& out, const Card c);
    
};
#endif /* CARD_H */