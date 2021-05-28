// Time Complexity : 
//  ------------------------------------------ LONGEST ARITHMETIC SUBARRAY -----------------------------------------------

#include <iostream>
using namespace std;
int main(){

    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    

    int prev_d = arr[1]-arr[0];
    int len = 2;
    int j=2;
    int cur_len = 2;
    while(j<n){ 
        if (prev_d == arr[j]-arr[j-1]){
            cur_len++;
        }
        else{
            prev_d = arr[j]-arr[j-1];
            cur_len = 2;
        }
        len = max(len,cur_len);
        j++;
    }
    cout<<"Lenght of longest Arithmetic subarray is : "<<len<<endl;
    return 0;
}