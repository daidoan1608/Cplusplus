#include <bits/stdc++.h>
using namespace std;

void docVaoMT(int* &V, int &m, int &n, const char *tenTep);
void duaRaMT(int* V, int m, int n);
void congMT(int* V1, int* V2, int m, int n);

int main() {
    int* V1 = NULL;
    int* V2 = NULL;
    int m, n;

    docVaoMT(V1, m, n, "matranA.txt");
    docVaoMT(V2, m, n, "matranB.txt");
    congMT(V1, V2, m, n);
    duaRaMT(V1, m, n);
    duaRaMT(V2, m, n);
    free(V1);
    free(V2);
    return 0;
}

void docVaoMT(int* &V, int &m, int &n, const char *tenTep)
{
    FILE *fp;
    fp = fopen(tenTep, "rt");

    fscanf(fp, "%d%d", &m, &n);

    // Cấp phát bộ nhớ cho ma trận
    V = (int*)malloc(m * n * sizeof(int));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            fscanf(fp, "%d", &V[i * n + j]);
        
    }
    // Đóng tệp
    fclose(fp);
}

void duaRaMT(int* V, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", V[i * n + j]);
        printf("\n");
    }
}

void congMT(int* V1, int* V2, int m, int n)
{
    FILE *fp;
    fp = fopen("kq-thctdlgtbai05.txt", "wt");

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fprintf(fp, "%d ", V1[i * n + j] + V2[i * n + j]);
        }
        fputs("\n", fp);
    }

    fclose(fp);
}
