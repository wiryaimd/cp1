#define debug(x) cerr << (#x) << " " << (x) << endl;
#define br cerr << endl;

#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

int main(){

    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        int a[n], b[n];
        for(int j = 0; j < n; j++){
            cin >> a[j];
        }

        set<int> st;
        for(int j = 0; j < n; j++){
            cin >> b[j];
            st.insert(b[j]);
        }

        int m;
        cin >> m;
        map<int, int> mp;
        int last = 0;
        for(int j = 0; j < m; j++){
            int ai;
            cin >> ai;
            // debug(ai);
            mp[ai]++;
            if(j == m - 1){
                last = ai;
            }
        }

        if(st.count(last) == 0){
            cout << "NO" << endl;
            continue;
        }

        bool good = true;
        for(int j = 0; j < n; j++){
            // debug(b[j]);
            // debug(mp[b[j]]);
            if(a[j] == b[j]){
                continue;
            }
            if(mp.count(b[j]) == 0){
                good = false;
                break;
            }

            if(mp[b[j]] == 0){
                good = false;
                break;
            }

            mp[b[j]]--;
        }

        cout << (good ? "YES" : "NO") << endl;
    }

    

    return 0;
}