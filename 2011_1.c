// 递归计算1+2+3+...+n

#include <stdio.h>

int fun(int n);
int main(void){

    int n;
    scanf("%d", &n);
    printf("%d\n", fun(n));

    getchar();
    getchar();
    return 0;
}
int fun(int n){
    if (n==1)
    {
        return 1;
    }
    else
    {
        return n+fun(n-1);
    }
}