#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 200005
//end, start, best movies

pair<pair<int, int>, int> movies[MAXN];

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> movies[i].first.second >> movies[i].first.first;
    }

    sort(movies, movies + n + 1);

    for (int i = 1; i <= n; i++)
    {
        movies[i].second = movies[i - 1].second;

        int j = lower_bound(movies, movies + n + 1, make_pair(make_pair(movies[i].first.second, movies[i].first.second), 0)) - movies - 1;
        //cout << "j " << j << endl;
        movies[i].second = max(movies[i].second, movies[j].second + 1);
    }

    // for (int i = 0; i <= n; i++)
    // {
    //     cout << movies[i].first.first << " " << movies[i].first.second << " " << movies[i].second << endl;
    // }

    cout << movies[n].second << endl;
}