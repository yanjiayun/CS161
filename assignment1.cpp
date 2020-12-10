/**********************************
** Program:Assignment1.cpp
** Author: Jiayun Yan
** Date: 01/13/2019
** Description: How to get the Maximum and Minimum values of Shorts, Longs and Ints (Include signed and unsigned)
** Input: Prprocessor Macros, Functions and Calculations,sizeof() and pow()
** Output: The values of Shorts, longs and ints.
***********************************/


#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int main() {
   cout << "Preprocessor Macros" << endl;
   cout << "The max and min sizes of signed and unsigned shorts" << endl;
   cout << "SHRT_MAX" << SHRT_MAX << endl;
   cout << "SHRT_MIN" << SHRT_MIN << endl;
   cout << "USHRT_MAX"<< USHRT_MAX << endl;
   cout << "The max and min sizes of signed and unsigned longs" << endl;
   cout << "LONG_MAX" << LONG_MAX << endl;
   cout << "LONG_MIN" << LONG_MIN << endl;
   cout << "ULONG_MAX" << ULONG_MAX << endl;
   cout << "THe man and min size of signed and unsigned Ints" << endl;
   cout << "INT_MAX" << INT_MAX << endl;
   cout << "INT_MIN" << INT_MIN << endl;
   cout << "UINT_MAX" << UINT_MAX << endl;

   cout << "Using Functions and Calculations" << endl;   

   cout << "The max and min sizes of signed and unsigned shorts" << endl;
   cout << "The max sizes of signed shorts" << pow(2,sizeof(short)*8)/2-1 << endl; //include zero, so we should minus 1.    
   cout << "The min sizes of signed shorts -" << pow(2,sizeof(short)*8)/2 << endl; //becasue it is signed, it should be negative
   cout << "The max sizes of unsigned shorts" << pow(2,sizeof(short)*8)-1 << endl; //include zero, so we should minus 1.    

   cout << "The max and min sizes of signed and unsigned longs" << endl;
   cout << "The max sizes of signed longs" << ((long) pow(2,sizeof(long)*8))-1 << endl;//include zero.
   cout << "The min sizes of signed longs" << ((long) pow(2,sizeof(long)*8)) << endl; //because it is signed,it should be negative
   cout << "The max sizes of unsigned longs" << (unsigned long) pow(2,sizeof(long)*8)-1 << endl;//include zero.

   cout << "The max and min sizes of signed and unsigned ints" << endl;
   cout << "The max sizes of signed ints" << ((int) pow(2,sizeof(int)*8))-1 << endl;//include zero
   cout << "The min sizes of signed ints" << ((int) pow(2,sizeof(int)*8)) << endl; //because it is signed, it should be negative
   cout << "The max sizes of unsigned ints" << (unsigned int) pow(2,sizeof(int)*8)-1 << endl;//inclue zero

   return 0;
}
  
