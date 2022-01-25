#include <bits/stdc++.h>
using namespace std;

void printStrings(string res, int n){
    if (res.size() == n) {
        cout<<res<<endl;
        return;
    }

    res.push_back('0');
    printStrings(res, n);
    res.pop_back();


    res.push_back('1');
    printStrings(res, n);
    res.pop_back();
    
    }

int main(){
    int n = 5;
    printStrings("", n);
    return 0;
}
