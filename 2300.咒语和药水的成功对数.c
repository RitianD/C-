/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 要求 spell * potion >= success
// 那么反过来， potion >= success/spell 就算成功
// 可以用二分去找到每个spell对应potion的的下界

int bs(int *potions, int potionsSize, int target) {
    int left = 0;
    int right = potionsSize - 1;
    int mid = 0;
    while (left <= right) {
        mid = (left + right) >> 1;
        if (potions[mid] > target) right = mid - 1;
        else left = mid + 1;
    }
    return right;
}

int cmp(void *a, void *b) {
    return *(int*)a - *(int*)b;
}

int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize) {
    *returnSize = spellsSize;
    int *ans = malloc(sizeof(int) * spellsSize);
    qsort(potions, potionsSize, sizeof(int), cmp);
    for (int i = 0; i < spellsSize; ++i) {
        long long target = (success - 1)/spells[i];//草了 查了半天 看别人题解才发现success 是long long， target如果是int 得到的值可能会有问题
        int right = bs(potions, potionsSize, target);
        if (target < potions[potionsSize - 1])
            ans[i] = potionsSize - right - 1;
        else ans[i] = 0;
    }

    return ans;
}
