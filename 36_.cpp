/*
 * Prob: Prison
 * File Created: Sunday, 12th May 2024 11:27:35 am
 * Author: Wiryaimd
 */

#include<iostream>

using namespace std;

int main(){

    /*
        given L and R position with M times
        find the most maximum number intersection (r-l) between all of given L and R
    */

    int n, m;
    cin >> n >> m;

    int minr = INT32_MAX;
    int maxl = 0;

    int l[m], r[m];
    for (int i = 0; i < m; i++){
        cin >> l[i] >> r[i];

        minr = min(minr, r[i]);
        maxl = max(maxl, l[i]);
    }

    if(minr - maxl < 0){ // if negative, l and r will never intersect each other
        cout << 0 << endl;
        return 0;
    }

    // no need to validate, cuz minr and maxl will invalid if the substract result is negative
    // bool valid = true;
    // for(int i = 0; i < m; i++){
    //     if(r[i] < minr || l[i] > maxl){
    //         valid = false;
    //         break;
    //     }
    // }

    cout << (minr - maxl + 1) << endl; // number intersection is most_minimum_right - most_maximum_left
    

    return 0;
}