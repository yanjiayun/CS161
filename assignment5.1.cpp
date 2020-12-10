/***************************************************
* Program: assignment5.1.cpp
* Author: Jiayun Yan
* Date: 03/03/2019
* Description: The program will let users enter a sentence or paragraph, and then enter some word they want to search. And it will show the frequency of those words.
* Input: The paragraph/sentence, the search number, the words.
* Output: The frequency of these words.
***************************************************/
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

/***************************************************
* Function: enter1
* Description: let user enter a paragraph/sentence
* Parameters: C-style array
* Return value: none
* Precondition: this sentence do not have any punctuation
* Postcondition: a c style array contain one sentence/paragraph
***************************************************/
void enter1 (char *arr1) {
	cout << "Plz enter a paragraph/sentence: " << endl;
	cin.getline(arr1,1000);
}

/***************************************************
* Function: change1
* Description: change all the letters in the previous sentence/paragraph to lower case
* Parameters: a C++ string
* Return value: none
* Precondition: function enter1 should run
* Postcondition: a C++ string contain a lower case sentence/paragraph
***************************************************/
void change1(string &arr3) {
	for (int i=0; i<arr3.size(); i++){
		if (arr3.at(i) >= 65 && arr3.at(i) <= 90){ //if one letter is captical
			arr3.at(i) = int(arr3.at(i)) + 32; //change it to lower case
		}
	}	
}

/***************************************************
* Function: number
* Description: let the user enter how many words they want to search
* Parameters: an integer
* Return value: none
* Precondition: none
* Postcondition: an integer
***************************************************/
void number (int &a) {
	cout << "Plz enter the number of words you want to search: " << endl;
	cin >> a;
	cin.ignore(256,'\n'); //becasue cin will ignore all white space, we need to use this command
	cin.clear();
}

/***************************************************
* Function: N_word
* Description: let user enter the words they want to search
* Parameters: an integer and some c++ string 
* Return value: none
* Precondition: the function number should run
* Postcondition: an array contain the words
***************************************************/
void N_word (int a, string *arr2) {
	for (int i=0;  i<a; i++) { 
		cout << "Plz enter your word" << i+1 << ": " << endl; //enter the words once
		getline(cin,arr2[i]);
	}		
}

/***************************************************
* Function: change2
* Description: change all the search words into lower case
* Parameters: an integer number, and one array
* Return value: none
* Precondition: the function number should run
* Postcondition: one array contain lower case words
***************************************************/
void change2(int a, string *arr2){
	for (int c=0; c<a; c++){
		for(int i=0; i<arr2[c].size(); i++){
			if (arr2[c].at(i) >= 65 && arr2[c].at(i) <= 90){ //if one letter is capital
				arr2[c].at(i) = int(arr2[c].at(i)) + 32; //change it to lower case
			}
		}
	}
}

/***************************************************
* Function: times
* Description: count the frequency of each word
* Parameters: an integer number, one c++ string and one array
* Return value: none
* Precondition: the function number should run
* Postcondition: the frequency
***************************************************/
void times(int a, string *arr2, string arr3){
	string temp; //a temporary container
	for (int c=0; c<a; c++){ //check n(number) times
		int time = 0;
		for (int i=0; i<arr3.size(); i++){ //for the whole sentence	
			temp += arr3.at(i); //let temp equals to the words
			if (arr2[c] == temp){
				time ++;  // count times
			}
			if (arr3.at(i) == 32){ // if there is a space, means the word end
				temp = "" ;
			}	
		}	
		cout << "The frequency of " << arr2[c] << " is: " << time << endl;
	}
}
				
int main(){
	char arr1[1000];
	string *arr2;
	int n;
	enter1(arr1);
	number(n);
	string arr3(arr1);
	change1(arr3);
	arr2 = new string[n];		
	N_word(n,arr2);
	change2(n,arr2);
	times(n,arr2,arr3);
	
	delete [] arr2 ;
		
	return 0;
}
