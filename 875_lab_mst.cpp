class Solution {
public:
    long long divisorsum(vector<int>piles, int mid){
        long long sum = 0;

        for(int i=0; i<piles.size(); i++){
            sum += ceil((double)piles[i] / mid);
        }

        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxval = INT_MIN;
        for(int i=0; i<piles.size(); i++){
            maxval = max(maxval, piles[i]);
        }

        int start = 1;
        int end = maxval;
        int ans = 0;

        while(start <= end){
            int mid = (start + end) / 2;

            if(divisorsum(piles, mid) <= h){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }

        return ans;
    }
};