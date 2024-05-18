#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Please enter name and phone number only\n");
        return 1;
    }

    FILE *fp = fopen("phonebook.txt", "a");
    if (fp == NULL)
    {
        printf("The process of opening the file failed\n");
        return 1;
    }

    fprintf(fp, "%s, %s\n", argv[1], argv[2]);
    fclose(fp);
}
