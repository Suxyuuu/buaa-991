// 计算s=a^1+a^2+...+a^n 其中a, n通过键盘键入 a为浮点数 n为正整数

#include <stdio.h>

float sum(float a, int n);
int main(void){
    float s, a;
    int n;
    printf("calculate: s=a^1+a^2+...+a^n\n");
    printf("input: a n\n");
    scanf("%f %d", &a, &n);
    printf("%f\n", sum(a, n));

    getchar();
    getchar();
    return 0;
}

float sum(float a, int n){
    if (n==1)
    {
        return a;
    }
    else
    {
        float m=1;
        for (int i = 0; i < n; i++)
        {
            m*=a;
        }
        return m+sum(a, n-1);
    }
    
}