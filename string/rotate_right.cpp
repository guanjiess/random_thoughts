#include <algorithm>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    int n;
    cin >> s;
    cin >> n;
    reverse(s.begin(), s.end());    
    reverse(s.begin(), s.begin()+n);
    reverse(s.begin()+n, s.end());
    cout << s;
    return 0;
}