#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<numeric>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

using ll = long long;

int main(){

    /*
        difference array is technique to update operation from range l to r with o1 time

        eg. given query = 2,
            adding 2 from 1 to 3
            adding 3 from 2 to 4
        init array is {1, 2, 3, 4, 5}
        final result is {1, 4, 8, 9, 8}

        the things is store added value only at diff[l] += val and
        recover value until r element using diff[r + 1] -= val
        
        then using prefix sum to calculate which position is differ from each other range,
        then update init array with arr[i] += diff[i] which is o1 time
    */

    int q = 2;
    std::tuple<int, int, int> opr[q] = {
        std::make_tuple(1, 3, 2),
        std::make_tuple(2, 4, 3)
    };

    std::vector<int> ps = {1, 2, 3, 4, 5};
    std::vector<int> diff(ps.size() + 1, 0); // n + 1, because need to store recover value at r + 1 and avoid IOOB

    for(int i = 0; i < q; i++){
        int l, r, v;
        std::tie(l, r, v) = opr[i]; // init tuple to int l, r, v
        debug(l);
        debug(r);
        debug(v); br;

        diff[l] += v; // store added value only at l position
        diff[r + 1] -= v; // need recover original value after r (which is r + 1), so diff.size() need be n + 1
        // may check IOOB
        // if(r + 1 < ps.size()){ // if not exceed size then recover after index r
        //     diff[r + 1] -= v;
        // }
    }

    ps[0] += diff[0]; // ps is 0-based indexing (instead of 1)
    for(int i = 1; i < ps.size(); i++){
        diff[i] = diff[i] + diff[i - 1]; // make prefix sum for diff
        ps[i] += diff[i]; // sum result
    }

    for(int i = 0; i < diff.size(); i++){
        debug(diff[i]);
    }

    for(int i = 0; i < ps.size(); i++){
        debug(ps[i]);
    }

    return 0;
}