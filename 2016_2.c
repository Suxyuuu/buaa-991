#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*
* 读取文件D:/score.dat(其中每行为一个学生的数据, 学生姓名(纯英文)和学生成绩(包含小数), 中间用 \t 隔开)
* 若学生人数小于3, 输出所有信息. 否则, 输出平均分数并输出前三名的学生信息
* 文件内容示例:
*   zhangsan  84.5
*   lisi    78
*   wangwu  90
*/

struct StudentInfo
{
    char name[20];
    float score;
};

int cmp(const void * a, const void * b);
void output(struct StudentInfo student[], int count);
int main(void){
    char filedir[20]="D:/score.dat";
    char buff[20];
    char name[20];
    char score[20];
    struct StudentInfo student[20];
    FILE* fp;
    int count=0;
    if(fp=fopen(filedir, "r")){
        while (fgets(buff, 20, fp))
        {
            int cnt_name=0, cnt_score=0;
            for (int i = 0; i < strlen(buff); i++)
            {
                if (buff[i]!='\t' && buff[i]!='\n' && buff[i]!='\0')
                {
                    if (buff[i]>='A' && buff[i]<='z')
                    {
                        name[cnt_name]=buff[i];
                        cnt_name++;
                    }
                    if ((buff[i]>='0'&& buff[i]<='9') || buff[i]=='.')
                    {
                        score[cnt_score]=buff[i];
                        cnt_score++;
                    }
                }       
            }
            name[cnt_name]='\0';
            score[cnt_score]='\0';
            strcpy(student[count].name, name);
            student[count].score=atof(score); 
            count++; 
        }
        fclose(fp);
        output(student, count);    
    }
    else
    {
        fprintf(stdout, "can't open file\n");
    }
    
    getchar();
    return 0;
}

int cmp(const void * a, const void * b){
    return ((struct StudentInfo *)b)->score - ((struct StudentInfo *)a)->score;
}
void output(struct StudentInfo student[], int count){
    if (count<3)
    {
        for (int i = 0; i < count; i++)
        {
            printf("%s %.1f\n", student[i].name, student[i].score);
        }
    }
    else
    {
        qsort(student, count, sizeof(struct StudentInfo), cmp);
        float average=0, sum=0;
        for (int i = 0; i < count; i++)
        {
            //printf("%s %.1f\n", student[i].name, student[i].score);
            sum+=student[i].score;
        }
        printf("average: %.2f\n", sum/count);
        for (int i = 0; i < 3; i++)
        {
            printf("%s %.1f\n", student[i].name, student[i].score);
        }
        
    }
    
    
    

    
}