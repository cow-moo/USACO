#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        long long l, n;
        cin >> l >> n;

        long long ans = 0;
        long long curc = 0;
        long long cura = 0;
        for (int i = 0; i < n; i++)
        {
            long long d;
            char c;
            cin >> d >> c;

            if (c == 'C')
            {
                if (cura > 0)
                {
                    if (cura - d < 0)
                    {
                        curc = d - cura;
                        cura = 0;
                    }
                    else
                    {
                        cura -= d;
                    }
                }
                else
                {
                    curc += d;
                }
            }
            else
            {
                if (curc > 0)
                {
                    if (curc - d < 0)
                    {
                        cura = d - curc;
                        curc = 0;
                    }
                    else
                    {
                        curc -= d;
                    }
                }
                else
                {
                    cura += d;
                }
            }

            ans += curc / l;
            curc %= l;
            ans += cura / l;
            cura %= l;

            //cout << curc << " " << cura << " " << ans << endl;
        }
        cout << "Case #" << z << ": " << ans << endl;
    }
}
