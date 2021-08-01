class Solution {
public:
    
    int dp[1001][2001];
    
    int cnt=0;
    
    void func(vector<int> &nums,int target,int idx,int sum){
        if(idx==nums.size()){
            if(sum==target) cnt++;
            return;
        }
        // cout<<idx<<" "<<1000+sum<<endl;
        // if(dp[idx][1000 + sum] != -1) return;
        
        func(nums,target,idx+1,sum+nums[idx]);
        func(nums,target,idx+1,sum-nums[idx]);
        
        dp[idx][1000+sum] = 1;
        
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        
        cnt=0;
        func(nums,target,0,0);
        
        return cnt;
        
    }
};