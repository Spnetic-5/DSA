
#include <bits/stdc++.h>  
#include <iostream>

 
using namespace std;
 

string LCP(string s1, string s2){
    string res;
    int n1 = s1.size();
    int n2 = s2.size();
    int i, j;
    for(i=0, j=0; i<=n1-1 && j<=n2-1; i++, j++){
        if(s1[i] != s2[j]){
            break;
        }
            
        res.push_back(s1[i]);
    }
        
    return res;
}
    
string longestCommonPrefix(vector<string> const &str) {
        
    string pre = str[0];
        
    for(int i=1; i<str.size(); i++){
        pre = LCP(pre, str[i]);
    }
        
    return pre;
}
int main()
{
     vector<string> str { "flower","flow","flight" };
    cout<<longestCommonPrefix(str);
    return 0;
}




