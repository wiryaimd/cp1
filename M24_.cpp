/*
 * Prob: #
 * File Created: Monday, 3rd June 2024 10:57:44 am
 * Author: Wiryaimd
 */


#define debug(x) cerr << (#x) << " " << (x) << endl;
#define br cerr << endl;

#include<iostream>

using namespace std;
using ll = unsigned long long;

int main(){

    /*
        find ordered combination with N length digit from min A value to max B value

        eg.
            N=4, A=4, B=6
            then the combination will be N-2 (because first and last not count)
            4, 4
            4, 5
            5, 5
            5, 6
            6, 6
            total = 5
        nb.
            first and last digit value still with his minimum and max
        
        using formula ((N-2)*B - (N-2)*A) + 1 to get the result


        other note:
            Suppose you are counting the number of ways to arrange or select items with certain constraints, 
            where N is the number of items, and 
            A and B are parameters influencing the selection process
    */

    int n, a, b;
    cin >> n >> a >> b;

    if(n == 1){
        if(a == b){
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
    }else{
        if(a > b){
            cout << 0 << endl;
            return 0;
        }
        ll r = (ll)(n - 2) * b;
        ll l = (ll)(n - 2) * a;
        cout << r - l + 1 << endl;
    }

    return 0;
}