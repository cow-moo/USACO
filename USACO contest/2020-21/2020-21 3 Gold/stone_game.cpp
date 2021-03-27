#include <iostream>
#include <algorithm>
using namespace std;

int stones[100005];

int main()
{
    int n, maxStones = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> stones[i];
        maxStones = max(maxStones, stones[i]);
    }

    sort(stones, stones + n + 1);

    long long ans = 0;
    for (int i = 1; i <= maxStones; i++)
    {
        //cout << "i: " << i << endl;
        int curPile = -1;
        int num = 0;
        int firstOdd = -1;
        int firstNum = 0;
        int secondOdd = -1;
        bool tooManyOdd = false;
        for (int j = n; j >= 0; j--)
        {
            //cout << stones[j] / i << " ";
            if (stones[j] / i != curPile)
            {
                if (num % 2 == 1)
                {
                    if (firstOdd == -1)
                    {
                        firstOdd = curPile;
                        firstNum = num;
                    }
                    else if (secondOdd == -1)
                    {
                        secondOdd = curPile;
                        if (secondOdd + 1 != firstOdd)
                            break;
                    }
                    else
                    {
                        tooManyOdd = true;
                        break;
                    }
                }

                if (stones[j] / i == 0)
                    break;

                curPile = stones[j] / i;
                num = 1;
            }
            else
                num++;
        }
        //cout << endl;

        if (!tooManyOdd)
        {
            if ((secondOdd != -1 && secondOdd + 1 == firstOdd) || (secondOdd == -1 && firstOdd == 1))
            {
                ans += firstNum;
            }
        }
    }

    cout << ans << endl;
}
