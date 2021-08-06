class Solution {
public:
    
    
//     int get(vector<int> &v,int start,int end){
//       int pivot = v[end];
//       int idx=start;
//       for(int i=start;i<end;i++){
//         if(v[i]<pivot){
//           swap(v[idx],v[i]);
//           idx++;
//         }
//       }
//       swap(v[end],v[idx]);
//       return idx;
//     }


//     void quickSort(vector<int> &v,int start,int end){
//       if(start<end){
//         int pivot = get(v,start,end);
//         quickSort(v,start,pivot-1);
//         quickSort(v,pivot+1,end);
//       }
    
//     }

    
    
    vector<int> merge(vector<int> &a,vector<int> b){
    int n=a.size(),m=b.size();

    int i=0,j=0;
    vector<int> ans;
    while(i!=n && j!=m){
        if(a[i]<b[j]){
            ans.push_back(a[i]);
            i++;
        }
        else if(a[i]>=b[j]){
            ans.push_back(b[j]);
            j++;
        }

    }

    while(i!=n){
        ans.push_back(a[i]);
        i++;
    }

    while(j!=m){
        ans.push_back(b[j]);
        j++;
    }

    return ans;

}

vector<int> mergeSort(vector<int> &a,int start,int end){

    if(start==end){
        vector<int> some={a[start]};
        return some;
    }

    int mid = (start + end)/2;
    vector<int> fir = mergeSort(a,start,mid);
    vector<int> sec = mergeSort(a,mid+1,end);

    return merge(fir,sec);

}
    
    
    vector<int> sortArray(vector<int>& nums) {
        vector<int> ans = mergeSort(nums,0,nums.size()-1);
        return ans;
    }
};