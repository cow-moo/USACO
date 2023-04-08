#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long n;
    int k;
    cin >> n >> k;

    vector<long long> terms;
    terms.push_back(-n);

    for (int i = 0; i < k; i++)
    {
        long long p;
        cin >> p;
        for (int j = terms.size() - 1; j >= 0; j--)
        {
            terms.push_back(-terms[j] / p);
        }
    }

    long long res = 0;
    for (int i = 1; i < terms.size(); i++)
    {
        res += terms[i];
    }
    cout << res << endl;
}
