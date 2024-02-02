#include <iostream>
#include <string>
#include <stack>
using namespace std;



bool isBalanced (string str) {
    stack <char> s;
    string exp = str;


    for(int i = 0; i < exp.length();i++) {
        if (exp[i] == '[' || exp[i] == '{' || exp[i] == '(') {

            s.push(exp[i]);
        } else if (exp[i] == ']' || exp[i] == '}' || exp[i] == ')') {
            if (s.empty())
                return false;

            else if (exp[i] == ']' && s.top() != '[') {
                return false;

            } else if (exp[i] == '}' && s.top() != '{') {
                return false;
            } else if (exp[i] == ')' && s.top() != '(') {
                return false;
            }

            s.pop();
        }
    }
    return s.empty();
}

int main(){

    string str = "{[()]}";
    if(isBalanced(str)){
        cout << "Balanced" << endl;
    }
    else {
        cout << "Not Balanced" << endl;
    }

    return 0;
}
