#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define DEBUG 1

void printa(int *a, int n)
{
    if (a == NULL || n <= 0)
        return;
    printf("[ ");
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        if (i < n - 1)
            printf(", ");
    }
    printf("]\n");
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int lines(int *a, int n, int days)
{
    int cups = 0;
    int loss = 0;
    int effects = 0;

    int result = 0;

    if (a == NULL || n <= 0 || days <= 0)
        return 0;

    cups = n / days;

    if (DEBUG)
        printf("\t\t%s(): days = %d, cups per day = %d\n", __func__, days, cups);

    for (int i = 0; i < n; i++)
    {
        loss = i / days;
        effects = a[i] - loss;
        if (effects > 0)
        {
            result += effects;
            if (DEBUG)
                printf("\t\t\tlines += a[%d] - %d -> %d\n", i, loss, result);
        }
        else
        {
            break;
        }
    }

    if (DEBUG)
        printf("\t\t%s() returns %d\n", __func__, result);

    return result;
}

int solve(
    int *a, // the array ai
    int n,  // n cups of coffee
    int m   // lines of code
)
{
    int l, c, r; // left, current, right
    int days = 0;
    int temp = 0;
    int result = -1;

    if (DEBUG)
        printf("\n%s(m=%d)\n", __func__, m);

    if (a == NULL || n <= 0)
        return result;

    l = 1;
    c = n;
    r = n;

    while (1)
    {
        // slow down
        if (DEBUG)
        {
            sleep(1);
            // printf("\tl=%f, c=%f, r=%f\n", l, c, r);
            printf("\tl=%d, c=%d, r=%d\n", l, c, r);
        }
        if (c == days)
            break;
        days = c;
        temp = lines(a, n, days);
        if (temp < m)
        {
            if (days == n)
                break;
            l = c;
            c = (c+r)/2;
        }
        else if (temp == m)
        {
            result = days;
            break;
        }
        else {
            if (result != -1 && days >= result)
                break;
            else
                result = days;
            r = c;
            c = (c+l)/2;
        }
    }
    return result;
}

// int a[200001];
int a[11];
int main(void)
{
    int t, n, m, total;
    scanf("%d", &t);
    for (size_t i = 0; i < t; ++i)
    {
        scanf("%d%d", &n, &m);
        total = 0;
        for (size_t j = 0; j < n; ++j) {
            scanf("%d", &a[j]);
            total += a[j];
        }
        if (DEBUG)
        {
            printf("\n");
            printa(a, n);
        }
        if (total > m) {
            printf("%d\n", solve(a, n, m));
        } else if (total < m) {
            printf("-1\n");
        } else {
            printf ("%d\n", n);
        }
    }
    return 0;
}