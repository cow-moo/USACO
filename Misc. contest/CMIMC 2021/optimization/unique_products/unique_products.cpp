#include <iostream>
#include <set>
#include <vector>
#include <stdio.h>
#include <fstream>
using namespace std;

set<int> sets[10];
bool notPrime[40050];
vector<int> primes;

void GeneratePrimes(int m)
{
    for (int i = 2; i * i <= m; i++)
    {
        if (!notPrime[i])
        {
            for (int j = i * i; j <= m; j += i)
                notPrime[j] = true;
        }
    }

    for (int i = 2; i <= m; i++)
    {
        if (!notPrime[i])
            primes.push_back(i);
    }
}

//which set, which prime, upper limit on values
void AddPrime(int i, int p, int m)
{
    set<int> newSet = sets[i];

    for (int pow = p; pow <= m; pow *= p)
    {
        for (int num : sets[i])
        {
            if (num * pow <= m)
                newSet.insert(num * pow);
            else
                break;
        }
    }

    sets[i] = newSet;
}

int main()
{
    int n, m;
    cin >> n >> m;

    GeneratePrimes(m);
//    for (int p : primes)
//        cout << p << " ";
//    cout << endl;

    for (int i = 0; i < n; i++)
    {
        sets[i].insert(1);
    }
    //cout << primes.size() << endl;
//greedy: 99
    for (int i = 0; i < primes.size(); i++)
    {
        int minim = 0;
        for (int j = 0; j < n; j++)
        {
            if (sets[j].size() < sets[minim].size())
                minim = j;
        }

        AddPrime(minim, primes[i], m);
        //cout << i << endl;
    }

//alternating: 82, 667
//    for (int i = 0; i < primes.size(); i++)
//    {
//        AddPrime(i % 2, primes[i], m);
//    }

    int minim = 0;
    for (int j = 0; j < n; j++)
    {
        if (sets[j].size() < sets[minim].size())
            minim = j;
    }
    minim = sets[minim].size();

    ofstream fout;
    fout.open("output6.txt");
    for (int i = 0; i < n; i++)
    {
        cout << "Set " << i << ": " << sets[i].size() << endl;
        int counter = 0;
        for (int num : sets[i])
        {
            if (counter >= minim)
                break;
            fout << num << " ";
            counter++;
        }
        fout << endl;
    }
    fout.close();
}
