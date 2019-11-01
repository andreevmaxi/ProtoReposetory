#include <cstdio>

double RekSec(int n);

int main()
{
    int n = 0;
    FILE* tmp = fopen("input.txt", "r");
    fscanf(tmp, "%d", &n);
    fclose(tmp);
    tmp = fopen("output.txt", "w");
    double ans = RekSec(n);
    fprintf(tmp, "%.3lf", ans);
    fclose(tmp);
    return 0;
}

double RekSec(int n)
    {
    double ans = 0.0;
    if(n == 0)
        {
        ans = 1.0;
        } else
        {
        ans =  1.0 + 1.0 / RekSec(n - 1);
        }
    return ans;
    }
