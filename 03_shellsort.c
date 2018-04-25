#include "stdio.h"

/* shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n)
{
    for (int gap = n/2; gap > 0; gap /=2)
        for (int i = gap; i < n; i++)
            for (int j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
            {
                int tmp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = tmp;
            }
}

int main()
{
    int v[] = { 2, 3, 1, 8, 5, 0};
    shellsort(v, 6);

    for (int i = 0; i < 6; i++)
    {
        printf("%d%s", v[i], i == 5 ? "\n" : ", ");
    }

    return 0;
}