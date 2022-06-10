// Balanced Parentheses Code

#include <bits/stdc++.h>
using namespace std;


bool doesMatch(char a, char b){
    return(
        (a == '(' && b == ')') ||
        (a == '[' && b == ']') ||
        (a == '{' && b == '}') ||
        (a == '<' && b == '>')
    );

}

bool isClosing(char t){

    return(
        t == ')' ||
        t == ']' ||
        t == '}' ||
        t == '>' 
    );
}


bool isBalanced(string s){
    
    stack<char> sau;
    int n = s.length();
    for(int i = 0; i < n; i++){
        if(isClosing(s[i])){
            if (!sau.empty() && doesMatch(sau.top(), s[i])){
                sau.pop();
            }   
            else return false;
            }
        else sau.push(s[i]);
    }
    if (sau.empty()) return true;
    return false;
}


int main(){

    string s; cin>>s;
    if(isBalanced(s))cout<<"Balanced"<<endl;
    else cout<<"Not Balanced"<<endl;
    return 0;
}
