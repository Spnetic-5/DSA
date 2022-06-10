
#include <bits/stdc++.h>  
#include <iostream>

 
using namespace std;
 

 string defangIPaddr(string address) {
 string s;
    for(int i=0;i<address.length();i++)
    {
        if(address[i]!='.')
            s+=address[i];
        else
            s+="[.]";
    }
    return s;
 }
int main()
{
    
    string st = "192.68.1.1" ;
    cout<<defangIPaddr(st);
    return 0;
}

