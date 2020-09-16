#include <stdio.h>
#include <string.h>
#define MAXSIZE 2000

/*
* 检查FASTQ文件格式是否合规
* a. 以四行为一组.
* b. 第一行需以@开头
* c. 第二行字符仅包含A G T C a g t c 这八种字符
* d. 第三行需以+开头
* e. 第四行所用字符其ascii码值需在33到126之间且总个数与第二行相同
* 任意一条不符合, 则不合规
*/

int judgefline(char* buff);
int judgesline(char* buff, int* secondnum);
int judgetline(char* buff);
int judgefoline(char* buff, int* secondnum);
int main(int argc, char* argv[]){
    char filename[100]="./exe/2018.txt";
    char buff[MAXSIZE];
    FILE* fp;
    fp=fopen(argv[1],"r");  //命令行执行语句: 2018_2 2018.txt
    //fp=fopen(filename,"r");
    int row=0;
    int flag=0;
    int secondnum=0;
    while (fgets(buff,MAXSIZE,fp)!=NULL)
    {
        if (buff[strlen(buff)-1]=='\n')
        {
            buff[strlen(buff)-1]='\0';
        }
        //printf("%s\n",buff);
        row++;
        if (row%4==1)
        {
            if ((flag=judgefline(buff))==0)
            {
                printf("%s\n",buff);
                printf("1 failed.\n");
                break;
            }
        }
        if (row%4==2)
        {
            if ((flag=judgesline(buff, &secondnum))==0)
            {
                printf("%s\n",buff);
                printf("2 failed.\n");
                break;
            }
        }
        if (row%4==3)
        {
            if ((flag=judgetline(buff))==0)
            {
                printf("%s\n",buff);
                printf("3 failed.\n");
                break;
            }
        }
        if (row%4==0)
        {
            if ((flag=judgefoline(buff, &secondnum))==0)
            {
                printf("%s\n",buff);
                printf("4 failed.\n");
                break;
            }
        }
    }
    if (flag && row%4==0)
    {
        printf("pass!\n");
    }
    else
    {
        printf("last failed.\n");
    }
    fclose(fp);
    getchar();
    return 0;
}

int judgefline(char* buff){
    return buff[0]=='@';
}
int judgesline(char* buff, int* secondnum){
    int flag;
    *secondnum=strlen(buff);
    for (int i = 0; i < strlen(buff); i++)
    {
        if (buff[i]!='A' && buff[i]!='C' && buff[i]!='T' && buff[i]!='G' && buff[i]!='a' && buff[i]!='c' && buff[i]!='t' && buff[i]!='g')
        {
            flag=0;
            return flag;
        }
        flag=1;
    }
    return flag;
}
int judgetline(char* buff){
    return buff[0]=='+';
}
int judgefoline(char* buff, int* secondnum){
    if (strlen(buff)!=*secondnum)
    {
        return 0;
    }
    else
    {
        int flag;
        for (int i = 0; i < strlen(buff); i++)
        {
            if (buff[i]>126 || buff[i]<33)
            {
                flag=0;
                return flag;
            }
            else
            {
                flag=1;
            }             
        }
        return flag;     
    }
}