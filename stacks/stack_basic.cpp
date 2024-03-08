#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
public:
    stack<int> stIn;
    stack<int> stOut;
    MyQueue() {

    }
    
    void push(int x) {
        stIn.push(x);
    }
    
    int pop() {
        if(stOut.empty()){
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int ans = stOut.top();
        stOut.pop();
        return ans;
    }
    
    int peek() {
        int ans = this->pop();
        stOut.push(ans); 
        return ans;
    }
    
    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};


int main()
{
    return 0;
}