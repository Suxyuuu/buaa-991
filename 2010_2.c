// 实现命令 tail [-n] filename
// 通过命令行读取参数, 读取并输出文件的最后n行
// 若n缺省, 则默认10行, 若文件总行数小于10, 则输出文件所有内容

// 用一个长度为n的循环单链表来从头读取并存储文件, 最后留在单链表中的就是倒数n行

#include <stdio.h>
#include <stdlib.h>
#include <alloca.h>
#include <string.h>
#define MAXSIZE 100

struct node
{
    char data[MAXSIZE];
    struct node *next;
};


// 命令行输入 2010_2 tail -n example.txt
int main(int argc, char * argv[]){
    char * filename;
    char buff[MAXSIZE];
    int n;
    struct node *list, *p, *q;
    
    if (argc==4 && argv[2][0]=='-' && argv[1][0]=='t' && argv[1][1]=='a' && argv[1][2]=='i' && argv[1][3]=='l')
    {
        n=atoi(argv[2]+1);
        filename=argv[3];
    }
    else if (argc==3 && argv[1][0]=='t' && argv[1][1]=='a' && argv[1][2]=='i' && argv[1][3]=='l')
    {
        filename=argv[2];
        n=10;                   // 参数缺省则为10
    }
    else
    {
        fprintf(stderr, "Usage: tail [-n] filename\n");
        return 0;
    }
    //printf("%s\n%s\n%s\n", argv[0],argv[1],argv[2]);
    FILE * fp;
    if ((fp=fopen(filename, "r"))==NULL)
    {
        fprintf(stderr, "file open failed\n");
        return 0;
    }
    else
    {
        list=q=(struct node *)malloc(sizeof(struct node));
        q->data[0]='\0';
        for (int i = 0; i < n-1; i++)
        {
            p=(struct node *)malloc(sizeof(struct node));
            p->data[0]='\0';
            q->next=p;
            q=p;
        }
        p->next=list;       // 建立用初始化长度为n的循环单链表
        p=list;
        while (fgets(buff, MAXSIZE, fp)!=NULL)
        {
            strcpy(p->data, buff);
            p=p->next;
        }
        for (int i = 0; i < n; i++)
        {
            if (p->data[0]!='\0')
            {
                printf("%s\n", p->data);
                p=p->next;
            }
        }
        fclose(fp);
        
    }

    return 0;
}