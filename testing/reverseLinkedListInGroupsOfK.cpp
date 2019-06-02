#include <iostream>

using namespace std;

class Node {
public:
	Node(int data){
		this->data = data;
		this->next = NULL;
	}
	Node *next;
	int data;
};

class LinkedList {
public:
	Node *head;
	LinkedList(Node* head):head(head){}
	void addNode(int data)
	{
		Node* newNode = new Node(data);
		Node* a = head;
		while(a->next != NULL)
			a = a->next;
		a->next = newNode;
	}

	void printList(){
		Node *a = head;
		while(a != NULL){
			cout << a->data << " ";
			a = a->next;
		}
		cout << endl;
	}

	// void reverse(Node* start, Node* end)
	// {
	// 	Node *curr = start;
	// 	Node *prev, *next;

	// 	Node* a = start;
	// 	while(a != end){
	// 		cout << a->data << " ";
	// 		a = a->next;
	// 	}
	// 	cout<< a->data << endl;

	// 	while(curr != end)
	// 	{
	// 		next = curr->next;
	// 		curr->next = prev;
	// 		prev = curr;
	// 		curr = next;
	// 	}

	// 	a = end;
	// 	while(a != end){
	// 		cout << a->data << " ";
	// 		a = a->next;
	// 	}
	// 	cout<<endl;
	// }

	Node* reverse(Node *curr, Node* end)
	{
		if(curr == end)
			return end;
		else{
			cout << "DIC s" << curr->data << endl;
			reverse(curr->next, end)->next = curr;
		}
	}

	void reverseInGroups(int k)
	{
		int count = 1;
		Node *a = head;
		Node *start = NULL;
		Node *end = NULL;
		Node *prev_end = nullptr;

		while(a != NULL){
			if(count == 1)
			{
				start = a;
				count++;
				if (prev_end != nullptr)
					cout << "Prev_end " << prev_end->data << endl;
				else
					cout << "Prev_end was none " << endl;
				cout << "Start " << start->data << endl;
			}
			else if (count == k)
			{
				end = a;
				count = 1;
				cout << "End " << end->data << endl;
				if(prev_end != nullptr)
					prev_end->next = end;
				prev_end = start;
				reverse(start, end);
				start->next = a->next;
			}

			else
				count++;
			a = a->next;
		}

	}
};


int main(){
	LinkedList* myList = new LinkedList(new Node(1));
	myList->addNode(2);
	myList->addNode(3);
	myList->addNode(4);
	myList->addNode(5);
	myList->addNode(6);
	myList->addNode(7);
	myList->addNode(8);
	myList->addNode(9);
	myList->addNode(10);
	myList->printList();
	myList->reverseInGroups(3);
	myList->printList();
	return 0;
}