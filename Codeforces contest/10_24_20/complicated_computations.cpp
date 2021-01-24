#include <iostream>
#include <vector>
using namespace std;

struct Vertex
{
    Vertex *l, *r;
    int minim;
    int pos = -1;

    Vertex(int val, int pos) : l(nullptr), r(nullptr), minim(val), pos(pos) {}
    Vertex (Vertex *l, Vertex *r): l(l), r(r), minim(1000000)
    {
        if (l)
            minim = min(minim, l->minim);
        if (r)
            minim = min(minim, r->minim);
    }
};

//tl and tr are the range of the interval that the vertex is responsible for
Vertex* build(int tl, int tr)
{
    //if leaf, create with no children
    if (tl == tr)
        return new Vertex(-1, tl);
    int tm = (tl + tr) / 2;
    return new Vertex(build(tl, tm), build(tm + 1, tr));
}

int get_min(Vertex* v, int tl, int tr, int l, int r)
{

}

//v is the root of the segment tree we want to update
//tl and tr are passed to update correct nodes
Vertex* update(Vertex* v, int tl, int tr, int pos, int new_val)
{
    if (tl == tr)
        return new Vertex(new_val, tl);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos, new_val), v->r);
    else
        return new Vertex(v->l, update(v->r, tm + 1, tr, pos, new_val));
}

//returns pos of the first element with value smaller than val
int FirstSmaller(Vertex* v, int tl, int tr, int val)
{
    while (v->pos == -1)
    {
        if (v->l->minim < val)
        {
            v = v->l;
        }
        else
        {
            v = v->r;
        }
    }
    return v->pos;
}

int arr[100050];
Vertex* roots[100050];
vector<int> locations[100050];

int main()
{
    int n;
    cin >> n;
    roots[0] = build(1, n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        locations[arr[i]].push_back(i);
        roots[i] = update(roots[i - 1], 1, n + 1, arr[i], i);
    }

    for (int i = 1; i <= n + 2; i++)
    {
        int prev = 0;
        bool done = true;
        locations[i].push_back(n + 1);
        for (int j : locations[i])
        {
            //cout << i << " " << j << " " << prev << " " << FirstSmaller(roots[j - 1], 1, n, prev + 1) << endl;
            if (j - 1 >= prev + 1 && FirstSmaller(roots[j - 1], 1, n + 1, prev + 1) == i)
            {
                done = false;
                break;
            }
            prev = j;
        }
        if (done)
        {
            cout << i << endl;
            break;
        }
    }

//    for (int i = 1; i <= n + 2; i++)
//    {
//        int prev = 0;
//        bool done = true;
//        for (int j = 1; j <= n + 1; j++)
//        {
//            if (arr[j] == i || j == n + 1)
//            {
//                //cout << i << " " << j << " " << prev << " " << FirstSmaller(roots[j - 1], 1, n, prev + 1) << endl;
//                if (FirstSmaller(roots[j - 1], 1, n + 1, prev + 1) == i)
//                {
//                    done = false;
//                    break;
//                }
//                prev = j;
//            }
//        }
//        if (done)
//        {
//            cout << i << endl;
//            break;
//        }
//    }
}
