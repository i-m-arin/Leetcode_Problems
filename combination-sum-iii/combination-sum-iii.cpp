class Solution {
public:
    
    void func(vector<vector<int>> &ans, vector<int> v,int k,int n,int sum,int cnt,int i){
    
    // cout<<cnt<<" "<<sum<<endl;

    if(cnt==k && sum==n){
        ans.push_back(v);
        return;
    }    
    if(cnt>k || sum>n ) return;

    if(i>9) return;
    
//         if(v.size()==0){
//             for(int i=1;i<=9;i++){
            
//                 v.push_back(i);
//                 func(ans,v,k,n,sum+i,cnt+1);
//                 v.pop_back();
            
//             }
//             return;
//         }
//         int last;
//         if(v.size()==0) last=0;
//         else last = v[v.size()-1];
    
//         for(int i=last+1;i<=9;i++){
        
//             v.push_back(i);
//             func(ans,v,k,n,sum+i,cnt+1);
//             v.pop_back();
//         }
    func(ans,v,k,n,sum,cnt,i+1);
        v.push_back(i);
    func(ans,v,k,n,sum+i,cnt+1,i+1);
    return;
}   
    
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> ans;
        vector<int> v;
        func(ans,v,k,n,0,0,1);
        return ans;
    }
};