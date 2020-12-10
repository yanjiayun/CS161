/******************************************
 *Program:assignment6.cpp
 *Date:03/19/2019
 *Description:The program will simulate and print the diffsion of heat through wire or plate
 *Input:their choose about wire or plate; whether they want to modify k,c,rho; whether they want to play again; the temp; length/width/height/time and their sections.
 *Output:the heat diffsion 
******************************************/
#include<iostream>
#include<cstring>
#include<string>
#include<climits>
#include<stdlib.h>
#include<cmath>

using namespace std;

double check_r1(int enter,double t, double l, double &k, double &rho, double &c, int i, int s);
void re_enter1(int &b, double &k, double &rho, double &c, double t, double l, int i ,int s);
double check_r2(int q,double t, double h, double w, double &k, double &rho, double &c, int i, int rows, int cols);
void re_enter2 (int &b, double &k, double &rho, double &c, double t, double h,double w, int i,int rows,int cols);
void iarray1(int s, float *array1,float *narray1, double lt, double rt, double te);
void carray1(int s,float *narray1,float *array1,double lt,double rt,double te,double k,double rho,double c,double t,double l,int i);
void iarray2(int cols, int rows, float **array2, double lt, double rt, double te, double tt, double bt);
void carray2(int rows,int cols,int i,float **narray2,float **array2,double lt,double rt,double tt, double bt, double te,double k,double rho,double c,double t,double w, double h);

/******************************************
 * Function:check_binary
 * Description:to check whether users inputs are integer number 1 or 2.
 * Parameters: A string 
 * Return values: bool
 * Pre_conditions: this function need to be called
 * Post_conditions: The input can'y be anything except integer number 1 and 2.
******************************************/
bool check_binary(string &a1){
	bool check = true;
	if (a1.size() == 1){
		if (a1.at(0) == 49 || a1.at(0) == 50){ //only allow integer number 1 or 2
			check = true;
		}
		else{
			cout << "Error! Please enter again: " << endl;
			return false;
		}
	}
	else{
		cout << "Error! Please enter again: " << endl;
		return false;
	}

	return check;
}

/****************************************** 
 * Function:binary
 * Description:let users enter whether they want to simulate over wire-1 or plate-2
 * Parameters: an integer number
 * Return values: an integer number 
 * Pre_conditions: should be an integer number enter, this function need to be called
 * Post_conditions: integer number 1 or 2
******************************************/
int binary (int &a){
	string a1;
	bool check;
	cout << "Where did you want to simulate heat diffusion? Over a plate or wire? \n(1-wire and 2-plate)" << endl;
	
	do{ //let users re-enter until there is a good value
		getline(cin,a1); 
		check = check_binary(a1);
	}while(check == false);

	a = atoi(a1.c_str()); //transfer string a1 to int a

	return a;
}

/******************************************
 * Function: check_int
 * Description: check whether the input is an integer number or not
 * Parameters: a string x
 * Return values: a bool check 
 * Pre_conditions: this function need to be called 
 * Post_conditions: only the integer number will be accepted as an input 
******************************************/
bool check_int (string x){
	bool check = true;
	if(x.size() == 0){ //avoid an empty input
		cout << "Error! Please enter again: " << endl;
		return false;
	}
	for(int i=0; i<x.size(); i++){
		if (x.at(i) >= '0' && x.at(i) <= '9'){ //the string should just contain 1-9
			check = true;
		}
		else {
			cout << "Error! Please enter again: " << endl;
			return false;
		}
	}
	return check;
}

/******************************************
 * Function: check_float
 * Description: check whether the input is a/an float/integer number or not
 * Parameters: a string x
 * Return values: a bool check 
 * Pre_conditions: this function need to be called 
 * Post_conditions: only the float/integer number will be accepted as an input 
******************************************/
bool check_float(string x){
	bool check = true;
	int times = 0;
	if(x.size() == 0){ //avoid empty input
		cout << "Error! Please enter again: " << endl;
		return false;
	}
	for(int i=0; i<x.size(); i++){
		if(x.at(i) == '.'){ 
			times++; //count the '.' times
		}
	}	
	if (times == 0){ //not dot, means that might be an integer
		for(int i=0; i<x.size(); i++){
			if(x.at(i) >= '0' && x.at(i)<= '9'){ // the string should just contain 1-9 to be a integer number	
				check = true;
			}
			else{		
				cout << "Error! Please enter again: " << endl;
				return false;
			}
		}
	}
	else if (times == 1){ //one dot, means that might be a float
		for(int i=0; i<x.size(); i++){
			if(((x.at(i) >= '0' && x.at(i)<= '9')||x.at(i)=='.')&&x.size()>1){ //the string should just contain 1-9 and the dot			
				check = true;
			}
			else {
				cout << "Error! Please enter again: " << endl;
				return false;
			}
		}
	}
	else{		
		cout << "Error! Please enter again: " << endl;
		return false;
	}
	return check;
}

