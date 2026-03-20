class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        for(long long b : batteries)
            sum += b;

        long long low = 0;
        long long high = sum / n;
        long long ans = 0;

        while(low <= high){
            long long mid = (low + high) / 2;

            long long total = 0;
            for(long long b : batteries){
                total += min(b, mid);
            }

            if(total >= (long long)n * mid){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }
};