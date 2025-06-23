//link: https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int top = 0;
       int bottom = matrix.size() - 1;

       while(top <= bottom){
            int mid = top + (bottom - top) / 2;

            if(target < matrix[mid][0]){
                bottom = mid - 1;
            }

            else if(target > matrix[mid][matrix[mid].size() - 1]){
                top = mid + 1;
            }

            else{
                int left = 0;
                int right = matrix[mid].size() - 1;

                while(left <= right){
                    int midVec = left + (right - left) / 2;

                    if (matrix[mid][midVec] == target) {
                        return true;
                    }
                    else if(target < matrix[mid][midVec]){
                        right = midVec - 1;
                    } else {
                        left = midVec + 1;
                    }
                    }
                    return false;
                }
            }
            return false;
       }
};