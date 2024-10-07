int searchInsert(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int mid = 0;
    while (left <= right) {
        mid = (left + right)>>1;
        if (nums[mid] == target) break;
        else if (nums[mid] > target) right = mid - 1;
        else left = mid + 1;
    } 
    return nums[mid] == target ? mid : left;
}
