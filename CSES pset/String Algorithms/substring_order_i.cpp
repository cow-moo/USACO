#include <iostream>
#include <vector>
using namespace std;
#define MAXN 100005
#define LOGN 30
 
int order[2][MAXN], classes[LOGN][MAXN], cnt[MAXN];
int n;
 
//sorts order by value in class
void countSort(int classCount, int ind)
{
    fill(cnt, cnt + classCount, 0);
    for (int i = 0; i < n; i++)
    {
        cnt[classes[ind][i]]++;
    }
    for (int i = 1; i < classCount; i++)
    {
        cnt[i] += cnt[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        order[1][--cnt[classes[ind][order[0][i]]]] = order[0][i];
    }
    swap(order[0], order[1]);
}
 
long long getOverlap(int a, int b)
{
    long long res = 0;
    while (true)
    {
        for (int i = 1; ; i++)
        {
            if (classes[i][a] != classes[i][b])
            {
                if (i == 1)
                {
                    return res;
                }
                else
                {
                    res += 1 << (i - 2);
                    a += 1 << (i - 2);
                    if (a >= n)
                        a -= n;
                    b += 1 << (i - 2);
                    if (b >= n)
                        b -= n;
                    break;
                }
            }
        }
    }
}
 
int main()
{
    long long k;
    string str;
    cin >> str >> k;
    str += '`';
    n = str.length();
 
    int classCount = 27;
    for (int i = 0; i < n; i++)
    {
        order[0][i] = i;
        classes[0][i] = str[i] - '`';
    }
 
    for (int i = 0, shift = 0; shift < n; i++, shift = (1 << i >> 1))
    {
        for (int j = 0; j < n; j++)
        {
            order[0][j] -= shift;
            if (order[0][j] < 0)
                order[0][j] += n;
        }
        countSort(classCount, i);
        classes[i + 1][order[0][0]] = 0;
        classCount = 1;
        for (int j = 0; j < n; j++)
        {
            pair<int, int> cur = {classes[i][order[0][j]], classes[i][(order[0][j] + shift) % n]};
            pair<int, int> prev = {classes[i][order[0][j - 1]], classes[i][(order[0][j - 1] + shift) % n]};
            if (cur != prev)
                classCount++;
            classes[i + 1][order[0][j]] = classCount - 1;
        }
        //swap(classes[0], classes[1]);
    }
 


    //cout << ans << endl;
    for (int i = 0; i < n; i++)
    {
        k -= n - 1 - order[0][i];
        if (i > 0)
            k += getOverlap(order[0][i - 1], order[0][i]);
        if (k < 0)
        {
            cout << str.substr(order[0][i], str.length() - order[0][i] + k - 1) << "\n";
            break;
        }
    }
 
}   