/* 
 * File:   Pile.h
 * Author: Nick Podsiadlo
 *
 * Created on November 28, 2018, 4:33 PM
 */

#ifndef PILE_H
#define PILE_H
#include <vector>
#include "card.h"

class Pile 
{
protected:
    vector<Card> p;
    
public:
    
    Pile();
    
    Card dealCard();
    int getCount() const;
    void shuffle();
    void clear();
    Pile operator + (const Card& c) const;
    Pile operator + (Pile& b);
    friend ostream& operator << (ostream& out, const Pile& b);

};
#endif /* PILE_H */