#define _CRT_SECURE_NO_WARNINGS
#include"Inventory.h"
#include"Purchases.h"
#include<iomanip>


Inventory::~Inventory() {
	delete[] items;
}

void Inventory::displayTime() {
	time_t tt;

	struct tm* ti;

	time(&tt);

	ti = localtime(&tt);

	cout << asctime(ti);
}

void Inventory::findItem(string item) {
	bool found = false;
	string str = item;
	str[0] = toupper(str[0]);
	string part2 = { "s" };
	for (int i = 0; i < 5; i++) {
		if (items[0][i] == str + part2 || items[0][i] == str) {
			found = true;
			cout << items[0][i] << " : " << items[1][i] << " : " << "$" << items[2][i] << endl;
		}
	}
	if (found) {
		return;
	}
	else {
		cout << "Item not found in Inventory! " << endl;
	}
}


void Inventory::print() {
	displayTime();

	cout << "Inventory items are: " << endl;
	cout << "  Name    Quantity   Price" << endl;
	for (int i = 0; i < 5; i++) {
		cout << setw(8) << items[0][i] << " :" << setw(5) << items[1][i] << "   :  " << "$" << items[2][i] << endl;
	}
}

void Inventory::add(string name, int amount) {
	bool pass = false;
	for (int i = 0; i < 5; i++) {
		if (items[0][i] == name) {
			int newAmt = stoi(items[1][i]);
			newAmt = newAmt + amount;
			items[1][i] = to_string(newAmt);
			pass = true;
		}
	}
	if (pass) {
		cout << "Item returned to inventory. ";
	}
	else {
		"No item found in inventory! ";
	}
}

bool Inventory::find(string name) {
	bool pass = true;
	for (int i = 0; i < 5; i++) {
		if (items[0][i] == name) {
			return true;
		}
	}
	return false;
}

double Inventory::calcTotal(string name, int amount) {
	double newAmnt = 0.00;
	for (int i = 0; i < 5; i++) {
		if (items[0][i] == name) {
			newAmnt = stod(items[2][i]);
			newAmnt = newAmnt * amount;
		}
	}
	return newAmnt;
}

string Inventory::remove(string name, int amount) {
	bool pass = false;
	for (int i = 0; i < 5; i++) {
		if (items[0][i] == name) {
			int newAmt = stoi(items[1][i]);
			newAmt = newAmt - amount;
			if (newAmt < 0) {
				return "Not enough in stock to complete transaction. Transaction Cancelled.";
			}
			else {
				items[1][i] = to_string(newAmt);
				pass = true;
			}
		}
	}
	if (pass) {
		return "T";
	}
	else {
		return "No item found in inventory! ";
	}
}