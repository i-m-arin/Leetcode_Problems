class Solution {
public:
    
    bool func(vector<int> nums, vector<int> v,int target, int n){
        
        for(int i=0;i<v.size();i++){
            if(v[i]+nums[n]>target) continue;
            v[i]+=nums[n];
            if(n==nums.size()-1) return true;
            if(func(nums,v,target,n+1)) return true;
            v[i]-=nums[n];
            // if(v[i]==0) return false;
            
        }
        
        return false;
        
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(auto x:nums) sum+=x;
        if(sum%k) return false;
        int target = sum/k;
        sort(nums.rbegin(),nums.rend());
        vector<int> v(k,0);
        
        return func(nums,v,target,0);
        
    }
};