//link:https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length == 0){
            return 0;
        }

        int maxSequence = 1;
        HashSet<Integer> numSet = new HashSet<>();
        for (int num : nums) {
            numSet.add(num);
        }    

        for(int num : numSet){
            int i = 1;
            int sequence = 1;
            //Verifico se o número dá inicio a sequencia
            if(!numSet.contains(num - i)){
                while(numSet.contains(num + i++)){
                    sequence++;
                }

            maxSequence = (sequence > maxSequence) ? sequence : maxSequence;
            }
        }

        return maxSequence;    
    }
}