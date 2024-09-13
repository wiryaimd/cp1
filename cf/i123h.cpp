#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){

    int n, m;
    cin >> n >> m;

    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < n; i++){
        pair<int, int> p;
        cin >> p.second >> p.first;
        pq.push(p);
    }

    multiset<int> carts;
    for(int i = 0; i < m; i++){
        int a;
        cin >> a;
        carts.insert(a);
    }

    ll cnt = 0;
    while(!pq.empty()){
        pair<int, int> a = pq.top();

        auto pos = carts.lower_bound(a.second);
        if(pos != carts.end()){
            carts.erase(pos);
            cnt += a.first;
        }

        pq.pop();
    }

    cout << cnt << endl;

    return 0;
}