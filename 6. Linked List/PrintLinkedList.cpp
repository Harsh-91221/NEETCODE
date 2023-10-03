#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insertathead(Node *&head, Node *&tail, int data)
{
    // STEP 1:CREATE NEW NODE
    Node *temp = new Node(data);
    // STEP 2:POINT IT TOWARDS HEAD
    temp->next = head;
    // STEP 3:SHIFT THE HEAD TO TEMP
    if (head == NULL)
    {
        tail = temp;
    }
    head = temp;
}
void insertattail(Node *&head, Node *&tail, int data)
{
    // STEP 1:CREATE NEW NODE
    Node *temp = new Node(data);
    // STEP 2:POINT IT TOWARDS HEAD
    tail->next = temp;
    // STEP 3:SHIFT THE HEAD TO TEMP
    if (head == NULL)
    {
        head = temp;
    }
    tail = temp;
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