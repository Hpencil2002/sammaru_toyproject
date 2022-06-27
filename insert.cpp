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
	telephone* tele = NULL;
	init(tele);
	string t_name, t_number;

	while (1) {
		cout << "이름, 번호를 입력하세요(이름이나 번호에 0을 입력하면 종료)";
		getline(cin, t_name);
		getline(cin, t_number);
		if (t_name == "0" || t_number == "0")
			break;

		telePointer Newnode = NULL;
		telePointer temp = tele;
		Newnode = new telephone;
		Newnode->name = t_name;
		Newnode->number = t_number;
		Newnode->left = NULL;
		Newnode->right = NULL;

		do {
			if (temp->name == " ") {
				tele->name = Newnode->name;
				tele->number = Newnode->number;
				break;
			}
			else if (Newnode->name > temp->name && Newnode->name < temp->right->name) {
				insert(temp, Newnode);
				break;
			}
			else if (Newnode->name > temp->name && temp->right == NULL) {
				Newnode->left = temp;
				temp->right = Newnode;
				break;
			}
			else if (Newnode->name > temp->name && Newnode->name > temp->right->name) {
				temp = temp->right;
			}
		} while (1);
	}

	return 0;
}