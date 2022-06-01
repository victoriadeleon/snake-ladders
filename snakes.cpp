// Assignment 1 - Structured and Object-Oriented Programming
// Victoria Rodríguez de León A01656328
// Alejandro Pozos Aguirre A01656017

#include <iostream>
using namespace std; 

#include "MyGame.h"
#include "Player.h"

int main(){
    // Create an object g of type MyGame
    MyGame g;
    g.startNewGame();

    string n1, n2; // Player 1 and Player 2 names

    cout<<"Enter player 1's name: ";
    cin>>n1;

    cout<<"Enter player 2's name: ";
    cin>>n2; 

    Player player1(n1); // Create player1 object of type Player
    Player player2(n2); // Create player2 object of type Player
    int posP1=0, posP2=0;

    // Locate both players on the 1st position.
    player1.setPlayerPosition(posP1); 
    player2.setPlayerPosition(posP2);

    // Print initial status of game
    cout<<player1.getPlayerName()<<" is at position "<<player1.getPlayerPosition()<<endl;
    cout<<player2.getPlayerName()<<" is at position "<<player2.getPlayerPosition()<<endl;

    bool gamestate = true;    
    char inp; // Main interaction with user.

    while(gamestate == true){
        g.printBoard();

        // Ask for user's input
        cout<<"Press C to continue next turn, or E to end the game: ";
        cin>>inp;

        // If user chooses to continue next turn:
        if (inp == 'C' || inp == 'c')
        {
            // Print turn information
            cout <<"...\nTurn number: " << g.getTurn() << endl;
            cout<<"~~~ PLAYER "<<player1.getPlayerName()<<"'S TURN"<<endl;

            // ---- PLAYER 1----
            srand(time(0));
            int dice1 = player1.rollDice(); // Roll the dice for player 1

            posP1 = posP1 + dice1;  // Change position of Player 1
            player1.setPlayerPosition(posP1);
            
            if (posP1<=29){
                cout<<"- "<<player1.getPlayerName()<<" landed in position "<<posP1<<", that puts them in box "<<g.getBox(posP1)<<endl;
                
                // If player1 lands on a snake, execute:
                if (g.getBox(posP1)=='S'){
                    cout<<"<!> Oh-oh, player "<<player1.getPlayerName()<<" landed on a snake! Too bad, go back 3 spaces."<<endl;
                    posP1 = g.snake(player1);
                    player1.setPlayerPosition(posP1);
                    cout<<"Player 1's current position: "<<player1.getPlayerPosition()<<endl;

                // If player1 lands on a ladder, execute:
                } else if(g.getBox(posP1)=='L') {
                    cout<<"<!> Player "<<player1.getPlayerName()<<" just landed on a ladder! Congratulations! Go on 3 spaces!"<<endl;
                    posP1 = g.ladder(player1);
                    player1.setPlayerPosition(posP1);
                    cout<<"Player 1's current position: "<<player1.getPlayerPosition()<<endl;

                } else{
                // If player1 lands on a normal box, execute: 
                player1.setPlayerPosition(posP1);
                cout<<"Player 1's current position: "<<player1.getPlayerPosition()<<endl;
                }

            }else if (posP1==30) {
                cout<<"- "<<player1.getPlayerName()<<" landed in position "<<posP1<<"."<<endl;
                cout<<"Player "<<player1.getPlayerName()<<" is the winner!"<<endl;
                cout<<"Thanks for playing."<<endl;
                gamestate = false;
                break;

            // when the player's position is out of the board's range:
            }else{
                posP1 = 30-(posP1-30);
                cout<<"- "<<player1.getPlayerName()<<" landed in position "<<posP1<<", that puts them in box "<<g.getBox(posP1)<<endl;
            }

            // ---- PLAYER 2 ----
            cout<<endl;
            cout<<"~~~ PLAYER "<<player2.getPlayerName()<<"'S TURN"<<endl; 

            // Roll the dice for Player 2    
            int dice2 = player2.rollDice();
            
            // Position of Player 2
            posP2 = posP2 + dice2;
            player2.setPlayerPosition(posP2);

            if (posP2<=29){
                cout<<"- "<<player2.getPlayerName()<<" landed in position "<<posP2<<", that puts them in box "<<g.getBox(posP2)<<endl;

                if (g.getBox(posP2)=='S'){
                    cout<<"<!> Oh-oh, player "<<player2.getPlayerName()<<" landed on a snake! Too bad, go back 3 spaces."<<endl;
                    posP2 = g.snake(player2);
                    player2.setPlayerPosition(posP2);
                    cout<<"Player 2's current position: "<<player2.getPlayerPosition()<<endl;

                }else if(g.getBox(posP2)=='L'){
                    cout<<"<!> Player "<<player2.getPlayerName()<<" just landed on a ladder! Congratulations! Go on 3 spaces!"<<endl;
                    posP2 = g.ladder(player2);
                    player2.setPlayerPosition(posP2);
                    cout<<"Player 2's current position: "<<player2.getPlayerPosition()<<endl;

                } else{
                    player2.setPlayerPosition(posP2);
                    cout<<"Player 2's current position: "<<player2.getPlayerPosition()<<endl;
                }

            }else if (posP2==30){
                cout<<"<!!> Player "<<player2.getPlayerName()<<" is the winner! Congratulations!"<<endl;
                cout<<"Thanks for playing."<<endl;
                gamestate = false;
                break;
                
            }else{
                posP2 = 30-(posP2-30);
                cout<<"- "<<player2.getPlayerName()<<" landed in position "<<posP2<<", that puts them in box "<<g.getBox(posP2)<<endl;
            }

        }else if (inp == 'E'|| inp == 'e'){  // If user wants to exit the game, break loop.
            gamestate = false;
            break;

        }else{
            cout<< "Invalid option, please press C to continue next turn or E to end the game. "<<endl;
        }

        cout<<"--------------------------------------------------------------------------------"<<endl;
        g.setTurn(1);
    } 
return 0;
}

