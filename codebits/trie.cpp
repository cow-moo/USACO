#include <iostream>
using namespace std;

struct Node {
    Node* children[26];

    bool isEnd;
};

//creates/initializes a new node
Node* getNode() {
    Node* pNode = new Node;
    for (int i = 0; i < 26; i++) {
        pNode->children[i] = nullptr;
    }
    pNode->isEnd = false;
    return pNode;
}

void ins(Node* r, string word) {
    Node* curNode = r;
    for (int i = 0; i < word.length(); i++) {
        if (curNode->children[word[i] - 'a'] == nullptr)
            curNode->children[word[i] - 'a'] = getNode();
        curNode = curNode->children[word[i] - 'a'];
    }

    curNode->isEnd = true;
}

//search function not written because it was not needed for the problem

int main() {
    Node* root = getNode();
}
