#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
#define MAXN 100050

struct Node {
    bool isFile;
    int nameLen;

    vector<Node*> children;

    int numLeaves;
    long long totalSubtreeLen;
    long long total;
};

Node nodes[MAXN];
int n, nleaves;

void dfs1(Node* node) { //calculates subtree lengths
    node->numLeaves = (node->isFile ? 1 : 0);
    node->totalSubtreeLen = 0;
    for (Node* child : node->children) {
        dfs1(child);
        node->numLeaves += child->numLeaves;
        node->totalSubtreeLen += child->totalSubtreeLen + child->numLeaves * (child->nameLen + (child->isFile ? 0 : 1));
    }
}

void dfs2(Node* node, long long parentlen) {
    node->total = node->totalSubtreeLen + parentlen;

    for (Node* child : node->children) {
        if (child->isFile)
            continue;
        dfs2(child, parentlen + node->totalSubtreeLen -
                    child->totalSubtreeLen - (child->numLeaves * (child->nameLen + 1)) +
                    (3 * (nleaves - child->numLeaves)));
    }

}

int main() {
    freopen("dirtraverse.in", "r", stdin);
    freopen("dirtraverse.out", "w", stdout);
    int n, m, childId;
    string name;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name;
        nodes[i].nameLen = name.length();

        cin >> m;
        nleaves += (m == 0);
        for (int j = 0; j < m; j++) {
            cin >> childId;
            nodes[i].children.push_back(&nodes[childId - 1]);
            //cout << i << " gets " << childId - 1 << endl;
        }
        nodes[i].isFile = (m == 0);
    }
    for (int i = 0; i < n; i++) {
        //cout << nodes[i].isFile << endl;
    }

    dfs1(&nodes[0]);
    dfs2(&nodes[0], 0);

    long long minim = nodes[0].total;
    for (int i = 1; i < n; i++) {
        //cout << nodes[i].total << endl;
        if (nodes[i].total < minim && !nodes[i].isFile)
            minim = nodes[i].total;
    }

    cout << minim << endl;
}
