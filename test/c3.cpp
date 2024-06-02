#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){

    int a, b;
    cin >> a >> b;

    cout << a << " hooh " << b << endl;

    int ab[] = {2, 3, 4, 5, 6};
    int res = accumulate(ab, ab + 5, 0);
    cout << res << endl;



    // use a < c3.in for custom input from file .in

    return 0;
}