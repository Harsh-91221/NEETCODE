#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insertathead(Node *&head, Node *&tail, int data)
{
    // IF LIST IS EMPTY
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }
    // STEP 1:CREATE NEW NODE
    Node *temp = new Node(data);
    // STEP 2:POINT IT TOWARDS HEAD
    temp->next = head;
    // STEP 3:SHIFT THE HEAD TO TEMP
    head = temp;
}
void insertattail(Node *&head, Node *&tail, int data)
{
    // IF LIST IS EMPTY
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }
    // STEP 1:CREATE NEW NODE
    Node *temp = new Node(data);
    // STEP 2:POINT IT TOWARDS HEAD
    tail->next = temp;
    // STEP 3:SHIFT THE HEAD TO TEMP
    tail = temp;
}
void insertatposition(Node *&head, Node *&tail, int position, int data)
{
    // IF LIST IS EMPTY
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }
    // STEP 1: FIND CURR AND PREV POSITION
    Node *prev = head;
    int i = 1;
    while (i < position)
    {
        prev = prev->next;
        i++;
    }
    // POINT CURR TO PREV NEXT
    Node *curr = prev->next;
    // CREATE NEW NODE
    Node *temp = new Node(data);
    // POINT THE NEWNODE TO CURR
    temp->next = curr;
    // POINT PREV TO NEW NODE
    prev->next = temp;
}
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
    insertathead(head, tail, 20);
    insertathead(head, tail, 30);
    insertathead(head, tail, 40);
    insertathead(head, tail, 50);
    insertattail(head, tail, 60);
    insertattail(head, tail, 70);
    insertatposition(head, tail, 3, 10);
    // Node *first = new Node(10);
    // Node *second = new Node(20);
    // Node *third = new Node(30);
    // Node *fourth = new Node(40);
    // Node *fifth = new Node(50);

    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;
    // fifth->next = NULL;
    print(head);
}