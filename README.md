Perform a simulation for a simplified and modified version of the Snakes and Ladders game [1] [2] with 
the following features.   
1. Board features 
1.1. The board must contain 30  tiles. 
1.2. The board must contain 3 snake-type squares  indicated by the letter S  (snakes). 
1.3. The board must contain 3  ladder-type boxes with the  letter L  (ladders). 
1.4. The remaining boxes must be identified as normal boxes with the letter N. 
1.5. Each snake square must take the player back 3 squares  (penalty). 
1.6. Each stair box should advance 3 additional boxes (reward). 
1.7. Each box is identified by a natural number from 1. 
2. Player Features 
2.1. The game must support 2 players. 
2.2. Each player is identified with a natural number from 1. 
2.3. At the beginning of the game all players are in box 1. 
2.4. Player 1 starts the first turn of game  
3. Game features 
3.1. The game consists of a succession of turns 
3.2. Each turn can be executed on the command line any of the following 2 possible actions: 
3.2.1. Enter the letter "C" (continue) to continue the game with the next turn 
3.2.2. Enter the letter "E" (end) to end the game 
3.2.3. Only before the first turn you should print the following instruction menu:  Press  
C  to  continue  next  turn,  or  E  to  end  the  game: 
3.2.4. If  the  key  entered  is  not  one  of  "C"  or  "E"  the  following  message  should  be 
printed: Invalid  option,  please  press  C  to  continue  next  turn  or  E  to  end  the  game 
3.3. Execution of the turn 
3.3.1. During each turn, the following turn information must be printed on the console. 
3.3.2. The number of the turn (the first turn is indicated by the number 1) 
3.3.3. The number of the player with the current turn 
3.3.4. The box number corresponding to the player's current position 
3.3.5. The number obtained by simulating a conventional 6-sided die 
3.3.6. The type of square the player should move to after throwing the dice 
3.3.6.1. N for normal boxes 
3.3.6.2. S for snake squares (Snake) 
3.3.6.3. L for ladder boxes (Ladder) 
3.3.7. The final square to which the player must move 
3.3.7.1. If the box is Normal, then indicate the final position directly 
3.3.7.2. If the box is Ladder, the final position will be the result of the 
corresponding increment in squares indicated by the reward 
3.3.7.3. If the box  is Snake,  the final position will result  from the corresponding 
retracement in squares, indicated by the penalty 
3.3.7.4. If a special square (Snake or Ladder) results in the turn player falling into 
another special square, this second should be ignored, i.e. only one jump or one recoil 
per turn is allowed 
  
3.3.8. The  following  example  represents  the  result of  the  first  turn,  for  player 
number 1, assuming he gets a 5 on the die, and box number 6 is a snake with a penalty 
of 3 squares:  1 1 1 5 S 3 
3.3.9. Each turn element must be separated from the previous one by a blank 
space 
3.4. End of game: 
3.4.1. Once the game is over, either by a player's victory, by instruction of a player or by 
  the turn limit, the message must be printed on a new line:  -- GAME OVER -- 
3.4.2. If the maximum number of turns has been reached, the following message should 
be printed: The  maximum  number  of  turns  has  been reached... 
3.4.3. If at the end of the turn the current or current playhas reached or exceeded the 
final  square,  the  game  ends.  In  this  case  you  must  print  the  number  of  the  last  box  on  the 
board,  that  is,  if  the  board  has  30  boxes,  you  cannot  print  that  box  31.  Once  the  turn 
information is printed, the following message should be printed indicating which player won 
the game instead of the symbol "#":  Player # is the winner!!! 
3.4.4. If the final box has not been exceeded and the key with the uppercase letter "E" 
is pressed, the game ends and the following message should be printed:  Thanks for playing!!! 
