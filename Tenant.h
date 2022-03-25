#pragma once
#include "Student.h"
#include "Dorm.h"
#include "ISerializable.h" // needed for iequals function
class Tenant :
	public Student, public Dorm, public ISerializable // 3 base classes
{
public:
	void set_new();
	~Tenant();
	void set_new_room(); //implementation of visuol function from Dorm class. allows change room number
	void set_new_dorm(); //implementation of visuol function from Dorm class. allows change dorm 
	const Tenant operator =(const Tenant& theother); // operatar overloading. it will be used in the search function
	void Save(std::ostream&); //implementation of visuol function from ISeriazible class. save a single tenant into file
	void Load(std::istream&); //implementation of visuol function from ISeriazible class. load a single tenant from file
	bool operator == (const Tenant& theother); //compares two tenants by first and last name 
	void show_tenant (); // show all datas of tenant

};

bool iequals(const string& a, const string& b); // taken from internet. it compares two string in lower case


