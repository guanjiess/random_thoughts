#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

// KMP算法模式匹配的核心概念：前缀、后缀、前缀表、next数组
// 前缀：模式串从第一个字符开始的字串，但不能包括最后一个字符
// 后缀：模式串以最后一个字符为结尾的字串，但不能包括第一个字符
// 前后缀匹配：前缀 = 后缀
// next数组：next[i]记录着模式串中0~i内字串中，最大匹配前后缀的长度-1 
void getNext(int* next, const string& pattern){
    int j = -1, size = pattern.size();
    next[0] = j;
    for (int i = 1; i < size; i++) {
    //i为当前字串的最后一个字符下标，当前比较位。
    //j记录了当前循环内字串的（最大匹配前后缀长度-1），即最大匹配前缀的末尾下标
        //处理不匹配的情况
        while (j != -1 && pattern[i] != pattern[j+1]) {
            j = next[j];
        }
        //如果匹配，j+1
        if(pattern[i] == pattern[j+1]){
            j ++;
        }
        //记录j，即最长匹配前缀下标
        next[i] = j;
    }
    for (int i = 0; i < size; i ++) {
        printf("%d ", next[i]);
    }
    printf("\n");
}

int KMP(string& text, string& pattern){
    if(pattern.size() == 0) return 0;
    int j = -1;
    int next[pattern.size()];
    getNext(next, pattern);
    for (int i = 0; i < pattern.size(); i++) {
        while(text[i] != pattern[j+1]){
            j = next[j];
        }
        if(text[i] == pattern[j+1]){
            j ++;
        }
        if(j == (pattern.size()-1)){
            return (i-pattern.size()+1);
        }
    }
    return -1;
}

int main()
{
    string text = "aabaafaafa";
    string pattern1 = "aabaaf";
    string pattern2 = "abababc";
    int* next = new int[pattern2.length()];
    getNext(next, pattern2);
    int index = KMP(text, pattern1);
    cout << index << endl;

    delete[] next;
    return 0;
}