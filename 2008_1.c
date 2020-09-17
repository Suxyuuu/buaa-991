// 将字符串从第k个开始的全部字符复制成为另外一个字符串

#include <stdio.h>
#define MAXSIZE 20

void solve(char * a, int k, char * b);
int main(void){
    char a[MAXSIZE];
    char b[MAXSIZE];
    int k;
    scanf("%s %d", a, &k);  // 输入格式: 字符串 k值
    printf("%s\n", a);
    printf("%d\n", k);
    solve(a, k, b);
    printf("%s\n", b);

    getchar();
    getchar();
    return 0;
}
void solve(char * a, int k, char * p){
    //char * p;
    for (int i = 0; i < k-1; i++)
    {
        a++;
    }
    while (*a!='\0')
    {
        *p=*a;
        p++;
        a++;
    }
    *p='\0';
    //return p;
}