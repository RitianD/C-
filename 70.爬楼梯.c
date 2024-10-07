int climbStairs(int n) {
    int *record = malloc (sizeof(int) * (n+1));
    memset(record, 0, sizeof(int)* (n+1));
    record[0] = 1;
    record[1] = 1;
    for (int i = 2; i <= n; ++i) {
        record[i] = record[i-1] + record[i-2];
    }
    return record[n];
}
