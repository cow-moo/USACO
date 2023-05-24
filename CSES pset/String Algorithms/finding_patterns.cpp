#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 1000005
 
int order[2][MAXN], classes[2][MAXN], cnt[MAXN];
int n;
string str;
 
//sorts order by value in class
void countSort(int classCount)
{
    fill(cnt, cnt + classCount, 0);
    for (int i = 0; i < n; i++)
    {
        cnt[classes[0][i]]++;
    }
    for (int i = 1; i < classCount; i++)
    {
        cnt[i] += cnt[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        order[1][--cnt[classes[0][order[0][i]]]] = order[0][i];
    }
    swap(order[0], order[1]);
}
 
bool comp(int a, string b)
{
    return str.substr(a, b.length()) < b;
}
 
int main()
{
    cin >> str;
    str += "{";
    n = str.length();
 
    int classCount = 27;
    for (int i = 0; i < n; i++)
    {
        order[0][i] = i;
        classes[0][i] = str[i] - 'a';
    }
 
    for (int i = -1, shift = 0; shift == 0 || (1 << i) < n; i++, shift = (1 << i))
    {
        for (int j = 0; j < n; j++)
        {
            order[0][j] -= shift;
            if (order[0][j] < 0)
                order[0][j] += n;
        }
        countSort(classCount);
        classes[1][order[0][0]] = 0;
        classCount = 1;
        for (int j = 0; j < n; j++)
        {
            pair<int, int> cur = {classes[0][order[0][j]], classes[0][(order[0][j] + shift) % n]};
            pair<int, int> prev = {classes[0][order[0][j - 1]], classes[0][(order[0][j - 1] + shift) % n]};
            if (cur != prev)
                classCount++;
            classes[1][order[0][j]] = classCount - 1;
        }
        swap(classes[0], classes[1]);
    }
 
    // for (int i = 0; i < n; i++)
    // {
    //     cout << order[0][i] << " " << str.substr(order[0][i]) << endl;
    // }
 
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        string s;
        cin >> s;
        //cout << lower_bound(order[0], order[0] + n, s, comp) - order[0] << endl;
        //cout << str.substr(lower_bound(order[0], order[0] + n, s, comp) - order[0]) << endl;
        cout << (str.substr(*lower_bound(order[0], order[0] + n, s, comp), s.length()) == s ? "YES" : "NO") << endl;
    }
}