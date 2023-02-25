#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
#define MAXN 100050

struct Seed
{
    long long q;
    long long l;
    long long v;
} seeds[MAXN];

bool comp(Seed a, Seed b)
{
    return (a.v == b.v) ? a.l > b.l : a.v > b.v;
}

set<pair<long long, long long> > full;
map<long long, long long> part;

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        full.clear();
        part.clear();

        long long d, n, x;
        cin >> d >> n >> x;

        for (int i = 0; i < n; i++)
        {
            cin >> seeds[i].q >> seeds[i].l >> seeds[i].v;
        }
        sort(seeds, seeds + n, comp);

//        for (int i = 0; i < n; i++)
//        {
//            cout << "t" << seeds[i].q << " " << seeds[i].l << " " << seeds[i].v << endl;
//        }

        long long ans = 0;
        full.insert({0, 0});
        full.insert({d + 2, d + 2});
        for (int i = 0; i < n; i++)
        {
            while (seeds[i].q > 0)
            {
                long long right = d - seeds[i].l;
                auto it = --full.upper_bound({right, d});

                cout << "r" << right << endl;

                if (it->second >= right)
                {
                    if (it->first == 0)
                        break;

                    right = it->first - 1;
                    auto itpart = part.find(right + 1);
                    if (itpart != part.end())
                    {
                        if (seeds[i].q > (x - itpart->second))
                        {
                            ans += (x - itpart->second) * seeds[i].v;
                            seeds[i].q -= (x - itpart->second);
                            part.erase(itpart);
                        }
                        else
                        {
                            ans += seeds[i].q * seeds[i].v;
                            itpart->second += seeds[i].q;
                            seeds[i].q = 0;
                            if (itpart->second == x)
                                part.erase(itpart);
                            break;
                        }
                    }
                    it--;
                }
                //cout << right << endl;
                long long left;
                if ((right - it->second) * x >= seeds[i].q)
                {
                    //plant
//                    if ((right - it->second) * x == seeds[i].q)
//                    {
//                        ans += seeds[i].q * seeds[i].v;
//                        //it->second = right;
//                        left = it->second + 1;
//                        seeds[i].q = 0;
//                        //break;
//                    }
                    //else
                    //{
                    ans += seeds[i].q * seeds[i].v;
                    left = right - seeds[i].q / x + 1;
                    //full.insert({first, right});
                    if (seeds[i].q % x != 0)
                    {
                        part[--left] = seeds[i].q % x;
                    }
                    seeds[i].q = 0;
                    //break;
                    //}
                }
                else
                {
                    ans += (right - it->second) * x * seeds[i].v;
                    seeds[i].q -= (right - it->second) * x;
                    //it->second = right;
                    left = it->second + 1;
                    //need to loop
                }

                auto itright = it;
                itright++;
                if (itright->first == right + 1 && part.find(itright->first) != part.end())
                {
                    if (it->second == left - 1)
                    {
                        //it->second = itright->second;
                        //full.erase(itright);

                        left = it->first;
                        right = itright->second;
                        full.erase(it);
                        full.erase(itright);
                        full.insert({left, right});
                    }
                    else
                    {
                        //itright->first = left;
                        right = itright->second;
                        full.erase(itright);
                        full.insert({left, right});
                    }
                }
                else if (it->second == left - 1)
                {
                    //it->second = right;
                    left = it->first;
                    full.erase(it);
                    full.insert({left, right});
                }
                else
                {
                    full.insert({left, right});
                }
            }
        }

        cout << "Case #" << z << ": " << ans << endl;
    }
}
