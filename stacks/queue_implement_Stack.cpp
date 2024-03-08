#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> que1; 
    queue<int> que2;

    MyStack() {

    }
    
    void push(int x) {
        que1.push(x);
    }
    
    int pop() {
        int size1 = que1.size();
        //执行size-1次循环
        size1 --;
        while(size1--){
            que2.push(que1.front());
            que1.pop();
        }
        int result = que1.front();
        que1.pop();
        while(!que2.empty()){
            que1.push(que2.front());
            que2.pop();
        }
        return result;
    }
    
    int top() {
        return que1.back();
    }
    
    bool empty() {
        return que1.empty();
    }
};


int main()
{
    MyStack queue;
    queue.push(1);        
    queue.push(2);        
    queue.pop();   // 注意弹出的操作       
    queue.push(3);        
    queue.push(4);       
    queue.pop();  // 注意弹出的操作    
    queue.pop();    
    queue.pop();    
    queue.empty(); 

    return 0;
}
