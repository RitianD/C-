/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int bs(int *nums, int target, int numsSize){
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

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int *ans = malloc(sizeof(int) * 2);
    int left = bs(nums, target, numsSize);
    if (left >= numsSize || nums[left] != target) {
        ans[0] = -1;
        ans[1] = -1;
        return ans;
    }
    int right = bs(nums,target+1, numsSize) - 1;
    ans[0] = left;
    ans[1] = right;
    return ans;
}
