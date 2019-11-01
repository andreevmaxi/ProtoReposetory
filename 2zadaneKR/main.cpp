#include <cstdio>

int main()
{
    long long n = 0;
    FILE* tmp = fopen("input.txt", "r");
    fscanf(tmp, "%lld", &n);
    fclose(tmp);
    tmp = fopen("output.txt", "w");
    fprintf(tmp, "%d", (n - 1) % 5);
    fclose(tmp);
    return 0;
}
