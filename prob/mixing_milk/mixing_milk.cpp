/*
 * Author: Wiryaimd
 * File Created: Monday, 25th March 2024 3:11:57 pm
 * USACO: Mixing milk, 15mins?
 */

#include<iostream>

using namespace std;
int main(){ // solved

    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    int c[3], m[3];
    for(int i = 0; i < 3; i++){
        cin >> c[i] >> m[i];
    }

    for(int i = 0; i < 100; i++){
        int dif = min(c[(i + 1) % 3] - m[(i + 1) % 3], m[i % 3]);
        m[(i + 1) % 3] += dif;

        // m[i % 3] = m[i % 3] - dif; // atau
        m[i % 3] -= dif;
    }

    for(int i = 0; i < 3; i++){
        cout << m[i] << endl;
    }

    return 0;
}