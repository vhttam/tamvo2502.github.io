#include <stdio.h>
#define FI "Data.inp"
void InputData(int *n)
{
    FILE *fi;
    fi = fopen(FI, "rt");
    if (fi == NULL)
    {
        printf("Khong the doc file\n");
        return;
    }
    fscanf(fi, "%d",n);
    fclose(fi);
}
int main()
{
    int n;
    InputData(&n);
    printf("n = %d", n);
    return 0;
}