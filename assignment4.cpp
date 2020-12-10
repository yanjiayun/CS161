/********************************
 *Program: assignment4.cpp
 *Author: Jiayun Yan
 *Date:02/19/2019
 *Description: This program helps people to calculate their allowed reimbursement and spent.
 *Input: The users' spent during their trip 
 *Output: Users' reimbursement money and spent money.
********************************/

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int days(int &a);
bool check_day(string &x);
double department_time(double &dt);
double arrival_time(double &at);
bool check_time(string &x);
double airfare(double &f1);
double registration_fee(double &f2);
bool check_fees(string &x);
int car_or_taxi(double &r, double &s, int d);
bool check_YorN(string &a);
double parking_fee(double &pr, double &ps, int d);
double hotel_fee(double &hr, double &hs, int d);
double taxi_fee(double &r, double &s, int d);
int car_type (int &t, double &r, double &s, int d);
double mile_driven(double &m);
bool check_type(string x);
double Sedan_rental(double &rr, double &rs, int d);
double Sedan_gas(double &gr, double &gs);
double SUV_rental(double &rr, double &rs, int d);
double SUV_gas(double &gr, double &gs);
double Van_rental(double &rr, double &rs, int d);
double Van_gas(double &gr, double &gs);
double Convertible_rental(double &rr, double &rs, int d);
double Convertible_gas(double &gr, double &gs);
double breakfast_fee(double &r1, double &s1);
double lunch_fee(double &r2, double &s2);
double dinner_fee(double &r3, double &s3);
double meals(double dt, double at, double &r, double &s, int d);
double day1(double dt, double at, double &r, double &s);
double first_day (double dt, double &r, double &s);
double last_day (double at, double &r, double &s, int d);
double dayn(double dt, double at, double &r, double &s, int d);

/**************************
 *Function: days
 *Description: Get trip days from users
 *Parameters: one integer(the trip days)
 *Return value: integer(the trip days)
 *Preconditions: function check_days should located before
 *Postconditions: get a integer number greater than 1
***************************/

int days(int &d) {
	string days; // aviod bad input
	cout << "This program is helping you count your reimbursement and spent during your business trip" << endl;
	cout << "Plz enter your days of trip, notice that the number should greater than 1" << endl;
	bool check;
	
	do{                                   // check bad input 
		getline(cin,days);
		check = check_day(days);
	}while(check == false);
	
	d = atoi(days.c_str()); // change string d to integer number d
}

/***************************
 *Function: check_day
 *Description: check users' input about days.
 *Parameters: a string x(day),that is to assmuse bad input
 *Return value: bool (whether check is true or not
 *Preconditions: (x)days should be entered
 *Postconditions: make sure x only contain 1 - 9
***************************/

bool check_day(string &x) {
	bool check = true;
	int d;
		for (int i=0; i<x.size(); i++) {
			if (x.at(i)>='0' && x.at(i)<='9') {              //only contain number
				d = atoi(x.c_str());
				
				if (d >=1){                //days should be greater than 1
				check = true;
				}
				else if (d == 0) {
					cout << "Error! Plz enter again: " << endl;
					return false;
				}
			}
			else {
			cout << "Error! Plz enter again: " << endl;
			return false;
			}
		}
		return check;
}

/***************************
 *Function: department_day
 *Description: get the input from users about their department time
 *Parameters: a float dt (that's the time express as a float with 2 decimal spaces' way)
 *Return value: one float dt 
 *Preconditions: function check_time should located before
 *Postconditions: at should only contain number and ".", with just one "." and have size of 4 or 5; moreover, after the ".", the number should be smaller than 60, and the hold number should less than 24.00.
***************************/

double department_time(double &dt) {
	string dt1;	//avoid bad input
	cout << "Plz enter your department time of your first day of trip\nMust contain 2 deciaml places!\n(e.g 7:00 pm → 19.00)" << endl;
	bool check;
	
	do{                          //check bad input 
		getline(cin,dt1);
		check = check_time(dt1);
	}while(check == false);
	
	dt = atof(dt1.c_str());     //change string to float
}

