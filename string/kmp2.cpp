#include <iostream>
using namespace std;

// 1e5 means 1*100000
const int N = 1e4+10, M = 1e5+10;
int ne[N];

// ne中记录着模式串中前缀和后缀的最长公共元素长度
void getNe(string& pattern, int* ne)
{
    int j = -1;
    ne[0] = -1;
    // ne[0]已定，从1开始循环，每次循环判断一次 pattern[i]==pattern[j+1]
    for (int i = 1; i < pattern.size(); i++) {
        while(j != -1 && pattern[i] != pattern[j+1]){
            j = ne[j];
        }
        if(pattern[j+1] == pattern[i]){
            j ++;
        }
        ne[i] = j;
    }
}
int kmp(string& text, string& pattern)
{
    if(pattern.size() == 0) return -1;
    int ne[pattern.size()];
    int j = -1;
    ne[0] = -1;
    int count = 0;
    getNe(pattern, ne);
    for(int i = 0; i < text.size(); i++){
        while(j != -1 && pattern[j+1] != text[i]){
            j = ne[j];
        }
        if(pattern[j+1] == text[i]){
            j ++;
        }
        if(j == pattern.size()-1){
            count ++;
            j = ne[j];
            //return (i - pattern.size() + 1);
        }
    }
    return count;
}



int main()
{
    string text = "aabaafaafa";
    string pattern1 = "aabaaf";
    int count1 = kmp(text, pattern1);
    printf("%d\n", count1);
    string text2 = "aabaabaabaabaaba";
    string pattern2 = "aab";
    int count2 = kmp(text2, pattern2);
    printf("%d\n", count2);
    return 0;
}