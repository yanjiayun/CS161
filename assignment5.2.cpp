/**************************************
* Porgram: assignment5.2.cpp
* Author: Jiayun.Yan
* Date: 03/03/2019
* Desciprtion: Print something
* Input: n and i
* Output: some stars and spaces
 *************************************/
#include<iostream>

using namespace std;

/**************************************
* Function: input
* Description: let user enter n and i 
* Parameters: two integer number
* Return value: none
* Precondition: none
* Postcondition: 2 integer number
***************************************/
void input (int &n, int &i){
	cout << "Plz enter the number of stars: " << endl;
	cin >> n;
	cout << "Plz enter indents: " << endl;
	cin >> i;
}

/**************************************
* Function: patter
* Description: print the picture by recursiving
* Parameters: two integer number
* Return value: none
* Precondition: function input need run
* Postcondition: the ugly picture :(
***************************************/
void pattern(int n, int i){
	if (n < 1){
		return;
	}
	pattern(n/2,i);
	for (int k=1; k<=i; k++){
		cout << "  " ;
	}
	for (int k=1; k<=n; k++){
		cout << "* " ;
	}
	cout << "\n";
	pattern(n/2,(i+n/2));
}

int main (){
	int n,i;
	input(n,i);
	pattern(n,i);

	return 0;
}
