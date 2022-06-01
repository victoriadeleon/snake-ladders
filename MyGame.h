// Assignment 1 - Structured and Object-Oriented Programming
// Victoria Rodríguez de León A01656328
// Alejandro Pozos Aguirre A01656017

#include <iostream>
#include <random>
#include <ctime>
#include "Player.h"

#ifndef MYGAME_H
#define MYGAME_H

class MyGame{
    private:
    // Create board that will be filled in startNewGame() method.
    char board[30]; 
    int turn; 

    public:
    void startNewGame(){
        std::cout<<"Game Started. "<<std::endl;
        int cont1 = 0, cont2 = 0;
        // give a seed to the random number generator
        srand(time(0));

        for (int i=0; i<=30; i++){
            // generate a number between 0 and 2
            int random = rand()%3;

            // assign the random value of: 0 for 'L', 1 for 'S' and 2 to 'N'
            if (random==0 && cont1!=3 && i>=6){
            board[i] = 'L';
            cont1++;

            } else if (random==1 && cont2!=3 && (i>=12 && i<=27)){
            board[i] = 'S';
            cont2++;

            } else{
            board[i] = 'N';  
            }  
        }
        
       board[30] = '\0';
       turn = 0;
    };

    // Method that returns the Turn number
    int getTurn(){
        this->turn = turn;
        return turn;
    }
    
    // Method to print the board.
    void printBoard(){
        for(int i = 0; i<=30; i++){
            std::cout<<board[i]<<"  ";
        }
        std::cout<<std::endl;
        
        // defined ranges for formatting purposes.
        for (int i=1;i<=9;i++){
            std::cout<<i<<"  ";
        }
        for (int i=10;i<=30;i++){
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;
    };
    
    // Method to set the Turn number
    void setTurn(int n){
        turn = turn + n;
        this->turn = turn;
    };

    // Method to get the box in which the player is located. 
    char getBox(int n){
        char temp = board[n-1]; 
        return temp;
    };


    // Method to change the player position if the user lands on a snake box.
    int snake(Player P){
        int playerPosition = P.getPlayerPosition();
        // If the player is located between the first and third  box, return them to the beginning of the board
        if (playerPosition == 1 || playerPosition <= 3){
            int pp = 1;
            return pp;

        // Else, take the player back 3 squares (penalty)
        } else{
            int pp = playerPosition - 3; 
            return pp;
        }
    };

    // Method to change the player position if the user lands on a ladder box
    int ladder(Player P){
        int pp = P.getPlayerPosition();
        pp = pp + 3;
        P.setPlayerPosition(pp);
        return pp;
    };
    
};
#endif