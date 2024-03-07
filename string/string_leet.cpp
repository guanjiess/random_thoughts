#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;


// leetcode 28
string srtStr(string haystack, string needle){
    string ans;

    return ans;
}

// leetcode 151
string removeExtraSpace(string s){
    //正常英语短语中，首尾没有空格、单词间只有一个空格，需要考虑去重
    //" long live the   king "--> "long live the king"
    string ans;
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if(s[i] != ' '){
            //每经历一个while，拆出一个单词
            //单词前补一个空格
            if(i>0 && ans.length() != 0 && s[i] != ' ' ) ans += ' ';
            while (s[i] != ' ') {
                ans += s[i];
                i ++;
            }
        }
    }
    return ans;
}
void reverse(string &s, int start, int end){
    for(int i = start, j = end; i < j; i++, j--){
        swap(s[i], s[j]);
    }
}

string reverseWords(string s) {
    string ans;
    //step1. remove extra space
    ans = removeExtraSpace(s);
    cout << ans << endl;
    reverse(ans, 0, ans.size()-1);
    cout << ans << endl;
    int start = 0;
    for (int i = 0; i < ans.size(); i++) {
        if(i == ans.size()-1) reverse(ans, start, i);
        if(ans[i] == ' '){
            reverse(ans, start, i-1);
            start = i + 1;
        }
    }
    cout << ans << endl;
    return ans;
}

// leetcode 541
string reverse_2k(string s, int len){
    for (int i = 0; i < len/2; i++) {
        swap(s[i], s[len-1-i]);
    }
    return s;
}
string reverseStr(string s, int k) {
    string ans;
    int len = s.length();
    int break_point = 0;
    string sub;
    //注意substr的用法，sub(i,len)，表示从i开始，截取长度为k的字符
    for (int i = 0; i < len; i += 2*k) {
        if(i+2*k < len){
            string sub1 = s.substr(i, k);
            string sub2 = s.substr(i+k, k);
            string rev_sub1 = reverse_2k(sub1, k);
            ans = ans + rev_sub1 + sub2; 
        } else {
            break_point = i;
            break;
        }
    }
    if(len-break_point >= k){
        string sub1 = s.substr(break_point, k);
        sub1 = reverse_2k(sub1, k);
        string sub2 = s.substr(break_point+k);
        ans = ans + sub1 + sub2;
    } else{
        string sub1 = s.substr(break_point);
        sub1 = reverse_2k(sub1, len-break_point);
        ans = ans + sub1;
    }
    return ans;
}


// leetcode 344
void reverseString(vector<char>& s){
    int size = s.size();
    for (int front = 0; front < size/2; front++){
        int rear = size - front - 1;
        swap(s[front], s[rear]);
    }
}