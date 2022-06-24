#include<iostream>
#include<cmath>
#include<vector>


using namespace std;

struct Node {
	int key;
	Node* next = nullptr;
	Node(int data, Node* next = nullptr) {
		this->key = data;
		this->next = next;
	}
};

class List {
private:
	Node* head = nullptr; // Указател към началото
	Node* tail = nullptr; // Указател към края;

public:
	List() = default; // Дефинираме конструкура като дефалтен, дори да го изтрием отдолу, все ще има такова нещо

	/*	Описание за freeMemory():
		
		Създава се кутийка temp която взима указателя към началото, след това правим цикъл който следи докогато 
		указателя за на temp e различен от празния пойнтър, и създаваме нов пойнтър който да пази кутията, след това
		задаваме на новия пойнтър да отиде с една кутия напред и трием temp пойнтъра като след това присвояваме кутията която се пази от
		next и повтаряме докогато не стане == на nullptr след което head i tail se зануляват

	*/
	void freeMemory() {
		Node* temp = head;
		while (temp!=nullptr){
			Node* next = temp->next;
			delete temp;
			temp = next;
		}
		head = nullptr;
		tail = nullptr;
	}

	~List() {
		freeMemory(); // Трие целият линкед лист;
	}

	void push_front(int number) {

		Node* newHead = new Node(number, head);
		head = newHead;
		if (tail == nullptr) {
			tail = head;
		}
	}

	void print() const {
		Node* i = head;
		while (i != nullptr) {
			cout << i->key << " ";
			i = i->next;
		}
		cout << "\n";
	}

	void Insert(int number, int position) {
		if (position == 0) {
			push_front(number);
			return;
		}

		if (head == nullptr) {
			throw out_of_range("Invalid insert index, list is empty");
		}

		Node* current = head;
		Node* previous = nullptr;

		for (int i = 0; i < position; i++) {
			if (current != nullptr) {
				previous = current;
				current = current->next;
			}else {
				throw out_of_range("Cannot insert in invalid position");
			}
		}

		previous->next = new Node(number, current);
		if (tail == previous) {
			tail = previous->next;
		}
	}
};


int main() {

	List list;

	list.Insert(0, 0);
	list.Insert(1, 1);
	list.Insert(3, 2);
	list.Insert(5, 3);
	list.Insert(7, 4);

	list.print();





}