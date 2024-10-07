int cmp(void *a, void *b) {
    return *(int*)a - *(int*)b;
}

long long minimumTime(int* time, int timeSize, int totalTrips) {
    qsort(time, timeSize, sizeof(int), cmp);
    long long left = time[0];
    long long right = (long long)time[0] * totalTrips;
    long long res = 0;
    while (left <= right) {
        long long sum = 0;
        long long mid = (left + right) >> 1;
        for (int i = 0; i < timeSize; ++i) {
            sum += mid / time[i];
        }
        if (sum < totalTrips) {
            left = mid + 1;
        } else {
            res = mid;
            right = mid - 1;
        }
    }
    return res;
}
