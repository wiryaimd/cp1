/*
 * Prob: Count Balls
 * File Created: Monday, 6th May 2024 3:44:44 pm
 * Author: Wiryaimd
 */

#include<iostream>

using namespace std;
using ll = unsigned long long;

int main(){

    /*
        count infinite placed red and blue balls when he placed with formation
        'A' blue balls and 'B' red balls repeatedly
        eg: A = 3, B = 2, then the balls will be

        AAABBAAABBAAABBAAA and so on
                     ^
                     |
                eg N at 14, then A's = 9
        
        given N input
        count how much A (blue) balls at N position from start

    */

    ll n, a, b;
    cin >> n >> a >> b;

    ll t = n / (a + b); // make A and B balls as 'one step sequence' to get how much step can be make using A + B
    ll rem = n % (a + b); // get remainder from that step n % (a + b)
    ll res = t * a + min(rem, a); // count the result step * a (not including b)
    
    // + min(rem, a) to sum A balls not exceed remainder, or A not exceed B balls

    cout << res << endl;

    return 0;
}
