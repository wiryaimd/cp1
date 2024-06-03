#define debug(x) cerr << (#x) << " " << (x) << endl;
#define br cerr << endl;

#include<iostream>
#include<algorithm>

using namespace std;

int main(){

    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        int a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        bool used = false, good = true;
        int g1 = __gcd(a1, a2), g2 = __gcd(a2, a3);
        int curr = a3;
        int currg = g2;
        for(int j = 3; j < n; j++){
            debug(j);
            int ai;
            cin >> ai;
            int g = __gcd(curr, ai);
            if(currg > g){
                if(used){
                    good = false;
                    break;
                }
                used = true;
            }

            curr = ai;
        }

        cout << (good ? "YES" : "NO") << endl;
    }

    return 0;
}