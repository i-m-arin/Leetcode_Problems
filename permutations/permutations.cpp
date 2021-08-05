class Solution {
    
    
    
    typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef priority_queue<ll> pqll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef map<ll,ll> mpll;
typedef set<ll> stll;

#define f(i, a, n)   for(ll i=a; i<(ll)n; i++)
#define f2(i, a, b) for(ll i=a; i<=(ll)b; i++)
#define pb       push_back
#define ff       first
#define ss       second
#define pf      push_front
#define mp      make_pair
#define all(a)    (a).begin(),(a).end()
    
    
public:
    
    
    
    void func(vector<int> v,ll n,vector<int> idx,set<int> st, vector<vector<int>> &ans){

	if(st.size()==n){
		vector<int> temp;
		for(auto x:idx){
			temp.pb(v[x]);
		}
		ans.pb(temp);
		return;
	}


	f(i,0,n){
		if(st.find(i)==st.end()){
			set<int> temp=st;
			temp.insert(i);
			// vector<int> some = idx;
			// some.pb(i);
            idx.pb(i);
			func(v,n,idx,temp,ans);
            idx.pop_back();
		}
		
	}

}
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v =nums;
        int n=v.size();
        set<int> cur;
        vector<vector<int>> ans;
        vector<int> some;
        func(v,n,some,cur,ans);
        
        return ans;
    }
};