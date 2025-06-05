class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> setNums(nums.begin(), nums.end());
        int maxSequence = 0;

        for (int num : setNums) {
            //checks if the number is the start of a sequence
            if (setNums.count(num - 1) == 0) {  
                int currentNum = num;
                int currentSequence = 1;

                //if is, then checks if there is a sequence to the number
                while (setNums.count(currentNum + 1) > 0) {
                    currentNum++;
                    currentSequence++;
                }

                maxSequence = max(maxSequence, currentSequence);
            }
        }

        return maxSequence;
    }
};
