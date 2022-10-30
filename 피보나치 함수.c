#include <stdio.h>
#include <stdlib.h>

int zero = 0, one = 0, *n;

int fibonacci(int n) // reculsive X  interactive O
{
    if (n == 0)
    {
        zero++;
        return 0;
    }
    else if (n == 1)
    {
        one++;
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main(void)
{
    int num, a;

    scanf("%d", &num);

    n = (int *)malloc(sizeof(int) * num * 2);

    for (int i = 0; i < num; i++)
    {
        scanf("%d", &n[i]);
    }

    for (int i = 0; i < num; i++)
    {
        fibonacci(n[i]);
        printf("%d %d\n", zero, one);
        zero = one = 0;
    }

    return 0;
}