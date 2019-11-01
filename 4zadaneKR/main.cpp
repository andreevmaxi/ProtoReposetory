#include <cstdio>

int f(int n);

int main()
{
    int n = 0;
    FILE* tmp = fopen("input.txt", "r");
    fscanf(tmp, "%d", &n);
    fclose(tmp);
    tmp = fopen("output.txt", "w");
    fprintf(tmp, "%d", f(n));
    fclose(tmp);
    return 0;
}

int f(int n)
    {
    if(n > 2)
        {
        return 14* f(n-1) - 51*f(n-2) + 54*f(n-3);
        } else
        {
        switch(n)
            {
            case 0:
                return 3;
                break;

            case 1:
                return 14;
                break;

            case 2:
                return 94;
                break;

            default:
                return 0;
                break;
            }
        }
    }
