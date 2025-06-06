// Link: https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //tranform into a hash
        unordered_map<int, int> pairHash;

        for(int i = 0; i < nums.size(); i++){
            //checks if there is a hash with key value (target - nums[i])
            if(pairHash.find(target - nums[i]) != pairHash.end()){
                //if there is, return the nums index with the value of searched key value
                return {i, pairHash[target - nums[i]]};
            }

            pairHash[nums[i]] = i;
        }

        return {};
    }
};