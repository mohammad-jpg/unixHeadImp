/*************************************************************************************************
Name : Mohammad Syed
Student Number : 17305051
email : mohammad.syed@ucdconnect.ie
I managed to complete most of the assignment, the head and tail funtion work perfectly fine, and
does the even and odd ,where by when the user enters "head -n 10 -e" it gets the first 10 even lines
(line 2,4,6,8...,20) -V and -h return the requested texts. I have implemneted error checks
as functions for secanrios where the user toggles both e and o and if the file doesnt open.
the head function works. when no file is read in the stdin function comes in
**************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define maxchar 144
void standardinput(int n)
{
    char string[maxchar];
    for (int i =0 ; i <= n ; i++)
    {
        scanf("%s", string);
        printf("\n%s\n", string);
    }

}


void FileErrorChecker(char string[])
{

    FILE *F;
    if ((F = fopen(string, "r")) == NULL)
    {

        printf("\nunable to open file\n%s",string);
        exit(EXIT_FAILURE);
    }
    else
    {
        fclose(F);
    }
}
void h_toggeld(int h)
{
    if (h)
    {
        printf("\n-n K output the first|last K lines.\n-V Output version info: Your name, email, student number.\n-e print even lines.\n-o print odd lines.\n");
    }

}
void ErrorCheckEO(int o, int e)
{
    if (e && o )
    {
        printf("ERROR BOTH E AND O TOGGLED\n");
        exit(EXIT_FAILURE);
    }
}
void V_toggled(int V)
{
    if (V)
    {
        printf("\nName : Mohammad Syed\nEmail Address : mohammad.syed@ucdconnect.ie\nStudent number : 17305051\nCourse : Engineering");
    }
}

int main (int argc, char ** argv)
{
    int n=10,V=0,h=0,e=0,o=0,count=1, count2=0,count3=1;
    int y;
    FILE *f;
    char str[maxchar];
    while ((y = getopt(argc, argv, "n:hVeo")) != -1)
    {

        switch (y)

        {
        case 'e':
            e = 1;
            break;
        case 'o':
            o = 1;
            break;
        case 'n':
            n = atoi(optarg);
            break;
        case 'V':
            V = 1;
            break;
        case 'h':
            h = 1;
            break;

        }


    }

    int file = argc - 1;
    int ht = argc - 2;

    if (optind<3)
    {
        standardinput(n);
    }
    ErrorCheckEO(e,o);
    V_toggled(V);
    h_toggeld(h);
    FileErrorChecker(argv[file]);
    f = fopen(argv[file],"r");


    if ((strcmp(argv[ht],"head"))==0)
    {


        while (fgets(str, maxchar, f) != NULL )
        {

            if (count == (n+1)*2)
            {
                break;
            }

            else if (e)
            {

                if (count == (n+1)*2)
                {
                    break;
                }
                else
                {
                    if(count%2==0)
                    {
                        printf("line %d\t%s\n",count, str);
                    }
                    count++;

                }
            }
            else if (o)
            {

                if (count == (n+1)*2)
                {
                    break;
                }
                else
                {
                    if(count%2!=0)
                    {
                        printf("line %d\t%s\n",count, str);
                    }
                    count++;

                }
            }
            else
            {
                printf("%s", str);
                count++;
            }
        }


    }

    else if ((strcmp(argv[ht],"tail"))==0)
    {

        while (fgets(str, maxchar, f) != NULL )
        {

            count2++;

        }
        rewind(f);

        while (fgets(str, maxchar, f) != NULL )
        {
            count3++;




            if (e)
            {
                if (count3>=count2-2*n)

                    if(count3%2==0)
                    {
                        printf("\n%d:%s\n",count3,str);
                    }
            }
            else if (o)
            {
                if (count3>=count2-(2*n)+1)


                    if (count3%2!=0)
                    {
                        printf("\n%d:%s\n",count3,str);

                    }
            }
            else
            {
                if (count3>=count2-n)
                {
                    printf("\n%d:%s\n",count3,str);

                }
            }
        }

    }


    else
    {
        h=1;
        h_toggeld(h);

    }




}











