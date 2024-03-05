#include <cstdio>
#include <iostream>
#include <new>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;


// leetcode 383
bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> mag_cha;
    for(char m:magazine){
        mag_cha[m]++;
    }
    for(char ran:ransomNote){
        if(mag_cha.find(ran) != mag_cha.end()){
            if(mag_cha[ran]) mag_cha[ran]--;
            else return false;
        } else {
            return false;
        }

    }
    return true;
}

// leetcode 454
int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    int count = 0;
    // sum12用来记录1、2两个集合中的数字之和，key记录和，value记录出现次数
    unordered_map<int,int> sum12;
    int size = nums1.size();
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            int sum = nums1[i] + nums2[j];
            sum12[sum]++;
        }
    }
    for (int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++){
            int complement = -(nums3[i]+nums4[j]);
            if(sum12.find(complement) != sum12.end()){
                count += sum12[complement];
            }
        }
    }
    return count;
}

// leetcode 1
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    // elements key-value定义为：数字-下标
    unordered_map<int,int> elements;
    for(int i = 0; i < nums.size(); i++){
        int num = target - nums[i];
        //找到后，把结果推入ans内，并跳出for循环
        if(elements.find(num) != elements.end()){
            ans.push_back(elements[num]);
            ans.push_back(i);
            break;
        }
        //没找到
        elements[nums[i]] = i; 
    }
    return ans;        
}


// leetcode 202
int squareSum(int n){
    int sum = 0;
    while(n){
        sum += (n%10)*(n%10);
        n = n / 10;
    }
    return sum;
}

bool isHappy(int n ){
    int sum =  n;
    unordered_set<int> sum_square;
    while(sum != 1){
        sum = squareSum(sum);
        if(sum_square.find(sum) != sum_square.end()) return false;
        sum_square.insert(sum);
    }    
    return true;
}

// leetcode 349
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set <int> result;
    unordered_set<int> nums(nums1.begin(),nums1.end());
    //遍历查询nums2中的元素，如果nums中也存在，则加入intersec
    for (int num:nums2) {
        //unordered_set，如果查询到元素，返回元素所在地的迭代器，
        //否则返回集合的末尾，end
        if(nums.find(num) != nums.end()){
            result.insert(num);
        }
    }
    vector<int> ans(result.begin(), result.end());
    return ans;
}



// leetcode 242
bool isAnagram(string s, string t){
    int record[26] = {0};
    if(s.length() != t.length()) return false;
    for (int i = 0; i < s.length(); i++) {
        record[s[i]-'a']++;
    }
    for (int i = 0; i < s.length(); i++) {
        record[t[i]-'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if(record[i]) return false;
    }
    return true;
}
bool isAnagram1(string s, string t){
    bool is = false;
    if(s.length() != t.length()) return false;
    int size = s.length();
    // 注意，动态地创建数组时，用括号()可以把所有值初始为0
    int* s_table = new int[size]();
    int* t_table = new int[size]();
    for (int i = 0; i < size; i++) {
        int s_index = s[i] - 'a';        
        int t_index = t[i] - 'a';
        s_table[s_index] ++;
        t_table[t_index] ++;        
    }
    for (int i = 0; i < 26; i++) {
        if(s_table[i] != t_table[i]) return false;
    }
    delete[] s_table;
    delete[] t_table;
    return true;
}
