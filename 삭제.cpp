#include <iostream>
#include <string>
using namespace std;

struct telephone {
	telePointer left;
	string name;
	string number;
	telePointer right;
};

typedef struct telephone* telePointer;

typedef struct head {
	telePointer first;
}headnode;

void delete_member(headnode* h, string name);

void delete_all(headnode* h);

int main() {



	return 0;
}

void delete_member(headnode* h, string name) {

	if (h->first == NULL){	//member�� ���� �� �Լ� ����
		cout << "������ ��ȭ��ȣ�� �����ϴ�.\n";
		return;
	}
	telePointer n = h->first;
	while (n != NULL) {
		if (n->name == name) {
			if (n == h->first) {
				h->first = n->right;
				
				free(n);
			}
			else if (n->right == NULL) {
				n->left->right == NULL;
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

	cout <<"�ش� ��ȭ��ȣ�� ã�� ���Ͽ����ϴ�.("<< name <<")\n"; //Ž�� ����
	return;
}

void delete_all(headnode* h) {
	telePointer p=h->first;
	telePointer trail;
	while (p) {
		trail = p;
		p=p->left;
		free(trail);
	}
	free(h);
}