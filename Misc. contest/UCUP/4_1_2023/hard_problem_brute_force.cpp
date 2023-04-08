#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i=0;i<n;i++) cin >> A[i];
    int ans = 1e9;
    auto dfs = [&](auto self, int cnt) -> void {
      bool ok = true;
      for (int i=0;i<n;i++) {
        if (A[i] != 0) {
          ok = false;
        }
      }
      if (ok) {
        ans = min(ans, cnt);
        return;
      }
      for (int l=0;l<n;l++){
        for (int r=l;r<n;r++){
          bool oo = true;
          for (int i=l;i<=r;i++){
            if (A[i] == 0) oo = false;
          }
          if (oo) {
            for (int i=l;i<=r;i++){
              A[i]--;
            }
            self(self, cnt+1);
            for (int i=l;i<=r;i++){
              A[i]++;
            }
          }
          oo = true;
          int cnt2 =0;
          for (int i=l;i<=r;i++){
            if (i%2 == 0 && A[i] == 0) oo = false;
            if (i%2 == 0) cnt2++;
          }
          if (oo && cnt2 > 1) {
            for (int i=l;i<=r;i++){
              if  (i%2 == 0)
              A[i]--;
            }
            self(self, cnt+1);
            for (int i=l;i<=r;i++){
              if  (i%2 == 0)
                A[i]++;
            }
          }
          oo = true;
          cnt2=0;
          for (int i=l;i<=r;i++){
            if (i%2 == 1 && A[i] == 0) oo = false;
            if (i%2 == 1) cnt2++;
          }
          if (oo && cnt2) {
            for (int i=l;i<=r;i++){
              if  (i%2 == 1)
              A[i]--;
            }
            self(self, cnt+1);
            for (int i=l;i<=r;i++){
              if  (i%2 == 1)
                A[i]++;
            }
          }
        }
      }
    };
    dfs(dfs, 0);
    cout << ans << "\n";
  }
}