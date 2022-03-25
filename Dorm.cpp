#include "Dorm.h"
#include <iostream>
using namespace std;

void Dorm::set_Dorm()
{
	cout << "Please enter in which dorm to move:"; 
	cin >> DormName; //initialize Dorm's name by user's entered variable
	cout << "Please enter in which room to move:";
	cin >> RoomNum;//initialize Room number by user's entered variable
	cout << endl;

}

Dorm::~Dorm()
{
	DormName.clear(); //clear string 
	RoomNum.clear(); //clear string
}
