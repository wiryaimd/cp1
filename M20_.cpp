/*
 * Prob: Write and Erase
 * File Created: Wednesday, 29th May 2024 2:36:33 pm
 * Author: Wiryaimd
 */

#include<iostream>
#include<set>
#define debug(x) cerr << (#x) << " " << (x) << endl;
#define br cerr << endl;

using namespace std;

int main(){

    /*
        given n with xi value

        xi writed when not exist
        xi removed when already exist
        then count total writed xi value at the end

        constrainst xi <= 1e9 and n <= 1e5

        approach 1 (not optimized):
            using bool status[1e9] to store if value already exist or not
            and count value which status[i] == true
            will time limit because rep(i, 1e9) if(a[i]) cnt++;
        
        approach 2 (optimized solution):
            store xi in set, and use .count() function to check if xi already exist.
            if yes, then remove in set
            if not, then insert in set
            the result is set.size()

        other sol:
            sort it, then count if his xi with xi+1 ... % 2 is even, then += 0 else, += 1
    */

    int n;
    cin >> n;

    set<int> st;
    // int cnt = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;

        if(st.count(a) > 0){
            // cnt--;
            st.erase(a);
        }else{
            // cnt++;
            st.insert(a);
        }
    }

    cout << st.size() << endl;

    return 0;
}