#include <iostream>
#include <string>
using namespace std;

struct telephone // refered to insert.cpp
{
	telePointer left;
	string name;
	string number;
	telePointer right;
};

typedef struct telephone* telePointer; // refered to insert.cpp

telephone createNode();
telePointer searchNode(int count, string name, telePointer array[]);
void printMenu();

void insert(telePointer node, telePointer newnode); // refered to insert.cpp
void init(telePointer node); // refered to insert.cpp

int main()
{
	telePointer list[100];
	for (int i = 0; i < 100; i++)
	{
		init(list[i]);
	}
	int x = 0;
	int y = 1;
	int count = 0;
	string searchName;
	telePointer SearchResult;

	int Menu;
	while (1)
	{
		printMenu();
		cin >> Menu;
		switch (Menu)
		{
			case 1:
				insert(list[x++], list[y++]);
				break;
			case 2:
				cout << "Enter the name you want to search : ";
				getline(cin, searchName);
				SearchResult = searchNode(count, searchName, list);
				if (SearchResult)
				{
					cout << "=================================" << endl;
					cout.width(18);
					cout.setf(ios_base::left);
					cout << SearchResult->name << SearchResult->number << endl;
					cout << "=================================" << endl;
				}
				else
				{
					cout << "No result" << endl;
					cout << "\n\n";
				}
				break;
			case 3:

		}
		if (Menu == 4)
		{
			break;
		}
	}
	cout << "The program has been ended" << endl;
}
telephone createNode()
{
	telephone newNode;

	newNode.left = NULL;
	newNode.right = NULL;
	newNode.name = "";
	newNode.number = "";

	return newNode;
}
telePointer searchNode(int count, string name, telePointer array[])
{
	for (int i = 0; i < count; i++)
	{
		if ((array[i]->name == name) == 0)
		{
			return array[i];
		}
	}
	return NULL;
}
void printMenu()
{
	cout << "===========Menu===========" << endl;
	cout << "1. Add Contacts" << endl;
	cout << "2. Search Contacts" << endl;
	cout << "3. Delete Contacts" << endl;
	cout << "4. Exit the program" << endl;
	cout << "==========================" << endl;
	cout << "Menu : ";
	cout << "\n\n";
}
void insert(telePointer node, telePointer newnode) // refered to insert.cpp
{
	newnode->left = node;
	newnode->right = node->right;
	node->right->left = newnode;
	node->right = newnode;
}
void init(telePointer node) // refered to insert.cpp
{
	node->name = " ";
	node->number = " ";
	node->left = NULL;
	node->right = NULL;
}