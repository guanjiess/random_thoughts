#include<deque>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

// leetcode 239，给定一个数组和一个窗口，窗口每次向右滑动一格，求滑动窗口中的最大值
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    for(int i = 0; i < nums.size()-k+1; i++){    
        vector<int> window(k,0);
        for (int j = 0; j < k; j++) {
            window[j] = nums[i+j];
        }    
        sort(window.begin(),window.end());
        ans.push_back(window[k-1]);
    }
    return ans;
}

int main()
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> ans = maxSlidingWindow(nums, k);
    for(int a : ans){
        cout << a << " " ;
    }
    cout << endl;
    return 0;
}