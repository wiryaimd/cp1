/*
 * Prob: Choose Integers
 * File Created: Tuesday, 21st May 2024 9:25:35 pm
 * Author: Wiryaimd
 */


#include<iostream>

using namespace std;

int main(){

    /*
        given a which is the value can be multiple of 'a' (eg 7, then 14, 21, 28, so on)

        check if a value can be congruent to c mod b, print yes/no

        eg c mod b = 5
        and a-2th mod b = 5
        then the value is congruent (yes)

        need to know that, loop up to 100 or more than 1000 because
        a-th multiplies will always loop same value eg 7%b, 14%b, 21%b.
            if at 1000 loop cannot find the condition a mod b == c mod b 
                then its will not possible
    */

    int a, b, c;
    cin >> a >> b >> c;

    int rem = c % b;
    for(int i = 0; i < 1000; i++){
        if(((i + 1) * a) % b == rem){
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}