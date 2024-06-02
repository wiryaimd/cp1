/*
 * Prob: #
 * File Created: Wednesday, 29th May 2024 6:01:38 pm
 * Author: Wiryaimd
 */


#include<iostream>
#define debug(x) cerr << (#x) << " " << (x) << endl;
#define br cerr << endl;

#include<vector>
#include<cstring>

using ll = unsigned long long;

using namespace std;

int main(){

    /*
        given n, xi val

        find total AP for each index, where at i-th value will removed (decrement -= 1) to count its total AP
            which is
                total += (nth - 1) * (nth + 0) / 2
            nth
                is for each index, eg. 
                1 1 2 1 2
                    i=0, 1 2 1 2
                    i=1, 1 2 1 2
                    i=2, 1 1 1 2
                    1=3, 1 1 2 2 (count this total AP)
                    and so on
            eg, AP = 1 1 1 2
                n1 = (3-1) * (3) / 2
                n2 = (1-1) * (1) / 2
    */

    // freopen("M21.in", "r", stdin);
    // freopen("M21.out", "w", stdout);

    int n;
    cin >> n;

    int len = 2e5 + 5;
    int ai[n + 1];

    vector<ll> sn(len, 0); // use vector instead of static array, for init data 2e5 or more with default value = 0
    vector<ll> k(len, 0);

    // will crash when sn[200000] // idk why, use vector instead
    // ll sn[len];
    // ll k[len];
    // memset(sn, 0, sizeof(sn));
    // memset(k, 0, sizeof(k));

    for(int i = 0; i < n; i++){
        cin >> ai[i];
        k[ai[i] - 1]++; // count total for all xi value
    }

    ll cnt = 0;
    for(int i = 0; i < len; i++){
        if(k[i] == 0) continue;
        sn[i] = (k[i] - 1) * (k[i]) / 2; // store all AP result to sn[]

        cnt += sn[i]; // also count the total AP
    }

    for(int i = 0; i < n; i++){
        // each ith index is removed, then cnt -= sn[ith], cnt += sn_decremented_1
        
        ll n0 = k[ai[i] - 1] - 1; // make all ull instead of int, to avoid miss calculation in bigger value
        ll sn0 = (n0 - 1) * (n0) / 2;

        ll tmp = cnt;
        tmp -= sn[ai[i] - 1];
        tmp += sn0;
        cout << tmp << endl;
    }

    return 0;
}