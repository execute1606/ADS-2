// Copyright 2021 NNTU-CS

int countPairs1(int* arr, int len, int value)
{
    int chet = 0;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if ((arr[i] + arr[j]) == value)
                chet++;
        }
    }
    return chet;
}
int countPairs2(int* arr, int len, int value)
{
    int chet = 0;
    for (int i = 0; i < len - 1; i++)
        for (int j = len - 1; j < len; j--)
        {
            if (i == j)
                return chet;
            else if ((arr[i] + arr[j]) == value)
                chet++;
        }
    return chet;
}

int countPairs3(int* arr, int len, int value)
{
    int chet = 0;
    int siz = 0;
    for (int z = 1; z < len; z++)
    {
        if ((arr[z] + arr[0]) == value)
            siz = z;
    }

    int twoElement = value - arr[0];
    for (int i = 0; i <= siz; i++)
    {
        if (arr[i] == twoElement)
            chet++;
    }
    return chet;
}
return 0;
