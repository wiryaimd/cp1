/*
 * Prob: #
 * File Created: Friday, 26th April 2024 9:32:51 pm
 * Author: Wiryaimd
 */


#include<iostream>
#include<cmath>

using namespace std;

int main(){

    string a, b;
    cin >> a >> b;

    string con = a + b;
    int c = stoi(con);
    // int c = stoi(a + b); // or this instead

    double s = sqrt(c);
    if(s * 100 == ((int)s) * 100){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }


    return 0;
}