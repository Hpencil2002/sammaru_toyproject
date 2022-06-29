#include <iostream>
#include <string>
using namespace std;

#include "telephone.h"

int main() {
	string t_name, t_number;
	telepointer h = new telephone;

	int count = 0;
	string SearchName;
	telepointer SearchResult;

	int menu, f_menu;
	do {
		h->printMenu();
		cin >> menu;
		cin.ignore();

		switch (menu) {
		case 1:
			cout << "\n" << "�̸�: ";
			cin >> t_name;
			cout << "��ȭ��ȣ: ";
			cin >> t_number;
			h->insertNode(h, t_name, t_number);
			break;
		case 2:
			cout << "ã�� �̸��� �Է��ϼ���: ";
			getline(cin, SearchName);
			SearchResult = h->searchNode(SearchName);
			if (SearchResult) {
				cout << "=================================" << endl;
				cout << "�̸�: ";
				cout.width(15);
				cout.setf(ios_base::left);
				cout << SearchResult->name << "��ȭ��ȣ: " << SearchResult->number << endl;
				cout << "=================================" << endl;
			}
			else {
				cout << "��� ����" << endl;
				cout << "\n\n";
			}
			break;
		case 3:
			cout << "������ �̸��� �Է��ϼ���: ";
			cin >> t_name;
			h->delete_member(h, t_name);
			break;
		case 4:
			h->show_member();
			break;
		case 5:
			h->delete_all();
			break;
		case 6:
			cout << "\nã�� �̸��� �Է��ϼ���: ";
			getline(cin, SearchName);
			SearchResult = h->searchNode(SearchName);
			if (SearchResult) {
				SearchResult->modify(h);
			}
			else {
				cout << "��� ����" << endl;
				cout << "\n\n";
			}
			break;
		case 7:
			cout << "1. �߰�\n";
			cout << "2. ����\n";
			cout << "3. ���\n";
			cout << "���ã�� �޴�: ";
			cin >> f_menu;
			if (f_menu == 1)
				h->add_Favorites();
			else if (f_menu == 2)
				h->delete_Favorites();
			else if (f_menu == 3)
				h->print_Favorites();
			break;
		case 8:
			cout << "���α׷��� �����մϴ�.\n";
			break;
		}
	} while (menu != 8);

	h->delete_all();


	return 0;
}