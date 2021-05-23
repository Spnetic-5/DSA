// Logic : 
// 1) Initialize start and end indexes as start = 0, end = n-1 
// 2) In a loop, swap arr[start] with arr[end] and change start and end as follows : 
// start = start +1, end = end – 1

#include <iostream>
using namespace std;
int main(){
    int n;cin>>n;
    int array[n];
    int start = 0; 
    int end = n-1; 
    
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    
    
    while(start<end){
        int s = array[start];
        array[start] = array[end];
        array[end] = s;
        start++;
        end--;

    }
    cout<<"Reversed array"<<endl;
    for(int i=0;i<n;i++){
        
        cout<<array[i];
    }

    return 0;
}