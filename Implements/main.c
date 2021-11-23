#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
struct subscriber
{
char phoneNum[20];
char fullname[50];
float amounts;
}s;
void adding_records();
void listing_records();
void edit_records();
void remove_records();
void searching_records();
void payment_records();
char get;
int main()
{	int pass;
	int phoneNum;
	char options;




	system("cls");
	printf("\n\t\t\t  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    printf("\n\t\t\t  +      ++++++++++++++++++++++++++++++++++++++++++++++++      +");
    printf("\n\t\t\t  +      +                                              +      +");
    printf("\n\t\t\t  +      +                                              +      +");
    printf("\n\t\t\t  +      + WELCOME TO TELECOM BILLING MANAGEMENT SYSTEM +      +");
    printf("\n\t\t\t  +      +                                              +      +");
    printf("\n\t\t\t  +      +                                              +      +");
    printf("\n\t\t\t  +      ++++++++++++++++++++++++++++++++++++++++++++++++      +");
    printf("\n\t\t\t  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\n\t\t\t  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\n\t\t\t  PRESS ANY KEY TO CONTINUE");
	Sleep(2000);
	getch();
    system("cls");
	while (1)
	{
	system("cls");
	printf("\n\t\t\t\t FEATURE OF TELECOM BILLING\n\t\t\t\t ______________________________________________");
    printf("\n\t\t\t\t| [1] ADDING NEW RECORDS                       |");
    printf("\n\t\t\t\t| _____________________________________________|");
    printf("\n\t\t\t\t| [2] LIST OF RECORDS                          |");
    printf("\n\t\t\t\t| _____________________________________________|");
    printf("\n\t\t\t\t| [3] EDIT RECORDS                             |");
    printf("\n\t\t\t\t| _____________________________________________|");
    printf("\n\t\t\t\t| [4] PAYMENT                                  |");
    printf("\n\t\t\t\t| _____________________________________________|");
    printf("\n\t\t\t\t| [5] SEARCHING RECORDS                        |");
    printf("\n\t\t\t\t| _____________________________________________|");
    printf("\n\t\t\t\t| [6] DELETING RECORDS                         |");
    printf("\n\t\t\t\t| _____________________________________________|");
    printf("\n\t\t\t\t| [0] EXIT                                     |\n\t\t\t\t________________________________________________\n\t\t\t\t\t\t\t\t");

	printf("\n\t\t\t\tPLEASE CHOOSE A NUMBER IN THE BOX ABOVE:");
		options=getche();
		options=toupper(options);
		switch(options)
		{
			case '4':
				payment_records();break;
			case '1':
				adding_records();break;
			case '2':
				listing_records();break;
			case '3':
				edit_records();break;
			case '5':
				searching_records();break;
			case '6':
				remove_records();break;
			case '0':
				system("cls");
				printf("\n\n\t\t\t\tTHANK YOU");
				printf("\n\n\n\n\n:\n\tFOR USING OUR SERVICE");
				Sleep(2000);
				exit(0);
				break;
			default:
				system("cls");
				printf("Incorrect Input");
				printf("\nAny key to continue");
				getch();
		}
	}
}
void adding_records()
{
	FILE *f;
	char test;
	f=fopen("c:/file.ojs","ab+");
	if(f==0)
	{   f=fopen("c:/file.ojs","wb+");
		system("cls");
		printf("please wait while we configure your computer");
		printf("/npress any key to continue");
		getch();
	}
	while(1)
	{
		system("cls");
		printf("\n Enter phone number:");
		scanf("%s",&s.phoneNum);
		printf("\n Enter your name:");
		fflush(stdin);
		scanf("%[^\n]",&s.fullname);
		printf("\n Enter your amount:");
		scanf("%f",&s.amounts);
		fwrite(&s,sizeof(s),1,f);
		fflush(stdin);
		system("cls");
		printf("1 your record successfully added");
		printf("\n Press esc key to exit, any other key to add other record:");
		test=getche();
		if(test==27)
			break;
	} 
	fclose(f);
}
void listing_records()
{
	FILE *f;
	int i;
	if((f=fopen("c:/file.ojs","rb"))==NULL)
		exit(0);
	system("cls");
	printf("Phone Number\t\tUser Name\t\t\tAmount\n");
	for(i=0;i<79;i++)
		printf("-");
	while(fread(&s,sizeof(s),1,f)==1)
	{
		printf("\n%-10s\t\t%-20s\t\tPhp%.2f /-",s.phoneNum,s.fullname,s.amounts);
	}
	printf("\n");
	for(i=0;i<79;i++)
		printf("-");

fclose(f);
getch();
}
void remove_records()
{
	FILE *f,*t;
	int i=1;
	char phoneNum[20];
	if((t=fopen("c:/temp.ojs","w+"))==NULL)
	exit(0);
	if((f=fopen("c:/file.ojs","rb"))==NULL)
	exit(0);
	system("cls");
	printf("Enter the phone number to be deleted from the Database");
	fflush(stdin);
	scanf("%[^\n]",phoneNum);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.phoneNum,phoneNum)==0)
		{       i=0;
			continue;

		}
		else
			fwrite(&s,sizeof(s),1,t);
	}
	if(i==1)
	{       system("cls");
		printf("Phone number \"%s\" not found",phoneNum);
		remove("c:/file.ojs");
		rename("c:/temp.ojs","c:/file.ojs");
		getch();
		fclose(f);
		fclose(t);
		main();
	}
	remove("c:/file.ojs");
	rename("c:/temp.ojs","c:/file.ojs");
	system("cls");
	printf("The Number %s Successfully Deleted!!!!",phoneNum);
	fclose(f);
	fclose(t);
	getch();
}
void searching_records()
{
	FILE *f;
	char phoneNum[20];
	int flag=1;
	f=fopen("c:/file.ojs","rb+");
	if(f==0)
		exit(0);
	fflush(stdin);
	system("cls");
	printf("Enter Phone Number to search in our database");
	scanf("%s", phoneNum);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.phoneNum,phoneNum)==0)
		{	system("cls");
			printf(" Record Found ");
			printf("\n\nPhonenumber: %s\nName: %s\nAmount: Php%0.2f\n",s.phoneNum,s.fullname,s.amounts);
			flag=0;
			break;
		}
		else if(flag==1)
		{	system("cls");
			printf("Requested Phone Number Not found in our database");
		}
	}
	getch();
	fclose(f);
}
void edit_records()
{
	FILE *f;
	char phoneNum[20];
	long int size=sizeof(s);
	if((f=fopen("c:/file.ojs","rb+"))==NULL)
		exit(0);
	system("cls");
	printf("Enter phone number of the subscriber to modify:");
	scanf("%[^\n]",phoneNum);
	fflush(stdin);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.phoneNum,phoneNum)==0)
		{
			system("cls");
			printf("\n Enter phone number:");
			scanf("%s",&s.phoneNum);
			printf("\n Enter naphoneNumme: ");
			fflush(stdin);
			scanf("%[^\n]",&s.fullname);
			printf("\n Enter amount: ");
			scanf("%f",&s.amounts);
			fseek(f,-size,SEEK_CUR);
			fwrite(&s,sizeof(s),1,f);
			break;
		}
	}
	fclose(f);
}
void payment_records()
{
	FILE *f;
	char phoneNum[20];
	long int size=sizeof(s);
	float amt;
	int i;
	if((f=fopen("c:/file.ojs","rb+"))==NULL)
		exit(0);
	system("cls");
	printf("Enter phone number of the subscriber for payment");
	scanf("%[^\n]",phoneNum);
	fflush(stdin);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.phoneNum,phoneNum)==0)
		{
			system("cls");
			printf("\n Phone No.: %s",s.phoneNum);
			printf("\n Name: %s",s.fullname);
			printf("\n Current amount: %f",s.amounts);
			printf("\n");
			for(i=0;i<79;i++)
				printf("-");
			printf("\n\nEnter amount of payment :");
			fflush(stdin);
			scanf(" %f",&amt);
			s.amounts=s.amounts-amt;
			fseek(f,-size,SEEK_CUR);
			fwrite(&s,sizeof(s),1,f);
			break;
		}
	}
	system("cls");
	printf("THANK YOU %s FOR YOUR TIMELY PAYMENTS",s.fullname);
	getch();
	fclose(f);
}
