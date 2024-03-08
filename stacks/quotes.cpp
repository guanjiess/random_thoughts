#include <iostream>
#include <stack>
using namespace std;

// leetcode 20
// 分析：一个可以多重嵌套的括号，一定是完全左右对称的 (((({{{{[[[     ]]]}}}}))))
// 或者这种组合型  {[]}{{(([]))}}
// 这种结构正好和栈的先进后出结构非常契合，即，最外层的左括号对应着最右边的右括号。
// 所以每遇到一个左括号，都可以在栈内压入一个右括号。
// 每遇到一个右括号，都可以和栈顶元素做对比，如果相同，那么则是匹配的，可以弹出当前
// 右括号，继续匹配下一个右括号，共有三种错误情况
// 1、左括号多余，表现为栈非空
// 2、右括号多余，表现为在for循环内对比时，栈已经空了
// 3、数量是够的，但是括号类型不匹配，表现类似于这种 {]
bool isValid(string s){
    if(s.size()%2 == 1) return false;

    stack<char> quotes;
    for (int i = 0; i < s.size(); i++) {
        char temp = s[i];
        if(temp == '(') quotes.push(')');
        else if(temp == '[') quotes.push(']');
        else if(temp == '{') quotes.push('}');
        else if (quotes.empty() || quotes.top() != s[i]){
            return false;
        }
        else quotes.pop();
    }
    return quotes.empty();
}


int main()
{
    // case1, leftovers on the left
    string s1 = "()[{}]()";
    bool valid1 = isValid(s1);
    cout << valid1 << endl;

    // case2, leftovers on the right
    string s2 = "()";
    bool valid2 = isValid(s2);
    cout << valid2 << endl;
    
    // case3, no leftover, but not match
    string s3 = "(((])))";
    bool valid3 = isValid(s3);
    cout << valid3 << endl;
    return 0;
}