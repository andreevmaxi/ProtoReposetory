#include <cstdio>
#include <cstdlib>
#include <stdlib.h>

char* summ(char* str1, char* str2);

int main()
{
    char str1[100];
    char str2[100];
    char* pstr1 = &str1[0] + 100 - 1;
    char* pstr2 = &str2[0] + 100 - 1;
    int n = 0;
    FILE* tmp = fopen("input.txt", "r");
    int schet = 0;
    *pstr1 = fgetc(tmp);
    ++schet;
    while(*pstr1 != ' ')
        {
        printf("%c", *pstr1);
        *pstr1 = fgetc(tmp);
        --pstr1;
        ++schet;
        }
    printf("%c", *pstr1);
    *pstr1 = '\0';
    pstr1 = &str1[0] + 100 - 1;
    *(pstr1 + 1) = (char)schet;

    schet = 0;
    *pstr2 = fgetc(tmp);
    ++schet;
    while(*pstr2 <= '9' && *pstr2 >= '0')
        {
        ++schet;
        *pstr2 = fgetc(tmp);
        --pstr2;
        }
    *pstr2 = '\0';
    pstr2 = &str2[0] + 100 - 1;
    *(pstr2 + 1) = (char)schet;

    fclose(tmp);
    tmp = fopen("output.txt", "w");

    char* pans = summ(pstr1, pstr2);

    int prs = (int)*pans;
    --pans;

    for(int i = 0; i < prs; ++i)
        {
        fputc(*(pans - i), tmp);
        }
    free(pans);
    fclose(tmp);
    return 0;
}

char* summ(char* str1, char* str2)
    {
    char* ans = (char*) calloc(200, sizeof(char));
    *ans = (char)0;
    char* TmpAns = ans + 200 - 1;
    int l1 = (int)*(str1 + 1);
    int l2 = (int)*(str2 + 1);
    int bonus = 0;
    int ca = 0;
    int cb = 0;
    int s = 0;
    int maxl = 0;
    if(l1 > l2)
        {
        maxl = l1;
        } else
        {
        maxl = l2;
        }
    for(int i = 0; i < maxl; ++i)
        {
        if (l1 - i > 0)
            {
            printf("%c\n", *(str1-i));
            ca = (*(str1 - i) - '0');
            } else
            {
            ca = 0;
            }
        if (l2 - i > 0)
            {
            cb = (*(str2 - i) - '0');
            } else
            {
            cb = 0;
            }
        s = ca + cb + bonus;
        *TmpAns = (s % 10 + bonus) + '0';
        bonus = s / 10;
        --TmpAns;
        *ans = (char)((int)*ans + 1);
        }
        if(bonus > 0)
            {
            *TmpAns = (bonus) + '0';
            *ans = (char)((int)*ans + 1);
            }
        return ans;
    }
