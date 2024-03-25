/*
 * Author: Wiryaimd
 * File Created: Monday, 25th March 2024 11:42:48 am
 * 13mins?
 */


#include<iostream>
using namespace std;
int main(){ // solved

    // read melalui file freopen(), jadi tidak perlu input manual melalui cmd
    freopen("shell.in", "r", stdin);

    int n;
    cin >> n; // ini otomatis input dari file shell.in
    
    int data[3] = {1, 2, 3};
    int c1 = 0, c2 = 0, c3 = 0;
    for(int i = 0; i < n; i++){
        int a, b, g;
        cin >> a >> b >> g;

        int tmp = data[a - 1];
        data[a - 1] = data[b - 1];
        data[b - 1] = tmp;

        if(data[g - 1] == 1){
            c1++;
        }

        if(data[g - 1] == 2){
            c2++;
        }

        if(data[g - 1] == 3){
            c3++;
        }
    }

    freopen("shell.out", "w", stdout); // memasukan output yg di cout ke file shell.out

    int maxx = max(c1, max(c2, c3));
    cout << maxx << endl;

    return 0;
}