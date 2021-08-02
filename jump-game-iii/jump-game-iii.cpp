class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        int n =arr.size();
        int vis[n];
        memset(vis,0,sizeof(vis));
        
        q.push(start);
        vis[start]=1;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            if(arr[cur]==0) return true;
            if(cur + arr[cur]<n && vis[cur + arr[cur]]==0){
                vis[cur + arr[cur]]=1;
                q.push(cur+arr[cur]);
            }
            if(cur - arr[cur]>=0 && vis[cur - arr[cur]]==0){
                vis[cur - arr[cur]]=1;
                q.push(cur-arr[cur]);
            }
            
        }
        
        return false;
        
    }
};