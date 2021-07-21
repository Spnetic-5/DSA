#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
struct node{
    int value;
    node *next;
};

node *insert(node *head, int val){
    node *new_node = new node;
    new_node->value = val;
    new_node->next = head;
    return new_node;
}

void print_list(node *head){
    node *temp = head;
    while(temp != NULL){
        cout << temp->value << " -> ";
        temp = temp->next;
        }
   cout<<endl;    
}



int main()
{
    node *ll;
    ll = insert(ll, 5);
    ll = insert(ll, 2);
    ll = insert(ll, 9);
    ll = insert(ll, 4);
    ll = insert(ll, 8);
    print_list(ll);

    return 0;
}