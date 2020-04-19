#include<iostream>
#include<vector>
#include<utility> 

using namespace std;

//Using arrays with same logic is the fastest method
class MinStack {
public:
    vector<pair<int, int>> stack;
    int currmin;
    MinStack() {
    }
    
    void push(int x) {
        if(stack.empty() || x<currmin){
            currmin=x;
        }
        stack.push_back(make_pair(x,currmin));
    }
    
    void pop() {
        if(stack.empty()){
            cout<<"Empty stack";
        }
        else{
            stack.pop_back();
            if(!stack.empty())
                currmin=stack.back().second;
        }
    }
    
    int top() {
        if(stack.empty()){
            return -1;
        }
        return stack.back().first;
        
    }
    
    int getMin() {
        if(stack.empty()){
            return -1;
        }
        return currmin;
    }
};

int main(){
    return 1;
}
