class Solution {
public:
    int cnt;
    int vis[200*200 +10];
    vector<int> ar[202];
    
//    void dfs(vector<vector<int>>& arr,int i,int j,int n){
//         if(i<0 || j<0 || i>=n || j>=n)
//             return;
//         if(vis[i][j]==1 || arr[i][j]==0)
//             return;
//         vis[i][j]=1;
        
//         dfs(arr,i+1,j,n);
//         dfs(arr,i-1,j,n);
//         dfs(arr,i,j+1,n);
//         dfs(arr,i,j-1,n);
//     }
        
    void dfs(int n){
        vis[n]=1;
        for(auto x:ar[n]){
            if(vis[x]==0) dfs(x);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        cnt=0;
        int n = isConnected.size();
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            ar[i].clear();
            for(int j=0;j<n;j++){
                
                if(isConnected[i][j]==1){
                    ar[i].push_back(j);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                cnt++;
                dfs(i);
            }
        }
        
        return cnt;
    }
};