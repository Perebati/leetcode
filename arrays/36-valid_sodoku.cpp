//Link: https://leetcode.com/problems/valid-sudoku/

struct hash_pair {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 4);
    }
};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> horizontalCheck;
        unordered_map<int, unordered_set<char>> verticalCheck;
        unordered_map<pair<int, int>, unordered_set<char>, hash_pair> squareCheck;

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;

                char val = board[i][j];
                pair<int, int> box = {i/3, j/3};

                if(
                    verticalCheck[i].count(val) ||
                    horizontalCheck[j].count(val) ||
                    squareCheck[box].count(val)
                ){
                    return false;
                }

                horizontalCheck[j].insert(val);
                verticalCheck[i].insert(val);
                squareCheck[box].insert(val);
            }
        }
        return true;
    }
};