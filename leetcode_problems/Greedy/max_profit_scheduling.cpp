// GFG
// TC: O(NlogN) + O(NxM)
// SC: O(M)  

bool comp(Job a, Job b){
    return (a.profit > b.profit);
};
    
vector<int> JobScheduling(Job arr[], int n) 
{ 
    // your code here
       
    sort(arr, arr+n, [this] (Job a, Job b){
        return comp(a,b);
    });
        
    int maxi= arr[0].dead;
    for(int i = 1; i<n; i++){
        maxi = max(maxi, arr[i].dead);
    }
    int slot[maxi +1];
        
    for(int i = 0; i<maxi; i++){
        slot[i] = -1;
    }
        
    int countJobs = 0, jobProfit = 0;
        
    for(int i=0; i<n; i++){
        for(int j = arr[i].dead; j>0; j++){
            if(slot[j]==-1){
                slot[j] = i;
                countJobs++;
                jobProfit+=arr[i].profit;
                break;
            }
        }
    }
    vector<int> result;
    result[0] = jobProfit;
    result[1] = countJobs;
 return result;   
} 




// Leetcode
struct Data{
        int s,e,c;
        Data(int x, int y, int z){
        s= x;
        e= y;
        c = z;
        }
    };
        
bool cmp(Data a, Data b){
    return a.e<b.e;
}

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    vector<Data> j;
    int n = startTime.size();
      for (int i = 0; i < n; i++) {
         Data temp(startTime[i], endTime[i], profit[i]);
         j.push_back(temp);
      }
      
      sort(j.begin(), j.end(), [this] (Data a, Data b)
           {
               return cmp(a,b);
           });
      vector<int> dp(n);
      dp[0] = j[0].c;
      for (int i = 1; i < n; i++) {
         int temp = 0;
         int low = 0;
         int high = i - 1;
         while (low < high) {
            int mid = low + (high - low + 1) / 2;
            if (j[mid].e <= j[i].s)
               low = mid;
            else
               high = mid - 1;
         }
         dp[i] = j[i].c;
         if (j[low].e <= j[i].s)
            dp[i] += dp[low];
         dp[i] = max(dp[i], dp[i - 1]);
      }
      return dp[n - 1];
        
    }