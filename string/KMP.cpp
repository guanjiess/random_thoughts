#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

// KMP算法模式匹配的核心概念：前缀、后缀、前缀表、next数组
// 前缀：模式串从第一个字符开始的字串，即不包括最后一个字符的左字串
// 后缀：模式串以最后一个字符为结尾的子串，即不包括首字符的右子串
// 前后缀匹配：前缀 = 后缀
// next数组：next[i]记录着模式串中0~i子串中，最大匹配前缀的末位下标 
void getNext(int* next, const string& pattern){
    int j = -1, size = pattern.size();
    next[0] = j;
    for (int i = 1; i < size; i++) {
    //i为当前字串的最后一个字符下标，当前比较位。
    //j+1就是最大匹配前后缀的长度，j就是最大匹配前缀的末尾下标
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
        //不行就退一步，再不行就继续退，退到退无可退
        while(text[i] != pattern[j+1]){
            j = next[j];
        }
        //匹配成功，前进一步
        if(text[i] == pattern[j+1]){
            j ++;
        }
        if(j == (pattern.size()-1)){
            return (i-pattern.size()+1);
        }
    }
    return -1;
}

int KMP_violence(string source, string pattern)
{
    for(int i = 1; i <= source.size(); i++){
        bool flag = true;
        for(int j = 1; j <= pattern.size(); j++){
            if(source[i] != pattern[j]) return false;
        }
    }
    return true;
}

void getNe(string& pattern, int* ne){
    int size = pattern.length();
    int j = -1;
    ne[0] = j;
    for (int i = 1; i < size; i++) {
        // 不匹配，就回退
        while(j != -1 && pattern[i] != pattern[j+1]){
            j = ne[j];
        }
        if(pattern[i] == pattern[j+1]){
            j++;
        }
        ne[i] = j;
    }
}
const int N = 1e5 + 10, M = 1e6 + 10; 
int ne[N];
int kmp(string& text, string& pattern){
    getNe(pattern, ne);
    int j = -1;
    for (int i = 0; i < text.size(); i++) {
        while (j != -1 && pattern[j+1] != text[i]) {
            j = ne[j];
        }
        if(pattern[j+1] == text[i]){
            j ++;
        }
        if(j == (pattern.size()-1)){
            int ans = i - pattern.size() + 1;
            printf("%d\n", ans);
            return ans;
        }
    }
    return -1;
}

int main()
{
    //string text = "aabaafaafa";
    //string pattern1 = "aabaaf";
    //string pattern2 = "abababc";
    //int* next = new int[pattern2.length()];
    //getNext(next, pattern2);
    //int index = KMP(text, pattern1);
    //cout << index << endl;
//
    string text = "aabaafaafa";
    string pattern1 = "aabaaf";
    kmp(text, pattern1);

    return 0;
}