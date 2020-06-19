#include <iostream>
using namespace std;

struct Node {
    int cnt = 0;

    Node* children[2] = {NULL, NULL};
};

int main() {
    int m, n;
    cin >> m >> n;

    Node root;

    int inp1;
    bool inp2;
    for (int i = 0; i < m; i++) {
        cin >> inp1;
        Node* curNode = &root;
        for (int j = 0; j < inp1; j++) {
            cin >> inp2;
            if (curNode->children[inp2] == NULL) {
                Node* n = new Node;
                curNode->children[inp2] = n;
                curNode = n;
                curNode->cnt = 1;
            }
            else {
                curNode = curNode->children[inp2];
                curNode->cnt++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> inp1;
        int ans = m;
        Node* curNode = &root;
        for (int j = 0; j < inp1; j++) {
            cin >> inp2;
            if (curNode->children[!inp2] != NULL){
                ans -= curNode->children[!inp2]->cnt;
            }
            else {
            }
            if (curNode->children[inp2] != NULL) {
                curNode = curNode->children[inp2];
            }
            else {
                for (int k = j + 1; k < inp1; k++) {
                    cin >> inp2;
                }
                break;
            }
        }
        cout << ans << endl;
    }
}
