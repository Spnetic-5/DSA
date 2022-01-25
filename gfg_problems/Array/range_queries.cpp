// -------------------------------------------------------------------- Range Queries ----------------------------------------------------------------------------
// Time Complexity O(Q+N)

#include <bits/stdc++.h>
using namespace std;
int main(){
    
    int n=10;
    vector<int> arr(n+1);
    vector<vector<int>> queries = {
        {2,3,5},
        {1,6,3},
        {3,9,7},
        {0,4,3}
    };

    for(auto q : queries){
        arr[q[0]] += q[2];
        arr[q[1]] -= q[2];
    }

    for(int i=0; i<n; i++){
        arr[i] = arr[i] + arr[i-1];        
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";        
    }
    cout<<endl;


    return 0;
}
