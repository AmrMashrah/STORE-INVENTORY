#pragma once
#include<iostream>
#include<string>
#include<ctime>

using namespace std;

class Inventory {
private:
	string items[3][5] = {
		{ "Oranges", "Apples", "Bananas", "Pears", "Limes" },
		{ "10", "10", "10", "10", "10" },
		{ "1.00", "0.75", "0.35", "1.00", "0.85" }
	};
public:
	void print();
	~Inventory();
	void displayTime();
	void add(string item, int amount);
	string remove(string item, int amount);
	bool find(string item);
	void findItem(string item);
	double calcTotal(string name, int amount);
};
