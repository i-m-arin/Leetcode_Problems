class Solution {
public:
    int furthestBuilding(vector<int>& height, int x, int q) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0;

        for(int i = 0; i < height.size() - 1; i++){
            int diff = height[i+1] - height[i];
            if(diff <= 0){
                
            }
            else{
                pq.push(diff);
            }

            if(pq.size() > q){
                x -= pq.top();
                pq.pop();
            }
            if(x < 0){
                break;
            }
            ans++;
        }

        return ans;
    }
};