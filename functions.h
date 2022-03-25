#pragma once
#include"Tenant.h"

Tenant* set_up(int& n); //intialize existing tenants from file to dynamic array 
Tenant* saving_tenant(Tenant* list, int& n); //saving a new tenant to dynamic array
int line_count(char* filename); //counting how many lines file has
Tenant search_in_array(Tenant* list, int num, bool& found); //searching function in the array of tenant
Tenant* remove(Tenant* list, int& n); //remove tenant from dynamic array if exist 
void display(Tenant* list, int n); //displays tenant if exist
void wr_to_file(Tenant* list, int n); //writes from dynamic array to tenants.txt file
Tenant* change_room(Tenant* list, int n); //changes tenant's room if exist
Tenant* change_dorm(Tenant* list, int n);////changes tenant's dorm if exist

