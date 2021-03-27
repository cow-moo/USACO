#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int cnt[30];
int pairs[30][30];
unordered_map<int, int> curMap;
unordered_map<int, int> prevMap;

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int get_sum(int letter, int used)
{
    int sum = 0;
    for (int i = 0; i < 26; i++)
    {
        if (!(used & (1 << i)) && i != letter)
        {
            sum += pairs[letter][i];
        }
    }
    return sum;
}

int main()
{
    string str;
    cin >> str;

    for (int i = 0; i < str.length(); i++)
        cnt[str[i] - 'a']++;

    for (int i = 1; i < str.length(); i++)
    {
        pairs[str[i - 1] - 'a'][str[i] - 'a']++;
    }

    prevMap.emplace(0, 0);

    for (int i = 0; i < 26; i++)
    {
        //prevMap = curMap;
        curMap.clear();
        int maxVal = 0;
        //cout << i << endl;
        for (pair<int, int> maxim : prevMap)
        {
            for (int j = 0; j < 26; j++)
            {
                if (!(maxim.first & (1 << j)))
                {
                    int sum = get_sum(j, maxim.first);
                    if (sum == 0)
                        continue;
                    if (!curMap.count(maxim.first + (1 << j)))
                    {
                        curMap.emplace(maxim.first + (1 << j), maxim.second + sum);
                    }
                    else
                    {
                        curMap[maxim.first + (1 << j)] = max(curMap[maxim.first + (1 << j)], maxim.second + sum);
                    }
                    maxVal = max(maxVal, maxim.second + sum);
                }
            }
        }

        if (curMap.size() == 0)
        {
            //cout << prevMap.size() << endl;
            for (pair<int, int> p : prevMap)
            {
                maxVal = max(maxVal, p.second);
            }
            curMap.insert({0, maxVal});
            break;
        }

//        prevMap.clear();
//        vector<pair<int, int> > temp;
//        for (pair<int, int> p : curMap)
//        {
////            if (p.second >= maxVal / 2)
////            {
////                prevMap.insert(p);
////            }
//            temp.push_back(p);
//        }
//        sort(temp.begin(), temp.end(), comp);
//        for (int i = 0; i < min((int)temp.size(), 1000); i++)
//        {
//            prevMap.insert(temp[i]);
//        }

        prevMap = curMap;

    }

    cout << str.length() - curMap.begin()->second << endl;
}
