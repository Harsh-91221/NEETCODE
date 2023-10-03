#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void inserthead(node *&head, node *&tail, int data)
{
    if (head == NULL)
    {
        node *temp = new node(data);
        head = temp;
        tail = temp;
        return;
    }
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}
void inserttail(node *&head, node *&tail, int data)
{
    if (head == NULL)
    {
        node *temp = new node(data);
        head = temp;
        tail = temp;
        return;
    }
    node *temp = new node(data);
    tail->next = temp;
    tail = temp;
}
void insertpos(node *&head, node *&tail, int pos, int data)
{
    if (head == NULL)
    {
        node *temp = new node(data);
        head = temp;
        tail = temp;
        return;
    }
    node *prev = head;
    int i = 1;
    while (i < pos)
    {
        prev = prev->next;
        i++;
    }
    node *curr = prev->next;
    node *temp = new node(data);
    temp->next = curr;
    prev->next = temp;
}
void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    node *head = NULL;
    node *tail = NULL;
    inserthead(head, tail, 50);
    inserthead(head, tail, 40);
    inserthead(head, tail, 30);
    inserthead(head, tail, 20);
    inserthead(head, tail, 10);
    inserttail(head, tail, 60);
    inserttail(head, tail, 70);
    inserttail(head, tail, 80);
    inserttail(head, tail, 100);
    insertpos(head, tail, 8, 90);
    print(head);
}