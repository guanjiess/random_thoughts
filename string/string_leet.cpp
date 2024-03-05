#include <cstdio>
#include <string>
#include <vector>
using namespace std;

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