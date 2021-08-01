class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        mp[0]=1;
        int cnt=0,sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            cnt+=mp[sum-k];
            mp[sum]++;
        }
        
        return cnt;
        
        
    }
};