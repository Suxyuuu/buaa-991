#include <stdio.h>
#include <string.h>
#define MAXSIZE 100
/* 
* ��ĳ�����ַ�����ָ���ַ������ֵ�Ƶ��
* �� abcdefgdefkd �� def Ϊ2��  aaaa �� aa Ϊ3��
*/
int freqs(char* source, char* destination);
int main(void){
    char source[MAXSIZE]="accdefgdefkdxefaaaa";
    char destination[MAXSIZE]="aa";
    printf("%d\n",freqs(source, destination));
    getchar();
    return 0;
}

int freqs(char* source, char* destination){
    int desnum=strlen(destination);
    int count=0;
    int flag;
    int m;
    for (int i = 0; i < strlen(source)-desnum+1; i++)
    {
        m=i;
        flag=1;
        for (int j = 0; j < desnum; j++,m++)
        {
            if (source[m]!=destination[j])
            {
                flag=0;
                break;
            }
        }
        if (flag)
        {
            count++;
        }
        
    }
    return count;
}