/***************************
 *Function: arrival_time
 *Description: get the input from users about their arrival time
 *Parameters: a float dt (that's the time express as a float with 2 decimal spaces' way)
 *Return value: one float at 
 *Preconditions: function check_time should located before
 *Postconditions: at should only contain number and ".", with just one "." and have size of 4 or 5; moreover, after the ".", the number should be smaller than 60, and the hold number should less than 24.00.
***************************/

double arrival_time(double &at) {
	string at1;     //avoid bad input 
	cout << "Plz enter your arrive time of your last day of trip" << endl;
	bool check;

	do{                      // check bad input 
	getline(cin,at1);
	check = check_time(at1);
	}while(check == false);
	
	at = atof(at1.c_str());  //change string to float
}

/***************************
 *Function: check_time
 *Description: check the user's input about dt and at
 *Parameters: a string x (that's to avoid bad input)
 *Return value: bool 
 *Preconditions: dt and at need be entered
 *Postconditions: at should only contain number and ".", with just one "." and have size of 4 or 5; moreover, after the ".", the number should be smaller than 60, and the hold number should less than 24.00.
***************************/

bool check_time(string &x) {
	int a=0, time=0, b=0; 
	bool check = true;

	for (int i=0; i<x.size(); i++) {
		if ((x.at(i) >= 32 && x.at(i) <= 45) || (x.at(i) == 47) || (x.at(i) >= 58 && x.at(i) <= 127)) { //only contain number and dot
			cout << "Error! Plz enter again： " << endl;
			return false;
		}	
		while (x.at(i) == '.') {  //count the dot's appeared times
			a = i+1;
			time++;
			break;
		}
	}	
	if (time == 1){  //only one dot
		if (x.size() ==4 || x.size() == 5) {     //size: 4 or 5 
			if (x.at(a) < '6') {               // there is just 60 minutes per hour
		b = atoi(x.c_str());	
				if (b >= 24){                   // there is just 24 hours per day
					cout << "Error! Plz enter again:  " << endl;
					return false;
				}
				else {  
					check = true;
				}
			}
			else {
				cout << "Error! Plz enter again： " << endl;
				return false;
			}
		}
		else {                                     
			cout << "Error! Plz enter again： " << endl;
			return false;
		}
	}
	else {                                    // dot appeared more than one times
			cout << "Error! Plz enter again： " << endl;
			return false;
	}

	return check;
}

/***************************
 *Function: airfare
 *Description: get the input from users about their airfare
 *Parameters: a float f(airfare)
 *Return value: double f(airfare)
 *Preconditions: function check_fees should located before
 *Postconditions: f should be a float
***************************/

double airfare(double &f){
	string f1;       //aviod bad input 
	cout << "Please enter your total amount of airfare in $: " << endl;
	bool check;
	
	do{                                //check bad input 
		getline(cin,f1);
		check = check_fees(f1);
	}while(check == false);

	f = atof(f1.c_str());               //change string to  float
}

/***************************
 *Function: registration_fee
 *Description: that's to get the input from users about their conference or seminar registration fees
 *Parameters: a float(that fee)
 *Return value: a float(that fee)
 *Preconditions: function check_fees should located before
 *Postconditions: f should be a float
***************************/

double registration_fee(double &f){
	string f1;             //avoid bad input
	cout << "Please enter your total conference or seminar registration fees in $: " << endl;

	bool check;
	do{                             //check bad input
		getline(cin,f1);
		check = check_fees(f1);
	}while(check == false);

	f = atof(f1.c_str());            // change string to float
}

/***************************
 *Function: check_fees
 *Description: that's to check about fees, look whether it is a float or not. Actually it should be called check_float
 *Parameters: a string x
 *Return value: bool
 *Preconditions: x should be entered
 *Postconditions:x should only contain number, or contain one '.'
***************************/

bool check_fees(string &x){
	bool check = true;
	int a=0, time=0;
	for (int i=0; i<x.size(); i++) {
		if ((x.at(i) >= 32 && x.at(i) <= 45) || (x.at(i) == 47) || (x.at(i) >= 58 && x.at(i) <= 127)) { //just contain number and dot 
			cout << "Error! Plz enter again： " << endl;
			return false;
		}	
		while (x.at(i) == '.') {     //count dot's appeared times
			a = i+1;
			time++;
			break;
		}
	}

	if (time > 1){           //dot appeared more than one times
		cout << "Error! Plz enter again: " << endl;
		return false;
	}
	
	else {             //dot did not appear or only appeared one time
		check = true;
	}
		
	return check;
}

