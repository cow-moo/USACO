#include <iostream>
#include <vector>
using namespace std;
#define MAXN 1000005

int order[2][MAXN], classes[2][MAXN], cnt[MAXN];
int n;

//sorts order by value in class
void countSort(int classCount)
{
    fill(cnt, cnt + classCount, 0);
    for (int i = 0; i < n; i++)
        cnt[classes[0][i]]++;
    for (int i = 1; i < classCount; i++)
        cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; i--)
        order[1][--cnt[classes[0][order[0][i]]]] = order[0][i];
    swap(order[0], order[1]);
}

int main()
{
    string str;
    cin >> str;
    str += '`';
    n = str.length();


    int classCount = 27;
    for (int i = 0; i < n; i++)
    {
        order[0][i] = i;
        classes[0][i] = str[i] - '`';
    }

    for (int shift = 0; shift < n; shift = (shift << 1) | !shift)
    {
        for (int j = 0; j < n; j++)
            order[0][j] = order[0][j] - shift < 0 ? order[0][j] + n - shift : order[0][j] - shift;
        countSort(classCount);
        classes[1][order[0][0]] = 0;
        classCount = 1;
        for (int j = 1; j < n; j++)
        {
            if (tie(classes[0][order[0][j]], classes[0][(order[0][j] + shift) % n]) != tie(classes[0][order[0][j - 1]], classes[0][(order[0][j - 1] + shift) % n]))
                classCount++;
            classes[1][order[0][j]] = classCount - 1;
        }
        swap(classes[0], classes[1]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << order[0][i] << " " << str.substr(order[0][i]) << str.substr(0, order[0][i]) << endl;
    }

    cout << str.substr(order[0][0]) << str.substr(0, order[0][0]) << endl;
}