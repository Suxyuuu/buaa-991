#include <stdio.h>

// 将用户通过键盘输入的若干字符(EOF结束, windows下为CTRL+Z)存入一维数组s中, 输入其中ascii码最大的字符及其axcii码值
// 要求: 操作使用指针完成

int main(void){

    char s[100];
    char * p=s;
    char max;
    while (scanf("%c", p++)!=EOF);
    *p='\0';
    max=*p;
    p=s;
    while (*++p != '\0')
    {
        if (max<*p)
        {
            max=*p;
        }
    }
    printf("%d\n",max);
    
    getchar();
    return 0;
}