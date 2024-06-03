#define debug(x) cerr << (#x) << " " << (x) << endl;
#define br cerr << endl;

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n, f, k;
        cin >> n >> f >> k;
        int a[n];
        vector<int> as(101, 0);
        for(int j = 0; j < n; j++){
            cin >> a[j];
            as[a[j] - 1]++;
        }
        int fav = a[f - 1];
        // debug(fav);
        // debug(as[fav - 1]);

        sort(a, a + n, greater<int>());
        bool removed = false;
        bool maybe = false;
        for(int j = 0; j < k; j++){
            // debug(a[j]);
            if(a[j] == fav && as[fav - 1] > 1){
                if(k - j >= as[fav - 1]){
                    removed = true;
                    break;
                }
                maybe = true;
                break;
            }
            if(a[j] == fav){
                removed = true;
                break;
            }
        }

        if(maybe){
            cout << "MAYBE" << endl;
            continue;
        }

        if(removed){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}