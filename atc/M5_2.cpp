/*
 * Prob: Mod sum
 * File Created: Friday, 17th May 2024 10:16:01 am
 * Author: Wiryaimd
 */

#include<iostream>

using namespace std;

int main(){

    /*
        using arithmetic progression to sum 1...n-1
    */

    int n;
    cin >> n;

    n--;
    unsigned long long res = (unsigned long long) n * (n + 1) / 2;
    cout << res << endl;

    return 0;
}