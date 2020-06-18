//checks if a point is enclosed within a polygon
//assumes point is not on polygon sides, but code can probably be adjusted for that
//polygon given as a list of consecutive vertices with the last one equal to the first

bool is_enclosed(vector<pair<int, int> > const &verts, pair<int, int> point) {
    int intersectCount = 0;

    //extend ray vertically and count intersections
    for (int i = 0; i < verts.size() - 1; i++) {
        //point.x must be >= l.first and < r.first
        pair<int, int> l, r;
        if (verts[i].first < verts[i + 1].first) {
            l = verts[i]; r = verts[i + 1];
        }
        else if (verts[i].first > verts[i + 1].first) {
            l = verts[i + 1]; r = verts[i];
        }
        //if line is vertical, we can ignore (can be proven to work))
        else
            continue;

        if (point.first >= l.first && point.first < r.first) {
            intersectCount += ((long long) (r.second - l.second) * (point.first - l.first) >
                               (long long) (point.second - l.second) * (r.first - l.first));
        }
    }
    return intersectCount % 2;
}
