#pragma once
#include<string>
#include<iostream>
using namespace std;

class Dorm // abstract base class of tenant class
{
protected:
	string RoomNum;
	string DormName;
public:
	void set_Dorm(); //initialize dorm 
	~Dorm();
	virtual void set_new_room()=0; // allows change room number
	virtual void set_new_dorm()=0; // allows change dorm 
};

