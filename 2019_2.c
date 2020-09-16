#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
/*
* 读取文件中的单词(不超过100个) 每个单词小于20个字母
* 若与所给目标单词字母相同但顺序不同则符合乱序词要求, 例如 listen 和 slient
* 将符合要求的乱序词按照字母表升序输出(相同单词只输出一次)
*/
void judgeword(char *wordpoint[], char word[][21], int wordnum, char sourseword[],int *realnum);
void sortstr(char *wordpoint[], int num);
int main(void){
    char filename[20]="./exe/2019.txt";
    char sourceword[22]="silent";
    char *wordpoint[100];
    char word[100][21];
    int length=0;
    int realwordnum=0;
    FILE *fp;
    if((fp=fopen(filename,"r"))==NULL){
        puts("openerr");
    }
    else{
        while (fscanf(fp, "%s", word[length])==1)
        {
            length++;
        }   
    }

    judgeword(wordpoint, word,length,sourceword,&realwordnum);
    sortstr(wordpoint,realwordnum);
    
    for (int i = 0; i < length; i++)
    {
        printf("%s\n",wordpoint[i]);
    }
    
    fclose(fp);
    system("pause");
    return 0;
}

void judgeword(char *wordpoint[], char word[][21],int wordnum, char sourceword[],int *realnum){
    int len0=strlen(sourceword);
    int zimubiao0[26]={0};
    int count=0;
    int i,j,m;
    for (int i = 0; i < len0; i++)
    {
        zimubiao0[sourceword[i]-'a']++;
    }
    
    for (i = 0; i < wordnum; i++)
    {
        int len=strlen(word[i]);
        if (len==len0)
        {
            int zimubiao[26]={0};
            for (j = 0; j < len; j++)
            {
                word[i][j]=tolower(word[i][j]);
                zimubiao[word[i][j]-'a']++;
            }            
            int flag=1;
            for (int i = 0; i < 26; i++)
            {
                if (zimubiao0[i]!=zimubiao[i])
                {
                    flag=0;
                    break;
                }              
            }
            //printf("%d\n",*realnum);
            for (m = 0; m < count; m++)
            {
                
                if (strcmp(word[i],wordpoint[m])==0)
                {
                    flag=0;
                    break;
                }       
            }
            if (flag)
            {
                wordpoint[count]=word[i];
                count++;
            }      
        }        
    }  
    *realnum=count; 
}
void sortstr(char *wordpoint[], int num){
    char *temp;
    int top,seek;
    for (top = 0; top < num-1; top++)
    {
        for (seek = top+1; seek < num; seek++)
        {
            if (strcmp(wordpoint[top], wordpoint[seek])>0)
            {
                temp=wordpoint[top];
                wordpoint[top]=wordpoint[seek];
                wordpoint[seek]=temp;
            }
        }
    }
    
}