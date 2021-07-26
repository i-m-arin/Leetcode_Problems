class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n=s.size()-1;
        int m=t.size()-1;
        int i=n,j=m;
        while(i>=0 || j>=0){
            int some=0;
            while(i>=0){
                if(s[i]=='#'){
                    some++;
                    i--;
                }
                else if(some>0){
                    some--;
                    i--;
                }
                else break;
            }
            some=0;
            while(j>=0){
                if(t[j]=='#'){
                    some++;
                    j--;
                }
                else if(some>0){
                    some--;
                    j--;
                }
                else break;
            }
            if(i>=0 && j>=0 && s[i]!=t[j]) return false;
            if(i<0 && j>=0) return false;
            if(j<0 && i>=0) return false;
            i--;
            j--;
            // cout<<i<<" "<<j<<endl;
        }
        
        return true;
    }
};