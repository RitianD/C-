long long mod = 1000000007;

int countGoodStrings(int low, int high, int zero, int one) {
    long long *record = malloc(sizeof(long long) * (high+1));
    memset(record, 0, sizeof(long long) * (high + 1));
    record[0] = 1;
    for (int i = 1; i <= high; ++i) {
        if (i - zero >= 0)
            record[i] += record[i - zero]%mod;
        if (i - one >= 0)
            record[i] += record[i - one]%mod;
    }
    long long sum = 0;
    for (int j = low; j <= high; ++j) {
        sum += record[j];
    }
    return sum%mod;
}

