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
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int> stack;
        int i=0;
        int n=heights.size();
        int ans=0;
        while(i<n){
            if(stack.empty() || heights[i]>= heights[stack.top()]){
                stack.push(i);
                i++;
            } 
            else{
                int some = stack.top();
                stack.pop();
                int prev=0;
                if(stack.empty()) prev = i;
                else prev = i-stack.top()-1;
                
                ans = max(ans,heights[some]*prev);
            }
        }
        while(stack.empty()==false){
            int some = stack.top();
            stack.pop();
            int prev=0;
            if(stack.empty()) prev = n;
            else prev = n-stack.top()-1;

            ans = max(ans,heights[some]*prev);   
        }
        
        return ans;
    }
};