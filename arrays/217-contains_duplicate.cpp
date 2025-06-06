//Link: https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> values;

        for(int i = 0; i < nums.size(); i++){
            if(!values.insert(nums[i]).second){
                return true;
            }
        }

        return false;
    }
};