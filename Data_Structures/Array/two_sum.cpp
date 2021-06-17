// ------------------------------------------------------------------- TWO SUM PROBLEM --------------------------------------------------------------------------------------
// Time Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

int main(){

    int sum = 15;
    vector<int> arr={5, 6, 7, 8, 2, 4};

    unordered_map<int, int> mp;

    for (int i = 0; i < arr.size(); i++){
        int rem = sum - arr[i];
    
    if(mp.find(rem) != mp.end()){
        cout<< i << " " << mp[rem] << endl;  // if rem in map print indices
    }
    mp[arr[i]] = i; // insert element in map
    }


    return 0;
}