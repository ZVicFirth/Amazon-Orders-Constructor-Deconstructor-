/*Name:  Zachary Firth        Z#  : Z23543282
Course : Foundations of Computer Science(COP3014)
Professor : Dr.Lofton Bullard
Due Date : 4/25/22   Due Time: 11:59PM
Total Points: 20
Assignment #12: amazon_porders11.cpp
Description : Separate the declarations, the implementations, and the driver of the program into their own files
and print out the amazon order records as an array.
*/


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>


#include "order_class.h"



//driver to test the functionality of your class.
int main()
{
	class order_record
	{
	public:
		string cell_number;
		string item_number;
		double quantity;
		double price;
		int processing_plant;
		double tax_rate;
		double order_tax;
		double net_cost;
		double total_cost;
	};
	order_class myOrders;//declaring order_class object myOrders; the default constructor is called automically.
		cout << "**********************************************************************\n";
	//Test 1:
	cout << "Test 1: Testing default construcor, double_size, process, is_full and operator<< " << endl;
		myOrders.process();
	cout << myOrders;
	cout << "End of Test 1" << endl;
	cout <<
		"**********************************************************************\n";
	cout <<
		"**********************************************************************\n";
	//Test 2:
	void add();
	cout << "Test 2: Testing add, double_size, process, is_full, and operator<< "
		<< endl;
	myOrders.add();
	cout << myOrders;
	cout << "End of Test 2" << endl;
	cout <<
		"**********************************************************************\n";
	cout <<
		"**********************************************************************\n";
	//Test 3:
	void remove(string key);
	cout << "Test 3: Testing operator-, is_Empty, search and operator<< " <<
		endl;
	cout << "Removing 954632155, 7877176590, and 3051234567\n";
	myOrders - "9546321555" - "7877176590" - "3051234567";
	cout << myOrders;
	cout << "Removing 9546321555 ---AGAIN--- SHOULD GET MESSAGE\n";
	myOrders - "9546321555";
	cout << myOrders;
	cout << "End of Test 3" << endl;
	cout <<
		"**********************************************************************\n";
	cout <<
		"**********************************************************************\n";
	//Test 4:
	//copy constructor
	cout << "Test4: Testing copy constructor\n\n";
	order_class yourOrders = myOrders;
	cout << yourOrders << endl;
	cout << "End of Test 4" << endl;
	cout <<
		"**********************************************************************\n";
	cout <<
		"**********************************************************************\n";
	//Test 5:
	//destructor will be invoked when object myOrders goes out of scope
	cout << "Test 5: Destructor called" << endl;
	cout << "End of Test 5" << endl;
	cout <<
		"**********************************************************************\n";
	cout <<
		"**********************************************************************\n";
	return 0;
}
