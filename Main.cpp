#include <iostream>
#include "Tenant.h"
#include"functions.h"
#include <fstream>
using namespace std;


int main()
{
	int num = 0; //number of tenants
	char choice;
	try
	{
		Tenant* tenants = set_up(num);
		cout << "        MAIN MENU" << endl << endl;
		cout << "1) Add  a new tenant." << endl;
		cout << "2) Remove a tenant." << endl;
		cout << "3) Display a tenant." << endl;
		cout << "4) Change a room." << endl;
		cout << "5) Change a dorm." << endl;
		cout << "0) Exit" << endl;
		cout << endl << "Please choose one of options: ";

		cin >> choice;
		while (choice != 0)
		{
			switch (choice)
			{
			case '1': //Add a new tenant
			{
				tenants = saving_tenant(tenants, num);
				cout << "        MAIN MENU" << endl << endl;
				cout << "1) Add  a new tenant." << endl;
				cout << "2) Remove a tenant." << endl;
				cout << "3) Display a tenant." << endl;
				cout << "4) Change a room." << endl;
				cout << "5) Change a dorm." << endl;
				cout << "0) Exit" << endl;
				cout << endl << "Please choose one of options: ";
				cin >> choice;
			}continue;


			case '2'://Delete tenant
			{
				try {
						tenants = remove(tenants, num); 
					}
					catch (int x)
					{
						if (x == 103)
							cerr << "No tenants at all!" << endl;
						break;
					}
				
				cout << "        MAIN MENU" << endl << endl;
				cout << "1) Add  a new tenant." << endl;
				cout << "2) Remove a tenant." << endl;
				cout << "3) Display a tenant." << endl;
				cout << "4) Change a room." << endl;
				cout << "5) Change a dorm." << endl;
				cout << "0) Exit" << endl;
				cout << endl << "Please choose one of options: ";
				cin >> choice;
			}continue;

				case '3': // Display tenant
				{
							display(tenants, num);
					
					cout << "        MAIN MENU" << endl << endl;
					cout << "1) Add  a new tenant." << endl;
					cout << "2) Remove a tenant." << endl;
					cout << "3) Display a tenant." << endl;
					cout << "4) Change a room." << endl;
					cout << "5) Change a dorm." << endl;
					cout << "0) Exit" << endl;
					cout << "Please choose one of options: ";
					cin >> choice;
				}continue;

				case '4': // change a room 
				{
					
					tenants = change_room(tenants, num);
					cout << "        MAIN MENU" << endl << endl;
					cout << "1) Add  a new tenant." << endl;
					cout << "2) Remove a tenant." << endl;
					cout << "3) Display a tenant." << endl;
					cout << "4) Change a room." << endl;
					cout << "5) Change a dorm." << endl;
					cout << "0) Exit" << endl;
					cout << "Please choose one of options: ";
					cin >> choice;
				}continue;

				case '5'://Change a dorm
				{
				
					tenants = change_dorm(tenants, num);
	
			
					cout << "        MAIN MENU" << endl << endl;
					cout << "1) Add  a new tenant." << endl;
					cout << "2) Remove a tenant." << endl;
					cout << "3) Display a tenant." << endl;
					cout << "4) Change a room." << endl;
					cout << "5) Change a dorm." << endl;
					cout << "0) Exit" << endl;
					cout << "Please choose one of options: ";
					cin >> choice;
				}continue;

				case '0': break;
				default: //if invalid variable is entered
				{
					cout << "Please enter right variable!!! Please choose one of options:";
					cin >> choice;
				}continue;

			}
			break; // breaks first while loop
		}

		wr_to_file(tenants, num);
	}
	catch (int x)
	{
		if (x == 100)
			cerr << "Can not open tenants.txt file." << endl;
	}

	return 0;
}