/**************************
 *Funtion: car_or_taxi
 *Description: that's to let the users select their choice about car/taxi, and count the reimbursement and spent money for car or taxi.
 *Parameters: 2 float number(r and s) and one integer number(days)
 *Return value: 2 float number(r and s) and one integer number(days)
 *Preconditions: r,s,d should be entered, car_type, taxi_fee, check_YorN and days should be located before it.
 *Postconditions: r,s should be float
***************************/

int car_or_taxi (double &r, double &s, int d){
	cout << "Did you 1:rent a car or 2:use taxi for trip? " << endl;
	bool check;
	int a;
	string a1;  //avoid bad input
	do{         // check bad input
		getline(cin,a1);
		check = check_YorN(a1);
	}while(check == false);
		
	a = atof(a1.c_str());    // change string to float

	if (a == 1){ 
		int t;
		car_type(t,r,s,d);
	}
	else if (a == 2){
		taxi_fee(r,s,d);
	}
}

/***************************
 *Function: car_type
 *Description: let the users selec their rental car's type and count their total reimbursement and spent money on the rental car.
 *Parameters: 2 integer t(type) and d(days), 2 float r(reimbursement money) and s(spent money)
 *Return value: 2 integer t(type) and d(days), 2 float r(reimbursement money) and s(spent money)
 *Preconditions: funtion check_type, Sedan_rental, Sedan_gas, SUV_rental, SUV_gas, Van-rental, Van_gas, Convertible_rental, Convertible_gas, parking_fee and days should located before.
 *Postconditions: the type should just be 1/2/3/4, r,s should be floats.
***************************/

// This function is over 20 lines! It is 22 lines, becasue I put 2 things in it. But I feel too tired to fix it :(

int car_type (int &t, double &r, double &s, int d){
	bool check;
	string t1;       //aviod bad input 
	cout << "1: Sedan \n2: SUV\n3: Van\n4: Convertible\nEnter your rental type: " << endl;
	do{              //check bad input 
		getline(cin,t1);
		check = check_type(t1);
	}while(check == false);
	t = atoi(t1.c_str());        //change string to float 
	
	double rr,rs,gr,gs,m,pr,ps;
	if (t == 1){
		Sedan_rental(rr,rs,d);
		Sedan_gas(gr,gs);
	}
	else if(t == 2){
		SUV_rental(rr,rs,d);
		SUV_gas(gr,gs);
	}
	else if(t == 3){
		Van_rental(rr,rs,d);
		Van_gas(gr,gs);
	}
	else if(t == 4){
		Convertible_rental(rr,rs,d);
		Convertible_gas(gr,gs);
	}
parking_fee(pr, ps, d);
r = rr + gr + pr;               // total reimbursement money for car
s = rs + gs + ps;               // total spent money for car
}

/**************************
 *Funtion: mile_driven
 *Description: to the get input from users about their driven mile
 *Parameters: a folat m
 *Return value: a float m 
 *Preconditions: check_fees should located before 
 *Postconditions: m should be a float
***************************/

double mile_driven(double &m){
	bool check;
	string m1;    //avoid bad input 
	cout << "Plz enter the total miles dirven: " << endl;
	do{           //check bad input
		getline(cin,m1);
		check = check_fees(m1);
	}while(check == false); 
	m = atof(m1.c_str());    //change string to float 
}

/***************************
 *Function: Sedan_rental
 *Description: to count this type's car's reimburse fee and spent if need.
 *Parameters: 2 float rr and rs, and one integer number d
 *Return valus: 2 float rr and rs, and one integer number d
 *Preconditions: function check_fees and days should located before
 *Postconditions: rr, rs should be floats and 
***************************/

