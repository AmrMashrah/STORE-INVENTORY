#include"Purchases.h"
#include"Inventory.h"
#include <iomanip>

// Pre-Condition: class Purchases nd Inventory created
//Post Condition: performs purchases and store them in purchase history
void purchase(Purchases& s, Inventory& i) {
	string name;
	int amount;
	string item;
	string items[] = { "empty", "empty", "empty", "empty", "empty" };
	int moreItems = 1;
	int itemCount = 0;
	double total = 0.0;
	cout << "Please enter the customer name: ";
	cin >> name;
	do
	{
		cout << "Please enter item name: ";
		cin >> item;
	
		//if item does not end with s
		if (item.back() != 's') {
			string s = "s";
			item = item + s;
		}
		//if item is lowercase
		if (islower(item[0])) {
			item[0] = toupper(item[0]);
		}

		cout << "Please enter the amount of the item: ";
		while (true)
		{
			cin >> amount;
			if (!cin) // if amount is not a number display error messageandask for amount again
			{
				cout << "Amount must be a number! Please try again. " << endl;
				cout << "Please enter the amount of the item: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
			else break;
		}
		cout << endl;
		if (i.find(item)) { 
			if (i.remove(item, amount) == "T")
			{
				cout << "Item removed from inventory. ";
				items[itemCount] = item;
				++itemCount;
				total += i.calcTotal(item, amount);
				cout << "Current Total: $" << total << endl;
			}
			else
			{
				cout << i.remove(item, amount); //checks if amount is in stock
				return;
			}
		}
		else {
			cout << "Item does not exist! " << endl;
		}
		cout << "Do you want to purchase another item? (1)Yes (2)Checkout: " << endl;
		cin >> moreItems;
		while (moreItems != 1 && moreItems != 2)
		{
			cout << "Invalid! Please enter\n"
				<<"(1) to purchase another item.\n(2) to checkout.\n " << endl;
			cin >> moreItems;
		}
		if (moreItems == 2) //Checkout
		{
			cout << "Your total is: $" << fixed << showpoint << setprecision(2) << total << endl << endl;
		}
	} while (moreItems == 1);
	if (itemCount > 0)
	{
		s.addPurchase(name, items, total); //adds to purchase history
	}
}

// Pre-Condition: class Purchases nd Inventory created
//Post Condition: performs refund and return items to inventory
void refund(Purchases& s, Inventory& i) {
	cout << "Please enter the customer name: ";
	string name;
	cin >> name;
	cout << "Please enter item name: ";
	string item;
	cin >> item;

	//if item does not end with s
	if (item.back() != 's') {
		string s = "s";
		item = item + s;
	}
	//if item is lowercase
	if (islower(item[0])) {
		item[0] = toupper(item[0]);
	}

	cout << "Please enter the amount of the item: ";
	int amount;
	while (true) // if amount is not a number display error messageandask for amount again
	{
		cin >> amount;
		if (!cin)
		{
			cout << "Amount must be a number! Please try again. " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		else break;
	}
	cout << endl;
	if (s.removePurchase(name, item) == true) {
		i.add(item, amount);
	}
}

// Pre-Condition: class Purchases nd Inventory created
//Post Condition: display options and gets user input

void options()
{
	Purchases purchases = Purchases();
	Inventory i = Inventory();
	bool run = true;
	while (run)
	{
		string response;
		cout << " Choose: \n1 for purchase\n2 for refund\n3 for purchase history\n4 to display inventory\n5 to search for an item\n6 to quit" << endl;
		cin >> response;
		cout << endl;

		if (response == "1")
		{
			i.print();
			cout << endl;
			purchase(purchases, i);
		}
		else if (response == "2")
		{
			refund(purchases, i);
		}
		else if (response == "3")
		{
			purchases.print();
		}
		else if (response == "4")
		{
			i.print();
		}
		else if (response == "5")
		{
			string userInput;

			cout << "Search for Inventory Item: ";
			cin >> userInput;
			i.findItem(userInput);
			cout << endl;
			options();

		}
		else if (response == "6")
		{
			exit(0);
		}
		else
		{
			cout << "Invalid option!" << endl;
		}
		cout << endl;
	}
}

int main()
{
	options();
	return 0;
}