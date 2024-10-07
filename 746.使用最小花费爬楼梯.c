int minCostClimbingStairs(int* cost, int costSize) {
    int *record = malloc(sizeof(int) * (costSize + 1));
    memset(record,0,sizeof(int) * (costSize + 1));
    record[0] = cost[0];
    record[1] = cost[1];
    for (int i = 2; i < costSize; ++i) {
        int tmp = fmin(record[i-1], record[i-2]);
        record[i] = tmp + cost[i];
    }
    return fmin(record[costSize-1],record[costSize-2]);
}
