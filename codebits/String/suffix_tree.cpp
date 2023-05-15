#include <iostream>
#include <unordered_map>
using namespace std;

string str;
Node* root;
Node* active_node;
//char active_edge;
int active_length;
int rem; //remainder

struct Node
{
    int l, r;
    Node *parent, *link;
    unordered_map<char, Node*> next;

    Node(int l = 0, int r = 0, Node* parent = nullptr) : l(l), r(r), parent(parent), link(nullptr)
    {
        if (parent != nullptr)
        {
            parent->next[str[l]] = this;
        }
    }
    Node* getNext(char c)
    {
        if (!next.count(c))
            return nullptr;
        return next[c];
    }
    char getChar(int length)
    {
        if (r == 0)
            return '\0';
        return str[l + length];
    }
};

void add(int pos)
{
    rem++;

    if (pos >= active_node->r)
    {
        
    }
    if (active_node->getChar(active_length) != str[pos])
    {
        Node *prev = nullptr;
        while (rem > 0)
        {
            if (active_length != 0)
            {
                Node *split = new Node(active_node->l, pos, active_node->parent);
                //move active node to non-overlapping portion
                active_node->l += active_length;
                //update edge so split is parent of active_node
                active_node->parent = split;
                split->next[str[active_node->l]];

                active_node = split;
                //new Node(pos, str.length(), split);

                //active_node = split->next[]
                active_length--;

                if (prev != nullptr)
                {
                    prev->link = split;
                }
                prev = split;
            }
            active_node->next[str[pos]] = new Node(pos, str.length(), active_node);
            rem--;

            if (active_node->parent == root)
            {
                active_node = root->next[active_node->getChar(1)];
            }
            else
            {
                active_node = active_node->link->next[active_node->getChar(1)];
            }
        }
    }
    else
    {
        active_length++;
    }
}

int main()
{
    root = new Node();

    //active_edge = '\0';
    active_length = 0;
    active_node = root;
    rem = 0;

}