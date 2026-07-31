#ifndef SORT_H
#define SORT_H
#define SWAP(a, b, type) \
    {                    \
        type temp = a;   \
        a = b;           \
        b = temp;        \
    }

void BubbleSort(int *data, int size, int orderAsc)
{
    int hasSwapped = 1;
    int length = size - 1;
    while (hasSwapped)
    {
        hasSwapped = 0;
        for (int i = 0; i < length; i++)
        {
            if ((data[i] > data[i + 1]) && orderAsc)
            {
                SWAP(data[i], data[i + 1], int);
                hasSwapped = 1;
            }
            else if ((data[i] < data[i + 1]) && !orderAsc)
            {
                SWAP(data[i], data[i + 1], int);
                hasSwapped = 1;
            }
        }
        length--;
    }
}

void InsertionSort(int *data, int size, int orderAsc)
{
    for (int i = 1; i < size; i++)
    {
        int n = data[i];
        int j = i - 1;

        while (j >= 0 && ((data[j] > n && orderAsc) || (data[j] < n && !orderAsc) ))
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = n;
    }
}

void MergeSort(int* data, int size, int orderAsc);

void HeapSort(int* data, int size, int orderAsc);
#endif