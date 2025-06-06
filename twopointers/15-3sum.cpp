//Link: https://leetcode.com/problems/3sum/


/*  This is not the most optimal way to solve this problem.
    The main issue here is how to deal with duplicates, to this 
    I am just using a Set.
    Its simplier to undertand than whatever is to do with usign a permutation principle in this problem.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> resultSet;
        int l, r;
        for(int i = 0; i < nums.size() - 2; i++){
            l = i + 1, r = nums.size() - 1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum > 0){
                    r--;
                }else if(sum < 0){
                    l++;
                }else{
                    resultSet.insert({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
            }
        }    
        return vector<vector<int>>(resultSet.begin(), resultSet.end()); 
    }
};
