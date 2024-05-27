/*
 * Prob: Traveling
 * File Created: Thursday, 23rd May 2024 3:21:25 pm
 * Author: Wiryaimd
 */

#include<iostream>

using namespace std;

int main(){

    /*
        given N coordinates x, y and t
        point start at 0,0

        check if that coordinate can arrive at times t

        solution:
            count using mahattan distance
            if t more than distance, then check if dist - time is even or not

        note that if t more than dist, an odd movement will cannot arrive at point xy, because thats how coordinate works

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

        if(dist < currt && (currt - dist) % 2 == 0){ // if current time - distance is odd, then its not able to arrive at coordinate xy
            continue;
        }

        good = false;
        break;
    }

    cout << (good ? "Yes" : "No") << endl;

    return 0;
}