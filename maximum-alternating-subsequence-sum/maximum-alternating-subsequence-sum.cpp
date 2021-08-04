class Solution {
public:
    long long maxAlternatingSum(vector<int>& a) {
        
        long long ans=0;
        int n=a.size();
        int i=0;
        while(i<n-1 && a[i]<a[i+1]) i++;
        
        if(i==n) return a[n-1];
        
        ans = a[i];
        i++;
        while(i<n){
            int sum1=0,sum2=0;
            
            while(i<n-1 && a[i]>=a[i+1]) i++;
            if(i==n) break;
            sum2=a[i];
            i++;
            
            while(i<n-1 && a[i]<=a[i+1]) i++;
            if(i==n) break;
            sum1=a[i];
            i++;
            ans+=sum1-sum2;
        }
        
        return ans;
    }
};