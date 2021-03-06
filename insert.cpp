#include <iostream>
#include <string>
using namespace std;

typedef struct telephone* telePointer;

struct telephone {
	telePointer left;
	string name;
	string number;
	telePointer right;
};

void insert(telePointer node, telePointer newnode) {
	newnode->left = node;
	newnode->right = node->right;
	node->right->left = newnode;
	node->right = newnode;
}

void init(telePointer node) {
	node->name = " ";
	node->number = " ";
	node->left = NULL;
	node->right = NULL;
}

int main() {
	telePointer tele;
	tele = new telephone;
	init(tele);
	string t_name, t_number;

	while (1) {
		cout << "이름, 번호를 입력하세요(이름이나 번호에 0을 입력하면 종료)\n";
		cout << "이름: ";
		getline(cin, t_name);
		if (t_name == "0")
			break;
		cout << "전화번호: ";
		getline(cin, t_number);
		if (t_number == "0")
			break;
		cout << "\n";

		telePointer Newnode = NULL;
		telePointer temp = tele;

		Newnode = new telephone;
		Newnode->name = t_name;
		Newnode->number = t_number;
		Newnode->left = NULL;
		Newnode->right = NULL;

		while(1) {
			if (tele->name == " ") {
				tele->name = Newnode->name;
				tele->number = Newnode->number;
				break;
			}

			if (Newnode->name < tele->name) {
				tele->left = Newnode;
				Newnode->right = tele;
				tele = Newnode;
				break;
			}
			else {
				if (temp->right != NULL)
					temp = temp->right;

				if (Newnode->name > temp->name && temp->right == NULL) {
					Newnode->left = temp;
					temp->right = Newnode;
					break;
				}
				else if (Newnode->name > temp->name && temp->right != NULL) {
					temp = temp->right;
				}
				else {
					insert(temp->left, Newnode);
					break;
				}
			}
		}
	}

	cout << "\n";
	do {
		cout << "이름: " << tele->name << "\t" << "전화번호: " << tele->number << "\n";
		tele = tele->right;
	} while (tele != NULL);

	return 0;
}
