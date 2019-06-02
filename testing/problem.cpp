#include <stdlib.h>
#include <iostream>

using namespace std;

enum Color {
	RED,
	GREEN,
	BLUE
};

class Ball {
private:

	Color color;
	float radius;
	float bouncy;

public:
	Ball(float r){
		radius = r;
	}

	void bounce();
};

void Ball::bounce(){ 
	cout << "Bounce Boucne !!" << endl;
}

template <class T>
class Node
{
public:

	T data;
	Node* left;
	Node* right;

};

template <class T> 
class CustomTree 
{
public:

	Node<T> *root;

	CustomTree(){
		root = NULL;
	}

	~CustomTree(){

	}

	Node<T>* newNode(T data){
		Node<T>* temp = new Node<T>;
		temp->data = data;
		return (temp);
	}

	Node<T>* newNode(T* data){
		Node<T>* temp = new Node<T>;
		temp->data = data;
		return (temp);
	}
};



int main() {
	CustomTree<Ball>* tree1 = new CustomTree<Ball>;
	tree1->root 		= tree1->newNode(3.4);
	// tree1->root->right 	= tree1->newNode(new Ball(2));
	// tree1->root->left 	= tree1->newNode(3);
	// tree1->root->right->right = tree1->newNode(4);
	// tree1->root->right->left = tree1->newNode(5);
	// tree1->root->left->right = tree1->newNode(6);
	// tree1->root->left->left = tree1->newNode(7);
	// Printing sequence : 1 2 3 7 6 4 4
}