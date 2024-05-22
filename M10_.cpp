/*
 * Prob: Together
 * File Created: Tuesday, 21st May 2024 9:54:58 pm
 * Author: Wiryaimd
 */


#include<iostream>
#include<algorithm>

using namespace std;

int main(){

    /*
        TLE O n^2
    */

    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a + n);

    int maxx = 0;
    for(int i = 0; i < n; i++){
        int cnt = 1;
        int curr = a[i];
        for(int j = i + 1; j < n; j++){
            if(a[j] - curr > 2){
                break;
            }
            cnt++;
        }

        maxx = max(maxx, cnt);
    }

    cout << maxx << endl;

//     int n;
//     cin >> n;

//     int a[n];
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }

//     sort(a, a + n);

//     int pos = 0;
//     int cnt = 0;
//     int curr = a[0];

//     int maxx = 0;
//     for(int i = 1; i < n; i++){
//         if(a[i] - curr <= 2){
//             cnt++;
//             maxx = max(maxx, cnt);
//             continue;
//         }

//         for(int j = pos + 1; j < i; j++){
//             if(a[i] - a[j] <= 2){
//                 curr = a[j];
//                 break;
//             }
//             cnt--;
//         }
//         pos++;

//         maxx = max(maxx, cnt);
//     }

//     cout << maxx << endl;

    return 0;
}