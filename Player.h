// Assignment 1 - Structured and Object-Oriented Programming
// Victoria Rodríguez de León A01656328
// Alejandro Pozos Aguirre A01656017

#include <iostream>
#include <time.h>

#ifndef PLAYER_H
#define PLAYER_H

class Player{
private:
    std::string playerName; 
    int position;

public:
    // Default constructor 
    Player(){
        std::string playerName = "Joe Doe";
        this->position = 0;
    }
    // Constructor with arguments
    Player(std::string playerName){
        this->playerName = playerName;
        this->position = 0;
    }
    // getters and setters
    int getPlayerPosition(){
        return position;
    }
    // Method to set the player's position
    void setPlayerPosition(int position){
        this->position = position;
    }
    // Simulation of dice with random numbers
    int rollDice(){
        // generate random number from 1 to 6 (rand() generates from 0 to 5, when summed 1 the result is equal to 1 to 6)
        int yourLuckIs = 1 + rand()%6;  
        std::cout<<"[?] "<<playerName<<" rolled a "<<yourLuckIs<<std::endl;
        return yourLuckIs;
    }
    // Method to get the player's name
    std::string getPlayerName(){
        return playerName;
    }
};

#endif