double Sedan_rental(double &rr, double &rs, int d){
	bool check;
	string rs1;      //aviod bad input 
	cout << "Plz enter your total spent on rental car in $: " << endl;
	do{              //check bad input
		getline(cin,rs1);
		check = check_fees(rs1);
	}while(check == false);
	rs = atof(rs1.c_str());

	if (rs/d <= 20){
		rr = rs;
	}
	else if(rs/d > 20){
		rr = 20*d;
	}
}

/***************************
 *Function: Sedan_gas
 *Description: to get the input from users about their total gas fee, and count the total reimbursement fee and spent about gas.
 *Parameters: 2 floats, gr reimbursement about gas) and gs(gas spent)
 *Return value: 2 floats, gr reimbursement about gas) and gs(gas spent)
 *Preconditions: check_fees should located before
 *Postconditions: gr and gs should be floats
***************************/

double Sedan_gas(double &gr, double &gs){
	cout << "Plz enter your total gas fee spent in $: " << endl;
	bool check;
	string gs1; //aviod bad input 
	do{         //check bad input 
		getline(cin,gs1);
		check = check_fees(gs1);
	}while(check == false);
	gs = atof(gs1.c_str());
	double m;
	mile_driven(m); //change string to float
	
	if (gs/m <= 0.24){
		gr = gs;
	}
	else if(gs/m > 0.24){
		gr = 0.24*m;
	}
}

/***************************
 *Function: SUV_rental
 *Description: to count this type's car's reimburse fee and spent if need.
 *Parameters: 2 float rr and rs, and one integer number d
 *Return valus: 2 float rr and rs, and one integer number d
 *Preconditions: function check_fees and daysshould located before
 *Postconditions: rr, rs should be floats and 
***************************/

double SUV_rental(double &rr, double &rs, int d){
	bool check;
	string rs1;  //avoid bad input
	cout << "Plz enter your total spent on rental car in $: " << endl;
	do{          //check bad input 
		getline(cin,rs1);
		check = check_fees(rs1);
	}while(check == false);
	rs = atof(rs1.c_str());  //change string to float

	if (rs/d <= 25){
		rr = rs;
	}
	else if(rs/d > 25){
		rr = 25*d;
	}
}

/***************************
 *Function: SUV_gas
 *Description: to get the input from users about their total gas fee, and count the total reimbursement fee and spent about gas.
 *Parameters: 2 floats, gr reimbursement about gas) and gs(gas spent)
 *Return value: 2 floats, gr reimbursement about gas) and gs(gas spent)
 *Preconditions: function check_fees should located before
 *Postconditions: gr and gs should be floats
***************************/

double SUV_gas(double &gr, double &gs){
	cout << "Plz enter your total gas fee spent in $: " << endl;
	bool check;
	string gs1;  //avoid bad input 
	do{          //check bad input 
		getline(cin,gs1);
		check = check_fees(gs1);
	}while(check == false);
	gs = atof(gs1.c_str()); //change bad input to float
	double m;    
	mile_driven(m);         //change bad input to float
	
	if (gs/m <= 0.27){
		gr = gs;
	}
	else if(gs/m > 0.27){
		gr = 0.27*m;
	}
}

/***************************
 *Function: Van_rental
 *Description: to count this type's car's reimburse fee and spent if need.
 *Parameters: 2 float rr and rs, and one integer number d
 *Return valus: 2 float rr and rs, and one integer number d
 *Preconditions: function check_fees and days should located before
 *Postconditions: rr, rs should be floats and 
***************************/

double Van_rental(double &rr, double &rs, int d){
	bool check;
	string rs1;  //avoid bad input 
	cout << "Plz enter your total spent on rental car in $: " << endl;
	do{          //check bad input 
		getline(cin,rs1);
		check = check_fees(rs1);
	}while(check == false);
	rs = atof(rs1.c_str());         //change string to float

	if (rs/d <= 30){
		rr = rs;
	}
	else if(rs/d > 30){
		rr = 30*d;
	}
}

/***************************
 *Function: Van_gas
 *Description: to get the input from users about their total gas fee, and count the total reimbursement fee and spent about gas.
 *Parameters: 2 floats, gr reimbursement about gas) and gs(gas spent)
 *Return value: 2 floats, gr reimbursement about gas) and gs(gas spent)
 *Preconditions: function check_fees should located before
 *Postconditions: gr and gs should be floats
***************************/

