#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

string removeDuplicates(string s) {
    string result;
    for(char a : s){
        if(result.empty() || a != result.back()){
            result.push_back(a);
        }
        else{
            result.pop_back();
        }
    }

    return result;
}

int evalRPN(vector<string>& tokens) {
    int ans = 0;
    stack<long long> st;
    for (string s : tokens) {
        if(s == "+" || s == "-" || s == "*" || s == "/"){
            long long num2 = st.top(); st.pop();
            long long num1 = st.top(); st.pop();
            int num3;
            if(s == "+") num3 = num1 + num2;
            else if(s == "-") num3 = num1 - num2;
            else if(s == "*") num3 = num1 * num2;
            else if(s == "/") num3 = num1 / num2;
            st.push(num3);
        } else {
            long long num = stoll(s);
            st.push(num);
        }
    }
    ans = st.top();
    return ans;
}

int main()
{
    string s = "aabbac";
    string ans = removeDuplicates(s);
    cout << ans << endl;

    vector<string> token1 = {"2","1","+","3","*"};
    cout << evalRPN(token1) << endl;
    vector<string> token2 = {"4","13","5","/","+"};
    cout << evalRPN(token2) << endl;

}
