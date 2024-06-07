#include<iostream>
#include<vector>

using namespace std;
int main(){

    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<int> v;
    for(int i = 0; i < n; i++){
        int dist, lim;
        cin >> dist >> lim;
        for(int j = 0; j < dist; j++){
            v.push_back(lim);
        }
    }

    int maxx = 0;
    int curr = 0;
    for(int i = 0; i < m; i++){
        int dist, lim;
        cin >> dist >> lim;

        for(int j = curr; j < curr + dist; j++){
            maxx = max(maxx, lim - v[j]);
        }
        curr += dist;
    }

    cout << maxx << endl;

    return 0;
}