#define _CRT_SECURE_NO_WARNINGS
#include"Purchases.h"

Purchases::Purchases() {
	head = nullptr;
	tail = nullptr;
}

Purchases::~Purchases() {
	list* next = head;
	while (next != tail) {
		list* current = next;
		next = next->next;
		delete current;
	}
}

bool Purchases::isEmpty() {
	return head == nullptr;
}

list* Purchases::findPurchase(string customerName, string item) {
	list* current = head;
	if (isEmpty()) {
		cout << "The list is empty!" << endl;
		return nullptr;
	}
	while (current != nullptr) {
		if (current->customerName == customerName) {
			for (int i = 0; i < current->itemsCount; i++) {
				if (item == current->items[i]) {
					return current;
				}
			}
		}
		current = current->next;
	}
	cout << "\nThis purchase does not exist." << endl;
	cout << endl;
	return nullptr;
}
string Purchases::timeToString() {
	time_t tt;

	struct tm* ti;

	time(&tt);

	ti = localtime(&tt);
	return asctime(ti);
}

void Purchases::addPurchase(string customerName, string items[], double transactionTotal) {
	list* temp = new list();
	temp->customerName = customerName;
	for (int i = 0; i < 5; i++) {
		temp->items[i] = items[i];
		if (items[i] != "empty") {
			++temp->itemsCount;
		}
	}
	temp->transactionTotal = transactionTotal;
	temp->purchaseDate = timeToString();
	if (isEmpty()) {
		temp->back = nullptr;
		temp->next = nullptr;
		head = temp;
		temp->type = "Purchased";
	}
	else {
		temp->back = tail;
		temp->next = nullptr;
		temp->back->next = temp;
		temp->type = "Purchased";
	}
	tail = temp;
	cout << "Purchase complete!" << endl;
}

bool Purchases::removePurchase(string customerName, string item) {
	list* current = findPurchase(customerName, item);
	if (current != nullptr) {
		current->type = "Refunded";
		cout << "Refund complete! " << endl;
		return true;
	}
	else {
		cout << "Purchase not in history!" << endl;
		return false;
	}
}

void Purchases::print() {
	int i = 0;
	list* current = head;
	if (isEmpty()) {
		cout << "List is empty!" << endl;
	}
	cout << "Total Purchase History:" << endl << endl;

	while (current != nullptr) {
		cout << current->purchaseDate;
		cout << "Customer name: " << current->customerName << endl;
		cout << "Items bought: ";
		for (int i = 0; i < 5; i++) {
			if (current->items[i] != "empty") {
				cout << current->items[i] << "   ";
			}
		}
		cout << endl << "Total: $" << current->transactionTotal << endl;
		cout << "Type: " << current->type << endl << endl;
		current = current->next;
		++i;
	}
	cout << endl;
}


