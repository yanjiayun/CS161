/*****************************************
Program: TwentyOne(assignment3.cpp)
Author: Jiayun Yan
Date: 02/03/2019
Description: In this game, we can include 1-4 persons to play. 
				 Each player can bet with dealer in their turn. 
				 Who get closer to 21 points, and who will win the games. 
				 At the very begining of this game, I will show the insructions about how to play it.
Input: Players amount
		 Each player's starting money
		 How much money does each player want to use for bet
		 Whether they want to generate another numberto add to their total points
		 Whether they want to play again.
Output: Random number created for each player, random number for dealer. 
		  Compare players' number with dealer's, the result of each turn. 
		  Cout the rest money of each player, and their rest money in the bank. 
		  Ask the players whether they want to play again. End the turn when player going over 21 points
******************************************/
#include <iostream> // cout(ouput) and cin(input) 
#include <ctime> // include to allow time() to be used, that means run only one time 
#include <cstdlib> // include to allow rand() and srand() to be used, that means select a random number

using namespace std; // do not need to type "std::"

void instructions(); // There is the second function...I really feel confused about that TAT 

int main() 
{
	int a; // for do-while, whether the player want to play again
	int b; // for each person whether he/she wants one more random number
	int p; // the players amount
	int m1=0; // the starting money for player1
	int m2=0; // the starting money for player2
	int m3=0; // the starting money for player3
	int m4=0; // the starting money for player4
	int bm1; // the bet money for player 1
	int bm2; // the bet money for player 2
	int bm3; // the bet money for player 3
	int bm4; // the bet money for player 4
	int r1; // the random number for player 1
	int r2; // the random number for player 2
	int r3; // the random number for player 3
	int r4; // the random number for player 4
	int rd1; // the first random number for dealer
	int rd2; // the second random number for dealer
	int sumd=0; // the final number for dealer, it is equals to 0, and then it will be added some random numbers
	int rm1; // the rest money for player 1
	int rm2; // the rest money for player 2
	int rm3; // the rest money for player 3
	int rm4; // the rest money for player 4
	int sum1; // the final number for player 1
	int sum2; // the final number for player 2
	int sum3; // the final number for player 3
	int sum4; // the final number for player 4

   instructions();

	cout << "How many players do you want to include in this time:";
	cin >> p;
	/* Step1: Users enter their starting money */
goodplayervalue:
	if (p>0 && p<=4) {
		for(int x=1; x<=p; x++) { 
			switch(x) {
				case 1:
					cout << "Player 1, how much money are you starting with?\n";
					cin >> m1;
					if (m1>=0) {
						break;
					}
					else {
						do {
							cout << "Error! Please enter a positive number!\n";
							cin >> m1;
						}while(m1<0);
						break;
					}
				case 2:
					cout << "Player 2, how much money are you starting with?\n";
					cin >> m2;
					if (m2>=0) {
						break;
					}
					else {
						do {
							cout << "Error! Please enter a positive number!\n";
							cin >> m2;
						}while(m2<0);
						break;
					}
				case 3:
					cout << "Player 3, how much money are you starting with?\n";
					cin >> m3;
					if (m3>=0) {
						break;
					}
					else {
						do {
							cout << "Error! Please enter a positive number!\n";
							cin >> m3;
						}while(m3<0);
						break;
					}
				case 4:
					cout << "Player 4, how much money are you starting with?\n";
					cin >> m4;
					if (m4>=0) {
						break;
					}
					else {
						do {  
							cout << "Error! Please enter a positive number!\n";
							cin >> m4;
						}while(m4<0);
						break;
					}
			}

   /* This is to ensure in the further game playing the rest money will not always equals to the strating money*/
			 rm1 = m1;
			 rm2 = m2;  
			 rm3 = m3;
			 rm4 = m4;
		}
	}
	else if (p<=0 || p>4) {
		do {
			cout << "Error!This game just accept 1-4 players!" << endl;
			cout << "How many players do you want to include in this time:";
			cin >> p; 
		}while((cin.good()) && (p<=0 || p>4));

		if (p>0 && p<=4) {
			goto goodplayervalue;
		} 
	}
	
	
/* Step2: The Player1's game begin. */	
	srand(time(NULL));

	do{
		for (int x=1; x<=p; x++) { 		

switch2:
		if (x<=p) {
			switch(x) {
				case 1: 
					if (rm1==0) {
						cout << "Player 1's bank is 0, Player 1 get skipped!" << endl;
						x++;
						goto switch2;
					}
					else {
						cout << "Player 1, how much do you bet you can beat the dealer:";
						cin >> bm1;
						int sum1=0;
goodbm1:
						if (bm1>0 && bm1<=rm1) {
anothernumber1:
							/*This is the player1's turn*/
							r1=(rand()%11)+1;
							sum1= sum1 + r1;
							cout << "Player 1,you got " << r1 << ".Do you want to go again (0-no or 1-yes)";
							cin >> b;
good12forp1:
							if (sum1>21) { 
								cout << "Player 1, you busts!\nYou lost!" << endl;
								rm1 = rm1 - bm1;
								cout << "Player 1 has: " << rm1 << endl;
								x++;
								goto switch2;
					 		}
							
							if (b==0) {
								cout << "You final number is: " << sum1 << endl;
							} 
							else if (b==1) { 
								goto anothernumber1;
							}
							else if (b!=0 || b!=1) {
								do {
									cout << "Error! 0-no or 1-yes, please do not enter something else" << endl;
									cout << "Do you want to go again (0-no or 1-yes)";
									cin >> b;
								}while((b!=0 && b!=1) && (sum1<=21)); 

							   if(b==0 || b==1) { 
									goto good12forp1;
								}
							}
						}
						else {
							do { 
								cout << "Error!You can only enter a positive number, and that number should be less than your strating money," << endl;
								cout << "Player 1, how much do you bet you can beat the dealer:";
								cin >> bm1;
							}while(bm1<=0 || bm1>rm1);

							if (bm1>0 && bm1<=rm1) {
								goto goodbm1;
							}
						} 
						/*This is the dealer's turn to play against player1*/
						if (sum1<=21) { 
							rd1=(rand()%3)+9;
							cout << "The dealer get a random number: " << rd1 << endl;
							rd2=(rand()%3)+9;
							cout << "The dealer get another random number: " << rd2 << endl;
							sumd= rd1 + rd2;
							cout << "The dealer's final number is: " << sumd << endl;
							/*This is the compare part, to compare dealer's and player's number, and get the result of the game*/
							if (sumd>21) {
								cout << "The dealer busts!\nYou win!" << endl;
								rm1 = rm1 + bm1;
								cout << "Player 1 has: " << rm1 << endl;
							}
							else {
								if (sumd > sum1) {  
									cout << "Player 1, the dealer get closer to 21 than you!\nYou lost!" << endl;
									rm1 = rm1 - bm1;
									cout << "Player 1 has: " << rm1 << endl;
								}
								else if (sumd < sum1) {
									cout << "Player 1, you get closer than the dealer!\nYou win!" << endl;
									rm1 = rm1 + bm1;
									cout << "Player 1 has: " << rm1 << endl;
								} 
								else if (sumd = sum1) {
									cout << "It's a tie!" << endl;
									cout << "Player 1 has: " << m1 << endl;
								}
							}
						}
						break;
					}
				case 2:
					if (rm2==0) {
						cout << "Player 2's bank is 0, Player 2 get skipped!" << endl;
						x++;
						goto switch2;
					}
					else {
						cout << "Player 2, how much do you bet you can beat the dealer:";
						cin >> bm2;
						int sum2=0;
goodbm2:
						if (bm2>0 && bm2<=rm2) {
anothernumber2:
							/*This is the player2's turn*/
							r2=(rand()%11)+1;
							sum2= sum2 + r2;
							cout << "Player 2,you got " << r2 << ".Do you want to go again (0-no or 1-yes)";
							cin >> b;
good12forp2:
                     
							if (sum2>21) { 
								cout << "Player 2, you busts!\nYou lost!" << endl;
								rm2 = rm2 - bm2;
								cout << "Player 2 has: " << rm2 << endl;
								x++;
								goto switch2;
							}
							if (b==0) {
								cout << "You final number is: " << sum2 << endl;
							} 
							else if (b==1) { 
								goto anothernumber2;
							}
							else if (b!=0 || b!=1) {
								do {
									cout << "Error! 0-no or 1-yes, please do not enter something else" << endl;
									cout << "Do you want to go again (0-no or 1-yes)";
									cin >> b;
								}while(b!=0 && b!=1); 

								if(b==0 || b==1) { 
									goto good12forp2;
								}
							}	
						}
						else {
							do { 
								cout << "Error!You can only enter a positive number, and that number should be less than your strating money," << endl;
								cout << "Player 2, how much do you bet you can beat the dealer:";
								cin >> bm2;
							}while(bm2<=0 || bm2>rm2);

							if (bm2>0 && bm2<=rm2) {
								goto goodbm2;
							}
						} 
						/*This is the dealer's turn to play against player2*/
						if (sum2<=21) { 
							rd1=(rand()%3)+9;
							cout << "The dealer get a random number: " << rd1 << endl;
							rd2=(rand()%3)+9;
							cout << "The dealer get another random number: " << rd2 << endl;
							sumd= rd1 + rd2;
							cout << "The dealer's final number is: " << sumd << endl;
							/*This is the compare part, to compare dealer's and player's number, and get the result of the game*/
							if (sumd>21) {
								cout << "The dealer busts!\nYou win!" << endl;
								rm2 = rm2 + bm2;
								cout << "Player 2 has: " << rm2 << endl;
							}
							else {
								if (sumd > sum2) {  
									cout << "Player 2, the dealer get closer to 21 than you!\nYou lost!" << endl;
									rm2 = rm2 - bm2;
									cout << "Player 2 has: " << rm2 << endl;
								}
								else if (sumd < sum2) {
									cout << "Player 2, you get closer than the dealer!\nYou win!" << endl;
									rm2 = rm2 + bm2;
									cout << "Player 2 has: " << rm2 << endl;
								} 
								else if (sumd = sum2) {
									cout << "It's a tie!" << endl;
									cout << "Player 2 has: " << rm2 << endl;
								}
							}
						}
						break;
					}
				case 3:
					if (rm3==0) {
						cout << "Player 3's bank is 0, Player 3 get skipped!" << endl;
						x++;
						goto switch2;
					}
					else {
						cout << "Player 3, how much do you bet you can beat the dealer:";
						cin >> bm3;
						int sum3=0;
goodbm3:
						if (bm3>0 && bm3<=rm3) {
anothernumber3:
							/*This is the player3's turn*/
							r3=(rand()%11)+1;
							sum3= sum3 + r3;
							cout << "Player 3,you got " << r3 << ".Do you want to go again (0-no or 1-yes)";
							cin >> b;
good12forp3:
							if (sum3>21) { 
								cout << "Player 3, you busts!\nYou lost!" << endl;
								rm3 = rm3 - bm3;
								cout << "Player 3 has: " << rm3 << endl;
								x++;
								goto switch2;
							}
							else if (b==0) {
								cout << "You final number is: " << sum3 << endl;
							} 
							else if (b==1) { 
								goto anothernumber3;
							}
							else if (b!=0 || b!=1) {
								do {
									cout << "Error! 0-no or 1-yes, please do not enter something else" << endl;
									cout << "Do you want to go again (0-no or 1-yes)";
									cin >> b;
								}while(b!=0 && b!=1); 

								if(b==0 || b==1) { 
									goto good12forp3;
								}
							}
						}
						else {
							do { 
								cout << "Error!You can only enter a positive number, and that number should be less than your strating money," << endl;
								cout << "Player 3, how much do you bet you can beat the dealer:";
								cin >> bm3;
							}while(bm3<=0 || bm3>rm3);

							if (bm3>0 && bm3<=rm3) {
								goto goodbm3;
							}
						} 
						/*This is the dealer's turn to play against player3*/
						if (sum3<=21) { 
							rd1=(rand()%3)+9;
							cout << "The dealer get a random number: " << rd1 << endl;
							rd2=(rand()%3)+9;
							cout << "The dealer get another random number: " << rd2 << endl;
							sumd= rd1 + rd2;
							cout << "The dealer's final number is: " << sumd << endl;
							/*This is the compare part, to compare dealer's and player's number, and get the result of the game*/
							if (sumd>21) {
								cout << "The dealer busts!\nYou win!" << endl;
								rm3 = rm3 + bm3;
								cout << "Player 3 has: " << rm3 << endl;
							}
							else {
								if (sumd > sum3) {  
									cout << "Player 3, the dealer get closer to 21 than you!\nYou lost!" << endl;
									rm3 = rm3 - bm3;
									cout << "Player 3 has: " << rm3 << endl;
								}
								else if (sumd < sum3) {
									cout << "Player 3, you get closer than the dealer!\nYou win!" << endl;
									rm3 = rm3 + bm3;
									cout << "Player 3 has: " << rm3 << endl;
								} 
								else if (sumd = sum3) {
									cout << "It's a tie!" << endl;
									cout << "Player 3 has: " << rm3 << endl;
								}
							}
						}
						break;
					}
				case 4:
					if (rm4==0) {
						cout << "Player 4's bank is 0, Player 4 get skipped!" << endl;
						break;
					}
					else {
						cout << "Player 4, how much do you bet you can beat the dealer:";
						cin >> bm4;
						int sum4=0;
goodbm4:
						if (bm4>0 && bm4<=rm4) {
anothernumber4:
							/*This is the player4's turn*/
							r4=(rand()%11)+1;
							sum4= sum4 + r4;
							cout << "Player 4,you got " << r4 << ".Do you want to go again (0-no or 1-yes)";
							cin >> b;
good12forp4:
                  	if (sum4>21) { 
								cout << "Player 4, you busts!\nYou lost!" << endl;
								rm4 = rm4 - bm4;
								cout << "Player 4 has: " << rm4 << endl;
								break;
							}
							if (b==0) {
								cout << "You final number is: " << sum4 << endl;
							} 
							else if (b==1) { 
								goto anothernumber4;
							}
							else if (b!=0 || b!=1) {
								do {
									cout << "Error! 0-no or 1-yes, please do not enter something else" << endl;
									cout << "Do you want to go again (0-no or 1-yes)";
									cin >> b;
								}while(b!=0 && b!=1); 

								if(b==0 || b==1) { 
									goto good12forp4;
								}
							}
						}	
						else {
							do { 
								cout << "Error!You can only enter a positive number, and that number should be less than your strating money," << endl;
								cout << "Player 4, how much do you bet you can beat the dealer:";
								cin >> bm4;
							}while(bm4<=0 || bm4>rm4);

							if (bm4>0 && bm4<=rm4) {
								goto goodbm4;
							} 
						}
						/*This is the dealer's turn to play against player4*/
						if (sum4<=21) { 
							rd1=(rand()%3)+9;
							cout << "The dealer get a random number: " << rd1 << endl;
							rd2=(rand()%3)+9;
							cout << "The dealer get another random number: " << rd2 << endl;
							sumd= rd1 + rd2;
							cout << "The dealer's final number is: " << sumd << endl;
							/*This is the compare part, to compare dealer's and player's number, and get the result of the game*/
							if (sumd>21) {
								cout << "The dealer busts!\nYou win!" << endl;
								rm4 = rm4 + bm4;
								cout << "Player 4 has: " << rm4 << endl;
							}
							else {
								if (sumd > sum4) {  
									cout << "Player 4, the dealer get closer to 21 than you!\nYou lost!" << endl;
									rm4 = rm4 - bm4;
									cout << "Player 4 has: " << rm4 << endl;
								}
								else if (sumd < sum4) {
									cout << "Player 4, you get closer than the dealer!\nYou win!" << endl;
									rm4 = rm4 + bm4;
									cout << "Player 4 has: " << rm4 << endl;
								} 
								else if (sumd = sum4) {
									cout << "It's a tie!" << endl;
									cout << "Player 4 has: " << rm4 << endl;
								}
							}
						}
						else if (sum4>21) { 
							cout << "Player 4, you busts!\nYou lost!" << endl;
							rm4 = rm4 - bm4;
							cout << "Player 4 has: " << rm4 << endl;
						}
					}
				}
			}
				break;
		}


		if (rm1==0 && rm2==0 && rm3==0 && rm4==0) {
			cout << "All the players' bank come to 0!\nThe end!" << endl;
			break;
			}

		cout << "Do you want to play again or cash out collectively?\nEnter 1 to play again, 0 to cash out collectively: ";
		cin >> a;
		if (a==0) {
			cout << "ByeBye~" << endl;
			break;
		}
		else if (a!=0 && a!=1) {
			do {
				cout << "Error! play again-1, cash out-0 :";
				cin >> a;
			}while((cin.good()) && (a!=0 && a!=1));
		}
	}while(a==1);

}


void instructions() {
	cout << "Hi! Welcome to TwentyOne!\nIn this game, we can include 1-4 players.\nFor each player, you need to enter a starting money, and decide your bet money for each turn.\nYou will get a number between 1-11, and you can decide whether you want one more number.\nTo win the game, you need to get more closer to 21 points than dealer.\nWhen you get more than 21 points, you will lose.\nWhen all the players' bank are 0, the game will over automatically." << endl;
	cout << "Let's begin!" << endl;
}
