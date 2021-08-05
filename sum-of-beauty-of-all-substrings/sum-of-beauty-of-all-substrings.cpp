class Solution {
public:
    int beautySum(string s) {
        // map<char,int> mp;
        int ans=0;
        
        for(int i=0;i<s.size();i++){
            vector<int> mp(26,0);

            mp[s[i]-'a']++;
            for(int j=i+1;j<s.size();j++){
                mp[s[j]-'a']++;
                int mx=0,mn=1e6;
                for(int k=0;k<=25;k++){
                    if(mp[k]>0){
                        mx=max(mx,mp[k]);
                        mn = min(mn,mp[k]);
                    }
                }

                ans+=mx-mn;  
            }
            //cout<<ans<<endl;
        }

        
        return ans;
        
    }
};