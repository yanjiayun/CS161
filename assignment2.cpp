/***********************************************
** Program: assignment2.cpp
** Author: Jiayun Yan
** Date: 01/20/2019
** Description: This is a game in a shopping mall, users need to buy something for snowman or themselves. 
The money they can use is a random number.
If they prefer to buy something for snowman, they only need to do the math correctly and they can win.
If they prefer to buy something for themselves, they need to spend an even number and do the math correctlt to win. 
After that, they can choose to play again or leave.  
** Input: if and else if. Users need to input their choice and their total payment.
** Output: the instuction of the game, and the result of the game.
 **********************************************/

#include <iostream> // cout(output) and cin(input)
#include <ctime> // include to allow time() to be used, that means run only one time
#include <cstdlib>  // include to allow rand() and srand() to be used, that means select random number 

using namespace std; // do not need to type "std::"   

int main () 
{  
   cout << "Welcome to JY Shopping Mall" << endl; // background of the game 
   cout << "Get your money for today's shopping" << endl; // the random number for users
   
   begin:
   
   int x; // variable to get a random integer
   srand(time(NULL)); // Do this just once 
 
   x = rand()%6; // random number x<=5
   cout << "Your available money($):" << x << endl;
  
   int a; // an element of chance 
   cout << "Do you want to buy something for snowman?\nFor sonwman enter 1,for your self enter 2"<< endl;
   cin >> a; 
  
   if (a==1) {
      cout << "Buy something for snowman!" << endl;
      cout << "Carrot for nose $1\nBucket for hat $2\nScarf $3" << endl;
      
      int y; // the total spend      
      cout << "Please do the math by yourself!\nTotal Payment:" << endl;
      cin >> y;
         
         if (x-y==0) {
            cout << "Wonderful! You win!" << endl;
         } 
         else if (x-y<0) {
            cout << "You lost! Spent more money than you have!" << endl;     
         }
         else if (x-y>=0 && x-y<x) { //make sure users put a postive y
            cout << "You win! The sonwman is greatful to you!" << endl;
         }
         else if (x-y>=x) { // This mean someone put a negative y, they will lost
            cout << "You lost! You need to spend money!" << endl;
         }
   } 
   
   if (a==2) {
      cout << "Buy something for yourself!" << endl;
      cout << "Carrot $2\nBucket $4\nScarf $5" << endl;
      int z; // the total spend
      cout << "Please do the math by yourself!\nTotal Payment:" << endl;
      cin >> z;

         if (x-z<0) {
            cout << "You lost! Spent more money than you have!" << endl;
         }
         if (x-z>=0 && x-z<x) { // make sure users put a postive z
            if (z%2==1) {
               cout << "You lost! You lost!" << endl;
            }  
            else if (z%2==0) {
               cout << "You win! But the snowman feel so upset!" << endl;
            }
         }
         if (x-z>x) {
            cout << "You lost! You need to spend money!" << endl;
         } 
   }
   
   int b;
   cout << "Do you want to play again?\nPlay again enter 1, Leave enter 2." << endl;
   cin >> b;
  
      if (b==1) {
      goto begin;
      }
      if (b==2) {
      cout << "ByeBye~" << endl; 
      } 
  

   return 0;
}


