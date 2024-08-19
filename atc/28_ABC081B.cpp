/*
 * Prob: Shift Only
 * File Created: Monday, 6th May 2024 4:41:35 pm
 * Author: Wiryaimd
 */

#include<iostream>

using namespace std;

int main(){

    /*
        given array with n size and xi value

        count how much xi can be divisble by 2 (each)
        stop count when there some xi is odd
        
    */

    int n;
    cin >> n;

    int minn = INT32_MAX;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;

        int cnt = 0;
        while(a % 2 == 0){
            a /= 2;
            cnt++;
        }

        minn = min(cnt, minn);
    }

    cout << minn << endl;

    return 0;
}