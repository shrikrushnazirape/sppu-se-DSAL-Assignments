/*
Name                :- Shrikrushna S Zirape
Assigment No        :- 10
Roll no             :- 21286
Batch               :- H2
problem statement   :- 
                    Implement C++ program for expression conversion as infix to postfix and its evaluation using stack based on given          conditions:  1. Operands and operator, both must be single character. 2. Input Postfix expression must be in a desired format. 3. Only '+', '-', '*' and '/ ' operators are expected. 
​
*/
#include <iostream>
#include <string.h>
using namespace std;
class stack{
    char stack_array[30];
    int top=-1;
    int n=30;
    public:
        char top_element(){
            return stack_array[top];
        }
        bool isempty(){
            if(top == -1){
                return true;
            }
            else return false;
        }

        void pop(){
            if(top == -1){
                cout<<"Stack Underflow \n";
            }
            else{
                top --;
            }
        }
        void push(char c){
            if(top >= n-1){
                cout<<"Stack Overflow \n";
            }
            else{
                top ++;
                stack_array[top] = c;
            }
        }

}s;

int precedence( char c){
    if(c == '+' || c == '-'){
        return 1;
    }
    else if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '^'){
        return 3;
    }
    else{
        return -1;
    }
}

bool is_Operator(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^'){
        return true;
    }
    else{
        return false;
    }
}

string InfixToPostfix(string infix){
    string postfix;
    for (int i=0; i<infix.length(); i++){
        //condition if the char is operend
        if((infix[i] >= 'a' && infix[i] <='z')||(infix[i] >= 'A' && infix[i] <='Z')){
            postfix+=infix[i];
        }

        else if(infix[i] == '('){
            s.push(infix[i]);
        }

        else if(infix[i] == ')'){
            while((s.top_element() != '(') && (!s.isempty())){
                char temp = s.top_element();
                postfix += temp;
                s.pop();
            }
            if(s.top_element() == '('){
                s.pop();
            }
        }
        else if(is_Operator(infix[i])){
            if(s.isempty()){
                s.push(infix[i]);
            }
            else{
                if(precedence(infix[i])> precedence(s.top_element())){
                    s.push(infix[i]);
                }
                else{
                    while((!s.isempty()) && (precedence(infix[i])<= precedence(s.top_element()))){
                        postfix+=s.top_element();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }
    while ( !s.isempty()){
        postfix+=s.top_element();
        s.pop();
    }
    
    return postfix;
}

int main(){
    string s1;
    while (true){

    cout<<"Enter the string :";
    cin>>s1;
    cout<<"\n *******************************************\n";
    cout<<"Infix Exp:-        "<<s1<<endl;
    cout<<"Postfix Exp :-     "<<InfixToPostfix(s1)<<endl;
    cout<<"\n *******************************************\n";
    }
    return 0;
}
/*
OUTPUT:-

Enter the string :a+b*(c^d-e)^(f+g*h)-i

 *******************************************
Infix Exp:-        a+b*(c^d-e)^(f+g*h)-i    
Postfix Exp :-     abcd^e-fgh*+^*+i-        

 *******************************************
Enter the string :X*Y/Z+P*Q-R           

 *******************************************
Infix Exp:-        X*Y/Z+P*Q-R
Postfix Exp :-     XY*Z/PQ*+R-

 *******************************************
*/