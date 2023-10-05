#include <iostream>
#include <set>
#include <queue>
#include <random>
using namespace std;
#define uint unsigned int

void print(uint x)
{
    for (int i = 5; i >= 0; i--)
    {
        cout << ((x >> i) & 1);
    }
    cout << " ";
}

long long slow(uint a, uint b, uint c, uint d, uint m)
{
    set<pair<uint, uint>> visited;
    queue<pair<pair<uint, uint>, long long>> q;
    q.push({{a, b}, 0});
    uint temp2[] = {~c & ~d & m, ~c & d & m, c & ~d & m, c & d & m, ~c & ~d & ~m, ~c & d & ~m, c & ~d & ~m, c & d & ~m};
    // print(c), print(d);
    // cout << "cd: ";
    // for (int i = 0; i < 4; i++)
    // {
    //     print(temp2[i]);
    // }
    // cout << endl;

    while (!q.empty())
    {
        auto [cur, cnt] = q.front();
        auto [x, y] = cur;
        q.pop();

        if (visited.count(cur))
            continue;
        visited.insert(cur);

        uint temp1[] = {~x & ~y & m, ~x & y & m, x & ~y & m, x & y & m, ~x & ~y & ~m, ~x & y & ~m, x & ~y & ~m, x & y & ~m};
        bool g = true;
        //print(x), print(y);
        //cout << ": ";
        for (int i = 0; i < 4; i++)
        {
            //cout << temp1[i] << " ";
            //print(temp1[i]);
            if (!temp1[i])
                continue;
            bool good = false;
            for (int j = 0; j < 4; j++)
            {
                //cout << (temp1[i] & temp2[j]) << ": " << temp1[i] << endl;
                if ((temp1[i] & temp2[j]) == temp1[i])
                {
                    //cout << "good";
                    good = true;
                    break;
                }
            }
            if (!good)
            {
                g = false;
                break;
            }
        }
        //cout << endl;
        if (!g)
            continue;

        for (int i = 4; i < 8; i++)
        {
            //cout << temp1[i] << " ";
            //print(temp1[i]);
            if (!temp1[i])
                continue;
            bool good = false;
            for (int j = 4; j < 8; j++)
            {
                //cout << (temp1[i] & temp2[j]) << ": " << temp1[i] << endl;
                if ((temp1[i] & temp2[j]) == temp1[i])
                {
                    //cout << "good";
                    good = true;
                    break;
                }
            }
            if (!good)
            {
                g = false;
                break;
            }
        }
        //cout << endl;
        if (!g)
            continue;

        if (~c & d & ~(~x & y) & ~m)
            continue;
        if (~x & ~y & ~(~c & ~d) & ~m)
            continue;
        //if ()

        if (cur == make_pair(c, d))
        {
            return cnt;
        }

        q.push({{cur.first & cur.second, cur.second}, cnt + 1});
        //q.push({{cur.first & (cur.second ^ m), cur.second}, cnt + 1});
        q.push({{cur.first | cur.second, cur.second}, cnt + 1});
        //q.push({{cur.first | (cur.second ^ m), cur.second}, cnt + 1});
        q.push({{cur.first, cur.first ^ cur.second}, cnt + 1});
        q.push({{cur.first, cur.second ^ m}, cnt + 1});
    }
    return -1;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    //print(13);
    // std::random_device dev;
    // std::mt19937 rng(dev());
    // std::uniform_int_distribution<std::mt19937::result_type> dist(0, 1 << 30);

    // for (int i = 0; i < 100000; i++)
    // {
    //     int a = dist(rng), b = dist(rng), c = dist(rng), d = dist(rng), m = dist(rng);
    //     int res = slow(a, b, c, d, m);
    //     //if (res == -1)
    //     //    continue;
    //     //cout << a << " " << b << " " << c << " " << d << " " << m << endl;
    //     //cout << slow(a, b, c, d, m) << endl;
    // }
    // cout << "done" << endl;

    int t;
    cin >> t;

    while (t--)
    {
        uint a, b, c, d, m;
        cin >> a >> b >> c >> d >> m;

        cout << slow(a, b, c, d, m) << endl;
    }
}