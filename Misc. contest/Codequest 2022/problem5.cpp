#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.get();

    for (int i = 0; i < n; i++)
    {
        string s;
        //cin >> s;
        getline(cin, s);

        int name = s.find(',');
        //cout << name << endl;
        cout << s.substr(0, name) << "=";

        int hours = 0;
        int minutes = 0;
        for (int j = name + 1; j < s.length(); j += 6)
        {
            stringstream temp(s.substr(j, 2));
            int temp1 = 0;
            temp >> temp1;
            //cout << temp1 << endl;
            hours += temp1;
            //temp.str(s.substr(j + 3, 2));
            //temp.clear();
            stringstream temp2(s.substr(j + 3, 2));
            temp2 >> temp1;
            minutes += temp1;
            //cout << stoi(s.substr(j, 2)) << endl;
        }

        hours += minutes / 60;
        minutes %= 60;
        //cout << hours << " " << minutes << endl;
        cout << hours;
        if (hours == 1)
            cout << " hour";
        else
            cout << " hours";

        if (minutes == 1)
        {
            cout << " 1 minute";
        }
        else if (minutes != 0)
        {
            cout << " " << minutes << " minutes";
        }
        cout << endl;
    }
}
/*
3
Peter Gibbons,01:23,04:16,00:59,02:23,00:00
Milton Waddams,08:00,08:00,08:00,08:00,08:00
Bill Lumbergh,08:31,07:59,06:01,08:55,05:30
*/