/******************************************
 * Function: time
 * Description: let the users enter the simulate time and its intervals
 * Parameters: a double number t and an integer number i
 * Return values: a double number
 * Pre_conditions: the previous parts should called correctly
 * Post_conditions: the time should be a float/ an integer number and interval should be an integer number 
******************************************/
double time(double &t, int &i){
	string t1,i1;
	bool check1, check2;
	cout << "Please enter the time: " << endl;
	do{
		getline(cin,t1); //use getline to avoid bad input
		check1 = check_float(t1); //the time should be a float or an integer number 
	}while(check1 == false);  //until we get the good input

	cout << "Please enter the time intervals: " << endl;
	do{
		getline(cin,i1); //use getline to avoid bad input 
		check2 = check_int(i1); //the time interval should be an integer number 
	}while(check2 == false); //until we get the good input

	t = atof(t1.c_str()); //transfer string t1 to float t
	i = atoi(i1.c_str()); //transfer string i1 to float i

	return t; //return a double due to it is a double function
} 

/******************************************
 * Function:length
 * Description: let users enter the length of wire and its sections
 * Parameters: a double/integer number and an integer number 
 * Return values: double number 
 * Pre_conditions: the function need to be called
 * Post_conditions: a double/integer number and an integer number 
******************************************/
double length(double &l, int &s){
	string l1,s1;
	bool check1, check2;
	cout << "Please enter the length of wire: " << endl;
	do{
		getline(cin,l1); //use getline to avoid bad input 
		check1 = check_float(l1); //the length should be a float or an integer number 
	}while(check1 == false); //until we get the good input

	cout << "Please enter the length sections: " << endl;
	do{
		getline(cin,s1); //use getline to avoid bad input 
		check2 = check_int(s1); //the length sections should be an integer number 
	}while(check2 == false); //until we get the good input

	l = atof(l1.c_str()); //transfer string l1 to float l
	s = atoi(s1.c_str()); //transfer string s1 to float s

	return l;
}

/******************************************
 * Function:height
 * Description:let users enter the height of plate and its sections
 * Parameters: a double/integer number and an integer number 
 * Return values: double number 
 * Pre_conditions: the function need to be called
 * Post_conditions: a double/integer number and an integer number 
******************************************/
double height(double &h, int &rows){
	string h1,rows1;
	bool check1, check2;
	cout << "Please enter the height of plate: " << endl;
	do{
		getline(cin,h1); //use getline to avoid bad input 
		check1 = check_float(h1); //the height should be a float or an integer number 
	}while(check1 == false); //until we get the good input

	cout << "Please enter the height sections: " << endl;
	do{
		getline(cin,rows1); //use getline to avoid bad input 
		check2 = check_int(rows1); //the height sections should be an integer number 
	}while(check2 == false); //until we get the good input
 
	h = atof(h1.c_str()); //transfer string h1 to float h
	rows = atoi(rows1.c_str()); //transfer string rows1 to float rows

	return h;
}

/******************************************
 * Function:width
 * Description:let users enter the width of plate and its sections
 * Parameters: a double/integer number and an integer number 
 * Return values: double number 
 * Pre_conditions: the function need to be called
 * Post_conditions: a double/integer number and an integer number 
******************************************/
double width(double &w, int &cols){
	string w1,cols1;
	bool check1, check2;
	cout << "Please enter the width of plate: " << endl;
	do{
		getline(cin,w1); //use getline to avoid bad input 
		check1 = check_float(w1); //the width should be a float or an integer number 
	}while(check1 == false); //until we get the good input

	cout << "Please enter the width sections: " << endl;
	do{
		getline(cin,cols1); //use getline to avoid bad input 
		check2 = check_int(cols1); //the width sections should be an integer number 
	}while(check2 == false); //until we get the good input

  w = atof(w1.c_str()); //transfer string w1 to float w
	cols = atoi(cols1.c_str()); //transfer string cols1 to float cols

	return w;
}

