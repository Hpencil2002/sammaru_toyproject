#include <iostream>
#include <string>
using namespace std;

#include "telephone.h"

telephone::telephone() {
	left = NULL;
	name = " ";
	number = " ";
	star=false;
	right = NULL;
}

telephone::~telephone() {
}

void telephone::printMenu() {
	cout << "\n";
	cout << "===========Menu===========" << endl;
	cout << "1. �߰�" << endl;
	cout << "2. �˻�" << endl;
	cout << "3. ����" << endl;
	cout << "4. ���" << endl;
	cout << "5. ��ü ����" << endl;
	cout << "6. ����" << endl;
	cout << "7. ���ã��" << endl;
	cout << "8. ����" << endl;
	cout << "==========================" << endl;
	cout << "Menu : ";
}

telephone telephone::createNode() {
	telephone newNode;

	newNode.left = NULL;
	newNode.name = "";
	newNode.number = "";
	newNode.right = NULL;

	return newNode;
}

void telephone::delete_member(telepointer h, string name) {
	if (h->right == NULL) {
		cout << "������ ��ȭ��ȣ�� �����ϴ�.\n";
		return;
	}
	telepointer n = h->right;
	while (n != NULL) {
		if (n->name == name) {
			if (n == h->right) {
				h->right = n->right;
				free(n);
			}
			else if (n->right == NULL) {
				n->left->right = NULL;
				free(n);
			}
			else {
				n->left->right = n->right;
				n->right->left = n->left;
				free(n);
			}
			return;
		}
		n = n->right;
	}

	cout << "�ش� ��ȭ��ȣ�� ã�� ���߽��ϴ�. (" << name << ")\n";
	return;
}

void telephone::delete_all() {
	telepointer p = this->right;
	telepointer trail;
	while (p) {
		trail = p;
		p = p->right;
		delete trail;
	}
	this->right = NULL;
}

telepointer telephone::searchNode(string name) {
	telepointer n = new telephone;
	n = this->right;
	while (n) {
		if (n->name == name)
			return n;
		n = n->right;
	}

	return NULL;
}

void telephone::insertNode(telepointer h, string name, string number) {
	telepointer newnode = new telephone;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->name = name;
	newnode->number = number;

	telepointer n = h->right;

	if (h->right == NULL) {
		h->right = newnode;
		newnode->left = h;
		return;
	}

	telepointer trail;
	while (n) {
		if (newnode->name < n->name) {
			newnode->left = n->left;
			newnode->right = n;
			n->left->right = newnode;
			n->left = newnode;
			break;
		}
		trail = n;
		n = n->right;
	}
	if (n == NULL) {
		trail->right = newnode;
		newnode->left = trail;
	}
}

void telephone::show_member() {
	telepointer n = this->right;
	cout << "=================================" << endl;
	while (n) {
		cout << "�̸�: ";
		cout.width(15);
		cout.setf(ios_base::left);
		cout << n->name << "��ȭ��ȣ: " << n->number << endl;
		n = n->right;
	}
	cout << "=================================" << endl;
}

void telephone::modify(telepointer h) {
	string menu;
	cout << "�����ϰ� ���� �κ��� �Է��ϼ���: ";
	getline(cin, menu);

	if (menu == "�̸�") {
		string old_name, new_name, new_number;
		cout << "�ٲ� �̸��� �Է��ϼ���: ";
		getline(cin, new_name);
		old_name = this->name;
		new_number = this->number;
		delete_member(h, old_name);
		insertNode(h, new_name, new_number);
	}
	else if (menu == "��ȭ��ȣ") {
		string new_number;
		cout << "�ٲ� ��ȣ�� �Է��ϼ���: ";
		getline(cin, new_number);
		this->number = new_number;
	}
	else if (menu == "���") {
		string old_name, new_name, new_number;
		cout << "�ٲ� �̸��� �Է��ϼ���: ";
		getline(cin, new_name);
		cout << "�ٲ� ��ȣ�� �Է��ϼ���: ";
		getline(cin, new_number);
		old_name = this->name;
		delete_member(h, old_name);
		insertNode(h, new_name, new_number);
	}
	else {
		cout << "�߸��� �޴��Դϴ�.\n";
	}
}

void telephone::add_Favorites() {
	string s_name;
	telepointer p;
	cout << "���ã�⿡ �߰��� �̸�: ";
	cin >> s_name;
	p=searchNode(s_name);
	p->star = true;
}
void telephone::delete_Favorites() {
	string s_name;
	telepointer p;
	cout << "���ã�⿡�� ������ �̸�: ";
	cin >> s_name;
	p = searchNode(s_name);
	p->star = false;
}
void telephone::print_Favorites() {
	telepointer n = this->right;
	cout << "=================================" << endl;
	cout << "\t���ã�� ���\n";
	cout << "=================================" << endl;
	while (n) {
		if (n->star == true) {
			cout << "�̸�: ";
			cout.width(15);
			cout.setf(ios_base::left);
			cout << n->name << "��ȭ��ȣ: " << n->number << endl;
		}
		n = n->right;
	}
	cout << "=================================" << endl;
}