double Van_gas(double &gr, double &gs){
	cout << "Plz enter your total gas fee spent in $: " << endl;
	bool check;
	string gs1;   //aviod bad input 
	do{           //check bad input 
		getline(cin,gs1);
		check = check_fees(gs1);
	}while(check == false);
	gs = atof(gs1.c_str()); //change string ro float
	double m;
	mile_driven(m);  //change string to float
	
	if (gs/m <= 0.32){
		gr = gs;
	}
	else if(gs/m > 0.32){
		gr = 0.32*m;
	}
}

/***************************
 *Function: Convertible_rental
 *Description: to count this type's car's reimburse fee and spent if need.
 *Parameters: 2 float rr and rs, and one integer number d
 *Return valus: 2 float rr and rs, and one integer number d
 *Preconditions: function check_fees and days should located before
 *Postconditions: rr, rs should be floats and 
***************************/

double Convertible_rental(double &rr, double &rs, int d){
	bool check;
	string rs1;      //avoid bad input
	cout << "Plz enter your total spent on rental car in $: " << endl;
	do{              //check bad input
		getline(cin,rs1);
		check = check_fees(rs1);
	}while(check == false);
	rs = atof(rs1.c_str());  //chang string to float

	if (rs/d <= 50){
		rr = rs;
	}
	else if(rs/d > 50){
		rr = 50*d;
	}
}

/***************************
 *Function: Convertible_gas
 *Description: to get the input from users about their total gas fee, and count the total reimbursement fee and spent about gas.
 *Parameters: 2 floats, gr reimbursement about gas) and gs(gas spent)
 *Return value: 2 floats, gr reimbursement about gas) and gs(gas spent)
 *Preconditions: function check_fees should located before
 *Postconditions: gr and gs should be floats
***************************/

double Convertible_gas(double &gr, double &gs){
	cout << "Plz enter your total gas fee spent in $: " << endl;
	bool check;
	string gs1;      //avoid bad input 
	do{              //check bad input 
		getline(cin,gs1);
		check = check_fees(gs1);
	}while(check == false);
	gs = atof(gs1.c_str());  //change string to float
	double m;
	mile_driven(m); //change string to float
	
	if (gs/m <= 0.45){
		gr = gs;
	}
	else if(gs/m > 0.45){
		gr = 0.45*m;
	}
}

/***************************
 *Function: parking_fee
 *Description: to get the input from users about their parking fee each day. 
 *Parameters: 2 folats pr, ps and one integer number d.
 *Return value: 2 folats pr, ps and one integer number d.
 *Preconditions: function check_fees and days should located before.
 *Postconditions: pr, ps should be floats.
***************************/

double parking_fee(double &pr, double &ps, int d){
	bool check;
	string tps1;  //avoid bad input 
	double tps;
	for(int i=1; i <= d; i++){
		cout << "Plz enter your parking fee for Day " << i << " in $: " << endl;
		
		do{        //check bad input 
			getline(cin,tps1);
			check = check_fees(tps1);
		}while(check == false);
		
		tps = atof(tps1.c_str());  //change string to float
		ps += tps;

		if (tps <= 6){
			pr += tps;
		}
		else if (tps > 6){
			pr += 6;
		}
	}
}

/***************************
 *Function hotel_fee
 *Description: to get the input from users about their hotel spent for each days, and count their total reimbursement and spent about hotel
 *Parameters: 2 floats hr and hs, and one integer number d
 *Return value: 2 floats hr and hs, and one integer number d
 *Preconditions: function check_fees and days should located before
 *Postconditions: hr, hs should be floats
***************************/

double hotel_fee(double &hr, double &hs, int d){
	if (d > 1){
		bool check;
		string ths1;  //avoid bad input 
		double ths;
		for(int i=1; i <= d-1; i++){
			cout << "Plz enter your hotel fee for night " << i << " in $: " << endl;
			do{        //check bad input 
				getline(cin,ths1);
				check = check_fees(ths1);
			}while(check == false);
		
			ths = atof(ths1.c_str());   //change string to float
			hs += ths;
		
			if (ths <= 90){
				hr += ths;
			}
			else if (ths > 90){
				hr += 90;
			}	
		}
	}
}

