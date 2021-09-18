#include <iostream>
using namespace std;

//num[i] counts how many 100..0 with i number of zeros
int num[12];

int setupNum(int s)
{
    int res = 0;
    int cnt = 0;
    while (s > 0)
    {
        num[cnt++] = s % 10;
        res += s % 10;
        s /= 10;
    }
    return res;
}

int printAns(int n)
{
    if (n == 1)
        return 0;

    int sum = 0;
    int dig = 1;
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j < num[i]; j++)
        {
            cout << dig << " ";
            sum += dig;
            n--;

            if (n == 1)
                return sum;
        }
        dig *= 10;
    }
}

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int s, n;
        cin >> s >> n;
        int cur = setupNum(s);

//        for (int i = 0; i < 10; i++)
//        {
//            cout << i << ": " << num[i] << endl;
//        }
//        cout << cur << endl;

        while (cur < n)
        {
            //cout << "bad" << endl;
            for (int i = 1; i <= 9; i++)
            {
                if (num[i] > 0)
                {
                    num[i]--;
                    num[i - 1] += 10;

                    cur += 9;
                    break;
                }
            }
        }

        int sum = printAns(n);
        cout << s - sum << endl;
    }
}
