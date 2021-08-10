class Solution {
public:
    
    int dp[21][31];
    
    bool func(string s,string p,int i,int j){
        if(dp[i][j]!=-1) return dp[i][j];
        if(j==p.size()){
            if(i==s.size()) return dp[i][j]=1;
            else return dp[i][j]=0;
        }
        
        if(i > s.size()){
            return dp[i][j] = false;
        }
        
        bool some = p[j]==s[i] || p[j]=='.';
        
        if(j + 1 < p.size() && p[j+1]=='*'){
            return dp[i][j] = func(s,p,i,j+2) || some && func(s,p,i+1,j);
        }
        else return dp[i][j] = some && func(s,p,i+1,j+1);
    
    }
    
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));
        return func(s,p,0,0);
    }
};