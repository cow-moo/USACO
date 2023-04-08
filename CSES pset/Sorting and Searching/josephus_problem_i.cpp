#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
};

int main()
{
    int n;
    cin >> n;

    Node *root = new Node;
    Node *cur = root;
    cur->val = 1;
    for (int i = 2; i <= n; i++)
    {
        cur->next = new Node;
        cur = cur->next;
        cur->val = i;
    }
    cur->next = root;
    cur = cur->next;

    for (int i = 0; i < n; i++)
    {
        cout << cur->next->val << " ";
        cur->next = cur->next->next;
        cur = cur->next;
    }
    cout << endl;
}