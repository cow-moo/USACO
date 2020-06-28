#include <iostream>
#include <queue>
using namespace std;

//adj[a][b] returns whether a < b lexicographically
int adj[30][30];
bool visited[30];
bool recStack[30];
string words[30050];
bool ans[30050];
int cnt = 0;

struct Node {
    Node* children[26];

    int wIndex;
};

Node* getNode() {
    Node* pNode = new Node;
    for (int i = 0; i < 26; i++) {
        pNode->children[i] = nullptr;
    }
    pNode->wIndex = -1;
    return pNode;
}

void ins(Node* r, int index) {
    Node* curNode = r;
    for (int i = 0; i < words[index].length(); i++) {
        if (curNode->children[words[index][i] - 'a'] == nullptr)
            curNode->children[words[index][i] - 'a'] = getNode();
        curNode = curNode->children[words[index][i] - 'a'];
    }

    curNode->wIndex = index;
}

//returns whether it finds any cycles
bool dfs(int cur) {
    if (!visited[cur]) {
        visited[cur] = true;
        recStack[cur] = true;
        for (int i = 0; i < 26; i++) {
            if (!adj[cur][i] || cur == i)
                continue;
            if (!visited[i] && dfs(i)) {
                return true;
            }
            else if (recStack[i]) {
                return true;
            }
        }
    }
    recStack[cur] = false;
    return false;
}

bool is_tree() {
    for (int i = 0; i < 26; i++) {
        visited[i] = false;
        recStack[i] = false;
    }
    for (int i = 0; i < 26; i++) {
        if (dfs(i))
            return false;
    }
    cnt++;
    return true;
}

void recurse(Node* curNode) {
    if (curNode->wIndex != -1) {
        ans[curNode->wIndex] = is_tree();
        return;
    }
    for (int i = 0; i < 26; i++) {
        if (curNode->children[i] != nullptr) {
            for (int j = 0; j < 26; j++) {
                if (curNode->children[j] != nullptr && i != j)
                    adj[i][j]++;
            }
            recurse(curNode->children[i]);
            for (int j = 0; j < 26; j++) {
                if (curNode->children[j] != nullptr && i != j)
                    adj[i][j]--;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    Node* root = getNode();

    string word;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        ins(root, i);
    }

    recurse(root);

    cout << cnt << endl;
    for (int i = 0; i < n; i++) {
        if (ans[i])
            cout << words[i] << endl;
    }
}
