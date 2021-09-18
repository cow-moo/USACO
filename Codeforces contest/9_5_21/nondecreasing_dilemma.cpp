#include <iostream>
using namespace std;
#define P pair<long long, pair<long long, long long> >
//sum, l size, r size
//if sum == -1 and l == r then current segment completely inside increasing subarray, special case
//if sum == 0 and either l or r == 0 then current segment is end of increasing subarray, prob regular behavior
P tree[800050];
int arr[200050];
int n;

void printstr (P a)
{
    cout << "(" << a.first << ", " << a.second.first << ", " << a.second.second << ")";
}

P combine(P a, P b)
{
    P res = {0, {0, 0}};

    if (a.first != -1 && b.first != -1)
    {
        res.first = a.first + b.first;
        long long newl = a.second.second + b.second.first;
        res.first += newl * (newl + 1) / 2;

        res.second = {a.second.first, b.second.second};
    }
    else if (a.first == -1 && b.first == -1)
    {
        res.first = -1;
        res.second = {a.second.first + b.second.first, a.second.second + b.second.second};
    }
    else
    {
        if (a.first == -1)
        {
            res.first = b.first;
            res.second = {b.second.first + a.second.first, b.second.second};
        }
        else if (b.first == -1)
        {
            res.first = a.first;
            res.second = {a.second.first, a.second.second + b.second.second};
        }
    }

//    cout << "comb: ";
//    printstr(a);
//    cout << " + ";
//    printstr(b);
//    cout << " = ";
//    printstr(res);
//    cout << endl;
    return res;//{sum, a.second.first, b.second.second};
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = {0, {0, 0}};
        if (tl + 1 < n && arr[tl] <= arr[tl + 1])
            tree[v].second.second = 1;
        if (tl - 1 >= 0 && arr[tl] >= arr[tl - 1])
            tree[v].second.first = 1;

        if (tree[v].second.first == 0 && tree[v].second.second == 0)
        {
            tree[v].first = 1;
        }
        else if (tree[v].second.first == 1 && tree[v].second.second == 1)
        {
            tree[v].first = -1;
        }

        //cout << tl << ": " << tree[v].first << " " << tree[v].second.first << " " << tree[v].second.second << endl;
    }
    else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
    }
}

P query(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return {-1, {0, 0}};
    }
    if (l == tl && r == tr) {
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    //cout << tl << " " << tr << endl;
    return combine(query(v * 2, tl, tm, l, min(r, tm)), query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

//update val then call
void update(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        //cout << tl << ": " << tree[v].first << " " << tree[v].second.first << " " << tree[v].second.second << endl;
        //tree[v] = newVal;
        tree[v] = {0, {0, 0}};
        if (tl + 1 < n && arr[tl] <= arr[tl + 1])
            tree[v].second.second = 1;
        if (tl - 1 >= 0 && arr[tl] >= arr[tl - 1])
            tree[v].second.first = 1;

        if (tree[v].second.first == 0 && tree[v].second.second == 0)
        {
            tree[v].first = 1;
        }
        else if (tree[v].second.first == 1 && tree[v].second.second == 1)
        {
            tree[v].first = -1;
        }
        //cout << tl << ": " << tree[v].first << " " << tree[v].second.first << " " << tree[v].second.second << endl;
    }
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos);
        else
            update(v * 2 + 1, tm + 1, tr, pos);
        tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
        //cout << tl << " " << tr << endl;
    }
}

int main() {
    int q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build(1, 0, n - 1);
    //P temp = query(1, 0, n - 1, 2, 1);
    //cout << temp.first << " " << temp.second.first << " " << temp.second.second << endl;

    //return 0;

    for (int i = 0; i < q; i++)
    {
        int t, x, y;
        cin >> t >> x >> y;

        if (t == 1)
        {
            arr[x - 1] = y;
            update(1, 0, n - 1, x - 1);
            if (x - 2 >= 0)
                update(1, 0, n - 1, x - 2);
            if (x < n)
                update(1, 0, n - 1, x);
        }
        else
        {
            long long ans = 0;
            P temp = query(1, 0, n - 1, x - 1, y - 1);
            if (temp.first != -1)
            {
                ans += temp.first;
                ans += temp.second.first * (temp.second.first + 1) / 2;
                ans += temp.second.second * (temp.second.second + 1) / 2;
            }
            else
            {
                ans += temp.second.first * (temp.second.first + 1) / 2;
            }
            //cout << "a: " << temp.first << " " << temp.second.first << " " << temp.second.second << endl;
            cout << ans << endl;
        }
    }

//    cout << sum(1, 0, n - 1, 1, 6) << endl;
//    update(1, 0, n - 1, 3, 5);
//    cout << sum(1, 0, n - 1, 1, 6) << endl;
}

/*
5 6
3 1 4 1 5
2 2 5
2 1 3
1 4 4
2 2 5
1 2 6
2 2 5

5 6
3 1 4 1 5
2 2 5
1 4 4
2 2 5
*/
