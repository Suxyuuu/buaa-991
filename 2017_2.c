#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
* 读取一个字符串 识别其中的数字字符并将其转化为整型(不可使用atoi函数) 将数字从大到小输出
*/

void stoi(char(* nums)[20], int numi[20], int count);   //字符转数字
void output(int* numi, int count);                   //排序并输出
int comp(const void *a, const void *b);                 //快排比较函数

int main(void){
    
    char str[100]="abc123de45f*#6?*789&";
    //scanf("%s",str);
    //printf("%s\n",str);
    char num[20][20];
    char buff[20];
    int start=0, end=0;
    int pos=-1;
    int count=0;
    for (int i = 0; i < strlen(str)+1; i++)
    {
        if (str[i]>='0' && str[i]<='9' && pos==-1)
        {
            start=i;
            pos=i;
        }
        else if (str[i]>='0' && str[i]<='9' && pos!=-1)
        {
            pos++;
        }
        else
        {
            if (pos==i-1 && i!=0)
            {
                end=i-1;
                pos=-1;
                int j=0;
                for (int i = start; i < end+1; i++,j++)
                {
                    buff[j]=str[i];
                }
                buff[j]='\0';
                strncpy(num[count],buff,20);
                count++;
            }
            
        }        
    }
    for (int i = 0; i < count; i++)
    {
        printf("%s\n",num[i]);
    }
    printf("\n");
    
    int numi[20];
    stoi(num, numi, count);
    output(numi, count);
    
    getchar();
    getchar();
    return 0;
}

void stoi(char(* nums)[20], int* numi, int count){
    for (int i = 0; i < count; i++)
    {
        int sum=0;
        int j=0;
        while (nums[i][j]!='\0')
        {
            sum=sum*10+nums[i][j]-'0';
            j++;
        }
        numi[i]=sum;
    }
}

int comp(const void *a, const void *b){
	return *(int*)b-*(int*)a;
}

void output(int* numi, int count){
    qsort(numi, count, sizeof(int), comp);
    for (int i = 0; i < count; i++)
    {
        printf("%d\n", numi[i]);
    }
}