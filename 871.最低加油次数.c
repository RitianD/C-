int minRefuelStops(int target, int startFuel, int** stations, int stationsSize, int* stationsColSize){
    long *dp = (long *)malloc(sizeof(long) * (stationsSize + 1));
    memset(dp, 0, sizeof(long) * (stationsSize + 1));
    dp[0] = startFuel;
    for (int i = 0; i < stationsSize; i++) {
        for (int j = i; j >= 0; j--) {
            if (dp[j] >= stations[i][0]) {
                dp[j + 1] = fmax(dp[j + 1], dp[j] + stations[i][1]);
            }
        }
    }
    for (int i = 0; i <= stationsSize; i++) {
        if (dp[i] >= target) {
            free(dp);
            return i;
        }
    }
    free(dp);
    return -1;
}