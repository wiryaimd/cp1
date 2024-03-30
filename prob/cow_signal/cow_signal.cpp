/*
 * Author: Wiryaimd
 * File Created: Monday, 25th March 2024 3:48:04 pm
 * USACO: Cow Signal, 7mins
 */

#include<iostream>

using namespace std;
int main(){

    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;

    string data[n];
    for(int i = 0; i < n; i++){
        cin >> data[i];
    }

    for(int i = 0; i < n; i++){
        string curr = "";
        for(int j = 0; j < m; j++){
            for(int m = 0; m < k; m++){
                curr.append(1, data[i][j]);
            }
        }

        for(int j2 = 0; j2 < k; j2++){
            cout << curr << endl;
        }
    }

    return 0;
}