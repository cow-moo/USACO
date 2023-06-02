#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>
#include <set>
#include <sstream>
#include <array>
#include <algorithm>

using namespace std;

using num = long long;

struct Relation {
    array<num,4> coeffs = {};
    num c = 0;
    int n;
    Relation(int n) : n(n) {}
    Relation combine(const Relation& other, int i) const {
        num lcm = -coeffs[i] * other.coeffs[i] / gcd(coeffs[i], other.coeffs[i]);
        auto a = (*this) * (lcm / coeffs[i]);
        auto b = other * (lcm / other.coeffs[i]);
        return a + b;
    }
    Relation operator+(const Relation& other) const {
        Relation res(n);
        for (int i=0;i<n;i++){
            res.coeffs[i] = coeffs[i] + other.coeffs[i];
        }
        res.c = c + other.c;
        return res;
    }
    Relation operator*(num k) const {
        Relation res = *this;
        res.c *= k;
        for (int i=0;i<n;i++){
            res.coeffs[i] *= k;
        }
        return res;
    }
    void substitute(int i, num x) {
        c += coeffs[i] * x;
        coeffs[i] = 0;
    }
    bool operator<(const Relation& other) const {
        return tie(coeffs, c, n) < tie(other.coeffs, other.c, other.n);
    }
    
};

int n = 0;
bool contradiction = false;

//ret true if contra
//nonzero at index
void taut(set<Relation> &s, int index)
{
    set<Relation> res;
    vector<Relation> temp;
    for (auto it1 = s.begin(); it1 != s.end(); it1++)
    {
        for (auto it2 = next(it1); it2 != s.end(); it2++)
        {  
            // if (it1->coeffs[index] == 0 || it2->coeffs[index] == 0) continue;
            num lcm = abs(it1->coeffs[index] * it2->coeffs[index]) / gcd(abs(it1->coeffs[index]), abs(it2->coeffs[index]));
            auto a = (*it1) * abs(lcm / it1->coeffs[index]);
            auto b = (*it2) * abs(lcm / it2->coeffs[index]);
            bool same = true;
            for (int i = 0; i < n; i++)
            {
                if (a.coeffs[i] != b.coeffs[i])
                {
                    same = false;
                    break;
                }
            }
            if (!same) {
                it2++;
                continue;
            }
            if (a.coeffs[index] * b.coeffs[index] > 0)
            {
                if (a.c > b.c)
                {
                    temp.push_back(b);
                }
                else
                {
                    temp.push_back(a);
                }
                auto temp1 = it1;
                --it1;
                s.erase(temp1);
                auto temp2 = it2;
                --it2;
                s.erase(temp2);
            }
            else
            {
                if (a.c + b.c < 0)
                    contradiction = true;
                //contra
            }
        }
    }
}

int solve(vector<Relation> s, int index)
{
    bool lset = false, rset = false;
    num lower, upper;

    for (auto &rel : s)
    {
        //lower bound
        if (rel.coeffs[index] > 0)
        {
            if (!lset || ceil(rel.c / rel.coeffs[index]) < lower)
            {
                lset = true;
                lower = ceil(rel.c / rel.coeffs[index]);
            }
        }
        else
        {
            if (!rset || rel.c / rel.coeffs[index] > upper)
            {
                rset = true;
                upper = rel.c / rel.coeffs[index];
            }
        }
    }

    if (lset && rset && lset > rset)
        contradiction = true;

    return lower;
}

int main() {
    vector<string> var_names;
    string line;
    vector<Relation> sets[5];
    while (getline(cin, line)) {
        istringstream stream(line);
        switch (line[0]){
        case 'V': {
            string a, v;
            stream >> a >> v;
            var_names.push_back(a);
            n++;
            break;
        }
        case 'R': {
            string r;
            stream >> r;
            Relation relation(n);
            for (int i=0;i<n;i++){
                stream >> relation.coeffs[i];
            }
            string re;
            stream >> re;
            stream >> relation.c;
            relation.c *= -1;
            if (re == "<=") {
                relation = relation * -1;
            }
            sets[0].push_back(relation);
            break;
        }
        }
    }
    
    for (int i=0;i<n;i++){
        //taut(sets[i], i);
        vector<Relation> l, r, none;
        for (auto &rel : sets[i])
        {
            if (rel.coeffs[i] > 0)
                l.push_back(rel);
            else if (rel.coeffs[i] < 0)
                r.push_back(rel);
            else
                none.push_back(rel);
        }
        for (auto &rel1 : l)
        {
            for (auto &rel2 : r)
            {
                Relation res = rel1.combine(rel2, i);
                sets[i + 1].push_back(res);
            }
        }
    }

    num ans[10];
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] = solve(sets[i], i);
        for (int j = 0; j < i; j++)
        {
            for (auto &rel : sets[j])
            {
                rel.substitute(i, ans[i]);
            }
        }
    }

    if (contradiction)
    {
        cout << "No solution" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << var_names[i] << " := " << ans[i] << endl;
        }
    }
}

/*
V x
V y
R 2 1 <= 10
R 2 1 >= 5
R -1 2 <= 5
R -1 2 >= 0
*/