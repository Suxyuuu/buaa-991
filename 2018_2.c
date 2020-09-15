#include <stdio.h>
#include <string.h>
#define MAXSIZE 2000

int judgefline(char* buff);
int judgesline(char* buff, int* secondnum);
int judgetline(char* buff);
int judgefoline(char* buff, int* secondnum);
int main(int argc, char* argv[]){
    char filename[100]="./exe/2018.txt";
    char buff[MAXSIZE];
    FILE* fp;
    fp=fopen(argv[1],"r");  //√¸¡Ó––÷¥––”Ôæ‰: 2018_2 2018.txt
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