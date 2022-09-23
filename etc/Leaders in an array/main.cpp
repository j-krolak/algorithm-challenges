class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
       int maxSuf[n+1];
       maxSuf[n] = 0;
       for(int i = n-1; i >= 0; i--)
       {
            maxSuf[i] = max(a[i], maxSuf[i+1]);
       }
       
       vector<int> ans;
       
       for(int i = 0; i < n; i++)
       {
            if(a[i] >= maxSuf[i+1])
                ans.push_back(a[i]);
       }
       
       return ans;
    }
};
