int combinationSum4(int* nums, int numsSize, int target) {
    int *record = malloc(sizeof(int) * (target+1));
    memset(record, 0, sizeof(int)*(target+1));
    record[0] = 1;
    for (int i = 0; i <= target; ++i) {
        for (int j = 0; j < numsSize; ++j) {
            int curnum = nums[j];
            if (i - curnum >= 0 && record[i] < INT_MAX - record[i - curnum]) record[i] += record[i - curnum];
        }
    }
    return record[target];
}
