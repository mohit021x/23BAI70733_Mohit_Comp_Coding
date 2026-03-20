class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++)
            total += nums[i];

        int remainder = total % p;
        if(remainder == 0)
            return 0;

        unordered_map<int,int> mp;
        mp[0] = -1;

        long long prefix = 0;
        int ans = n;

        for(int i = 0; i < n; i++) {
            prefix = (prefix + nums[i]) % p;

            int needed = (prefix - remainder + p) % p;

            if(mp.count(needed))
                ans = min(ans, i - mp[needed]);

            mp[prefix] = i;
        }

        if(ans == n)
            return -1;

        return ans;
    }
};