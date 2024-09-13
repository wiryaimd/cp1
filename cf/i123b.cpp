#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int maxx = 0;
    for(int i = 0; i < n; i++){
        vector<int> tmp = a;
        sort(tmp.begin(), tmp.end() - i, greater<int>());
        int cnt = m;
        int c = k;
        bool pass = true;
        int pos = 0;
        for(int j = 0; j < n - i; j++){
            pos = j + 1;
            if(c > 0){
                c--;
                continue;
            }else{
                cnt -= tmp[j];
            }
        }

        if(cnt >= 0) maxx = max(maxx, pos);
    }

    cout << maxx << endl;

    return 0;
}
