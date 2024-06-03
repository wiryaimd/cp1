#define debug(x) cerr << (#x) << " " << (x) << endl;
#define br cerr << endl;

#include<iostream>
#include<vector>

using namespace std;

int main(){

    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n, m;
        cin >> n >> m;
        string dif;
        cin >> dif;
        int len = dif.length();
        vector<int> d(7, 0);
        for(int j = 0; j < len; j++){
            d[dif[j] - 'A']++;
        }

        int cnt = 0;
        for(int j = 0; j < 7; j++){
            // debug(d[j]);
            if(d[j] >= m) continue;
            cnt += m - d[j];
        }
        cout << cnt << endl;
    }

    return 0;
}