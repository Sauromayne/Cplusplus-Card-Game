/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Card Driver.cpp
 * Author: Nick
 *
 * Created on November 28, 2018, 5:55 PM
 */

#include <cstdlib>
#include "card.h"
#include "Pile.h"
#include "Deck.h"
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL)); 
    
    Card a(4, 'h');
    Card b(1, 'd');
    Card c(9, 's');
    Card d(12, 'C');
    Card e(13, 's');
    Card f(a);
    Card g(4, 'c');
    
    cout << "-------TESTING CARD------" << endl;
    cout << c << endl;
    c.setCard(5, 'd');
    cout << c << endl;
    cout << d << endl;
    cout << a.getRank() << endl;
    cout << b.getRank() << endl;
    
    cout << (a == b) << endl;
    cout << (a == g) << endl;
    cout << (b > a) << endl;
    cout << (a > b) << endl;
    
    Pile myPile;
    myPile = myPile + a;
    myPile = myPile + b;
    myPile = myPile + c;
    myPile = myPile + d;
    myPile = myPile + e;
    myPile = myPile + f;
    myPile = myPile + g;
    
    cout << "------TESTING PILE--------" << endl;
    cout << myPile.getCount() << endl;
    cout << myPile << endl;
    
    myPile.shuffle();
    cout << myPile << endl;
    
    myPile.shuffle();
    cout << myPile << endl;
    
    Pile myPile2;
    myPile2 = myPile2 + a;
    myPile2 = myPile2 + b;
    myPile2 = myPile2 + d;
    
    cout << myPile2 << endl;
    
    myPile = myPile + myPile2;
    
    cout << myPile << endl;
    
    a = myPile.dealCard();
    cout << "Testing dealCard(): " << a << endl;
    cout << myPile << endl;
    
    Deck myDeck;
    cout << "-----TESTING DECK-----" << endl;
    cout << myDeck << endl;
    
    
    return 0;
    
    
}

