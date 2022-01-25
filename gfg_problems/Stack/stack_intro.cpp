#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000;
class Stack{

private:
    int arr[MAX];
    int top;
public:
    Stack(){
        top = -1;
    }
    void push(int val){
        if(top==MAX-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        top++;
        arr[top]=val;
    }
    void pop(){
        if(top>=0){
            top--;
            return ;
        }
        cout<<"Stack is Empty"<<endl;
    }
    int peek(){
        if(top>=0){
            return arr[top];
        }
        cout<<"Stack is Empty"<<endl;
    }
    bool isEmpty(){
        return top==-1;
    }
};
int main(){
    Stack s;
    s.push(112);
    s.push(60);
    s.push(99);
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    s.push(1000);
    while(!s.isEmpty()){
        cout<<s.peek()<<" ";
        s.pop();
    }
    return 0 ; 
}