#include <cstdio>
#include <iostream>
#include <vector>
#include "hash_basic.cpp"
using namespace std;

void test_18()
{
    printf("----------->test for leetcode 18.\n");
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>> ans = fourSum(nums, target);
    for(auto it = ans.begin(); it != ans.end(); it++){
        vector<int> four = *it;
        for (auto it2 = four.begin(); it2 != four.end(); it2++) {
            printf("%d ", *it2);
        }
        printf("\n");
    } 
    printf("\n");
}

void test_242()
{
    printf("----------->test for leetcode 242.\n");
    string s1 = "rat";
    string s2 = "car";
    bool ans1 = isAnagram(s1, s2);
    printf(ans1?"true\n":"false\n");
    string s3 = "anagram";
    string s4 = "nagaram";
    bool ans2 = isAnagram(s3, s4);
    printf(ans2?"true\n":"false\n");
}

void test_349()
{
    printf("----------->test for leetcode 349.\n");
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    vector<int> ans1 = intersection(nums1, nums2);
    for(auto it = ans1.begin(); it != ans1.end(); it++){
        printf("%d ", *it);
    }

    printf("\n");
}

void test_202(){
    printf("----------->test for leetcode 202.\n");
    printf("%d\n", squareSum(12));
    printf("%d\n", squareSum(13));
    printf("%d\n", squareSum(16));
    printf("%d\n", squareSum(165));
    printf( isHappy(2)? "true\n":"false\n");
    printf( isHappy(19)? "true\n":"false\n");

    printf("\n");
}


int main()
{
    test_242();
    test_349();
    test_202();
    test_18();
}