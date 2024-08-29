/**
 *    author:  tourist
 *    created: 13.08.2024 07:50:42
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, k;
    cin >> n >> m >> k;
    int w;
    cin >> w;
    vector<int> a(w);
    for (int i = 0; i < w; i++) {
      cin >> a[i];
    }
    vector<int> coeff;
    coeff.reserve(n * m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int i1 = max(0, i - k + 1);
        int j1 = max(0, j - k + 1);
        int i2 = min(i, n - k);
        int j2 = min(j, m - k);
        coeff.push_back((i2 - i1 + 1) * (j2 - j1 + 1));
      }
    }
    sort(coeff.rbegin(), coeff.rend());
    sort(a.rbegin(), a.rend());
    int64_t ans = 0;
    for (int i = 0; i < w; i++) {
      ans += int64_t(a[i]) * coeff[i];
    }
    cout << ans << '\n';
  }
  return 0;
}

//----------------------------------------------------------

#include <bits/stdc++.h>
#define ll long long
using namespace std;
void Solve()
{
    int n,m,k,w;
    cin >> n >> m >> k >> w;
    ll a[w+1];
    ll d[n+5][m+5];
    memset(d,0,sizeof(d));
    for (int i = 1; i <= w; i++) cin >> a[i];
    sort(a+1,a+w+1);
    for (int i = k; i <= n; i++)
    {
        for (int j = k; j <= m; j++)
        { // difference array
            d[i - k + 1][j - k + 1]++;
            d[i + 1][j + 1]++;
            d[i - k + 1][j + 1]--;
            d[i + 1][j - k + 1]--;
        }
    }
    vector<ll> temp;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            d[i][j] = d[i][j] + d[i-1][j] + d[i][j-1] - d[i-1][j-1];
            temp.push_back(d[i][j]);
        }
    }
    sort(temp.begin(),temp.end());
    reverse(temp.begin(),temp.end());
    ll ans = 0;
    int p = w;
    for (auto x : temp)
    {
        //cout << x << " ";
        if (p == 0) break;
        ans += a[p]*x;
        p--;
    }
    cout << ans << "\n";
    return;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}
/*
void insert(int x1,int y1,int x2,int y2,int c)
{
    b[x1][y1] += c;
    b[x2+1][y1] -= c;
    b[x1][y2+1] -= c;
    b[x2+1][y2+1] += c;
}
*/


someone explain how to intuit the way they count it in problem E please.

consider 2D adjacent difference it could be a lot easier

do u know diffrence array? to update values in range for 1d vector it can be used here to count for 2d vector then 2d prefix sum


static inline int calcc(int i, int j) {
    int upr = min(i, n - k);
    int leftr = min(j, m - k);
    int upl = max(-1LL, i - k);
    int leftl = max(-1LL, j - k);
    return (upr - upl) * (leftr - leftl);
}
 
void build() {
    sort(arr, arr + w);
    reverse(arr, arr + w);
    p = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            prr[p++] = calcc(i, j);
    sort(prr, prr + p);
    reverse(prr, prr + p);
}
 