#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

int main(){

    /*
        given n array with xi value

        find how much subtring which subtring contain only increasing value, or decreasing value

        sol:
            need to notice that, if input: 1 2 1 2 1 2 1, we can't just check its increasing or decreasing
            because it will miss calculate

            so we need to use reset status, when xi increasing value changed to decreasing value, then reset it first and
            then check its first reset will increasing or decreasing

            after that count, when its not meet increasing or decreasing condition
    */

    int n;
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    int curr = a[0];
    bool reset = true; // firstly is true because its first value
    bool inc = false;
    int cnt = 1;
    for(int i = 1; i < n; i++){
        if(curr == a[i]){ // if same, skip
            curr = a[i];
            continue;
        }

        // debug(reset);
        // debug(curr); 
        // debug(a[i]); br;
        if(reset){ // check if reset (first value), will check the order and skip cnt++ below
            if(curr < a[i]){ // check order
                inc = true;
            }else{
                inc = false;
            }
            curr = a[i]; // update curr (last)
            reset = false; // set back to false
            continue; // need to skip
        }
        if(inc && curr > a[i]){ // if last order increasing and current is decreasing, then count
            cnt++;
            reset = true;
        }

        if(!inc && curr < a[i]){ // same when dec to inc
            cnt++;
            reset = true;
        }
        curr = a[i]; // update
    }

    std::cout << cnt << std::endl;

    /*
        other sol:
            in cr;
            cin>>cr;
            in a;
            bool up=0;
            bool dn=0;

            forn(z,n-1){
                cin>>a;

                if(a>cr) up=1;
                if(a<cr) dn=1;

                if(up && dn){
                    up=dn=0;
                    ++sm;
                }
                cr=a;
            }
            cout<<sm<<endl;

        when up and down is == 1, then sum++
            its because the value meet where in case increasing and also meet decreasing. vice versa
    */

    return 0;
}