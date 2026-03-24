#include <iostream>
#include <vector>


using namespace std;

struct Node {

	char data;
	Node* next;
	Node* prev;

	Node(char c ) : data(c),prev(nullptr),next(nullptr){}

};

Node* head = new Node('0');
Node* cursor = head;

void add(char c) {
	Node* newNode = new Node(c);
	newNode->next = cursor->next;
	newNode->prev = cursor;

	if (cursor->next != nullptr) {
		cursor->next->prev = newNode;
	}

	cursor->next = newNode;
	cursor = newNode;
	
}

void remove() {
	if (cursor == head) return;

	Node* target = cursor;
	Node*p = target->prev;
	Node*n = target->next;

	p->next = n;
	if (n != nullptr) n->prev = p;
	
	delete target;
	cursor = p;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	for (char c : s) add(c); 

	int m;
	cin >> m;
	while (m--) {
		char cmd;
		cin >> cmd;
		if (cmd == 'L') {
			if (cursor->prev != nullptr) cursor = cursor->prev;
		}
		else if (cmd == 'D') {
			if (cursor->next != nullptr) cursor = cursor->next;
		}
		else if (cmd == 'B') {
			remove();
		}
		else if (cmd == 'P') {
			char x; cin >> x;
			add(x);
		}
	}

	for (Node* curr = head->next; curr != nullptr; curr = curr->next) {
		cout << curr->data;
	}

	return 0;
}