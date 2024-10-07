/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


// 好像可以用排序+二分来做
// 虽然要求元素顺序，但是元素能删，那实质也是有序的？
int cmp (void *a, void *b) {
    return *(int*)a - *(int*)b;
}

int bs(int *nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int mid = 0;
    while (left <= right) {
        mid = (left + right) >> 1;
        if (nums[mid] > target) right = mid - 1;
        else left = mid + 1;
    }
    return right;
}

int* answerQueries(int* nums, int numsSize, int* queries, int queriesSize, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    *returnSize = queriesSize;
    int *ans = malloc(sizeof(int) * queriesSize);
    for (int i = 1; i < numsSize; ++i) {
        nums[i] += nums[i-1];
    }
    for (int i = 0; i < queriesSize; ++i) {
        int right = bs(nums, numsSize, queries[i]);
        ans[i] = right + 1;
    }
    return ans;
}
