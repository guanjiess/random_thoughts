#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int mid = size / 2;
        int left = 0, right = size - 1;
        for(int i = 0; i < size; i ++){
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target){
                left = mid;
                mid = (left + right) / 2;
            }else{
                right = mid - 1;
                left = (left + right) / 2;
            }
        }
        return -1;
    }
};


void test_arr()
{
    int array[2][3] = {{1,2,3}, {4,5,6}};
    cout << &array[0][0] << " " << &array[0][1] << " " << &array[0][2] << endl;
    cout << &array[1][0] << " " << &array[1][1] << " " << &array[1][2] << endl;
}

int main()
{
    test_arr();
    Solution solution1;
    vector<int> nums = {-1,0,3,5,9,12};
    vector<int> nums2 = {2,5};
    int s1 = solution1.search(nums, 2);
    printf("target:%d\n", s1);
    return 0;
}