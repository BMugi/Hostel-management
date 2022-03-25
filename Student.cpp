#include "Student.h"
#include <iostream>
using namespace std;

void Student::set_Student()
{
	Person::set_Person();
	cout << "Please enter Neptun code:";
	cin >> NeptunCode;//initialize Neptun code by user's entered variable
	cout << "Please enter which scientefic degree:";
	cin >> Degree;//initialize scientific degree by user's entered variable
}

Student::~Student()
{
	Person::~Person(); // call Person class' destructor
	NeptunCode.clear(); //clear string 
}
