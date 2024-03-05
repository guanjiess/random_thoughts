#include <cstdio>
#include <iostream>
#include <new>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;


// leetcode18 fourSum
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int size = nums.size();
    // a + b + c + d，由外及里，每一层都要进行去重操作
    //叠加两层for循环，再使用双指针求解
    for (int i = 0; i < size; i++) {
        if(nums[i] > target) return result;
        if(i > 0 && nums[i] == nums[i-1]) continue;
        for(int j = i + 1; j < size; j ++){
            int sum12 = nums[i] + nums[j];
            //双指针遍历
            int left = j + 1;
            int right = nums.size() - 1;
            while(right>left){
                //左右指针去重
                int sum = nums[left] + nums[right] + sum12;
                if(sum > 0){
                    right --;
                }else if(sum < 0){
                    left ++;
                }else{

                }
                right --;
                left ++;
            }
        }
    }
    return result;
}


// leetcode15 2 pointers
// 三个数字下标彼此不同
// 相同的三元组只能出现一次，如{-1,-1,2}可能出现多次，但在答案中只能出现一次
// 所以需要在求得一个解以后进行去重操作，排除和当前相同的
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++){
        //初始判断条件
        if(nums[i]>0) return result;
        //对a去重，去重的目的在于去除重复的三元组合
        //合理性在于，nums已排序，所以相同的元素都是相邻的，对于a而言
        if(i >0 && nums[i] == nums[i-1]) {
            continue;
        }
        //双指针遍历，对每个a可能出现的所有组合做一次遍历
        int left = i + 1;
        int right = nums.size()-1;
        while(right > left){
            if(nums[i]+nums[left]+nums[right] > 0){
                right --;
            } else if(nums[i]+nums[left]+nums[right] < 0){
                left ++;
            } else {
                result.push_back({nums[i], nums[left], nums[right]});
                //对right, left去重，跳出while时，left\right 都指向一连串重复值中的最后一个
                while(right > left && nums[right] == nums[right-1]) right--;
                while(right > left && nums[left] == nums[left+1]) left++;
                right--;
                left++;
            }
        }
    }
    return result;
}

// leetcode 15
vector<vector<int>> threeSum1(vector<int>& nums) {
    vector<vector<int>> ans;
    unordered_map<int,vector<int>> sum12;
    for(int i = 0; i < nums.size(); i++){
        for(int j = i + 1; j < nums.size(); j++){
            int sum = nums[i] + nums[j];
            sum12[i].push_back(i);
            sum12[i].push_back(j);
        }
    }
    for(int i = 0; i < nums.size(); i++){
        int complement = -nums[i];
        // 找到符合条件的值，再判断是否有重叠项
        auto it = sum12.find(complement);
        if(it != sum12.end()){
            vector<int> sub_ans = it->second;
            // jesus, this is tough, let's try another method.
            //auto it2 = find(sub_ans.begin(),sub_ans.end(), i);

        }
    }

    return ans;
}


// leetcode 383-2
bool canConstruct(string ransomNote, string magazine) {
    int record[26] = {0};
    if(magazine.size() < ransomNote.size()) return false;
    for (char mag:magazine) {
        record[mag-'a']++;
    }
    for (char ran:ransomNote) {
        record[ran -'a']--;
    }
    for(int i = 0; i < 26; i ++){
        if(record[i] < 0) return false;
    }
    return true;
}

// leetcode 383-1
bool canConstruct2(string ransomNote, string magazine) {
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
