#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
#define MAXN 5005
#define MOD 1000000007

struct Node {
    Node* children[26];
    int length;
    //0 if no word ends, otherwise length of word that ends there

    Node()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        length = 0;
    }
};

void insert(Node* r, string word) {
    Node* curNode = r;
    for (int i = 0; i < word.length(); i++) {
        if (curNode->children[word[i] - 'a'] == nullptr)
            curNode->children[word[i] - 'a'] = new Node();
        curNode = curNode->children[word[i] - 'a'];
    }

    curNode->length = word.length();
}

long long dp[MAXN];
//unordered_set<Node*> ends;
vector<Node*> pends;

int main()
{
    string str;
    cin >> str;

    Node *root = new Node();
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        string inp;
        cin >> inp;

        insert(root, inp);
    }

    dp[0] = 1;
    for (int i = 0; i < str.length(); i++)
    {
        pends.push_back(root);

        for (auto &p : pends)
        {
            if (p == nullptr)
                continue;
            
            p = p->children[str[i] - 'a'];
            if (p != nullptr && p->length != 0)
            {
                //cout << i << " " << p->length << endl;
                dp[i + 1] += dp[i - p->length + 1];
                if (dp[i + 1] >= MOD)
                    dp[i + 1] -= MOD;
            }
        }
    }
    cout << dp[str.length()] << endl;
}