/* 
 * File:   Deck.h
 * Author: Nick Podsiadlo
 *
 * Created on November 29, 2018, 10:44 PM
 */

#ifndef DECK_H
#define DECK_H
#include "Pile.h"
#include "card.h"
#include <vector>

class Deck : public Pile
{
    public:
        Deck();
        
        Deck reset();

};
#endif /* DECK_H */