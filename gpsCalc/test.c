#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    double lat, lon, alt, time;
    char name[10];
    FILE *fp;
    fp = fopen("sample_users_2.txt", "r");

    if (fp == NULL)
    {
        printf("Can't open file");
        exit(1);
    }

    int i, n;
    fscanf(fp, "%i", &n);

    fscanf(fp, "%s", &name);
    fscanf(fp, "%lf", &time);
    fscanf(fp, "%lf", &lat);
    fscanf(fp, "%lf", &lon);
    fscanf(fp, "%lf", &alt);
    printf("%s\n%lf\n%lf\n%lf\n%lf\n", name, time, lat, lon, alt);
    printf("---------------------");

    for (i = 0; i <= n; i++)
    {
        fscanf(fp, "%s", &name);
        fscanf(fp, "%lf", &time);
        fscanf(fp, "%lf", &lat);
        fscanf(fp, "%lf", &lon);
        fscanf(fp, "%lf", &alt);
        printf("%s\n%lf\n%lf\n%lf\n%lf\n", name, time, lat, lon, alt);
    }
}
