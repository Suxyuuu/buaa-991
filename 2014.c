// 求某个长字符串中指定字符串出现的频率 要求所有的字符串操作用指针完成!

#include <stdio.h>
#include <string.h>
#define MAXSIZE 100

int STRCOUNT(char* source, char* destination);
int main(void){
    char source[MAXSIZE]="accdefgdefkdxefaaaa";
    char destination[MAXSIZE]="def";
    char * s=source, * d=destination;
    printf("%d\n",STRCOUNT(s, d));
    getchar();
    return 0;
}

int STRCOUNT(char* source, char* destination){
    int count=0;
    char * s=source;
    char * d=destination;
    char * pos=source;

    while (*s)
    {
        //pos=s;
        if (*s == * d)
        {
            s++;
            d++;
        }
        else if (*d == '\0')
        {
            count++;
            pos++;
            s=pos;
            d=destination;
        }
        else
        {
            pos++;
            s=pos;
            d=destination;
        }
        
    }
    
    return count;
}