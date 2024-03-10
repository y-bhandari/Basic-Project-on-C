//STUDENT RECORD SYSTEM
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct person
{
	int Id;
    char Name[35];
    char Address[50];
    char Sex[8];
    char P_name[35];
    char Class[20];

};
void menu();
void start();
void addrecord();
void listrecord();
void modifyrecord();
void deleterecord();
void searchrecord();
int main()
{
    system("color 3f");
    start();
    return 0;
}
void start()
{
    menu();
}
void menu()
{
    system("cls");
printf("\t\t\t\t    STUDENT RECORD SYSTEM");
printf("\n\t\t\t\tKANTIPUR ENGINEERING COLLEGE[KEC]");
printf("\n\t\t\t\t     Dhapakhel,Lalitpur\t\t\n\n");
printf(" 1.Add Records  \n 2.List Records \n 3.Search Records \n 4.Modify Records \n 5.Delete Records \n 6.Exit");

switch(getch())
{
    case '1': addrecord();
    break;
    case '2': listrecord();
    break;
    case '3': searchrecord();
    break;
    case '4': modifyrecord();
    break;
    case '5': deleterecord();
    break;
    case '6': exit(0);
    break;
    default:
                system("cls");
                printf("\nENTER 1 TO 6 ONLY!!");
                printf("\n ENTER ANY KEY.");
                getch();

menu();
}
}
void addrecord()
{
        system("cls");
        FILE *f;
        struct person p;
        f=fopen("S_RECORD.bin","ab+");
        printf("ENTER DETAILS:\n\n");
        printf("Roll No:");
        scanf("%d",&p.Id);
        fflush(stdin);
        printf("Name:");
        gets(p.Name);
        fflush(stdin);
        printf("Address:");
        gets(p.Address);
        fflush(stdin);
        printf("Parent's name:");
        gets(p.P_name);
        fflush(stdin);
        printf("Sex:");
        gets(p.Sex);
        fflush(stdin);
        printf("Class:");
        gets(p.Class);
        fwrite(&p,sizeof(p),1,f);

      fflush(stdin);
        printf("\nRECORD ADDED!!");

fclose(f);

    printf("\n\nENTER ANY KEY.");

	 getch();
    system("cls");
    menu();
}
void listrecord()
{
    struct person p;
    FILE *f;
f=fopen("S_RECORD.bin","rb");
if(f==NULL)
{
printf("\nRECORD NOT FOUND:");

exit(1);
}
while(fread(&p,sizeof(p),1,f)==1)
{
     printf("\n\n\n YOUR RECORD IS:\n\n");
     printf("Roll No:%d\nName:%s\nAddress:%s\nParent's name:%s\nSex:%s\nClass:%s",p.Id,p.Name,p.Address,p.P_name,p.Sex,p.Class);
	 getch();
     system("cls");
}
     printf("\n ENTER ANY KEY.");

fclose(f);
 getch();
    system("cls");
menu();
}
void searchrecord()
{
    struct person p;
	FILE *f;
	int roll;
	int go=0;

	f=fopen("S_RECORD.bin","rb");
	if(f==NULL)
	{
    	printf("\n error in opening");
    	exit(1);

	}
	printf("\nENTER ROLL NO. OF STUDENT TO SEARCH:");
	scanf("%d",&roll);
	while(fread(&p,sizeof(p),1,f)==1)
	{
    	if(p.Id==roll)
    	{
        	printf("\n\tSEARCHED INFORMATION IS:");
        	printf("\nRoll No:%d\nName:%s\nAddress:%s\nParent's name:%s\nSex:%s\nClass:%s",p.Id,p.Name,p.Address,p.P_name,p.Sex,p.Class);
        	go=1;

    	}
	}
	if(go==0)
    {
        printf("\n   RECORD NOT FOUND!!");
    }
 	fclose(f);
  	printf("\n ENTER ANY KEY.");

	 getch();
    system("cls");
menu();
}
void deleterecord()
{
    struct person p;
    FILE *f,*ft;
	int go;
	int roll;
	f=fopen("S_RECORD.bin","rb");
	if(f==NULL)
		{

			printf("RECORD NOT FOUND!!");

		}
	else
	{
		ft=fopen("temp.txt","wb+");
		if(ft==NULL)

            printf("file opening error");
		else

        {


		printf("\nENTER STUDENT'S ROLL TO DELETE:");
		scanf("%d",&roll);

		fflush(stdin);
		while(fread(&p,sizeof(p),1,f)==1)
		{
			if(p.Id!=roll)
				fwrite(&p,sizeof(p),1,ft);
			if(p.Id==roll)
                go=1;
		}
	fclose(f);
	fclose(ft);
	if(go!=1)
	{
		printf("\nRECORD NOT FOUND!!");
		remove("temp.txt");
	}
		else
		{
			remove("S_RECORD.bin");
			rename("temp.txt","S_RECORD.bin");
			printf("\nRECORD DELETED!!");

		}
	}
}
 printf("\n\n ENTER ANY KEY.");

	 getch();
    system("cls");
menu();
}
void modifyrecord()
{
    FILE *f;
    int go=0;
    struct person p,s;
	int roll;
	f=fopen("S_RECORD.bin","rb+");
	if(f==NULL)
		{

			printf("RECORD NOT FOUND!!");
			exit(1);


		}
	else
	{
	    system("cls");
		printf("\nENTER ROLL OF STUDENT TO MODIFY:");
            scanf("%d",&roll);
            while(fread(&p,sizeof(p),1,f)==1)
            {
                if(p.Id==roll)
                {

                    printf("\n\nENTER NEW DETAILS:\n\n");
 					printf("Roll No:");
 					scanf("%d",&s.Id);
 					fflush(stdin);
                    printf("Name:");
                    gets(s.Name);
                    fflush(stdin);
                    printf("Address:");
                    gets(s.Address);
                    fflush(stdin);
                    printf("Parent's name:");
                    gets(s.P_name);
                    fflush(stdin);
                    printf("Sex:");
                    gets(s.Sex);
                    fflush(stdin);
                    printf("Class:");
                    gets(s.Class);
                    fseek(f,-sizeof(p),SEEK_CUR);
                    fwrite(&s,sizeof(p),1,f);
                    go=1;
                    break;



                }
                fflush(stdin);


            }
            if(go==1)
            {
                printf("\n RECORD MODIFIED!!");

            }
            else
            {
                    printf(" \n RECORD NOT FOUND!!");

            }
            fclose(f);
	}
	 printf("\n ENTER ANY KEY.");
	 getch();
    system("cls");
	menu();

}
