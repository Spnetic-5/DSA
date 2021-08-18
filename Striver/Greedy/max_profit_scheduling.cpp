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