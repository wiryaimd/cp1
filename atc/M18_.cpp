/*
 * Prob: Takahashi Information
 * File Created: Tuesday, 28th May 2024 8:10:28 am
 * Author: Wiryaimd
 */


#include<iostream>
#define debug(x) cerr << (#x) << " " << (x) << endl;
#define br cerr << endl;

using namespace std;

int main(){

    /*
        given matrix sq 3x3
        check if sq[i][j] = ai + bj. which a for row and b for col
        you can choose any fixed value for a1, a2, a3 and b1, b2, b3

        the things is get b1 from linear equation like
        a1 + b1 = c11, 
        a1 + b2 = c12
        a1 + b3 = c13

        a2 + b1 = c21 and so on

        notice that b1 used to sum a1, a2, a3. (this b1 must fixed value)
            then check if the sum b1, b2, b3 meets for a1, a2, a3. then its valid.
            you can get b1, b2, b3 from using c[0][1], c[0][2], c[0][3]
    */

    int n = 3;
    int sq[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> sq[i][j];
        }
    }

    int a[3], b[3];
    a[0] = 0;
    b[0] = sq[0][0] - a[0]; // get b1, b2, b3, literal from c11, c12, c13
    b[1] = sq[0][1] - a[0];
    b[2] = sq[0][2] - a[0];

    a[1] = sq[1][0] - b[0];
    a[2] = sq[2][0] - b[0];

    bool valid = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i] + b[j] != sq[i][j]){
                valid = false;
                break;
            }
        }
    }

    cout << (valid ? "Yes" : "No") << endl;

    /*
    
        int n=3;
	REP(i,n) REP(j,n) cin>>a[i][j];

	REP(i,n-1){
		if(a[0][i]-a[1][i]!=a[0][i+1]-a[1][i+1]||
			a[1][i]-a[2][i]!=a[1][i+1]-a[2][i+1]){
			cout<<"No\n";
		return 0;
		}
	}
	cout<<"Yes\n";
    */

    return 0;
}