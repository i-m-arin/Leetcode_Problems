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
    #define decimal(x)  fixed<<setprecision(x)
    #define fsort(a)  sort(all(a))
    #define rsort(a)  sort(all(a),greater<>())
    
    
public:
    int wiggleMaxLength(vector<int>& nums) {
        ll n = nums.size();
        if(n==0) return 0;
        if(n==1) return 1;
        vector<int> a=nums;
        ll diff[n];
        f(i,1,n){
            diff[i]=a[i]-a[i-1];
        }

        ll dp[n];
        dp[0]=1;
        if(a[0]!=a[1])
            dp[1]=2;
        else dp[1]=1;

        ll pos=-1,neg=-1;
        if(diff[1]>0) pos=1;
        else if(diff[1]<0) neg=1;
        f(i,2,n){
            if(diff[i]*diff[i-1]<0){
                dp[i]=dp[i-1]+1;
                if(diff[i]>0) pos=i;
                else neg=i;
            }
            else if(diff[i]*diff[i-1]>=0){
                if(diff[i]>0){
                    if(neg!=-1){
                        dp[i]=max(dp[i-1],dp[neg]+1);
                    }
                    else{
                        dp[i]=max(dp[i-1],2ll);
                    }
                    pos=i;
                }
                else if(diff[i]<0){
                    if(pos!=-1){
                        dp[i]=max(dp[i-1],dp[pos]+1);
                    }
                    else dp[i]=max(dp[i-1],2ll);

                    neg=i;
                }
                else{
                    dp[i]=dp[i-1];
                }
            }
//             else{
//                 if(a[i]==a[i-1]){
//                     dp[i]=dp[i-1];
//                 }
//                 else{
//                     if(diff[i]>0){
//                         if(neg!=-1){
//                             dp[i]=max(dp[i-1],dp[neg]+1);
//                         }
//                         else{
//                             dp[i]=max(dp[i-1],2ll);
//                         }
//                         pos=i;
//                     }
//                     else{
//                         if(pos!=-1){
//                             dp[i]=max(dp[i-1],dp[pos]+1);
//                         }
//                         else dp[i]=max(dp[i-1],2ll);

//                         neg=i;
//                     }
//                 }
//             }
        }
        
        ll ans=0;
        f(i,0,n) ans=max(ans,dp[i]);
        return ans;
    }
};