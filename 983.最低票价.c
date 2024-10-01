int mincostTickets(int* days, int daysSize, int* costs, int costsSize) {
    int lastday = days[daysSize - 1];
    int *arr = malloc(sizeof(int) * (lastday + 1));
    int index = 0;
    memset(arr, 0, sizeof(arr));
    for (int i = 1; i <= lastday; ++i) {
        if (i != days[index]) {
            arr[i] = arr[i - 1];
        } else {
            index++;
            int tmp0 = arr[i - 1] + costs[0];
            int tmp1 = arr[(int)fmax(0, i - 7)] + costs[1];
            int tmp2 = arr[(int)fmax(0, i - 30)] + costs[2];
            arr[i] = fmin(fmin(tmp0,tmp1), tmp2);
        }
    }

    return arr[lastday];
}
