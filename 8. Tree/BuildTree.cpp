#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *build()
{
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    Node *root = new Node(data);
    cout << "ENTER DATA FOR LEFT PART " << data << endl;
    root->left = build();
    cout << "ENTER DATA FOR RIGHT PART " << data << endl;
    root->right = build();
    return root;
}
int main()
{
    Node *root = NULL;
    root = build();
    levelorder(root);
}
