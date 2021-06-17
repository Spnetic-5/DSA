// -------------------------------------------------------------------- Kadane Algorithm ----------------------------------------------------------------------------
// Time Complexity O(N)

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n=8;
    vector<int> arr = {4, 6, -1, 7, 8, -3, -4, 2, 9};

    int ans = arr[0]; int sum_max = arr[0];

    for(int i=0; i<n; i++){
        sum_max = max(sum_max + arr[i], arr[i]);
        ans = max(sum_max, ans);
    }
    
    cout<<ans<<endl;
    


    return 0;
}
