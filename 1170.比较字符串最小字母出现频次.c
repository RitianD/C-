/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp(void *a, void *b) {
    return *(char*)a - *(char*)b;
}

int cmp2(void *a, void *b) {
    return *(int*)a - *(int*)b;
}

int count(char *tmp) {
    int size = strlen(tmp);
    qsort(tmp, size, sizeof(char), cmp);
    int res = 0;
    for (int i = 0; i < size; ++i) {
        res++;
        if (i+1 < size && tmp[i] != tmp[i+1]) break;
    }
    return res;
}

int bs(int *nums, int n, int target){
    int left = 0;
    int right = n - 1;
    int mid = (left + right) >> 1;
    while (left <= right) {
        mid = (left + right) >> 1;
        if (nums[mid] > target) right = mid - 1;
        else left = mid + 1;
    }
    return right;
}

int* numSmallerByFrequency(char** queries, int queriesSize, char** words, int wordsSize, int* returnSize) {
    int *q = malloc(sizeof(int) * queriesSize);
    int *w = malloc(sizeof(int) * wordsSize);
    *returnSize = queriesSize;
    for (int i = 0; i < wordsSize; ++i) {
        w[i] = count(words[i]);
    }
    qsort(w, wordsSize, sizeof(int), cmp2);
    for (int i = 0; i < queriesSize; ++i) {
        int target = count(queries[i]);
        //printf("%d\n", target);
        int n = wordsSize;
        q[i] = n - bs(w, n, target) - 1;
    }
    return q;
}
