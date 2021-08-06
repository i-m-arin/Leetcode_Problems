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
    
    
    
    
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        ll n,m;
        n=matrix.size();
        m=matrix[0].size();
        vector<vector<char>> s=matrix;
//         //cin>>n>>m;
//         //vs s(n);
//         //f(i,0,n) cin>>s[i];
//         ll hor[n][m],ver[n][m],diag[n][m];

//         f(i,0,n){
//             f(j,0,m){
//                 if(j==0){
//                     if(s[i][j]=='1') hor[i][j]=1;
//                     else hor[i][j]=0;
//                 }
//                 else{
//                     if(s[i][j]=='1') hor[i][j]=hor[i][j-1]+1;
//                     else hor[i][j]=0;
//                 }
//             }
//         }

//         f(i,0,m){
//             f(j,0,n){
//                 if(j==0){
//                     if(s[j][i]=='1') ver[j][i]=1;
//                     else ver[j][i]=0;
//                 }
//                 else{
//                     if(s[j][i]=='1') ver[j][i]=ver[j-1][i]+1;
//                     else ver[j][i]=0;
//                 }
//             }
//         }

//         if(s[0][0]=='1') diag[0][0]=1;
//         else  diag[0][0]=0;
//         f(i,0,n){
//             f(j,0,m){
//                 if(i==0 || j==0){
//                     if(s[i][j]=='1') diag[i][j]=1;
//                     else diag[i][j]=0;
//                 }
//                 else{
//                     if(s[i][j]=='0') diag[i][j]=0;
//                     else diag[i][j]=diag[i-1][j-1]+1;
//                 }
//             }
//         }

//        ll dp[n][m];

ll ans=0;
// f(i,0,n){
//     f(j,0,m){
//         ll some=min(ver[i][j],min(hor[i][j],diag[i][j]));
//         dp[i][j]=some;
//     }
// }

ll dp2[n][m];



f(i,0,n){
	f(j,0,m){
		if(s[i][j]=='1'){
			if(i==0 || j==0) dp2[i][j]=1;
			else{
				dp2[i][j]=min(dp2[i-1][j],min(dp2[i][j-1],dp2[i-1][j-1]));
				dp2[i][j]++;
			}
		}
		else dp2[i][j]=0;
	}
}


f(i,0,n){
	f(j,0,m) ans=max(ans,dp2[i][j]);
}


    return ans*ans;
//cout<<ans*ans<<endl;


        
    }
};