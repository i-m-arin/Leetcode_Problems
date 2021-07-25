class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        if(k==0){
            map<int,int> mp;
            for(int i=0;i<nums.size();i++){
                mp[nums[i]]++;
            }
            int cnt=0;
            for(auto x:mp){
                if(x.second>=2) cnt++;
            }
            return cnt;
        }
        
        set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int cnt=0;
        for(auto x:st){
            if(st.find(x-k)!=st.end()) cnt++;
            if(st.find(x+k)!=st.end()) cnt++;
        }
        
        return cnt/2;
    }
};