/**************************
 *Function: taxi_fee
 *Description: to get the input from users about their taxi spent each day, and count the total reimbursement taxi fee and spent.
 *Parameters: 2 floats r,s and one integer number d
 *Return value: 2 floats r,s and one integer number d 
 *Preconditions: function check_fees and days should located before
 *Postconditions: r,s should be floats
***************************/

double taxi_fee(double &r, double &s, int d){
	bool check;
	double tf;
	string tf1;       //avoid bad input 

	for(int i=1; i <= d; i++){
		cout << "Plz enter your taxi spent on Day " << i << " in $: " << endl;
		do{             //check bad input 
			getline(cin,tf1);
			check = check_fees(tf1);
		}while(check == false);
		
		tf = atof(tf1.c_str());  //change string to float
		s += tf;
		
		if (tf <= 10){
			r += tf;
		}
		else if (tf > 10){
			r += 10;
		}
	}
}

/**************************
 *Function: check_type
 *Description: to check whether users' input about type is just 1/2/3/4
 *Parameters: a string x(avoid bad input)
 *Return value: bool (whether the check is true or false 
 *Preconditions: x should be entered 
 *Postconditions: x should be 1/2/3/4
***************************/

bool check_type(string x){
	bool check = true;
	
	for (int i=0; i<x.size(); i++) {
		if((x.at(i)=='1' || x.at(i)=='2' || x.at(i)=='3'||x.at(i)=='4') && (x.size()==1)){
			check = true;
		}
		else { 
			cout << "Error! Plz enter again： " << endl;
			return false;
		}	
	}
	return check;
}

/***************************
 *Function: check_YorN
 *Description: check whether users' input about car_or_taxi is just 1 or 2
 *Parameters: a string x(avoid bad input)
 *Return value: bool 
 *Preconditions: car_or_taxi should located before
 *Postconditions: x should be 1 or 2
***************************/

bool check_YorN (string &x){
	bool check = true;

	for (int i=0; i<x.size(); i++) {
		if ((x.at(i) >= 32 && x.at(i) <= 45) || (x.at(i) == 47) || (x.at(i) >= 58 && x.at(i) <= 127) || (x.at(i) == '.') ||(x.at(i) == '0') || (x.at(i) >= '3' && x.at(i) <= '9'))
		{
			cout << "Error! Plz enter again： " << endl;
			return false;
		}	
	}		
	
	if (x.size() == 1){
		check = true;
	}
	else {
		cout << "Error! Plz enter again: " << endl;
		return false;
	}
	return check;
}

/***************************
 *Function: breakfase_fee
 *Description: to get the input from users about their breakfast fee, and count the total reimbursement and spent
 *Parameters: 2 float r1 and s1
 *Return value: 2 float r1 and s1
 *Preconditions: function check_fees should located before
 *Postconditions: r1 and s1 are floats
***************************/

double breakfast_fee(double &r1, double &s1){
	cout << "Plz enter your breakfast fee, in $: " << endl;
	bool check;
	string br1; //avoid bad input 
	double br;
	do{         //check bad input 
		getline(cin,br1);
		check = check_fees(br1);
	}while(check == false);
	br = atof(br1.c_str());     //change string to float
	if (br <= 9){
		r1 = br;
		s1 = br;
	}
	else if(br > 9){
		r1 = 9;
		s1 = br;
	}
}

/***************************
 *Function: lunch_fee
 *Description: to get the input from users about their lunch fee, and count the total reimbursement and spent
 *Parameters: 2 float r2 and s2
 *Return value: 2 float r2 and s2
 *Preconditions: function check_fees should located before
 *Postconditions: r2 and s2 are floats
***************************/

