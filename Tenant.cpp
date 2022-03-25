#include "Tenant.h"
#include <iostream>
#include <algorithm>

using namespace std;
void Tenant::set_new()
{
	Student::set_Student(); //call set_Student function from Student class
	Dorm::set_Dorm(); //call set_Dormm function from dorm class
}

Tenant::~Tenant()
{
	Student::~Student(); // call destructor of Student
	Dorm::~Dorm(); //call destructor of Dorm
}

void Tenant::set_new_room()
{
	cout << "Which room to change:"; 
	cin >> RoomNum;
}

void Tenant::set_new_dorm()
{
	cout << "Which dorm to change:";
	cin >> DormName;
}

const Tenant Tenant::operator =(const Tenant& theother) //operator= overloading
{
	Fname = theother.Fname;
	Lname = theother.Lname;
	email = theother.email;
	PhoneNum = theother.PhoneNum;
	NeptunCode = theother.NeptunCode;
	Degree = theother.Degree;
	DormName = theother.DormName;
	RoomNum = theother.RoomNum;
	return *this;

}

void Tenant::Save(std::ostream& f1) 
{
	if (!f1)
		throw 100; //error number for file opening
	f1 <<Fname <<';' <<Lname << ';' <<email << ';' << PhoneNum << ';';
	f1 <<NeptunCode << ';' << Degree << ';' << DormName << ';' <<RoomNum << endl;
}

void Tenant::Load(std::istream& f2)
{
	
	if (!f2)
		throw 100; //error number for file opening
	string fname;
	if (getline(f2, fname, ';') && getline(f2, Lname, ';') && getline(f2, email, ';') && getline(f2, PhoneNum, ';')
		&& getline(f2, NeptunCode, ';') && getline(f2, Degree, ';') && getline(f2, DormName, ';') && getline(f2, RoomNum))
		Fname = fname;
	else
		throw 200; // error number for loading tenant into file

}


bool iequals(const string& a, const string& b)
{
	return std::equal(a.begin(), a.end(),
		b.begin(), b.end(),
		[](char a, char b) {
			return tolower(a) == tolower(b);
		});
}

bool Tenant:: operator == (const Tenant& theother)
{
	return (iequals(this->Fname, theother.Fname) && iequals(this->Lname, theother.Lname));
}

void Tenant::show_tenant()
{
	cout << "First Name: " << Fname << endl;
	cout << "Last Name: " << Lname << endl;
	cout << "Email: " << email << endl;
	cout << "Phone number: " << PhoneNum << endl;
	cout << "Neptun code: " << NeptunCode << endl;
	cout << "Scintific degree: " << Degree << endl;
	cout << "Dorm: " << DormName << endl;
	cout << "Room number: " << RoomNum << endl << endl;
}


