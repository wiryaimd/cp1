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

/*
    functional graph https://www.notion.so/graph-c59999097eeb4e0daec3c816c7926aa4?pvs=4
    note that functional graph will always have cyclic graph

    then, we can use floyd cycle algorithm to find where start point of the cycle.
    we can use naive approach but space complexity is O(n)
*/ 


// find duplicate (naive approach) O(n) time and O(n) space
void fd(std::vector<int> a){
    std::set<int> st;
    for(int i = 0; i < a.size(); i++){
        if(st.find(a[i]) == st.end()){
            st.insert(a[i]);
        }else{
            std::cout << "dupe " << a[i] << std::endl;
            return;
        }
    }

    std::cout << "no dupe" << std::endl;
}

// using floyd cycle algorithm O(n) time and O(1) space
// also called as (tortoise and hare)
void floyd(std::vector<int> a){
    int slow = 0; // tortoise
    int fast = 0; // hare
    while(true){
        // this indexing approach used for acessing data for functional graph or other like linkedlist pointing (pointer chasing)
        slow = a[slow]; // jump one times
        fast = a[a[fast]]; // jump two times

        if(slow == fast) break;
    }

    // used to find main entry cycle point
    slow = 0;
    while(slow != fast){
        slow = a[slow];
        fast = a[fast]; // only jump one time for after find meeting point
        // nb.
        // start cycle point will always correct and already math proved using this approach
        // where each 'slow' and 'fast'. jump one by one and will meet at start cycle point
    }

    // nb. functional graph always have cyclic, so theres no case where graph an acyclic
    std::cout << "dupe " << slow << std::endl;


    // count the length of the cycle
    // fast = a[slow];
    // int cnt = 1;
    // while(fast != slow){
    //     fast = a[fast];
    //     cnt++;
    // }
}


int main(){

    // in this vector, functional graph represent f(x) = a[x] where x is index
    std::vector<int> a = {1, 2, 3, 4, 5, 6, 7, 11, 8, 9, 10, 3};

    // fd(a);
    floyd(a); // work same as find dupe fd(), if no dupe the return is 0

    return 0;
}