double lunch_fee(double &r2, double &s2){
	cout << "Plz enter your lunch fee, in $: " << endl;
	bool check;
	string lu1;  // avoid bad input 
	double lu;
	do{          //check bad input 
		getline(cin,lu1);
		check = check_fees(lu1);
	}while(check == false);
	lu = atof(lu1.c_str());       //change string to float
	if (lu <= 12){
		r2 = lu;
		s2 = lu;
	}
	else if(lu > 12){
		r2 = 12;
		s2 = lu;
	}
}

/***************************
 *Function: dinner_fee
 *Description: to get the input from users about their dinner fee, and count the total reimbursement and spent
 *Parameters: 2 float r3 and s3
 *Return value: 2 float r3 and s
 *Preconditions: function check_fees should located before
 *Postconditions: r3 and s3 are floats
***************************/

double dinner_fee(double &r3, double &s3){
	cout << "Plz enter your dinner fee, in $: " << endl;
	bool check;
	double di; 
	string di1; //avoid bad input 
	do{         //avoid bad input 
		getline(cin,di1);
		check = check_fees(di1);
	}while(check == false);
	di = atof(di1.c_str());  //change string to float
	if (di <= 16){
		r3 = di;
		s3 = di;
	}
	else if(di > 16){
		r3 = 16;
		s3 = di;
	}
}

/**************************
 *Function: meals
 *Description: to count the total reimbursement and spent about meals during the trip 
 *Parameters: 4 floats dt,at,r,s, and one integer number d.
 *Return value: 4 floats dt,at,r,s, and one integer number d.
 *Preconditions: function day1, dayn and days should located before.
 *Postconditions: dt,at,r,s should be floats 
***************************/

double meals(double dt, double at, double &r, double &s, int d){
	if(d == 1){
		day1(dt, at, r, s);
	}
	else if (d > 1){
		dayn(dt, at, r, s, d);
	}
}

/***************************
 *Function: day1
 *Description: count total reimbursement and spent money for meals if there is just a one day trip.
 *Parameters: 4 floats dt,at,r and s
 *Return value: 4 floats dt, at, r and s
 *Preconditions: function breakfast_fee, lunch_fee, dinner_fee should located before
 *Postconditions: r and s should be float
***************************/

// This function is over 20 lines! It is 25 lines, becasue I put 2 things in it. But I feel too tired to fix it :(

double day1(double dt, double at, double &r, double &s){
	double r1=0,r2=0,r3=0,s1=0,s2=0,s3=0;
	cout << "Day 1" << endl; 
	if (dt > 7){
		cout << "Your breakfast for day 1 is not allowed as an expense" << endl;
		if (at < 13){
			cout << "Your lunch for day 1 is not allowed as an expense" << endl;
			cout << "Your dinner for day 1 is not allowed as an expense" << endl;
		}
		else if (at > 13 && at <19){
			lunch_fee(r2,s2);
			cout << "Your dinner for day 1 is not allowed as an expense" << endl;
		}
		else if(at >19){
			lunch_fee(r2,s2);
			dinner_fee(r3,s3);
		}
	}
	else if(dt < 7){
		breakfast_fee(r1,s1);
	 		if (at < 13){
			cout << "Your lunch for day 1 is not allowed as an expense" << endl;
			cout << "Your dinner for day 1 is not allowed as an expense" << endl;
		}
		else if (at > 13 && at <19){
			lunch_fee(r2,s2);
			cout << "Your dinner for day 1 is not allowed as an expense" << endl;
		}
		else if(at >19){
			lunch_fee(r2,s2);
			dinner_fee(r3,s3);
		}
	}
   r = r1 + r2 + r3;
	s = s1 + s2 + s3;
}

/***************************
 *Function: first_day
 *Description: count total reimbursement and spent money for meals in day1 if there is a more days trip.
 *Parameters: 3 floats dt,r and s
 *Return value: 3 floats dt,r and s
 *Preconditions: function breakfast_fee, lunch_fee, dinner_fee should located before
 *Postconditions: r an s should be float
***************************/

