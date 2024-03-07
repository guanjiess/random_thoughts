#include <string>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include "string_leet.cpp"
using namespace std;

void test_28(){

}

void test_151(){
    string s = " long live the   king ";
    //string ans = removeExtraSpace(s);
    //cout << ans << endl;
    reverseWords(s);
}

void test_541()
{
    cout <<"==========test 344" << endl;
    string s1 = "abcdefg";
    string a1 = reverseStr(s1, 2);
    cout << s1 << endl << a1 <<endl;
    string s2 = "abcdefg";
    string a2 = reverseStr(s2, 8);
    cout << s2 << endl << a2 <<endl;

    cout <<endl;
}


void test_344()
{
    cout <<"==========test 344" << endl;
    vector<char> s1 = {'h','e','y'};
    reverseString(s1);
    for (char a : s1) {
        cout << a;
    }
    cout << endl;
}

int main()
{
    test_344();
    test_541();
    return 0;
}