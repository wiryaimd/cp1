/*
 * Prob: Traveling
 * File Created: Thursday, 23rd May 2024 3:21:25 pm
 * Author: Wiryaimd
 */

#include<iostream>

using namespace std;

int main(){

    /*

    */

    int n;
    cin >> n;

    int t[n], x[n], y[n];
    for(int i = 0; i < n; i++){
        cin >> t[i] >> x[i] >> y[i];
    }

    bool good = true;
    int t0 = 0, x0 = 0, y0 = 0;
    int currt = t0;
    for(int i = 0; i < n; i++){
        int dist = abs(x[i] - x0) + abs(y[i] - y0); // manhattan distance

        currt = t[i] - t0;
        // cout << "cek " << dist << " " << currt <<  endl;

        t0 = t[i];
        x0 = x[i];
        y0 = y[i];

        if(dist == currt){
            continue;
        }

        if(dist < currt && (dist - currt) % 2 == 0){
            continue;
        }

        good = false;
        break;
    }

    cout << (good ? "Yes" : "No") << endl;

    return 0;
}