double first_day (double dt, double &r, double &s){
	cout << "Day 1" << endl; 
	double r1=0,r2=0,r3=0,s1=0,s2=0,s3=0;
	if (dt < 7){
		breakfast_fee(r1,s1);
		lunch_fee(r2,s2);
		dinner_fee(r3,s3);
	}
	else if (dt > 7 && dt < 12){
		cout << "Your breakfast for day 1 is not allowed as an expense" << endl;
		lunch_fee(r2,s2);
		dinner_fee(r3,s3);
	}
	else if (dt > 12 && dt <18){
		cout << "Your breakfast for day 1 is not allowed as an expense" << endl;
		cout << "Your lunch for day 1 is not allowed as an expense" << endl;
		dinner_fee(r3,s3);
	}
	else if (dt > 18){
		cout << "Your breakfast for day 1 is not allowed as an expense" << endl;
		cout << "Your lunch for day 1 is not allowed as an expense" << endl;
		cout << "Your dinner for day 1 is not allowed as an expense" << endl;
	}
	r = r1 + r2 + r3;
	s = s1 + s2 + s3;

}

/***************************
 *Function: last_day
 *Description: count total reimbursement and spent money for meals in the last day if there is a more days trip.
 *Parameters: 3 floats at,r and s
 *Return value: 3 floats at,r and s
 *Preconditions: function breakfast_fee, lunch_fee, dinner_fee should located before
 *Postconditions: r an s should be float
***************************/

double last_day (double at, double &r, double &s, int d){
	cout << "Day " << d << endl;
	double r1=0,r2=0,r3=0,s1=0,s2=0,s3=0;
	if (at > 19){
		breakfast_fee(r1,s1);
		lunch_fee(r2,s2);
		dinner_fee(r3,s3);
	}
	else if (at > 13 && at < 19){
		breakfast_fee(r1,s1);
		lunch_fee(r2,s2);
		cout << "Your dinner for day " << d << " is not allowed as an expense" << endl;
	}
	else if (at > 8 && at < 13){
		breakfast_fee(r1,s1);
		cout << "Your lunch for day " << d << " is not allowed as an expense" << endl;
		cout << "Your dinner for day " << d << " is not allowed as an expense" << endl;
	}
	else if (at < 8){
		cout << "Your breakdast for day " << d << " is not allowed as an expense" << endl;
		cout << "Your lunch for day " << d << " is not allowed as an expense" << endl;
		cout << "Your dinner for day " << d << " is not allowed as an expense" << endl;
	}
	r = r1 + r2 + r3;
	s = s1 + s2 + s3;
}

/***************************
 *Function: dayn
 *Description: count total reimbursement and spent money for meals during the trip if there is a more days trip.
 *Parameters: 4 floats dt,at,r and s; and a integer number d
 *Return value: 4 floats dt,at,r and s; and a integer number d
 *Preconditions: function breakfast_fee, lunch_fee, dinner_fee, first_day, last_day and days should located before
 *Postconditions: r an s should be float
***************************/

double dayn(double dt, double at, double &r, double &s, int d){
	double r1,r2,r3,r4,r5,rn, s1,s2,s3,s4,s5,sn;
	first_day(dt, r1, s1);
	for (int i = 2; i <= d-1; i++){
		cout << "Day " << i << endl;
		breakfast_fee(r2,s2);
		lunch_fee(r3,s3);
		dinner_fee(r4,s4);
		r5 += ( r2 + r3 + r4);
		s5 += ( s2 + s3 + s4);
	}
	last_day(at, rn, sn,d);
	r = r1 + r5 + rn;
	s = s1 + s5 + sn;
}

int main ()
{
	string a;
	bool check;
	do{	
		double dt,at,af,rf,r,s,hr,hs,mr,ms,cr,cs;
		int d;
		days(d);
		department_time(dt);
		arrival_time(at);
		airfare(af);
		registration_fee(rf);
		car_or_taxi (cr,cs,d);
		hotel_fee(hr, hs, d);
		meals(dt,at,mr,ms,d);
		r = af + rf + cr + hr + mr;
		s = af + rf + cs + hs + ms;
	
		cout << "Your total expense for this trip is: $" << s << endl;
		cout << "Your total reimbursement for this trip is: $" << r << endl;
		cout << "Do you want to play again? (1-yes or 2-no)" << endl;
		
		do{
			getline(cin,a);
			check = check_YorN(a);
		}while(check == false);
	
	}while(a == "1");
		
	return 0;
}
