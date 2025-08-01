//Link: https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxArea = 0;
        while(l < r){
            int area = min(height[l], height[r]) * (r - l);
            if(area > maxArea){
                maxArea = area;
            }
            if(height[l] < height[r]){
                l++;
            }else{
                r--;
            }
        } 

        return maxArea;
    }
};