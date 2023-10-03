#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    // Constructor to initialize a Node with data
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void deleteHead(Node *&head, Node *&tail)
{
    // If the list is empty
    if (head == NULL)
    {
        cout << "LIST IS EMPTY" << endl;
        return;
    }
    // STEP 1: Create a temporary pointer to the current head
    Node *temp = head;
    // STEP 2: Update the head pointer to the next node
    head = head->next;
    // STEP 3: Disconnect the old head from the list
    temp->next = NULL;
    // STEP 4: Delete the old head node
    delete temp;
}

void deleteTail(Node *&head, Node *&tail)
{
    // If the list is empty
    if (head == NULL)
    {
        cout << "LIST IS EMPTY" << endl;
        return;
    }
    // STEP 1: Create a temporary pointer to the current tail
    Node *temp = tail;
    // STEP 2: Traverse the list to find the previous node of the tail
    Node *prev = head;
    while (prev->next != tail)
    {
        prev = prev->next;
    }
    // STEP 3: Update the tail pointer to the previous node
    tail = prev;
    // STEP 4: Disconnect the old tail from the list
    tail->next = NULL;
    // STEP 5: Delete the old tail node
    delete temp;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    // Creating nodes with data
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    // Connecting nodes to create a linked list
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Setting the head and tail pointers
    head = first;
    tail = fifth;

    // Deleting the head and tail nodes
    deleteHead(head, tail);
    deleteTail(head, tail);

    // Printing the updated list
    print(head);

    return 0;
}
