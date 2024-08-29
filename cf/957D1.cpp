#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<cstring>
#include<numeric>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

using ll = long long;

using namespace std;

// solved
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
 
    int sw = 0;  // Counter for swim distance in water
    int maxJump = 0;  // Maximum jump distance counter from logs or bank
 
    // Start from the left bank at position 0
    for (int i = 0; i < n; i++) {
        maxJump++;
        if(s[i]=='L') maxJump=0;
        if(maxJump>=m)
        {
            sw++;
            if(s[i]=='C')
            {
                cout<<"NO"<<endl;
                return;
            }
        } 
    }
    if(sw<=k)
    {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}

int main(){

    int t;
    std::cin >> t;
    while(t--){
        int n, m, k;
        std::cin >> n >> m >> k;

        std::string s;
        std::cin >> s;

        bool pass = true;
        int curr = 'L';


        bool jump = false;
        bool swim = true;
        int start_jump = 0;
        int start_swim = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'L'){
                curr = s[i];
                continue;
            }

            if((curr == 'W' || curr == 'C') && s[i] == 'L'){
                if(i - start_jump == k) {
                    pass = false;
                    break;
                }
                jump = false;
                curr = s[i];
                continue;
            }

            if(swim && i - start_swim > m){
                pass = false;
                break;
            }

            if(jump && i - start_jump == k){
                if(s[i] == 'W'){
                    swim = true;
                    start_swim = i;
                }else{
                    pass = false;
                    break;
                }
                curr = s[i];
                continue;
            }
            
            if(s[i] == 'W' && curr == 'L'){
                jump = true;
                start_jump = i - 1;
                curr = s[i];
                continue;
            }
        }

        std::cout << (pass ? "YES" : "NO") << std::endl;
    }

    return 0;
}