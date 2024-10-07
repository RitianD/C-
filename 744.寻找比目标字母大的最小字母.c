char nextGreatestLetter(char* letters, int lettersSize, char target) {
    int left = 0;
    int right = lettersSize - 1;
    int mid = 0;
    while (left <= right) {
        mid = (left + right) >> 1;
        if (letters[mid] < target + 1) left = mid + 1;
        else right = mid - 1;
    }    
    return left >=lettersSize ? letters[0] : letters[left];
}
