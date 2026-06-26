class Solution {
public:
    long long mod = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long ans = 1;

        while (exp > 0) {
            if (exp & 1)
                ans = (ans * base) % mod;

            base = (base * base) % mod;
            exp >>= 1;
        }

        return ans;
    }

    int countGoodNumbers(long long n) {

        long long even = (n + 1) / 2;
        long long odd = n / 2;

        return (power(5, even) * power(4, odd)) % mod;
    }
};