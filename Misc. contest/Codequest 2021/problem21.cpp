#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
using namespace std;

vector<pair<int, int> > landmarks;
vector<pair<double, double> > stops;
vector<pair<pair<double, double>, int> > stopInfo;
//sum of x and y, num of landmarks

double distSquared(int li, int si)
{
    return (landmarks[li].first - stops[si].first) * (landmarks[li].first - stops[si].first) + (landmarks[li].second - stops[si].second) * (landmarks[li].second - stops[si].second);
}

double roundPlaces(double num, int places)
{
    return round(num*pow(10,places))/pow(10,places);
}

bool compare(double a, double b)
{
    //return fabs(a - b) < 0.0001;
    return a == b;
}

int main()
{
    int t;
    cin >> t;

    cout << fixed;
    cout << setprecision(1);

    for (int z = 0; z < t; z++)
    {
        int l, s;
        cin >> l >> s;
        landmarks.clear();
        stops.clear();
        stopInfo.clear();
        landmarks.resize(l);
        stops.resize(s);
        stopInfo.resize(s);

        for (int i = 0; i < l; i++)
        {
//            int x, y;
//            cin >> x >> y;
//            landmarks.push_back({x, y});
            cin >> landmarks[i].first >> landmarks[i].second;
        }
        for (int i = 0; i < s; i++)
        {
//            int x, y;
//            cin >> x >> y;
//            stops.push_back({x, y});
//            stopInfo.push_back({0, 0});
            cin >> stops[i].first >> stops[i].second;
        }

        //cout << distSquared(5, 0) << endl;

        while (true)
        {
            pair<pair<double, double>, int> reset = {{0, 0}, 0};
            fill(stopInfo.begin(), stopInfo.end(), reset);

            //register each landmark to a stop
            for (int i = 0; i < l; i++)
            {
                double minDistSquared = -1;
                int minStop;
                for (int j = 0; j < s; j++)
                {
                    if (minDistSquared == -1 || distSquared(i, j) < minDistSquared || (compare(distSquared(i, j), minDistSquared) && stops[j] < stops[minStop]))
                    {
                        minStop = j;
                        minDistSquared = distSquared(i, j);
                    }
                }

                stopInfo[minStop].first.first += landmarks[i].first;
                stopInfo[minStop].first.second += landmarks[i].second;
                stopInfo[minStop].second++;
            }

            //update and check for change
            bool change = false;
            for (int i = 0; i < s; i++)
            {
                double newx = stopInfo[i].first.first / stopInfo[i].second;
                double newy = stopInfo[i].first.second / stopInfo[i].second;
                if (!compare(newx, stops[i].first) || !compare(newy, stops[i].second))
                {
                    change = true;
                    stops[i].first = newx; stops[i].second = newy;
                    //cout << newx << " " << newy << endl;
                }
            }

            if (!change)
                break;
        }
        for (int i = 0; i < s; i++)
        {
            cout << roundPlaces(stops[i].first, 1) << " " << roundPlaces(stops[i].second, 1) << endl;
        }
    }
}
