/*
 * Prob: #
 * File Created: Sunday, 2nd June 2024 11:48:50 pm
 * Author: Wiryaimd
 */

#include<iostream>
#define debug(x) cerr << (#x) << " " << (x) << endl;
#define br cerr << endl;

using namespace std;

int main(){

    /*
        probability approach

        just follow the formula in prob
    */

    int n, k;
    cin >> n >> k;

    double res = 0;
    for(int i = 1; i <= n; i++){
        double f = (double)1/n;
        int curr = i;
        while(curr < k){
            f /= 2;
            curr *= 2;
        }
        res += f;
    }

    printf("%.12lf", res);

    return 0;
}