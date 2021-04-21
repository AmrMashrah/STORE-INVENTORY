#pragma once
#include<iostream>
#include<string>
#include <ctime>

using namespace std;

struct list {
	string purchaseDate;
	string customerName;
	string items[5];
	string type;
	int itemsCount;
	double transactionTotal;
	list* next;
	list* back;
};

class Purchases {
private:
	list* head;
	list* tail;

public:
	Purchases();
	~Purchases();
	string timeToString();
	list* findPurchase(string name, string item); //add perameters.
	bool isEmpty();
	void print();
	void addPurchase(string name, string item[], double amount);
	bool removePurchase(string name, string item);
};
