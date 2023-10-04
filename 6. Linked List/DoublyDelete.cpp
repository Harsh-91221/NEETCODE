#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
void deletehead(Node *&head, Node *&tail)
{
    // If the list is empty
    if (head == NULL)
    {
        cout << "LL IS EMPTY" << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete temp;
}
void deletetail(Node *&head, Node *&tail)
{
    // If the list is empty
    if (head == NULL)
    {
        cout << "LL IS EMPTY" << endl;
        return;
    }
    Node *temp = tail;
    tail = tail->prev;
    temp->prev = NULL;
    tail->next = NULL;
    delete temp;
}
void deletepos(Node *&head, Node *&tail, int position)
{
    // If the list is empty
    if (head == NULL)
    {
        cout << "LL IS EMPTY" << endl;
        return;
    }
    // Find the current and previous nodes at the specified position
    Node *prevNode = head;
    int i = 1;
    while (i < position)
    {
        prevNode = prevNode->next;
        i++;
    }
    // Point the current node to the previous node's next
    Node *currNode = prevNode->next;
    Node *nextNode = currNode->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    currNode->prev = NULL;
    currNode->next = NULL;
    delete currNode;
}
// Function to print the linked list
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
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

    // deletehead(head, tail);
    deletetail(head, tail);
    // deletepos(head, tail, 3);

    // Print the linked list
    print(head);

    return 0;
}
