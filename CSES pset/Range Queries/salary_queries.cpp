#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define SIZE 400050
#define MAXN 200050

int bit[SIZE];

int sum(int i)
{
    if (i < 0)
        return 0;
    i++;
    int sum = 0;
    while (i > 0)
    {
        //cout << "b" << endl;
        sum += bit[i];
        i -= (i) & -(i);
    }
    return sum;
}

void add(int i, int delta)
{
    i++;
    while (i <= SIZE)
    {
        //cout << "a" << endl;
        bit[i] += delta;
        i += (i) & -(i);
    }
}

struct Query
{
    char inp;
    int a, b;
};

int salaries[MAXN];
vector<int> vals;
Query queries[MAXN];

int main()
{
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        cin >> salaries[i];
        vals.push_back(salaries[i]);
    }

    for (int i = 0; i < q; i++)
    {
        cin >> queries[i].inp >> queries[i].a >> queries[i].b;
        if (queries[i].inp == '!')
        {
            vals.push_back(queries[i].b);
        }
    }

    sort(vals.begin(), vals.end());

    for (int i = 1; i <= n; i++)
    {
        salaries[i] = lower_bound(vals.begin(), vals.end(), salaries[i]) - vals.begin();
        add(salaries[i], 1);
    }

    for (int i = 0; i < q; i++)
    {
        Query query = queries[i];
        if (query.inp == '!')
        {
            add(salaries[query.a], -1);
            salaries[query.a] = lower_bound(vals.begin(), vals.end(), query.b) - vals.begin();
            add(salaries[query.a], 1);
        }
        else
        {
            cout << sum(upper_bound(vals.begin(), vals.end(), query.b) - vals.begin() - 1) - sum(lower_bound(vals.begin(), vals.end(), query.a) - vals.begin() - 1) << endl;
        }
    }
}