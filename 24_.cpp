/*
 * Prob: Count Order
 * File Created: Sunday, 5th May 2024 7:15:06 pm
 * Author: Wiryaimd
 */

#include<iostream>

using namespace std;

int main(){

    /*
        care 100k constrainsts for a, b, m.
        
        find most minimum things problem
    */

    int a, b, m;
    cin >> a >> b >> m;

    int ax[a], bx[b];

    int minna = INT32_MAX;
    int minnb = INT32_MAX;
    for(int i = 0; i < a; i++){
        cin >> ax[i];
        minna = min(minna, ax[i]);
    }

    for(int i = 0; i < b; i++){
        cin >> bx[i];
        minnb = min(minnb, bx[i]);
    }

    int minnc = INT32_MAX;
    for(int i = 0; i < m; i++){
        int x, y, c;
        cin >> x >> y >> c;
        int sum = ax[x - 1] + bx[y - 1] - c;
        minnc = min(minnc, sum);
    }

    cout << min(minnc, minna + minnb) << endl;

    return 0;
}