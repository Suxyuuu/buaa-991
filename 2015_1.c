#include <stdio.h>

// ���û�ͨ����������������ַ�(EOF����, windows��ΪCTRL+Z)����һά����s��, ��������ascii�������ַ�����axcii��ֵ
// Ҫ��: ����ʹ��ָ�����

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