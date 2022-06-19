#include <iostream>
using namespace std;

int main()
{
    int q;
    cin >> q;

    for (int z = 0; z < q; z++)
    {
        int n;
        cin >> n;

        string s, t;
        cin >> s >> t;

        int sb = -1, tb = -1;
        while (true)
        {
            sb = s.find("b", sb + 1);
            tb = t.find("b", tb + 1);

            //cout << sb << " " << tb << endl;

            if (sb  == -1 || tb == -1)
                break;

            bool works = true;
//            if (sb < tb)
//            {
//                for (int i = sb + 1; i <= tb; i++)
//                {
//                    if (s[i] != 'c')
//                    {
//                        works = false;
//                        break;
//                    }
//                }
//                if (works)
//                {
//                    swap(s[sb], s[tb]);
//                    sb = tb;
//                }
//            }
            if (sb > tb)
            {
                for (int i = tb; i < sb; i++)
                {
                    if (s[i] != 'a')
                    {
                        works = false;
                        break;
                    }
                }
                if (works)
                    swap(s[sb], s[tb]);
            }

            if (!works)
                break;
        }

        sb = tb = n;
        while (true)
        {
            if (sb  == 0 || tb == 0)
                break;

            sb = s.rfind("b", sb - 1);
            tb = t.rfind("b", tb - 1);

            //cout << sb << " " << tb << endl;

            if (sb  == -1 || tb == -1)
                break;

            bool works = true;
            if (sb < tb)
            {
                for (int i = sb + 1; i <= tb; i++)
                {
                    if (s[i] != 'c')
                    {
                        works = false;
                        break;
                    }
                }
                if (works)
                {
                    swap(s[sb], s[tb]);
                    //sb = tb;
                }
            }

            if (!works)
                break;
        }

        cout << (s == t ? "YES" : "NO") << endl;
    }
}
