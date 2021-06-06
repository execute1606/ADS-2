// Copyright 2021 NNTU-CS

int countPairs1(int* arr, int len, int value) {
    int pairs = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                pairs++;
            }
        }
    }
    return pairs;
}

int countPairs2(int* arr, int len, int value) {
    int pairs = 0;
    int i = len - 1;
    while (arr[i] > value) {
        i--;
    }
    for (i; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[i] + arr[j] == value)
                pairs++;
        }
    }
    return pairs;
}

int countPairs3(int* arr, int len, int value) {
    int pairs = 0;
    for (int i = 0; i < len - 1; i++) {
        int left = i + 1, right = len;
        while (left < right) {
            int cen = (left + right) / 2;
            if (arr[cen] == (value - arr[i])) {
                while (arr[cen - 1] == (value - arr[i]) && (cen > left)) {
                    cen--;
                }
                while (arr[cen] == (value - arr[i])) {
                    cen++;
                    pairs++;
                }
                break;
            }
            else if (arr[cen] > (value - arr[i])) {
                right = cen;
            }
            else {
                left = cen + 1;
            }
        }
    }
    return pairs;
}
