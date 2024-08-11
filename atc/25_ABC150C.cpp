/*
 * Prob: Count Order
 * File Created: Sunday, 5th May 2024 7:41:15 pm
 * Author: Wiryaimd
 */

#include<iostream>
#include<algorithm>

using namespace std;

int main(){

    /*
        permutation generated in lexicography order (asc)
        given result of a and b permutation with size n

        find the |xth - yth| position, 
        when a is generated in x-th position and b in y-th position
    */

    int n;
    cin >> n;

    int a[n], b[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    int permut[n];
    copy(a, a + n, permut);
    sort(permut, permut + n);

    int cnta = 0;
    int cntb = 0;
    bool af = false, bf = false;
    do{
        bool afound = true, bfound = true;
        for(int i = 0; i < n; i++){
            if(permut[i] != a[i]){
                afound = false;
            }
            if(permut[i] != b[i]){
                bfound = false;
            }
        }

        if(afound){
            af = true;
        }

        if(bfound){
            bf = true;
        }

        if(!af){
            cnta++;
        }

        if(!bf){
            cntb++;
        }
    }while(next_permutation(permut, permut + n));

    cout << abs(cnta - cntb) << endl;

    return 0;
}