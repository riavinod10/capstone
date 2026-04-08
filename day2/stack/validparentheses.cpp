#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        int n = str.size();

        for (int i = 0; i < n; i++) {

            if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
                s.push(str[i]);
            }
            else {
                if (s.empty()) return false;

                if ((s.top() == '(' && str[i] == ')') ||
                    (s.top() == '{' && str[i] == '}') ||
                    (s.top() == '[' && str[i] == ']')) {
                    s.pop();
                }
                else {
                    return false;
                }
            }
        }

        return s.empty();
    }
};

int main() {
    Solution obj;

    string str = "{[()]}";

    if (obj.isValid(str))
        cout << "Valid Parentheses";
    else
        cout << "Invalid Parentheses";

    return 0;
}