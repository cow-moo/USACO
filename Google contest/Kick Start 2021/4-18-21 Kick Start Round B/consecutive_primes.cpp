#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
#define MAXN 50000

bool notPrime[MAXN + 100];
vector<int> primes;

int main()
{
    //cout << "a" << endl;
    for (int i = 2; i <= MAXN; i++)
    {
        if (!notPrime[i])
        {
            primes.push_back(i);
            for (long long j = (long long)i * i; j <= MAXN; j += i)
            {
                //if (j > MAXN)
                    //cout << j << endl;
                notPrime[j] = true;
            }
        }
        //if (i % 100 == 0)
        //    cout << i << endl;
    }

//    cout << primes.size() << endl;
//    return 0;

//    for (int i = 0; i < 10; i++)
//        cout << primes[i] << endl;
    //cout << primes[primes.size() - 1] << endl;
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        long long num;
        cin >> num;

        if (num < 15)
        {
            cout << "Case #" << z << ": " << 6 << endl;
            continue;
        }

        int root = sqrt(num);
        if (root % 2 == 0)
            root--;
        int firstPrime;

        //cout << "Root " << root << endl;
        for (int i = root; i >= 3; i -= 2)
        {
            firstPrime = i;
            for (int j = 0; j < primes.size() && primes[j] * primes[j] <= i; j++)
            {
                if (i % primes[j] == 0)
                {
                    firstPrime = 0;
                    break;
                }
            }
            if (firstPrime != 0)
                break;
        }
        //cout << "fp " << firstPrime << endl;

        int secondPrime = 0;
        for (int i = root + 2; (long long)i * firstPrime <= num; i += 2)
        {
            secondPrime = i;
            for (int j = 0; j < primes.size() && primes[j] * primes[j] <= i; j++)
            {
                if (i % primes[j] == 0)
                {
                    secondPrime = 0;
                    break;
                }
            }
            //cout << i << " " << secondPrime << endl;
            if (secondPrime != 0)
                break;
        }
        //cout << "sp1 " << secondPrime << endl;

        if (secondPrime == 0)
        {
            for (int i = firstPrime - 2; i >= 3; i -= 2)
            {
                secondPrime = i;
                for (int j = 0; j < primes.size() && primes[j] * primes[j] <= i; j++)
                {
                    if (i % primes[j] == 0)
                    {
                        secondPrime = 0;
                        break;
                    }
                }
                //cout << i << " " << secondPrime << endl;
                if (secondPrime != 0)
                    break;
            }
        }

        cout << "Case #" << z << ": " << (long long)firstPrime * secondPrime << endl;
        //cout << firstPrime << " " << secondPrime << endl;
    }
}