/******************************************
 * Function: temp 
 * Description: let users to enter the initial temperaure
 * Parameters: a double number 
 * Return values: double 
 * Pre_conditions: the function need to be called
 * Post_conditions: a double need to be return
******************************************/
double temp (double &t){
	string t1;
	bool check;
	cout << "Please enter the initial temperature: " << endl;
	do{
		getline(cin,t1); //use getline to avoid bad input
		check = check_float(t1); //the temp should be a float or an integer number
	}while(check == false); //until we get the good input

	t = atof(t1.c_str()); //transfer string t1 to float t

	return t;
}

/******************************************
 * Function: temp1 
 * Description: let users to enter the right and left temperaure
 * Parameters: 2 double number 
 * Return values: double 
 * Pre_conditions: the function need to be called
 * Post_conditions: a double need to be return
******************************************/
double temp1(double &rt, double &lt){
	string rt1,lt1;
	bool check1, check2;
	cout << "Please enter the right temperature: " << endl;
	do{
		getline(cin,rt1); //use getline to avoid bad input
		check1 = check_float(rt1); //the temp should be a float or an integer number
	}while(check1 == false); //until we get the good input

	cout << "Please enter the left temperature: " << endl;
	do{
		getline(cin,lt1); //use getline to avoid bad input
		check2 = check_float(lt1); //the temp should be a float or an integer number
	}while(check2 == false); //until we get the good input

	rt = atof(rt1.c_str()); //transfer string rt1 to float rt
	lt = atof(lt1.c_str()); //transfer string lt1 to float lt

	return rt;
}

/******************************************
 * Function: temp2 
 * Description: let users to enter the top and bottom temperaure
 * Parameters: 2 double number 
 * Return values: double 
 * Pre_conditions: the function need to be called
 * Post_conditions: a double need to be return
******************************************/
double temp2(double &tt, double &bt){
	string tt1,bt1;
	bool check1, check2;
	cout << "Please enter the top temperature: " << endl;
	do{
		getline(cin,tt1); //use getline to avoid bad input
		check1 = check_float(tt1); //the temp should be a float or an integer number
	}while(check1 == false);

	cout << "Please enter the bottom temperature: " << endl;
	do{
		getline(cin,bt1); //use getline to avoid bad input
		check2 = check_float(bt1); //the temp should be a float or an integer number
	}while(check2 == false); //until we get the good input

	tt = atof(tt1.c_str()); //transfer string tt1 to float tt
	bt = atof(bt1.c_str()); //transfer string bt1 to float bt

	return tt;
}

/******************************************
 * Function: modify_or_not1
 * Description: Ask the user whether they want to modify k,c,rho or not
 * Parameters: 3 integer number and 5 double number 
 * Return values: an integer number 
 * Pre_conditions: need to be called 
 * Post_conditions: none
******************************************/
int modify_or_not1 (int &b,double &k, double &rho, double &c, double t, double l, int i, int s){
	string b1;
	bool check;
	cout << "Do you want to modify rho, c and k?\nNow we are using the material properties of Nickel.[k=52.4,rho=0.321,c=0.12]\n(1-Yes and 2-No)" << endl;
	
	do{
		getline(cin,b1); //use getline to avoid bad input
		check = check_binary(b1);
	}while(check == false);

	b = atoi(b1.c_str());
	
	if(b==1){
		re_enter1(b,k,rho,c,t,l,i,s); 
	}
	else if(b==2){
		cout << "We will use the material properties of Nickel." << endl;
		k=52.4;
		rho=0.321; 
		c=0.12;
	}

	return i;
}

