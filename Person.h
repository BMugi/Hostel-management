#pragma once
#include<string>
using namespace std;
class Person //base class of student

{
protected:
	string Lname; // last name
	string Fname; // first name
	string email;
	string PhoneNum;
public:
	void set_Person(); //initialize person
	~Person(); 
	string getFname();
	string getLname();
};

