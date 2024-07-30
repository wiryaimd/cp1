#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> subset;
    set<vector<int>> res;

    void generate_subset(int n, vector<int> data, int index){
        if(index == n){
            vector<int> sub;
            for(int i = 0; i < subset.size(); i++){
                sub.push_back(subset[i]);
            }
            sort(sub.begin(), sub.end());
            res.insert(sub);
            return;
        }

        subset.push_back(data[index]);
        generate_subset(n, data, index + 1);

        subset.pop_back();
        generate_subset(n, data, index + 1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        generate_subset(nums.size(), nums, 0);
        vector<vector<int>> ret(res.begin(), res.end());
        return ret;
    }
};

int main(){
    Solution sol;

    vector<int> a = {4,4,4,1,4};
    auto res = sol.subsetsWithDup(a);
    for(vector<int> item : res){
        for(int j = 0; j < item.size(); j++){
            cout << item[j] << " ";
        }
        cout << endl;
    }
}