/******************************************
 * Function: re_enter1
 * Description: let user to modify k,c,rho for wire material
 * Parameters: double and integer 
 * Return values: none 
 * Pre_conditions: this function need to be called
 * Post_conditions: none
******************************************/
void re_enter1 (int &b, double &k, double &rho, double &c, double t, double l, int i ,int s){
	string k1,rho1,c1;
	bool check1, check2, check3;
	cout << "Please enter the k you want: " << endl;
	do{
		getline(cin,k1); //use getline to avoid bad input
		check1 = check_float(k1);
	}while(check1 == false);
	
	cout << "Please enter the rho you want: " << endl;
	do{
		getline(cin,rho1); //use getline to avoid bad input
		check2 = check_float(rho1);
	}while(check2 == false);
	
	cout << "Please enter the c you want: " << endl;
	do{
		getline(cin,c1); //use getline to avoid bad input
		check3 = check_float(c1);
	}while(check3 == false);
	
	k = atof(k1.c_str());
	rho = atof(rho1.c_str());
	c = atof(c1.c_str());
	int q;
	do{
		check_r1(q,t,l,k,rho,c,i,s); //Warning if the data a unstable
	}while(q == 1);
}

/******************************************
 * Function: check_r1
 * Description: check the re-enter data for wire material is stable or noy 
 * Parameters: int and double 
 * Return values: double 
 * Pre_conditions: the function need to be called
 * Post_conditions: none
******************************************/
double check_r1(int q,double t, double l, double &k, double &rho, double &c, int i, int s){
	double deltat, deltax, stability, stability1;
	string q1;
	bool check; 
	deltat = t/i; 
	deltax = l/s;
	stability1 = ((k*deltat)/((pow(deltax,2))*c*rho)); //the constant
	stability = abs(stability1); //absolute value

	if(stability >= 0.5){
		cout << "Warning! The datas are not stable, do you want to enter again? (1-Yes and 2-No)" << endl;
		do{
			getline(cin,q1); //use getline to avoid bad input
			check = check_binary(q1);
		}while(check == false);

		q = atoi(q1.c_str());
		
		if (q == 1){
			re_enter1(q,k,rho,c,t,l,i,s); //check whether they are stable or not
		}
	}
	return t;
}

/******************************************
 * Function: modify_or_not2
 * Description: ask whether the users want to modify the data of plate's materials
 * Parameters: int and double
 * Return values: int number 
 * Pre_conditions: the function need to be called
 * Post_conditions: none
******************************************/
int modify_or_not2 (int &b,double &k, double &rho, double &c, double t, double h, double w, int i, int rows, int cols){
	string b1;
	bool check;
	cout << "Do you want to modify rho, c and k?\nNow we are using the material properties of Nickel.[k=52.4,rho=0.321,c=0.12]\n(1-Yes and 2-No)" << endl;
	
	do{
		getline(cin,b1); //use getline to avoid bad input
		check = check_binary(b1);
	}while(check == false);

	b = atoi(b1.c_str());
	
	if(b==1){
		re_enter2(b,k,rho,c,t,h,w,i,rows,cols); 
	}
	else if(b==2){
		cout << "We will use the material properties of Nickel." << endl;
		k=52.4;
		rho=0.321; 
		c=0.12;
	}

	return i;
}

/******************************************
 * Function: re_enter2
 * Description: let user to input their c,k and rho
 * Parameters: int and double 
 * Return values: none 
 * Pre_conditions: the function need to be called
 * Post_conditions: none
******************************************/
void re_enter2 (int &b, double &k, double &rho, double &c, double t, double h,double w, int i,int rows,int cols){
	string k1,rho1,c1;
	bool check1, check2, check3;
	cout << "Please enter the k you want: " << endl;
	do{
		getline(cin,k1); //use getline to avoid bad input
		check1 = check_float(k1);
	}while(check1 == false);
	
	cout << "Please enter the rho you want: " << endl;
	do{
		getline(cin,rho1); //use getline to avoid bad input
		check2 = check_float(rho1);
	}while(check2 == false);
	
	cout << "Please enter the c you want: " << endl;
	do{
		getline(cin,c1); //use getline to avoid bad input
		check3 = check_float(c1);
	}while(check3 == false);
	
	k = atof(k1.c_str());
	rho = atof(rho1.c_str());
	c = atof(c1.c_str());
	int q;
	do{
		check_r2(q,t,h,w,k,rho,c,i,rows,cols); //check whether it is stable or not 
	}while(q == 1);
	
}

