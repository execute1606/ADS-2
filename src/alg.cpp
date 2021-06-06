// Copyright 2021 NNTU-CS

int countPairs1(int* arr, int len, int value) {
    int chet = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if ((arr[i] + arr[j]) == value)
                chet++;
        }
    }
    return chet;
}

int countPairs2(int* arr, int len, int value) {
    int chet = 0;
    for (int i = len - 1; i > 0; i--) {
        if (arr[i] <= value) {
            for (int j = 0; j < i; j++) {
                if ((arr[i] + arr[j]) == value)
                    chet++;
            }
        }
    }
    return chet;
}

int countPairs3(int* arr, int len, int value) {
    int chet = 0;
    for (int i = 0; i < len - 1; i++) {
        int left = i + 1, right = len, twoElement = value - arr[i];
        while (left < right) {
            int cent = (left + right) / 2;
            if (arr[cent] == twoElement) {
                while ((arr[cent - 1] == twoElement) && (cent > left)) {
                    cent--;
                }
                while (arr[cent] == twoElement) {
                    cent++;
                    chet++;
                }
                break;
            }
            else if (arr[cent] > twoElement) {
                right = cent;
            }
            else {
                left = cent + 1;
            }
        }
    }
    return chet;
}
