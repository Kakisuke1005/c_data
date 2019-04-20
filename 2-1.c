#include <stdio.h>
#include <assert.h>

int sum(int n);

int main(void) {
    int value;

    printf("正の偶数を入力して下さい:");
    scanf("%d", &value);
    printf("sum(%d) = %d\n",value,sum(value));

    return 0;
}

/* 引数 n は正の偶数 */
int sum(int n) {
    int ret;
    assert(n % 2 == 0 && n > 0);

    if (n==2)
        return 2;
    ret =n+sum(n-2);

    return ret;
}