/******************************************
 * Function: check_r2
 * Description: check wehther the users input are stable or not
 * Parameters: int and double
 * Return values: double 
 * Pre_conditions: the function should be called 
 * Post_conditions: none 
******************************************/
double check_r2(int q,double t, double h, double w, double &k, double &rho, double &c, int i, int rows, int cols){
	double deltat, deltax, deltay, stability;
	string q1;
	bool check; 
	deltat = t/i;
	deltax = h/rows;
	deltay = w/cols;
	stability = ((deltax*deltay*rho*c)/(4*k)); //the constant
	if(deltat > stability){
		cout << "Warning! The datas are not stable, do you want to enter again? (1-Yes and 2-No)" << endl;
		do{
			getline(cin,q1); //use getline to avoid bad input
			check = check_binary(q1);
		}while(check == false);

		q = atoi(q1.c_str());
		if (q == 1){
			re_enter2(q,k,rho,c,t,h,w,i,rows,cols); //check again
		}
	}
	return t;
}

/******************************************
 * Function: one_or_two
 * Description: ask correct data for wire or plate
 * Parameters: int numbers and double numbers
 * Return values: none 
 * Pre_conditions: all the function show need to be appeared above
 * Post_conditions: none 
******************************************/
void one_or_two (int a,int b,int &i,int &s,int &rows, int &cols, double &t, double &l, double &h, double &w, double &te, double &rt, double &lt, double &tt, double &bt, double &k, double &rho, double &c){
	if (a==1){ //wire
		time(t,i); 
		length(l,s);
		temp(te);
		temp1(rt,lt);
		modify_or_not1(b,k,rho,c,t,l,i,s);
	}
	else if(a == 2){ //plate
		time(t,i);
		height(h,rows);
		width(w,cols);
		temp(te);
		temp1(rt,lt);
		temp2(tt,bt);
		modify_or_not2(b,k,rho,c,t,h,w,i,rows,cols);
		}
}

/******************************************
 * Function: iarray1
 * Description: initialize array1
 * Parameters: int numbers, double numbers and float array
 * Return values: none 
 * Pre_conditions: the function need to be called 
 * Post_conditions: none 
******************************************/
void iarray1(int s, float *array1, float *narray1, double lt, double rt, double te){
	array1[0] = lt; //the left contain the left temp
	array1[s-1] = rt; //the right contain the right temp
	for(int i=1; i<(s-1); i++){ 
		array1[i] = te; //other contain the initial temp
	}
}

/******************************************
 * Function: carray1
 * Description: uses a temp array to change our array contain
 * Parameters: int numbers, double numbers and float arrays
 * Return values: none 
 * Pre_conditions: the function need to called 
 * Post_conditions: none 
******************************************/
void carray1(int s,float *narray1,float *array1,double lt,double rt,double te,double k,double rho,double c,double t,double l,int i){
	float z, deltat, deltax;
	deltat = t/i;
	deltax = l/s;
	z = (deltat*k)/(c*rho*pow(deltax,2)); //the constant
	narray1[0] = lt; //let the left contain left temp
	narray1[s-1] = rt; // let the right contain right temp
	for (int a=1; a<=i; a++){
		for(int i=1; i<(s-1); i++){
			narray1[i] = (z*(array1[i+1]-2*array1[i]+array1[i-1]))+array1[i]; //the evaluation to count
		}		
		for(int i=1; i<(s-1); i++){	
			array1[i] = (z*(narray1[i+1]-2*narray1[i]+narray1[i-1]))+narray1[i]; 
		}
		cout << endl;
		for(int i=0; i<s; i++){
			cout << array1[i] << " "; //print array
		}
	}
}

/******************************************
 * Function: iarray2
 * Description: initialize 2d array2
 * Parameters: integer numebrs, double numbers and float array
 * Return values: none 
 * Pre_conditions: the function should be called 
 * Post_conditions: none 
******************************************/
void iarray2(int cols, int rows, float **array2, double lt, double rt, double te, double tt, double bt){
	for(int i=0; i<(rows-1); i++){    //let all rows
		for(int j=0; j<(cols-1); j++){ //let all cols 
			array2[i][j] = te; //equals to initial temp
		}
	}
	for(int i=0; i<cols; i++){ 
		array2[0][i] = tt; //top of array contain top temp
	}	
	for(int i=0; i<rows; i++){
		array2[i][0] = lt; //left of array contain left temp
	}	 
	for(int i=0; i<cols; i++){
		array2[(rows-1)][i] = bt; //bottom of array contain bottom temp
	}
	for(int i=0; i<rows; i++){
		array2[i][(cols-1)] = rt; //right of array contain right temp
	}		
}

