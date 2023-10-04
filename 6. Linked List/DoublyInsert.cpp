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
void insertAtHead(Node *&head, Node *&tail, int data)
{
    // If the list is empty
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }
    // Create a new node
    Node *temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
void insertAtTail(Node *&head, Node *&tail, int data)
{
    // If the list is empty
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }
    // Create a new node
    Node *temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}
void insertAtPosition(Node *&head, Node *&tail, int position, int data)
{
    // If the list is empty
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
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
    // Create a new node
    Node *temp = new Node(data);
    // Point the new node to the current node
    temp->next = currNode;
    currNode->prev = temp;
    // Point the previous node to the new node
    prevNode->next = temp;
    temp->prev = prevNode;
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

    // Insert nodes at the head
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 50);

    // Insert nodes at the tail
    insertAtTail(head, tail, 60);
    insertAtTail(head, tail, 70);

    // Insert a node at a specific position
    insertAtPosition(head, tail, 3, 10);

    // Print the linked list
    print(head);

    return 0;
}
