//Link: https://leetcode.com/problems/min-stack/

//A chave é criar uma stack auxiliar para mapear os valoeres minimos
//Para isso será necessário um ponteiro auxiliar 

class MinStack {
private:
    vector<int> stack;      // stack principal
    vector<int> minStack;   // stack auxiliar para os mínimos
    int min;  

public:
    MinStack() {
    }
    
    void push(int val) {
        if(stack.empty()){
            stack.push_back(val);
            min = val;
            minStack.push_back(min);
        } else {
            stack.push_back(val);
            if(val < min){
                min = val;
                minStack.push_back(min);
            } else {
                minStack.push_back(min);
            }
        }
    }
    
    void pop() {
        if(stack.empty()){
            return;
        }

        stack.pop_back();
        minStack.pop_back();

        if(!minStack.empty()){
            min = minStack.back();
        }
        
    }
    
    int top() {
        if(stack.empty()){
            return -1;
        }

        return stack.back();
    }
    
    int getMin() {
        if(minStack.empty()){
            return -1;
        }

        return minStack.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */