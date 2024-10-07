long MOD = 1e9 + 7;

//一开始忽略了有的键盘对应三个字母，有的对应四个
long long three[100001];
long long four[100001];

void init(void) {
    three[0] = four[0] = 1;
    three[1] = four[1] = 1;
    three[2] = four[2] = 2;
    three[3] = four[3] = 4;
    for (int i = 4; i < 100001; ++i) {
        three[i] = (three[i - 1] + three[i - 2] + three[i - 3]) % MOD;
        four[i] = (four[i - 1] + four[i - 2] + four[i - 3] + four[i - 4]) % MOD;
    }
}

int countTexts(char* pressedKeys) {
    init();
    long long ans = 1;
    int count = 0;
    int len = strlen(pressedKeys);
    for (int i = 0; i < len; ++i) {
        count++;
        if (i == len - 1 || pressedKeys[i] != pressedKeys[i + 1]) {
            ans = ans * (pressedKeys[i] != '7' && pressedKeys[i] != '9' ? three[count] : four[count]) % MOD;
            count = 0;
        }
    }
    return ans;
}
