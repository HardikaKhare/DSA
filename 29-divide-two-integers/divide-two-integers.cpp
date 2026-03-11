class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)return INT_MAX;
        int sign = 1;
        if (dividend < 0 && divisor > 0)
            sign = -1;
        if (dividend > 0 && divisor < 0)
            sign = -1;

        long long n = dividend;
        long long d = divisor;
        n=abs(n);d=abs(d);
        long long ans = 0;
        while (n >= d) {
            int cnt = 0;
            while (n >= (d << (cnt + 1))) {
                cnt++;
            }
            ans += 1LL << cnt;
            n -= d * (1LL << cnt);
        }
        return ans * sign;
    }
};