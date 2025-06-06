//Link: https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<char> charStack;
        unordered_map<char, char> mapping = {{'(', ')'}, {'{', '}'}, {'[', ']'}};

        for(char c : s){
            //Se for caractere de abertura, empilha
            if(mapping.find(c) != mapping.end()){
                charStack.push(c);
            }
            else {
                //se não, verifica se a pilha está vazia
                if(charStack.empty()){
                    return false;
                }

                //pega o caracter do top e aplica o pop
                char top = charStack.top();
                charStack.pop();

                //checa para ver se o par bate
                if(mapping[top] != c){
                    return false;
                }
            }
        }

        return charStack.empty();
    }
};