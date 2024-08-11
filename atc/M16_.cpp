/*
 * Prob: Bugged (10mins)
 * File Created: Monday, 27th May 2024 1:37:02 pm
 * Author: Wiryaimd
 */

#include<iostream>
#include<algorithm>
#define debug(x) cerr << (#x) << " " << (x) << endl;
#define br cerr << endl;

using namespace std;

int main(){

    /*
        given n of xi value
        find most maximum value that % 10 != 0
    */

    int n;
    cin >> n;

    int a[n];
    int total = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        total += a[i];
    }

    sort(a, a + n);

    int skip = 0;
    for(int i = 0; i < n; i++){
        if(total % 10 != 0){
            break;
        }

        if(a[i] % 10 == 0){ // need to notice that, if a[i] is divisible by 10, then no need to decrease. because it will make still divisible to other ten
            skip++; // count to check if all skipped, then the result is 0
            continue;
        }

        total -= a[i];
    }

    cout << (skip == n ? 0 : total) << endl;


    /*
        other solution:

        you can find most minimum xi value that not divisble by 10, then decreased it to value total

    */

    return 0;
}