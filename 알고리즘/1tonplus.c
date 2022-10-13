#include <stdio.h>

int fast(int x);

int main(void)
{
    printf("%d", fast(50));
}

int fast(int x)
{
    if (x == 1)
    {
        return 1;
    }
    if (x % 2 == 1)
    {
        return fast(x - 1) + x;
    }
    return 2 * fast(x / 2) + (x / 2) * (x / 2);
}