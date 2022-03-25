#pragma once
#include "Person.h"
#include<string>
using namespace std;


class Student : //base class of tenant
	public Person
{
protected:
	string NeptunCode; 
	string Degree; //scientific degree of student
public:
	void set_Student(); //initialize student
	~Student();
};

