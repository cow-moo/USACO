#include <iostream>
#include <map>
#include <stdlib.h>
#include <algorithm>
#include <sstream>
using namespace std;
#define MAXN 50
#define MOD 1000000007

struct Pt
{
    int x, y;
    Pt(){}
    Pt(int _x, int _y) : x(_x), y(_y){}
    Pt operator-(const Pt &p) const { return Pt(x - p.x, y - p.y); }
    int cross(const Pt &p) const { return x * p.y - y * p.x; }
    //cross subtracting this
    int crossAbs(const Pt &a, const Pt &b) const { return abs((a - *this).cross(b - *this)); }
};



int n;
Pt pts[MAXN];
//i<j<k

int numInside[MAXN][MAXN][MAXN];

bool isInside(int p, int a, int b, int c)
{
    return pts[a].crossAbs(pts[b], pts[c]) == pts[p].crossAbs(pts[a], pts[b]) + pts[p].crossAbs(pts[b], pts[c]) + pts[p].crossAbs(pts[c], pts[a]);
}

void generateNumInside()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = 0; l < n; l++)
                {
                    if (l != i && l != j && l != k)
                    {
                        if (isInside(l, i, j, k))
                        {
                            numInside[i][j][k]++;
                            //cout << i + 1 << " " << j + 1 << " " << k + 1 << " " << l + 1 << endl;
                        }
                        //numInside[i][j][k] += isInside(l, temp);
                    }
                }
            }
        }
    }
}

struct State
{
    //vertex indexes
    int vertices[3];
    int insideUsed;

//    bool operator==(const State& rhs) const
//    {
//        return vertices[i] =
//    }
    bool operator<(const State& rhs) const
    {
        for (int i = 0; i < 3; i++)
        {
            if (vertices[i] < rhs.vertices[i])
                return true;
            else if (vertices[i] > rhs.vertices[i])
                return false;
        }
        return false;
    }

    bool checkReplace(int index, int p)
    {
        int temp = vertices[index];
        vertices[index] = p;

        bool result = isInside(temp, vertices[0], vertices[1], vertices[2]);

        vertices[index] = temp;
        return result;
    }

    void replaceVertex(int index, int p)
    {
        vertices[index] = p;
        sort(vertices, vertices + 3);
    }

    string getPrint() const
    {
        ostringstream ss;
        ss << vertices[0] + 1 << " " << vertices[1] + 1 << " " << vertices[2] + 1 << ", " << insideUsed;
        return ss.str();
    }
};

map<State, long long> dp;
map<State, long long> dpNext;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> pts[i].x >> pts[i].y;
    }

    generateNumInside();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                State newState = {i, j, k, 0};
                dp[newState] = 6;
                //cout << newState.getPrint() << endl;
            }
        }
    }
//    cout << dp.size() << endl;
//    for (auto p : dp)
//    {
//        cout << p.first.getPrint() << endl;
//    }

    for (int z = 0; z < n - 3; z++)
    {
        for (auto p : dp)
        {
            State state = p.first;
            long long cnt = p.second;
            //cout << state.getPrint() << ": " << cnt << endl;
            int insideTotal = numInside[state.vertices[0]][state.vertices[1]][state.vertices[2]];
            if (insideTotal - state.insideUsed > 0)
            {
                State newState = state;
                newState.insideUsed++;
                dpNext[newState] += cnt * (insideTotal - state.insideUsed);
                dpNext[newState] %= MOD;
            }

            for (int i = 0; i < n; i++)
            {
                if (i == state.vertices[0] || i == state.vertices[1] || i == state.vertices[2])
                    continue;

                for (int j = 0; j < 3; j++)
                {
                    if (state.checkReplace(j, i))
                    {
                        State newState = state;
                        newState.replaceVertex(j, i);
                        newState.insideUsed++;
                        dpNext[newState] += cnt;

                        dpNext[newState] %= MOD;
                        //cout << newState.getPrint() << endl;
                    }
                }
            }
        }

        dp = dpNext;
        dpNext.clear();
    }
//    cout << endl;
//    for (auto p : dp)
//    {
//        cout << p.first.getPrint() << ": " << p.second << endl;
//    }
    //cout << dp.begin()->first.getPrint() << endl;
    cout << dp.begin()->second << endl;
}
