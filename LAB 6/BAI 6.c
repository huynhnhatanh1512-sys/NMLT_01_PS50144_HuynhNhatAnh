#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main() {
void sapXepGiamDan(int a[], int n) //chuc nang 3
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
}