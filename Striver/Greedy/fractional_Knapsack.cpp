// Fractional Knapsack
// TC: O(NlogN) + O(N) 
// SC: O(1)

bool comp(Item a, Item b){
    double r1= (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1>r2;
}
    
//Function to get the maximum total value in the knapsack.
double fractionalKnapsack(int W, Item arr[], int n)
{
    // Your code here
    sort(arr, arr+n, [this] (Item a, Item b){
        return comp(a, b);
    });
    int curWeight = 0;
    double finalValue = 0.0;
        
    for(int i = 0; i<n;i++){
        if(curWeight + arr[i].weight <= W){
            curWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
            
        else{
            int remain = W - curWeight;
            finalValue += (arr[i].value / (double)arr[i].weight * (double)remain);
            break;
        }
    }
    
    return finalValue;
}