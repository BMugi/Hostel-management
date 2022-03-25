#include "Person.h"
#include <iostream>
using namespace std;

void Person::set_Person()
{
	cout << "Enter a first name:";
	cin >> Fname; //initialize First name by user's entered variable
	cout << "Enter a last name:";
	cin >> Lname;//initialize Last name by user's entered variable
	cout<< "Enter an email address:";
	cin >> email;//initialize email by user's entered variable
	cout<< "Enter a phome number:";
	cin >> PhoneNum;//initialize Phone number by user's entered variable
}

Person::~Person()
{
	Fname.clear(); //clear string 
	Lname.clear(); //clear string 
	email.clear(); //clear string 
	PhoneNum.clear(); //clear string 
}

string Person::getFname()
{
	return Fname; // return First name
}


string Person::getLname()
{
	return Lname; //return Last name
}