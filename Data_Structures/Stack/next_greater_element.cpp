
#include<bits/stdc++.h>
using namespace std;

int main(){

    int n = 10;
    int arr[n] = {5,2,34,9,32,9,12,11,9,24};
    int ans[n];
    stack<int>stk;
    for(int i=0; i<n;i++){
        while(!stk.empty() && stk.top() < arr[i]){

            ans[stk.top()] = arr[i];
            stk.pop(); 
        }
        stk.push(i);
    }
    while(!stk.empty()){
        ans[stk.top()]=-1;
        stk.pop();
    }
for(int i = 0 ; i < n ; i ++ )cout<<i<<" "<<arr[i]<<" "<<ans[i]<<endl;
    return 0 ; 
}