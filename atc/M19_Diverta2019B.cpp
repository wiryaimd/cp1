/*
 * Prob: RGB Boxes
 * File Created: Wednesday, 29th May 2024 1:30:25 pm
 * Author: Wiryaimd
 */


#include<iostream>
#define debug(x) cerr << (#x) << " " << (x) << endl;
#define br cerr << endl;

using namespace std;

int main(){

    /*
        given R, G, B value that each 1 boxes contain that value R, G, B
        find how many way to get N value with that each boxes

        eg:
            r=2 g=4 b=6 n=10
            there 5 way to get box which is:
            5, 0, 0 (5x2 + 0x4 + 0x6 = n)
            3, 1, 0 (same)
            1, 2, 0
            0, 1, 1
            2, 0, 1

        constrainst <= 3000 which is you cannot bruteforce all ri, gi, bi to check == n

        using complete search approach to solve the solution
            within get c by using linear equation, then check if c divisible by one boxes (C)
            n = a + b + c
            n - a - b = c (which is same as n - (a + b) = c)

            after get c then check multiple of box c, which is if(c % box_c == 0). then c is valid

            also check if cx >= 0 because a*i + b*j may produce more than N value

        
    */

    int a, b, c, n;
    cin >> a >> b >> c >> n;

    int cnt = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            // using linear equation to find c
            // int cx = n - ((i * a) + (j * b)); // equal to n - ai - ab
            int cx = n - i*a - j*b; // here
            // debug(cx);
            if(cx >= 0 && cx % c == 0){
                cnt++;
            }
        }
    }

    // not optimize solution
    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= n; j++){
    //         for(int k = 0; k <= n; k++){
    //             if(a*i + b*j + c*k == n){
    //                 cnt++;
    //             }
    //         }
    //     }
    // }

    cout << cnt << endl;

    return 0;
}