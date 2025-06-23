//link: https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
private:
    set<string> simbolSet = {"+", "-", "*", "/"};

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> notationStack;

        for(int i = 0; i < tokens.size(); i++){
            if(simbolSet.count(tokens[i]) && notationStack.size() >= 2){
                int num1 = notationStack.top(); notationStack.pop();
                int num2 = notationStack.top(); notationStack.pop();

                int op = 0;

                if(tokens[i] == "+") op = num2 + num1;
                else if(tokens[i] == "-") op = num2 - num1;
                else if(tokens[i] == "*") op = num2 * num1;
                else if(tokens[i] == "/") op = num2 / num1;

                notationStack.push(op);
            } else{
                notationStack.push(stoi(tokens[i]));
            }
        }

        return notationStack.top();
    }
};