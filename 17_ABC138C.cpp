/*
 * Prob: #
 * File Created: Friday, 3rd May 2024 3:32:33 pm
 * Author: Wiryaimd
 */

#include<iostream>
#include<algorithm>

using namespace std;

int main(){

    /*
        given n data with xi value.
        find when (x + y) / 2 is maximum (proceed repeatedly) and
        x and y will vanish until theres last one (x + y) / 2 result

        the solution is sorting first approach. and count (x + y) / 2 until remaining one left value

    */

    int n;
    cin >> n;
    int data[n];
    for(int i = 0; i < n; i++){
        cin >> data[i];
    }

    sort(data, data + n);

    double res = (double)data[0] / 2;
    double curr = data[0];
    for(int i = 1; i < n; i++){
        // cout << curr << " " << data[i] << endl;
        curr = (curr + data[i]) / 2;
        res = curr;
    }

    cout << res << endl;

    return 0;
}