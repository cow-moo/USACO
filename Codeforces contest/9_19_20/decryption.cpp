#include <iostream>
#include <vector>
using namespace std;

int pCount = 0;
vector<long long> factors;
void generate_primes(long long n)
{
    factors.push_back(1);

    if (n % 2 == 0)
    {
        pCount++;
        long long exp = 2;
        while (n % 2 == 0)
        {
            factors.push_back(exp);
            n /= 2;
            exp *= 2;
        }
    }

    for (long long i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            pCount++;
            vector<long long> newFactors;
            long long exp = i;
            while (n % i == 0)
            {
                for (int j = factors.size() - 1; j >= 0; j--)
                {
                    newFactors.push_back(factors[j] * exp);
                    //cout << f << " " << i << endl;
                }
                n /= i;
                exp *= i;
            }
            for (long long nf : newFactors)
                factors.push_back(nf);
        }
    }
    if (n != 1)
    {
        pCount++;
        vector<long long> newFactors;

        for (int j = factors.size() - 1; j >= 0; j--)
        {
            newFactors.push_back(factors[j] * n);
            //cout << f << " " << i << endl;
        }

        for (long long nf : newFactors)
            factors.push_back(nf);
    }
}

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        long long n;
        cin >> n;
        generate_primes(n);

        swap(factors[factors.size() - 2], factors[factors.size() - 1]);
        for (int i = 1; i < factors.size(); i++)
            cout << factors[i] << " ";
        cout << endl;
        if (pCount == 2 && factors.size() == 4)
            cout << 1 << endl;
        else
            cout << 0 << endl;

        pCount = 0;
        factors.clear();
    }
}
