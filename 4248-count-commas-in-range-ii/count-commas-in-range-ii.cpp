class Solution {
public:
    long long countCommas(long long n) {
        int digi = 0;
        long long k = n;

        while (k) {
            digi++;
            k /= 10;
        }

        if (digi <= 3)
            return 0;

        else if (digi <= 6)
            return n - 1000LL + 1;

        else if (digi <= 9)
            return 2 * (n - 1000000LL + 1)
                 + (1000000LL - 1000LL);

        else if (digi <= 12)
            return 3 * (n - 1000000000LL + 1)
                 + 2 * (1000000000LL - 1000000LL)
                 + (1000000LL - 1000LL);

        else if (digi <= 15)
            return 4 * (n - 1000000000000LL + 1)
                 + 3 * (1000000000000LL - 1000000000LL)
                 + 2 * (1000000000LL - 1000000LL)
                 + (1000000LL - 1000LL);

        else
            return 5 * (n - 1000000000000000LL + 1)
                 + 4 * (1000000000000000LL - 1000000000000LL)
                 + 3 * (1000000000000LL - 1000000000LL)
                 + 2 * (1000000000LL - 1000000LL)
                 + (1000000LL - 1000LL);
    }
};