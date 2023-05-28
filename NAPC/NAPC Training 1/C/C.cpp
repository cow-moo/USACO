#include <iostream>
#include <vector>
#include <optional>
using namespace std;
using ll = long long;
int n,m;
vector<vector<char>> A(3, vector<char>(m));

using num = int;

num parse_int(int i, int j, int len, int& consumed) {
    
}

num parse_term(int i, int j, int len, int& consumed) {
    int l;
    num a = parse_int(i, j, len, l);
    if (j + l + 1 < len && A[i][j + l + 1] == '*') {
        a *= parse_int(i, j + l + 2, len, l);

    }
    return a;

}

optional<num> parse_simple(pair<int, int> start, int len, int& consumed) {
    int l;
    if (optional<num> res = parse_term(start, len, l)) {
        return res;
    }
}   

void parse_term(pair<int, int> start, int len) {
    auto [i,y] = start;
    
}

void parse_simple(pair<int, int> start, int len) {
    
}   



int main() {

    cin >> n >> m;

    int d = n == 3 ? 0 : 1;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++){
            cin >> A[i+d][j];
        }
    }

    auto parse_int = [&](pair<int, int> start) {

    };
    auto parse_line = [&](pair<int,int> start, int len) {
        auto [i,y] = start;
        for (int j=y;j<y+len;j++) {

        }
    };
    int cur = 0;
    

    
}