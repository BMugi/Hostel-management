#include "functions.h"
#include <iostream>
#include <fstream>
#include<string>
using namespace std;

Tenant* set_up(int& n) //intialize existing tenants from file to dynamic array 
{
	n = line_count((char*)"tenants.txt"); //checking how many lines in the file (1 line=1 tenant).
	if (n != 0) //if in the file exist tenant  
	{
		ifstream f1("tenants.txt"); //opens tenants.txt file 
		if (!f1)
			throw 100; //exception handling if file is not opened
		Tenant* list = new Tenant[n]; //initialize new dynamic array of tenant
		for (int i = 0; i < n; ++i)
		{
			try
			{
				list[i].Load(f1); //loading tenant from file 
			}
			catch (int x)
			{
				if (x == 100)
					cerr << "Can not open tenants.txt file." << endl;
				else if (x == 200)
					cerr << "Error occured during loading from file to array." << endl;
			}
		}
		return list;
		f1.close(); // closing file 
	}
	else
		return NULL;
}

Tenant* saving_tenant(Tenant* list,int& n) //saving a new tenant to dynamic array
{
	if (list != NULL)
	{
		Tenant* tmp = new Tenant[n + 1];//initialize new dynamic array of tenant
		for (int i = 0; i < n; ++i)
		{
			tmp[i] = list[i]; 
		}
		tmp[n].set_new(); // setting new tenant at last element of array of tenant
		++n;
		delete[] list; //delete pointer that points previous array of tenant 
		list = tmp;
		return list;
	}
	else
	{
		Tenant* n_list = new Tenant[n + 1];
		n_list[n].set_new();
		++n;
		return n_list;
	}
}

int line_count(char* filename) //counting how many lines file has
{
	int num_of_lines = 0;
	string line; 
	ifstream f4(filename); //opens file
	if (!f4)
		throw 100; //exception handling if can not open file
	while (getline(f4, line)) 
	{
		++num_of_lines;
	}
	return num_of_lines; 
	f4.close();
	
}

Tenant* remove(Tenant* list, int& n) //remove tenant from dynamic array
{ 
	if (n == 0)
		throw 103;//excepction handling if file is empty
	bool found;
	Tenant* tmp = new Tenant[n - 1];
	try
	{
		Tenant t = search_in_array(list, n, found);
		for (int i = 0, j = 0; i < n; ++i, ++j)
		{
			if (t == list[i])
			{
				--j;
				t.~Tenant(); // calling destruction for founded tenant
			}
			else
				tmp[j] = list[i]; // copying from previous array of tenant to new array 
		}
		--n;
		delete[]list; // delete pointer that points previous array of tenant 
		cout << "Tenant successfully removed!"<<endl;
		return tmp; 
	}
	catch (int x)
	{
		if (x == 101)
			cerr << "Error: No tenant found" << endl;
	}

}

Tenant search_in_array(Tenant* list, int num, bool& found) //searching function in the array of tenant
{
	string fname;
	cout << "Enter First name of tenant: ";
	cin >> fname;
	found = false;
	for (int i = 0; i < num; ++i)
	{
		if (iequals(fname,list[i].getFname())) //using iequals to compare 2 string in lower case
		{
			return list[i]; //returns founded tenant
			found = true;
		}
	}
	if (!found)
		throw 101; //excepction handling 
}

void display(Tenant* list, int n) //displays tenant
{
	bool found;
	try
	{
		Tenant t = search_in_array(list, n, found); //searching tenant and getting that one
		t.show_tenant(); //shows data of found tenant
	}
	catch (int x)
	{
		if (x==101)
			cerr<< "Error: No tenant found" << endl;
	}
}

void wr_to_file(Tenant* list, int n) //writes from dynamic array to tenants.txt file
{
	ofstream f1("tenants.txt", ios::trunc); // overwrites tenants.txt file 
	if (!f1)
		throw 100; //excepction handling 
	for (int i = 0; i < n; ++i)
	{
		list[i].Save(f1); //saving into file
	}
	f1.close(); //closing file 
}

Tenant* change_room(Tenant* list, int n) //changes tenant's room
{
	try {
		Tenant t;
		Tenant* tmp=new Tenant[n];
		bool found;
		t = search_in_array(list, n, found); //searches tenant
		t.set_new_room(); //using tenant's method to change room 
		for (int i = 0; i < n; ++i)
		{
			if (t == list[i])
				tmp[i] = t; //found tenant replaces element of array
			else 
				tmp[i] = list[i]; //copying 
		}
		delete[] list;
		return tmp; //returning array with changed tenant
	}
	catch (int x)
	{
		if (x==101)
			cerr<< "Error: No tenant found" << endl;
	}
}

Tenant* change_dorm(Tenant* list, int n) //changes tenant's dorm. same to change room function.
{
	try {
		Tenant t;
		Tenant* tmp = new Tenant[n];
		bool found;
		t = search_in_array(list, n, found); //searches tenant
		t.set_new_dorm();//using Tenant method to change dorm 
		for (int i = 0; i < n; ++i)
		{
			if (t == list[i])
				tmp[i] = t;//found tenant replaces element of array
			else
				tmp[i] = list[i];//copying 
		}
		delete[] list;
		return tmp; //returning array with changed tenant
	}
	catch (int x)
	{
		if (x == 101)
			cerr << "Error: No tenant found" << endl;
	}
}
