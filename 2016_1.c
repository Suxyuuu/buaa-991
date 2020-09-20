// 实现c库函数strcmp
// 要求: 不能使用c库中字符串函数

#include <stdio.h>

int strcmp(char* a, char* b);
int main(void){

    char a[20]="agbskgbisbgsb";
    char b[20]="agbskgbisbgsa";
    printf("%d\n", strcmp(a,b));

    getchar();
    return 0;
}

int strcmp(char* a, char* b){
    int i=0;
    while (a[i]!='\0' && b[i]!='\0')
    {
        if (a[i]==b[i])
        {
            i++;
        }
        else
        {
            return a[i]-b[i];
        } 
    }
    if (a[i]=='\0' && b[i]=='\0')
    {
        return 0;
    }
    else if (a[i]!='\0')
    {
        return a[i];
    }
    else
    {
        return 0-b[i];
    }
    
    
    
}