/* Code: Infix to postfix
Given an infix expression S in the form of a string. You need to convert and print that input expression in postfix form. After that, evaluate and print the result of given expression in next line.
Input Format :
Infix expression
Output Format :
Line 1 : Corresponding postfix expression
Line 2 : Result of input expression after evaluation
Constraints :
1 <= Length of S <= 100
Sample Input 1 :
3+4
Sample Output 1 :
34+
7
*/

// Solution:
#include<bits/stdc++.h>
int length(char input[]){
    int i = 0;
    while(input[i]){
        i++;
    }
    return i;
}
int priority(char c){
    if(c == '*' or c == '/'){
        return 2;
    }
    else if(c == '+' or c == '-'){
        return 1;
    }
    else{
        return -1;
    }
}
int evaluate(int op1, int op2, char operate){
    switch(operate){
        case '*': return op2 * op1;
        case '/': return op2 / op1;
        case '+': return op2 + op1;
        case '-': return op2 - op1;
        default : return 0;
    }
}
void infixToPostfix(char* input){
    stack<char> s;
    int len = length(input);
    vector<char> output;
    for(int i = 0; i < len; i++){
        if(input[i] >= '0' and input[i] <= '9'){
            output.push_back(input[i]);
        }
        else if(input[i] == '('){
            s.push(input[i]);
        }
        else if(input[i] == ')'){
            while(!s.empty() and s.top() != '('){
                char c = s.top();
                s.pop();
                output.push_back(c);
            }
            if(s.top() == '('){
                char c = s.top();
                s.pop();
            }
        }
        else{
            while(!s.empty() and priority(input[i]) <= priority(s.top())){
                char c = s.top();
                s.pop();
                output.push_back(c);
            }
            s.push(input[i]);
        }
    }
    while(!s.empty()){
        char c = s.top();
        s.pop();
        output.push_back(c);
    }
    for(int i = 0; i < output.size(); i++){
        cout << output[i];
    }
    cout << endl;
    int i = 0;
    for(i = 0; i < output.size(); i++){
        input[i] = output[i];
    }
    input[i] = '\0';
}
int evalPostfix(char postfix[]){
    stack<int> s;
    int i = 0;
    char ch;
    int val;
    int len = length(postfix);
    while(i < len){
        ch = postfix[i];
        if(isdigit(ch)){
            s.push(ch - '0');
        }
        else{
            int op1 = s.top();
            s.pop();
            int op2 = s.top();
            s.pop();
            val = evaluate(op1, op2, ch);
            s.push(val);
        }
        i++;
    }
    cout << val;
}
void evaluatePostfix(char exp[]) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print the required output.
     * Taking input is handled automatically.
     */
    infixToPostfix(exp);
    evalPostfix(exp);
}

// Main Code:
/*
//  C++ implementation to convert infix expression to postfix
// Note that here we use std::stack  for Stack operations
#include<iostream>
using namespace std;
//Driver program to test above functions
int main()
{
    char exp[1000];
    cin >> exp;
    evaluatePostfix(exp);
    return 0;
}
*/