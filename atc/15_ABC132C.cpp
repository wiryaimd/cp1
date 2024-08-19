/*
 * Prob: Divide the Problems
 * File Created: Friday, 3rd May 2024 1:29:04 pm
 * Author: Wiryaimd
 */


#include<iostream>
#include<algorithm>

using namespace std;

int main(){

    /*
        the solution is find k between middle of data
        which is k = data[n / 2] - data[n / 2 - 1]
    */

    int n;
    cin >> n;
    int data[n];
    for(int i = 0; i < n; i++){
        cin >> data[i];
    }

    sort(data, data + n);
    int maxx = data[n / 2] - data[n / 2 - 1];
    cout << maxx << endl;

    return 0;
}