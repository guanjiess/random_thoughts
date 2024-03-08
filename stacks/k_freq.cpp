#include <utility>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <functional>
using namespace std;

class MyCompare{
public:
    bool operator()(const int& a, const int& b){
        return a > b;
    }
};

class Point {
public:
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

class Compare {
public:
    bool operator()(const pair<int,int>& p1, const pair<int,int>& p2) {
        // 按照 x 坐标的大小为优先级
        return p1.second > p2.second;
    }
};
// leetcode 347, top k frequent elements
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> frequency;
    for(int num: nums){
        frequency[num]++;
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

    unordered_map<int, int>::iterator it;
    for(it = frequency.begin(); it != frequency.end(); it++){
        pq.push(*it);
        if(pq.size()>k){
            pq.pop();
        }
    }    
    vector<int> ans;
    for(int i = k - 1; i > 0; i--){
        ans[i] = pq.top().first;
        pq.pop();
    }
    return ans;
}



int main()
{
    priority_queue<int> pq;
    pq.push(10);
    pq.push(5);
    pq.push(20);
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;

    priority_queue<int, vector<int>, MyCompare> pq2;
    // 添加元素
    pq2.push(10);
    pq2.push(5);
    pq2.push(20);
    cout << pq2.top() << endl;
    priority_queue<Point, vector<Point>, Compare> pq3;

    // 添加元素
    pq3.push(Point(1, 2));
    pq3.push(Point(3, 4));
    pq3.push(Point(0, 5));

    // 访问顶部元素
    Point top3 = pq3.top();
    cout << "Top element: (" << top3.x << ", " << top3.y << ")" << endl;

    

    return 0;
}