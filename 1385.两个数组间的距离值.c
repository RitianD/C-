bool judge(int* arr2, int arr2Size, int d, int target) {
    int left = 0;
    int right = arr2Size - 1;
    int mid = 0;
    int low = target - d;
    int high = target + d;
    while (left <= right) {
        mid = (left + right) >> 1;
        if (arr2[mid] >= low && arr2[mid] <= high) return true;
        else if (arr2[mid] <= low) left = mid + 1;
        else if (arr2[mid] >= high) right = mid - 1;
    }
    return false; 
}

int cmp(void *a, void *b){
    return *(int*)a - *(int*)b;
}

int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d) {
        qsort(arr2, arr2Size, sizeof(int), cmp);
        int res = 0;
        for (int i = 0; i < arr1Size; ++i) {
            if (!judge(arr2, arr2Size, d, arr1[i])) res++;
        }
        return res;
}
