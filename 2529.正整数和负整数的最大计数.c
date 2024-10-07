int bs(int *nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int mid = 0;
    while (left <= right) {
        mid = (left + right) >> 1;
        if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return left;
}

// 其实统计得到0的下界和上界就行
// 0的左边都是负数，0的右边都是正数
int maximumCount(int* nums, int numsSize) {
    int neg = bs(nums, numsSize, 0);
    int pos = numsSize - bs(nums, numsSize, 1);
    return fmax(neg, pos);
}
