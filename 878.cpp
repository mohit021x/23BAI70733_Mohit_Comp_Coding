class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long mod = 1000000007;

        long long l = min(a, b), r = 1LL * n * min(a, b);

        long long g = __gcd(a, b);
        long long lcm = (1LL * a * b) / g;

        while (l < r) {
            long long mid = l + (r - l) / 2;

            long long count = mid / a + mid / b - mid / lcm;

            if (count < n) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l % mod;
    }
};