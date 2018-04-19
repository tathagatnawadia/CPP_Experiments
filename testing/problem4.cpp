#include <iostream>
using namespace std;
 
// Linked list node
struct Node {
    int data;
    struct Node* next;
};

// function prototype for printing the list
void printList(struct Node*);
 
// Function to insert a node at the
// beginning of the linked list
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = new Node;
    new_node -> data = new_data;
    new_node -> next = *head_ref;
    *head_ref = new_node;
}
 
// function to print the linked list
void printList(struct Node* head)
{
    while (head != NULL) {
        cout << head -> data << " -> ";
        head = head -> next;
    }
}

void sortList(int arr[], int N, struct Node* head){
    return;
}
// Driver Code
int main()
{
    struct Node* head = NULL;
    int arr[] = { 5, 1, 3, 2, 8 };
    int N = sizeof(arr) / sizeof(arr[0]);
 
    // creating the linked list
    push(&head, 3);
    push(&head, 2);
    push(&head, 5);
    push(&head, 8);
    push(&head, 5);
    push(&head, 2);
    push(&head, 1);
 
    // Function call to sort the list in order
    // elements are apperaing in an array
    sortList(arr, N, head);
 
    // print the modified linked list
    cout << "Sorted List:" << endl;
    printList(head);
    return 0;
}