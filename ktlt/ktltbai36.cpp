#include<stdio.h>
#include<math.h>

int main()
{
    float khoangCach;
    char c1,c2;
    float x1,x2,y1,y2;
    FILE *fp;

    fp = fopen("input-bai36.txt", "w");

    if (fp == NULL)
    {
        printf("Khong the tao file");
        return 1;
    }

    fprintf(fp, "A 2.5 4\nB 3 5");

    fclose(fp);

    fp = fopen("input-bai36.txt", "r");

    if (fp == NULL)
    {
        printf("Khong the tao file");
        return 1;
    }

    fscanf(fp,"%c%f%f",&c1,&x1,&y1);
    fscanf(fp,"\n%c%f%f*c",&c2,&x2,&y2);

    fclose(fp);

    khoangCach=sqrt(pow(x2-x1,2)+pow(y2-y1,2));

    fp = fopen("output-bai36.txt","w");
    if (fp==NULL)
    {
        printf("Khong th mo tep");
        return 1;
    }
    
    fprintf(fp,"Khoang cach hai diem %c va %c la: %f,%f,%f,%f,%f",c1,c2,khoangCach,x1,y1,x2,y2);

    fclose(fp);

    return 0;
}