/******************************************
 * Function: carray2
 * Description: use a temp array to change
 * Parameters: integer numebers, double numbers and float arrays.
 * Return values: none 
 * Pre_conditions: the function need to be called
 * Post_conditions: none 
******************************************/
void carray2(int rows,int cols,int i,float **narray2,float **array2,double lt,double rt,double tt, double bt, double te,double k,double rho,double c,double t,double w, double h){
	float z, deltat, deltax, deltay,x2,y2;
	deltat = t/i;
	deltax = w/cols;
	deltay = h/rows;
	x2 = pow(deltax,2); //constant
	y2 = pow(deltay,2); //constant 
	z = (deltat*k)/(c*rho); //constant
	for(int r=0; r<rows; r++){   //let narray2 = array2
		for(int j=0; j<cols; j++){
			narray2[r][j] = array2[r][j]; 
		}
	}
	for(int a=1; a<=i; a++){
		for(int r=1; r<(rows-1); r++){
			for(int j=1; j<(cols-1); j++){
				narray2[r][j] = (z*(((array2[r+1][j]-2*array2[r][j]+array2[r-1][j])/x2)+((array2[r][j+1]-2*array2[r][j]+array2[r][j-1])/y2))+array2[r][j]);
			}
		}
		for(int r=1; r<(rows-1); r++){
			for(int j=1; j<(cols-1); j++){
				array2[r][j] = (z*(((narray2[r+1][j]-2*narray2[r][j]+narray2[r-1][j])/x2)+((narray2[r][j+1]-2*narray2[r][j]+narray2[r][j-1])/y2))+narray2[r][j]);
			}
		}
		for(int r=0; r<rows; r++){  //print the array
			for(int j=0; j<cols; j++){
			 	cout << narray2[r][j] << " " ;
			}
			cout << endl;
		}
	}
}

/******************************************
 * Function: again
 * Description: ask user whether they want to simulate again
 * Parameters: integer number 
 * Return values: none 
 * Pre_conditions: the function should be called
 * Post_conditions: the input shouble be 1 or 2
******************************************/
void again (int &m){
	string m1;
	bool check;
	cout << "\nDo you want to simulate again (Yes-1 and No-2): " << endl;
	do{
		getline(cin,m1); //avoid bad input 
		check = check_binary(m1); //check whether the input is 1,2 or not
	}while(check == false);
	m = atoi(m1.c_str()); //transfer string m1 to m
}

int main(){
	int a,i,s,rows,cols,b,m;
	double t,l,h,w,te,rt,lt,tt,bt,k,rho,c;
	float *array1,*narray1, **array2, **narray2;
	
	do{
	binary(a);	
	one_or_two (a,b,i,s,rows,cols,t,l,h,w,te,rt,lt,tt,bt,k,rho,c);	
	if (a==1){
		array1 = new float [s];  //create array1 on heap
		narray1 = new float [s]; //create narray1 on heap
		iarray1(s,array1,narray1,lt,rt,te);
		carray1(s,narray1,array1,lt,rt,te,k,rho,c,t,l,i);
		delete [] array1;  //delete array1 from heap
		delete [] narray1; //delete narray1 from heap
	}
	else if(a==2){
		array2 = new float *[rows]; //create rows of array2 on heap
	   for(int r=0; r<rows; r++){  //create cols of array2 on heap
			array2[r] = new float[cols];
		}
		narray2 = new float *[rows]; //create rows of narray2 on heap
		for(int r=0; r<rows; r++){
			narray2[r] = new float[cols]; //create cols of narray2 on heap
		}	
		
		iarray2(cols,rows,array2,lt,rt,te,tt,bt);
		carray2(rows,cols,i,narray2,array2,lt,rt,tt,bt,te,k,rho,c,t,w,h);		
		
		for(int r=0; r<cols; r++){ //free memory from heap
			delete [] array2[r];    //free memory from heap 
		}
		delete [] array2;
		for(int r=0; r<cols; r++){ //free memory from heap
			delete [] narray2[r];  
		}
		delete [] narray2;         //free memory from heap
	}	
	again(m);
	
	}while(m==1);
	
	return 0;
}
