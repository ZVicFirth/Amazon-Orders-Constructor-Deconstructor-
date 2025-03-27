#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "order_class.h"
using namespace std;


	//Name: default constructor
	//Precondition: The contructor for INV has not been called.
	//Postcondition: The contructor for INV has been called.
	//Decription: Reads the data file of purchase order information (cell number, item,
	//quantity, price, and processing plant) into the dynamic array of order records,
	//INV. If the count become equal to the size the function double_size is called and
	//the memory allocated to INV is doubled.
	order_class::order_class()
	{
		count = 0;
		size = 1;
		INV = new order_record[size];
		std::cout << "The default constructor has been called\n";
		ifstream in;
		in.open("purchase_data.txt");
		while (!in.eof())
		{
			if (count == size)
			{
				order_class::double_size();
			}
			in >> INV[count].cell_number >> INV[count].item_number >> INV[count].quantity
				>> INV[count].price >> INV[count].processing_plant;
			count++;
		}
		in.close();
	}

	//Name: copy constructor
	//Precondition: A deep copy has not been done.
	//Postcondition: A deep copy has been done.
	//Decription: performs a deep copy.
	order_class::order_class(const order_class& org)
	{
		(*this).count = org.count;
		this->size = org.count;

		INV = new order_record[size];

		for (int i = 0; i < count; i++)
		{
			INV[i] = org.INV[i];
		}
	}

	//Name: is_Empty
	//Precondition: INV has not been confirmed to be empty.
	//Postcondition: INV has been confirmed to be empty.
	//Decription: returns true if INV is empty.
	bool order_class::is_Empty()
	{
		return count == 0;
	}

	//Name: is_full 
	//Precondition: INV has not been confirmed to be full.
	//Postcondition: INV has been confirmed to be full.
	//Decription: returns true if INV is full.
	bool order_class::is_full()
	{
		return count == size;
	}

	//Name: search
	//Precondition: A certain element (key) of INV has not been selected.
	//Postcondition: A certain element (key) of INV has been selected.
	//Decription: locates key in INV if it is there; otherwise -1 is returned.
	int order_class::search(const string key)
	{
		for (int i = 0; i < count; i++)
		{
			if (INV[i].cell_number == key)
			{
				return i;
			}
		}
		return -1;
	}

	//Name: add
	//Precondition: An element has not been added to INV.
	//Postcondition: An element has been added to INV.
	//Decription: adds a call_record to INV; if INV is full, double_size is called to 
	//increase the size of INV.The user
	//is prompted to enter the cell number, item, quantity, price, and 
	//processing plant.
	void order_class::add()
	{
		if (order_class::is_full())
		{
			order_class::double_size();
		}
		else
		{
			std::cout << "Enter the cell number: ";
			cin >> INV[count].cell_number;
			std::cout << "Enter the item number: ";
			cin >> INV[count].item_number;
			std::cout << "Enter the quantity: ";
			cin >> INV[count].quantity;
			std::cout << "Enter the price: ";
			cin >> INV[count].price;
			std::cout << "Enter the processing plant: ";
			cin >> INV[count].processing_plant;
			count++;
			order_class::process();
		}
	}

	//Name: double_size
	//Precondition: The size of INV has not been doubled.
	//Postcondition: The size of INV has been doubled.
	//Decription: doubles the size (capacity) of INV.
	void order_class::double_size()
	{
		size *= 2;
		order_record* temp = new order_record[size];
		for (int i = 0; i < count; i++)
		{
			temp[i] = INV[i];
		}
		delete[] INV;
		INV = temp;
	}

	//Name: process
	//Precondition: The variables regarding taxes and costs have not been processed.
	//Postcondition: The variables regarding taxes and costs have been processed.
	//Decription: calculate the tax rate, order tax, net cost, total order cost for 
	//every call record in INV.
	void order_class::process()
	{
		for (int i = 0; i < count; i++)
		{
			if (INV[i].processing_plant >= 0 && INV[i].processing_plant <= 50)
				INV[i].tax_rate = .06;
			else if (INV[i].processing_plant >= 51 && INV[i].processing_plant <= 110)
				INV[i].tax_rate = .07;
			else if (INV[i].processing_plant >= 111 && INV[i].processing_plant <= 200)
				INV[i].tax_rate = .08;
			else if (INV[i].processing_plant >= 201 && INV[i].processing_plant <= 500)
				INV[i].tax_rate = .09;
			else
				INV[i].tax_rate = .11;
			INV[i].order_tax = INV[i].quantity * INV[i].price * INV[i].tax_rate;
			INV[i].net_cost = INV[i].quantity * INV[i].price;
			INV[i].total_cost = INV[i].net_cost + INV[i].order_tax;
		}
	}

	//Name: destructor
	//Precondition: All memory allocated to INV has not been de-allocated.
	//Postcondition: All memory allocated to INV has been de-allocated.
	//Decription: de-allocates all memory allocated to INV.  This will be the last 
	//function to be called(automatically by the compiler)
	//before the program is exited.
	order_class::~order_class()
	{
		std::cout << "The destructor has been called\n";
		delete[] INV;
		count = 0;
		size = 0;
	}

	//Name: operator-
	//Precondition: Order record(s) with cell number key has/have not been removed.
	//Postcondition: Order record(s) with cell number key has/have been removed.
	//Decription: removes all order records in INV with a cell number field that 
	//matches key, if it is there.  Chain was implemented.
	order_class& order_class::operator-(const string key) //removes an item from the list
	{
		int loc = order_class::search(key);
		if (loc != -1)
		{
			while (loc != -1)
			{
				for (int i = loc; i < count - 1; i++)
				{
					INV[i] = INV[i + 1];
				}
				count--;
				loc = order_class::search(key);
			}
		}
		else
		{
			cout << "Error: Order(s) already removed" << endl;
		}
		return *this;
	}

	//Name: operator<<
	//Precondition: Every field in INV has not been printed to the screen. 
	//Postcondition: Every field in INV has been printed to the screen.
	//Decription: prints every field of every call_record in INV formatted to the screen.
	ostream& operator<<(ostream& out, order_class& org) //prints all the elements in INV to the screen
	{

		for (int i = 0; i < org.count; i++)
		{
			out << setw(12) << left << org.INV[i].cell_number
				<< setw(10) << left << org.INV[i].item_number
				<< setw(10) << left << static_cast<int>(org.INV[i].quantity)
				<< setw(8) << left << org.INV[i].price
				<< setw(6) << left << org.INV[i].processing_plant
				<< setw(6) << left << static_cast<int>(100 * org.INV[i].tax_rate)
				<< setw(10) << left << org.INV[i].order_tax
				<< setw(10) << left << org.INV[i].net_cost
				<< setw(10) << left << org.INV[i].total_cost
				<< endl;
		}return out;
	}

