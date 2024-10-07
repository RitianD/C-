int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int n = gasSize;
    int index = 0;
    while (index < n) {
        int count = 0;
        int sum = 0;
        while (count < n) {
            int k = (index + count) % n;
            sum += gas[k];
            if (sum < cost[k]) {
                break;
            }
            sum -= cost[k];
            count++;
        }
        if (count == n) return index;
        index = index + count + 1;
    }
    return -1;
}