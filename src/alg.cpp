// Copyright 2021 NNTU-CS

int search(int* arr, int size, int value, unsigned int i) {
    int count = 0, min = i, max = size - 1, ave = i;
    while (min <= max) {
        ave = (min + max) / 2;
        if (arr[ave] == value && ave != i) {
            count++;
            break;
        }
        value < arr[ave] ? max = ave - 1 : min = ave + 1;
    }
    int l = 1;
    bool boo1 = true, boo2 = true;
    if (count) {
        while (ave > 0) {
            if (arr[ave - 1] == value && ave - 1 != i) {
                ave--;
            }
            else {
                break;
            }
        }
        while (boo1) {
            if (ave + l < size) {
                arr[ave + l] == value ? count++ : boo1 = false;
            }
            l++;
            if (ave + l >= size && ave - l < 0) break;
        }
    }
    return count;
}

int mod(int i) {
    if (i > 0) {
        return i;
    }
    else {
        return -i;
    }
}

int countPairs1(int* arr, int len, int value) {
    unsigned int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value && i != j) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    unsigned int count = 0, i = 0, left = 0, right = len - 1;
    while (left < right) {
        i = 1;
        while (true) {
            if (arr[right] > value || arr[left] + arr[right] > value) {
                right--;
            }
            else {
                break;
            }
        }
        while (left + i <= right) {
            if (arr[left] + arr[left + i] == value) count++;
            i++;
        }
        left++;
    }
    return count;
}
int countPairs3(int* arr, int len, int value) {
    unsigned int count = 0;
    for (int i = 0; i < len; i++) {
        count += search(arr, len, mod(value - arr[i]), i);
    }
    return count;
}
