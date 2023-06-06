/* 
 * File:   main.cpp
 * Author: Nick Podsiadlo
 *
 * Created on December 1, 2018, 7:59 PM
 */

#include <cstdlib>
#include "card.h"
#include "Pile.h"
#include "Deck.h"
#include <ctime>
#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;


int main()
{
    cout << "Hello, Welcome to the War Game!" << endl << endl;
    cout << "A deck of cards will be evenly distributed between you and the computer AI." << endl;
    cout << "The game will ask you how many cards you want to play face down before turning a card face up." << endl << endl;
    
    cout << "You cannot request more cards than the current player holding the least amount of cards minus 1 (because a card needs to be turned)." << endl;
    
    cout << "(EXAMPLE: If the player has 22 cards and the computer has 30 cards the most cards you can play face down is 21.)" << endl << endl;
    cout << "Comparing the cards placed faced up (Ace is considered low), the highest card rank wins the round and the winning player gets all of the cards added to the bottom of their pile of cards." << endl;
    cout << "If a tie occurs, the players keep placing cards face up until a winner is determined." << endl << endl;
    
    cout << "The game is played until a player runs out of cards and loses." << endl;
    cout << "ENJOY :)" << endl << endl;
    
    //define variables that will be needed
    char playAgain = 'Y';
    char playerName[50];
    Pile playerPile;
    Pile computerPile;
    Pile turnPile;
    Deck gameDeck;
    Card playersCard(1, 's'); //create some card, the card rank and value will be replaced later on
    Card computersCard(1, 's');
    int numCards;
    
    cout << "Player 1, please input your name: ";
    cin >> playerName;
    
    do
    {
        //distribute the gameDeck evenly between the players
        //we only want to do this if there are 52 cards in the gameDeck (full deck)
        if(gameDeck.getCount() == 52)
        {
            gameDeck.shuffle(); //shuffle the deck
            
            while(gameDeck.getCount() > 0)
            {
                playerPile = playerPile + gameDeck.dealCard();
                computerPile = computerPile + gameDeck.dealCard();
            }
        }
        
        while(playerPile.getCount() > 0 && computerPile.getCount() > 0)
        {
            cout << "How many cards should be placed face down?";
            cin >> numCards;
            cout << endl;

            while(numCards > (playerPile.getCount() - 1) || numCards > (computerPile.getCount() - 1)) //check that numCards is a valid number of cards
            {
                cout << "You cannot play, " << numCards << " cards face down because there are not enough cards in the piles." << endl << endl;
                cout << "Computer has " << computerPile.getCount() << " cards." << endl;
                cout << playerName << " has " << playerPile.getCount() << " cards." << endl << endl;
                cout << "Make sure you don't request more cards than the current player with the lowest pile minus 1." << endl;
                cout << "How many cards should be placed face down?";
                cin >> numCards;
                cout << endl;
            }

            //--------------------------COMPUTER TURN--------------------------------------------------------------------------
            //add computers cards to the turnPile
            cout << "Computer: ";
            for(int i = 0; i < numCards; i++)
            {
                turnPile = turnPile + computerPile.dealCard();    //so that we can remove the cards and add them to the pile
                cout << "**" << "  ";
            }

            computersCard = computerPile.dealCard();            //the card that will be turned over.
            cout << computersCard << endl; //display the computers turn

            //--------------------------PLAYER TURN---------------------------------------------------------------------------
            //repeat the process for the player
            cout << "Player:   ";
            for(int i = 0; i < numCards; i++)
            {
                turnPile = turnPile + playerPile.dealCard();    //so that we can remove the cards and add them to the pile
                cout << "**" << "  ";
            }

            playersCard = playerPile.dealCard();            //the card that will be turned over.
            cout << playersCard << endl << endl; //display the players turn

            //---------------------TIE-------------------------------------------------------------------------------------
            if(playersCard == computersCard) //nobody won, it must have been a tie
            {
                while(playersCard == computersCard && playerPile.getCount() > 0 && computerPile.getCount() > 0)
                {
                    cout << "---It's a Tie!---" << endl;

                    //add the old cards into the turnPile
                    turnPile = turnPile + computersCard;
                    turnPile = turnPile + playersCard;

                    //deal new cards
                    computersCard = computerPile.dealCard();
                    playersCard = playerPile.dealCard();

                    //display new cards
                    cout << "Current cards in the pot: " << turnPile.getCount() << endl;
                    cout << "Computer: " << computersCard << endl;
                    cout << playerName << ": " << playersCard << endl;
                }
            }
            //-------------------PLAYER WINS--------------------------------------------------------------------------------
            if(playersCard > computersCard) //player won
            {
                cout << "---" << playerName << " Wins!---" << endl;

                //put the face up cards into turnPile
                turnPile = turnPile + computersCard;
                turnPile = turnPile + playersCard;
                //then add turnPile to the bottom of players deck
                playerPile = playerPile + turnPile;
                
                turnPile.clear(); //reset the turnPile for the next turn
       
                //display current cards
                cout << "Computer has " << computerPile.getCount() << " cards." << endl;
                cout << playerName << " has " << playerPile.getCount() << " cards." << endl << endl;

            }
            //-----------------------COMPUTER WINS-------------------------------------------------------------------------
            else //computer must have won, same code as above but adding turnPile to computerPile
            {
                cout << "---Computer Wins!---" << endl;

                //put the face up cards into turnPile
                turnPile = turnPile + computersCard;
                turnPile = turnPile + playersCard;
                //then add turnPile to the bottom of players deck
                computerPile = computerPile + turnPile;
                
                turnPile.clear(); //reset the turnPile for the next turn
       
                //display current cards
                cout << "Computer has " << computerPile.getCount() << " cards." << endl;
                cout << playerName << " has " << playerPile.getCount() << " cards." << endl << endl;
            }
            

            if(playerPile.getCount() == 0) //player lost
            {
                cout << "Sorry " << playerName << " you have lost :/" << endl;
                cout << "Would you like to play again?: ";
                cin >> playAgain;
                cout << endl;
                //reset all piles for the next possible game
                playerPile.clear();
                computerPile.clear();
                //reset gameDeck for the next possible game
                gameDeck = gameDeck.reset();
            }
            else if(computerPile.getCount() == 0 && (playAgain == 'Y' || playAgain == 'y')) //player won
            {
                cout << "Congratulations " << playerName << " you have won!!! :)" << endl;
                cout << "Would you like to play again?: ";
                cin >> playAgain;
                cout << endl;
                //reset all piles for the next possible game
                playerPile.clear();
                computerPile.clear();
                //reset gameDeck for the next possible game
                gameDeck = gameDeck.reset();
            }
        }
    }while(playAgain == 'y' || playAgain == 'Y');
    
    return 0;
}