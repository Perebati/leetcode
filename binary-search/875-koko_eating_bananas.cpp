//link: https://leetcode.com/problems/koko-eating-bananas/
//Problema de valor mínimo, por isso while(left < right) e right = mid;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while(left < right){
            int mid = left + (right - left) / 2;
            int sum = 0;

            for(int i = 0; i < piles.size(); i++){
                sum += ceil((double) piles[i] / mid);
            }

            if (sum > h){
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;

    }
};