#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 500050

pair<long long, long long> prep[MAXN];

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        long long n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            cin >> prep[i].first;
            prep[i].second = i + 1;
        }
        sort(prep, prep + n);

        long long wins = n;
        for (long long i = 0; i < n; i++)
        {
            //cout << prep[i].first << " " << prep[i].second << endl;
            if (m < prep[i].first)
            {
                wins = i;
                for (long long j = i; j < n; j++)
                {
                    if (prep[j].second == wins + 1)
                    {
                        //cout << "hey" << endl;
                        if (i > 0 && prep[j].first - prep[i - 1].first <= m)
                        {
                            prep[j].second--;
                            prep[i - 1].second++;
                        }
                        break;
                    }
                }
                break;
            }
            m -= prep[i].first;
            prep[i].second--;
        }

        long long place = 1;
        for (long long i = 0; i < n; i++)
        {
            if (prep[i].second > wins)
                place++;
        }
        cout << place << endl;
    }
}
//0, 1, 2, ... n - 1
//k + 1th place
//n - k ... n - 1
//n - k - 1 or n - k wins


//1, 0
//2, 1
//3, 2

//1, 0
//2, 2
//3, 3
//m = 1
//win = 1

//1, 1
//2, 1
//3, 3

//3, 0
//3, 2
//3, 2
//m = 0
//win = 2


//5 wins
//4, 5, 6, 7, 8

//4 wins
//4, 4, 6, 7, 8

//5 10 10 10 15
//20
//2 wins
//1 2 2 3 5
