#include<iostream>
#define debug(x) cerr << (#x) << " " << (x) << endl;
#define br cerr << endl;

using namespace std;

int main(){

    int n, t;
    cin >> n >> t;

    unsigned long long total = 0;

    int t0;
    cin >> t0;

    for(int i = 1; i < n; i++){
        int a;
        cin >> a;

        total += min(t, a - t0); // just count if current_time - last_time is fewer than t, then use that
        t0 = a;

        // or use total += T - max(0, p - t); instead
    }

    total += t;

    cout << total << endl;
    

    return 0;
}