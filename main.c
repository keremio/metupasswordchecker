#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int sumup = 0, sumlow = 0, sumnum = 0, sumspec = 0;
    int harf = 0, rakam = 0, ozelk = 0;
    int rakbas = 0;
    int hatapuani = 0;
    char sifre[20];
    printf("sifrenizi giriniz: ");
    scanf("%s" , &sifre);
    int len = strlen(sifre);
    for (int i = 0; i < len; i++)
    {
        if ((int)sifre[i] > 47 && (int)sifre[i] < 58) //rakam sayisi kontrol
        {
            rakam++;
        }
        else if ((int)sifre[i] > 32 && (int)sifre[i] < 48) //ozel karakter sayisi kontrol
        {
            ozelk++;
        }
        else //harf sayisi kontrol
        {
            harf++;
        }
    }
    for (int i = 0; i < len; i++)
    {
        if ((int)sifre[i] == -121 || (int)sifre[i] == -89 || (int)sifre[i] == -108 || (int)sifre[i] == -97 || (int)sifre[i] == -127)
        {
            printf("turkce karakterler!\n"); //turkce karakter kontrol
            hatapuani++;
        }
        if (isupper(sifre[i])) //buyuk harf kontrol
        {
            sumup++;
        }
        if (islower(sifre[i])) //kucuk harf kontrol
        {
            sumlow++;
        }

        if ('0' <= sifre[i] && '9' >= sifre[i]) //rakam kontrol
        {
            sumnum++;
        }

        if((int)sifre[i] >= 33 && (int)sifre[i] <= 46) //ozel karakter kontrol
        {
            sumspec++;
        }
    }
    if (sumup == len - rakam - ozelk) //buyuk harf uyarisi
    {
        printf("sifrede en az bir kucuk harf olmali\n");
        hatapuani++;
    }
    if (sumlow == len - rakam - ozelk) //kucuk harf uyarisi
    {
        printf("sifrede en az bir buyuk harf olmali\n");
        hatapuani++;
    }
    if (sumnum == 0) //numara uyarisi
    {
        printf("sifrede en az bir rakam olmali\n");
        hatapuani++;
    }
    if (sumspec == 0) //ozel harf uyarisi
    {
        printf("sifrede en az bir ozel karakter olmali\n");
        hatapuani++;
    }
    for (int i = 2; i < len; i++) //tekrarlayan karakter uyarisi
        if (sifre[i-2] == sifre[i-1] && sifre[i-1] == sifre[i] && sifre[i])
        {
            printf("tekrar eden karakterler\n");
            hatapuani++;
            break;
        }
    for (int i = 3; i < len; i++) // ardisik sayilar uyarisi
    {
        int x3 = (int)(sifre[i-3] - '0');
        int x2 = (int)(sifre[i-2] - '0');
        int x1 = (int)(sifre[i-1] - '0');
        int x0 = (int)(sifre[i] - '0');
        if ((x0 == x1 + 1 && x1 == x2 + 1 && x2 == x3 + 1) || (x3 == x2 + 1 && x2 == x1 + 1 && x1 == x0 + 1))
        {
            printf("ardisik numaralar\n");
            hatapuani++;
            break;
        }
    }
    if (rakam == 4) //1900-2000 kontrol
    {
    for (int i = 0; i < len; i++)
    {
        if ((int)sifre[i] > 47 && (int)sifre[i] < 58) //once 4 rakamli baslangici kontrol
        {
            rakbas = i;
            break;
        }
    }
    int yil = (int)(sifre[rakbas] - '0') *1000 + (int)(sifre[rakbas+1] - '0') *100 + (int)(sifre[rakbas+2] - '0') *10 + (int)(sifre[rakbas+3] - '0') ;
    if (yil < 2021 && yil > 1900)
    {
        printf("sifrede 1900'lu ve 2000'li yillar yer alamaz.");
        hatapuani++;
    }
    }
    if (hatapuani == 0)
    {
        printf("guzel sifre!");
    }
}
