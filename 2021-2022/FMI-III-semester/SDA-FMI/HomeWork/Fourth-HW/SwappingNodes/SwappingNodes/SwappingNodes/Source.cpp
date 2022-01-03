

using namespace std;

struct node {
	int data;
	node* next = NULL;

	node(int data, node* next = NULL) {
		this->data = data;
		this->next = next;
	}
};

class List{
private:
	node* head, * tail;
public:
	List()
	{
		head = NULL;
		tail = NULL;
	}
	node* getHead() {
		return this->head;
	}
	void push(int number) {
		if (head == NULL) {
			head = new node(number);
			tail = head;
		}
		else {
			tail->next = new node(number);
			tail = tail->next;
		}
	}
	void print() const {
		node* i = head;
		while (i != NULL) {
			cout << i->data<<' ';
			i = i->next;
		}
	}
};

void swapData(node* x, node* y) {
	int c = x->data;
	x->data = y->data;
	y->data = c;
}

node* y_index(node* head, int position) {
	int counter = 0;

	node* current = head;
	while (current != NULL) {
		if (counter == position) {
			return current;
		}
		current = current->next;
		counter++;
	}
	return NULL;
}
void xSwapY(node* head, int& end) {

	int counter = 0;
	int operations = end / 2;
	node* current = head;
	int right = end;

	while (current != NULL && counter < end) {
		if (counter == operations) {break;}
		int position = right - (counter * 2) - 1;
		node* Yindex = y_index(current, position);

		if (Yindex == NULL) { right--;
			if (right == 0) {
				return;
			}
		}else {
			swapData(current, Yindex);
			current = current->next;
			counter++;
		}
	}
}
void llcubesReversed(node* head, int x, int y) {
	node* current = head;
	int n = x + y;
	while (current != NULL) {
		xSwapY(current, x);
		for (int i = 0; i < n; i++){
			current = current->next;
			if (current == NULL) {break;}
		}
	}
}

int main()
{
	List list;
	int n, x, y;
	cin >>n>> x >> y;
	for (int i = 0; i < n; i++){
		int input = 0;
		cin >> input;
		list.push(input);
	}
	node* head = list.getHead();
	llcubesReversed(head, x, y);
	list.print();
}
