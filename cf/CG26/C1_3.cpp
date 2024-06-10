#include <iostream>
#include <vector>
#include <climits>
using namespace std;
 
#define ll long long
#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;
 
void solve() {
  int n; cin >> n;
  vector<int> arr(n); for (int i = 0; i < n; ++i) cin >> arr[i];
  ll sum = 0, mn = 0;
  for (int i = 0; i < n; ++i) sum += arr[i], mn = min(mn, sum);
  debug(sum);
  debug(mn);
  cout << sum - 2 * mn << '\n';
}
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t; cin >> t;
  for (int i = 0; i < t; ++i) solve();
  return 0;
}