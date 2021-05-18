/*           A PROJECT ON HOSPITAL MANAGEMENT SYSTEM           */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

/*MAKING clrscr FUNCTION*/

void clrscr(void)
{
    system("cls");
}

/*MAKING gotoxy FUNCTION*/

void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

/* MAKING SCREEN HEADER FUNCTION */

void scrhd(void)
{
            printf("\n\n                                         >>>>WELCOME TO THE HOSPITAL<<<<                           \n\n");
}

/* DECLARATION OF FUNCTIONS TO BE USED */

void emp(void);
void menu(void);
void pat(void);
void inv(void);
void about(void);
void doc(void);

/* DECLARATION OF STRUCTURES TO BE USED */

struct address
{
                int hno;
                char street[40];
                char city[40];
                char state[40];
};

struct patient
{
                char name[40];
                char fname[40];
                int age;
                char bg[3];
                char gender;
                char regn[10];
                struct address a;
                char ph[10];
                char disease[60];
                char doc_name[40];
                char history[200];
                char date[10];
                char treatment[40];
                char med[40];
};

struct doctor
{
                char name[40];
                char gender;
                char idn[30];
                char email[25];
                struct address z;
                int age;
                char bg[3];
                char ph[10];
                char specialty[20];
                char nationality[20];
                char doj[15];
};

struct staff
{
                char name[40];
                char fname[40];
                int age;
                char bg[3];
                char gender;
                char uid[10];
                struct address b;
                char ph[10];
                double salary;
                char desig[40];
};

struct inventory
{
                int sno;
                char name[30];
                char dop[20];
                int qnty;
                float price;
                float amount;
};

/* MAIN MENU FUNCTION */

void menu()
{

                char choice;
                printf("\n\n\n\n");
                printf("                            ********************************************\n");
                printf("                                    **        HOSPITAL        **          \n");
                printf("                                    **       MANAGEMENT       **          \n");
                printf("                                    **         SYSTEM         **      \n");
                printf("                            ********************************************\n");
                printf("\n\n\n\n\n");
                printf("\t\t[1] DOCTOR");
                printf("\n\t\t[2] PATIANT");
                printf("\n\t\t[3] STAFF");
                printf("\n\t\t[4] INVENTORY");
                printf("\n\t\t[5] ABOUT PROGRAM");
                printf("\n\t\t[0] EXIT");
                printf("\n\n\t\t>>>>Enter your choice: ");
                fflush(stdin);
                choice=getche();

                switch(choice)
                {
                                case '1':
                                                doc();
                                                break;
                                case '2':
                                                pat();
                                                break;
                                case '3':
                                                emp();
                                                break;
                                case '4':
                                                inv();
                                                break;
                                case '5':
                                                about();
                                                break;
                                case '0':
                                                exit(1);
                }
}

/* MAIN FUNCTION*/

void main()
{
    char pass[10],password[10]="Hospital";
    int main_exit;
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\tEnter the password to login: ");
    scanf("%s",pass);
    if (strcmp(pass,password)==0)
        {
            clrscr();
            menu();
        }
    else
        {
            printf("\n\n\n\n\t\t\tWrong password!!\n\n");
            printf("\n\n\n\n\t\t\tPress 1 to try again or any key to exit: ");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {
                        clrscr();
                        main();
                    }
            else
                    {
                    clrscr();
                    exit(1);
                    }

        }
}

/* MODULE  1 */
/* DOCTOR */

void doc()
{
                FILE *fd,*fn;
                char extra,x;
                char id[20],specialtyn[20];
                int iF=0;
                long int recsizex;
                struct doctor d;

                fd=fopen("doc.DAT","rb+");
                if(fd==NULL)
                {
                                fd=fopen("doc.DAT","wb+");
                                if(fd==NULL)
                                {
                                                puts("\nSorry!! Cannot open file");
                                                exit(1);
                                }
                }
                recsizex=sizeof(d);
                while(1)
                {
                                clrscr();

/* DISPLAY OF OPTIONS */
                                scrhd();
                                printf("\n\n\t\t\t*DOCTOR*\n");
                                printf("\n\t\t[1] Enter a New Entry");
                                printf("\n\t\t[2] Modify Existing");
                                printf("\n\t\t[3] Search an Entry");
                                printf("\n\t\t[4] Listing of records");
                                printf("\n\t\t[5] Delete an Entry");
                                printf("\n\t\t[6] Main Menu");
                                printf("\n\n\t\t>>>>Enter your choice here: ");
                                fflush(stdin);
                                x=getche();

                                switch(x)
                                {

/* ADDITION OF RECORDS */

                                                case '1':
                                                                clrscr();
                                                                fseek(fd,0,SEEK_END);
                                                                extra='Y';
                                                                while(extra=='Y'||extra=='y')
                                                                {
                                                                i:
                                                                printf("\n\n\nEnter ID Number: ");
                                                                fflush(stdin);
                                                                scanf("%s",id);
                                                                rewind(fd);

/* CHECKING FOR ID NUMBER */

                                                                while(fread(&d,recsizex,1,fd)==1)
                                                                {

                                                                                if(strcmp(d.idn,id)==0)
                                                                                {
                                                                                                iF=1;
printf("\n\t\tTHIS ID NUMBER ALREADY EXISTS. ENTER ANOTHER ONE");
                                                                                                goto i;
                                                                                }
                                                                }
                                                                if(iF==0||fread(&d,recsizex,1,fd)==0)
                                                                {
                                                                                fseek (fd,0,SEEK_END);
                                                                                strcpy(d.idn,id);
                                                                                printf("\nEnter the name of the Doctor: ");
                                                                                fflush(stdin);
                                                                                gets(d.name);
printf("\nEnter the gender of the doctor(M.male or F.female): ");
                                                                                scanf("%c",&d.gender);
                                                                                fflush(stdin);
                                                                                printf("\nEnter the Blood group of the Doctor: ");
                                                                                scanf("%s",d.bg);
                                                                                printf("\nEnter the age of the Doctor: ");
                                                                                scanf("%d",&d.age);
                                                                                printf("\nEnter the address of the Doctor:\n");
                                                                                printf("\n\tEnter the house number: ");
                                                                                fflush(stdin);
                                                                                scanf("%d",&d.z.hno);
                                                                                fflush(stdin);
                                                                                printf("\n\tEnter the street/colony: ");
                                                                                scanf("%s",d.z.street);
                                                                                fflush(stdin);
                                                                                printf("\n\tEnter the city: ");
                                                                                scanf("%s",d.z.city);
                                                                                fflush(stdin);
                                                                                printf("\n\tEnter the state: ");
                                                                                scanf("%s",d.z.state);
                                                                                fflush(stdin);
                                                                                printf("\nEnter the phone number of the Doctor: ");
                                                                                scanf("%s",d.ph);
                                                                                printf("\nEnter the Email address: ");
                                                                                fflush(stdin);
                                                                                scanf("%s",d.email);
                                                                                printf("\nEnter the specialty: ");
                                                                                fflush(stdin);
                                                                                scanf("%s",d.specialty);
                                                                                printf("\nEnter the nationality: ");
                                                                                fflush(stdin);
                                                                                scanf("%s",d.nationality);
                                                                                printf("\nEnter the date of joining: ");
                                                                                fflush(stdin);
                                                                                scanf("%s",d.doj);
                                                                                fwrite(&d,recsizex,1,fd);
                                                                                printf("\n----------------------------------------------------");
                                                                                printf("\nWant to add entry of the another Doctor(Y/N): ");
                                                                                fflush(stdin);
                                                                                extra=getche();
                                                                }
                                                }
                                                                break;

/* MODIFICATION OF EXISTING RECORDS */

                                                case '2':
                                                                clrscr();
                                                                extra='Y';
                                                                while(extra=='Y'||extra=='y')
                                                                {
printf("\nEnter the ID number of the doctor to modify: ");
                                                                                fflush(stdin);
                                                                                scanf("%s",id);
                                                                                rewind(fd);
                                                                                while(fread(&d,recsizex,1,fd)==1)
                                                                                {
                                                                                                if(strcmp(d.idn,id)==0)
                                                                                                {
                                                                                printf("\nEnter the new name of the Doctor: ");
                                                                                fflush(stdin);
                                                                                gets(d.name);
printf("\nEnter the gender of the doctor(M.male or F.female): ");
                                                                                scanf("%c",&d.gender);
                                                                                fflush(stdin);
                                                                                printf("\nEnter the Blood group of the Doctor: ");
                                                                                scanf("%s",d.bg);
                                                                                printf("\nEnter the age of the Doctor: ");
                                                                                scanf("%d",&d.age);
                                                                                printf("\nEnter the address of the Doctor:\n");
                                                                                printf("\n\tEnter the new house number: ");
                                                                                fflush(stdin);
                                                                                scanf("%d",&d.z.hno);
                                                                                fflush(stdin);
                                                                                printf("\n\tEnter the street/colony: ");
                                                                                scanf("%s",d.z.street);
                                                                                fflush(stdin);
                                                                                printf("\n\tEnter the city: ");
                                                                                scanf("%s",d.z.city);
                                                                                fflush(stdin);
                                                                                printf("\n\tEnter the state: ");
                                                                                scanf("%s",d.z.state);
                                                                                fflush(stdin);
                                                                                printf("\nEnter the new phone number of the Doctor: ");
                                                                                scanf("%s",d.ph);
                                                                                printf("\nEnter the new Email address: ");
                                                                                fflush(stdin);
                                                                                scanf("%s",d.email);
                                                                                printf("\nEnter the specialty: ");
                                                                                fflush(stdin);
                                                                                scanf("%s",d.specialty);
                                                                                printf("\nEnter the nationality: ");
                                                                                fflush(stdin);
                                                                                scanf("%s",d.nationality);
                                                                                printf("\nEnter the date of joining: ");
                                                                                fflush(stdin);
                                                                                scanf("%s",d.doj);

                                                                                                                fseek(fd,-recsizex,SEEK_CUR);
                                                                                                                fwrite(&d,recsizex,1,fd);
                                                                                                                break;
                                                                                                }
                                                                                }
                                                                                 printf("\n----------------------------------------------------");
                                                                                 printf("\nModify another Record(Y/N): ");
                                                                                 fflush(stdin);
                                                                                 extra=getche();
                                                                }
                                                                break;

/*SEARCHING A PARTICULAR ENTRY (BY SPECIALTY) */

                                                case '3':
                                                clrscr();
                                                                extra='Y';
                                                                while(extra=='Y'||extra=='y')
                                                                {
                                                                                printf("\nEnter speciality to search: ");
                                                                                fflush(stdin);
                                                                                gets(specialtyn);
                                                                                rewind(fd);
                                                                                while(fread(&d,recsizex,1,fd)==1)
                                                                                {
                                                                                                if(strcmp(d.specialty,specialtyn)==0)
                                                                                                {
                                                                                printf("\nID Number of the Doctor : ");
                                                                                puts(d.idn);
                                                                                printf("\nName of the Doctor: ");
                                                                                puts(d.name);
printf("\nGender of the doctor(M.male or F.female): ");
                                                                                printf("%c\n",d.gender);
                                                                                printf("\nBlood group of the Doctor: ");
                                                                                puts(d.bg);
                                                                                printf("\nAge of the Doctor: ");
                                                                                printf("%d\n",d.age);
                                                                                printf("\nAddress of the Doctor:\n");
                                                                                printf("\n\tHouse number: ");
                                                                                printf("%d\n",d.z.hno);
                                                                                printf("\n\tStreet/colony: ");
                                                                                puts(d.z.street);
                                                                                printf("\n\tCity: ");
                                                                                puts(d.z.city);
                                                                                printf("\n\tState: ");
                                                                                puts(d.z.state);
                                                                                printf("\nPhone number of the Doctor: ");
                                                                                puts(d.ph);
                                                                                printf("\nEmail address: ");
                                                                                puts(d.email);
                                                                                printf("\nSpecialty: ");
                                                                                puts(d.specialty);
                                                                                printf("\nNationality: ");
                                                                                puts(d.nationality);
                                                                                printf("\nJoining date: ");
                                                                                puts(d.doj);

                                                                                                }
                                                                                }
                                                                 printf("\n----------------------------------------------------");
                                                                 printf("\nSearch another Entry(Y/N): ");
                                                                 fflush(stdin);
                                                                 extra=getche();
                                                                }
                                                                break;

/* LISTING OF ALL RECORDS */

                                                case '4':
                                                                clrscr();
                                                                rewind(fd);
                                                                while(fread(&d,recsizex,1,fd)==1)
                                                                {
                                                                                printf("\nID Number of the Doctor : ");
                                                                                puts(d.idn);
                                                                                printf("\nName of the Doctor: ");
                                                                                puts(d.name);
printf("\nGender of the doctor(M.male or F.female): ");
                                                                                printf("%c\n",d.gender);
                                                                                printf("\nBlood group of the Doctor: ");
                                                                                puts(d.bg);
                                                                                printf("\nAge of the Doctor: ");
                                                                                printf("%d\n",d.age);
                                                                                printf("\nAddress of the Doctor:\n");
                                                                                printf("\n\tHouse number: ");
                                                                                printf("%d\n",d.z.hno);
                                                                                printf("\n\tStreet/colony: ");
                                                                                puts(d.z.street);
                                                                                printf("\n\tCity: ");
                                                                                puts(d.z.city);
                                                                                printf("\n\tState: ");
                                                                                puts(d.z.state);
                                                                                printf("\nPhone number of the Doctor: ");
                                                                                puts(d.ph);
                                                                                printf("\nEmail address: ");
                                                                                puts(d.email);
                                                                                printf("\nSpecialty: ");
                                                                                puts(d.specialty);
                                                                                printf("\nNationality: ");
                                                                                puts(d.nationality);
                                                                                printf("\nJoining date: ");
                                                                                puts(d.doj);
                                                                                printf("\n----------------------------------------------------\n");

                                                                }
                                                                getche();
                                                                break;

/* DELETION OF RECORD */

                                case '5':
                                clrscr();
                                extra='Y';
                                                                while(extra=='Y'||extra=='y')
                                                                {
printf("\nEnter the ID number of the Doctor to be deleted: ");
                                                                                fflush(stdin);
                                                                                scanf("%s",id);
                                                                                fn=fopen("nur.DAT","wb+");
                                                                                rewind(fd);
                                                                                while(fread(&d,recsizex,1,fd)==1)
                                                                                {
                                                                                                if(strcmp(d.idn,id)!=0)
                                                                                                fwrite(&d,recsizex,1,fn);
                                                                                                else
printf("\nThe Record has been Deleted Successfully.");
                                                                                }

                                                                                fclose(fd);
                                                                                fclose(fn);
                                                                                remove("doc.DAT");
                                                                                rename("nur.DAT","doc.DAT");
                                                                                fd=fopen("doc.DAT","rb+");
                                                                                printf("\nDelete another record?(Y/N): ");
                                                                                fflush(stdin);
                                                                                extra=getche();
                                                                }
                                                 break;

                case '6':
                                {
                                fclose(fd);
                                clrscr();
                                menu();
                                }
                                break;
                  }
                }
}

/* MODULE  2 */
/* PATIENT */

void pat()
{
                FILE *fp,*ft;
                char another,ch;
                char reg[20],pname[40];
                int iF=0;
                long int recsize;
                struct patient p;

                fp=fopen("pat.DAT","rb+");
                if(fp==NULL)
                {
                                fp=fopen("pat.DAT","wb+");
                                if(fp==NULL)
                                {
                                                puts("\nSorry!! Cannot open file");
                                                exit(1);
                                }
                }
                recsize=sizeof(p);
                while(1)
                {
                                clrscr();

/* DISPLAY OF OPTIONS */

                                scrhd();
                                printf("\n\n\t\t\t*PATIENT*\n");
                                printf("\n\t\t[1] Enter a New Entry");
                                printf("\n\t\t[2] Modify Existing");
                                printf("\n\t\t[3] Search an Entry");
                                printf("\n\t\t[4] Listing of records");
                                printf("\n\t\t[5] Delete an Entry");
                                printf("\n\t\t[6] Main Menu");
                                printf("\n\n\t\t>>>>Enter your choice here: ");
                                fflush(stdin);
                                ch=getche();

                                switch(ch)
                                {

/* ADDITION OF RECORDS */

                                                case '1':
                                                                clrscr();
                                                                fseek(fp,0,SEEK_END);
                                                                another='Y';
                                                                while(another=='Y'||another=='y')
                                                                {
                                                                w:
                                                                printf("\n\n\nEnter Registration Number: ");
                                                                fflush(stdin);
                                                                scanf("%s",reg);
                                                                rewind(fp);

/* CHECKING FOR REGISTRATION NUMBER */

                                                                while(fread(&p,recsize,1,fp)==1)
                                                                {

                                                                                if(strcmp(p.regn,reg)==0)
                                                                                {
                                                                                                iF=1;
printf("\n\t\tTHIS REGISTRATION NUMBER ALREADY EXISTS. ENTER ANOTHER ONE");
                                                                                                goto w;
                                                                                }
                                                                }
                                                                if(iF==0||fread(&p,recsize,1,fp)==0)
                                                                {
                                                                                fseek (fp,0,SEEK_END);
                                                                                strcpy(p.regn,reg);
                                                                                fflush(stdin);
                                                                                printf("\nEnter the name of the patient: ");
                                                                                gets(p.name);
                                                                                printf("\nEnter the name of the Guardian: ");
                                                                                fflush(stdin);
                                                                                gets(p.fname);
printf("\nEnter the gender of the patient(M.male or F.female): ");
                                                                                scanf("%c",&p.gender);
                                                                                fflush(stdin);
                                                                                printf("\nEnter the Blood group of the patient: ");
                                                                                scanf("%s",p.bg);
                                                                                printf("\nEnter the age of the patient: ");
                                                                                scanf("%d",&p.age);
                                                                                printf("\nEnter the address of the patient:\n");
                                                                                printf("\n\tEnter the house number: ");
                                                                                fflush(stdin);
                                                                                scanf("%d",&p.a.hno);
                                                                                fflush(stdin);
                                                                                printf("\n\tEnter the street/colony: ");
                                                                                scanf("%s",p.a.street);
                                                                                fflush(stdin);
                                                                                printf("\n\tEnter the city: ");
                                                                                scanf("%s",p.a.city);
                                                                                fflush(stdin);
                                                                                printf("\n\tEnter the state: ");
                                                                                scanf("%s",p.a.state);
                                                                                fflush(stdin);
                                                                                printf("\nEnter the phone number of the patient: ");
                                                                                scanf("%s",p.ph);
                                                                                fflush(stdin);
printf("\nEnter the Disease or problem for which he/she wants treatment: ");
                                                                                gets(p.disease);
printf("\nEnter the name of the Doctor to which he/she being referred: ");
                                                                                fflush(stdin);
                                                                                gets(p.doc_name);
printf("\nEnter the history, if any, related to treatment of the patient(otherwise write NOT AVAILABLE): ");
                                                                                fflush(stdin);
                                                                                gets(p.history);
                                                                                                                                                                                                fflush(stdin);
printf("\n Enter the date of treatment given: ");
                                                                                                                gets(p.date);
printf("\nEnter the detail of treatment given: ");                                 fflush(stdin);
                                                                                                                gets(p.treatment);
                                                                                                                fflush(stdin);
                                                                                                                printf("\nEnter the medicines prescribed: ");
                                                                                                                gets(p.med);
                                                                                fwrite(&p,recsize,1,fp);
                                                                                printf("\n----------------------------------------------------");
                                                                                printf("\nWant to add entry of the another Patient(Y/N): ");
                                                                                fflush(stdin);
                                                                                another=getche();
                                                                }
                                                }
                                                                break;

/* MODIFICATION OF EXISTING RECORDS */

                                                case '2':
                                                                clrscr();
                                                                another='Y';
                                                                while(another=='Y'||another=='y')
                                                                {
printf("\nEnter the Registration number of the patient to modify: ");
                                                                                fflush(stdin);
                                                                                scanf("%s",reg);
                                                                                rewind(fp);
                                                                                while(fread(&p,recsize,1,fp)==1)
                                                                                {
                                                                                                if(strcmp(p.regn,reg)==0)
                                                                                                {
                                                                                                                fflush(stdin);
printf("\nEnter the new name of the patient: ");
                                                                                                                gets(p.name);
printf("\nEnter the new name of the Guardian: ");                               fflush(stdin);
                                                                                                                gets(p.fname);
printf("\nEnter the new Blood group of the patient: ");                        fflush(stdin);
                                                                                                                scanf("%s",p.bg);
printf("\nEnter the new age of the patient: ");
                                                                                                                scanf("%d",&p.age);
printf("\nEnter the new address of the patient:\n");
                                                                                                                printf("\n\tEnter the house number: ");
                                                                                                                scanf("%d",&p.a.hno);
                                                                                                                fflush(stdin);
                                                                                                                printf("\n\tEnter the street/colony: ");
                                                                                                                scanf("%s",p.a.street);
                                                                                                                fflush(stdin);
                                                                                                                printf("\n\tEnter the city: ");
                                                                                                                scanf("%s",p.a.city);
                                                                                                                fflush(stdin);
                                                                                                                printf("\n\tEnter the state: ");
                                                                                                                scanf("%s",p.a.state);
printf("\nEnter the new phone number of the patient: ");                    fflush(stdin);
                                                                                                                scanf("%s",p.ph);
                                                                                                                fflush(stdin);
printf("\n Enter the date of treatment given: ");
                                                                                                                gets(p.date);
printf("\nEnter the detail of treatment given: ");                                 fflush(stdin);
                                                                                                                gets(p.treatment);
                                                                                                                fflush(stdin);
                                                                                                                printf("\nEnter the medicines prescribed: ");
                                                                                                                gets(p.med);

                                                                                                                fseek(fp,-recsize,SEEK_CUR);
                                                                                                                fwrite(&p,recsize,1,fp);
                                                                                                                break;
                                                                                                }
                                                                                }
                                                                                 printf("\n----------------------------------------------------");
                                                                                 printf("\nModify another Record(Y/N): ");
                                                                                 fflush(stdin);
                                                                                 another=getche();
                                                                }
                                                                break;

/*SEARCHING A PARTICULAR ENTRY (BY NAME) */

                                                case '3':
                                                clrscr();
                                                                another='Y';
                                                                while(another=='Y'||another=='y')
                                                                {
                                                                                printf("\nEnter name to search: ");
                                                                                fflush(stdin);
                                                                                gets(pname);
                                                                                rewind(fp);
                                                                                while(fread(&p,recsize,1,fp)==1)
                                                                                {
                                                                                                if(strcmp(p.name,pname)==0)
                                                                                                {
printf("\nRegistration Number of the Patient : ");
                                                                                                                puts(p.regn);
                                                                                                                printf("\nName of the Patient : ");
                                                                                                                puts(p.name);
                                                                                                                printf("\nName of the Guardian : ");
                                                                                                                puts(p.fname);
                                                                                                                printf("\nAge : %d",p.age);
                                                                                                                printf("\nGender : %c",p.gender);
                                                                                                                printf("\nBlood group: %s",p.bg);
printf("\nAddress  : %d,%s,%s,%s",p.a.hno,p.a.street,p.a.city,p.a.state);
                                                                                                                printf("\nphone number : +91-%s",p.ph);
                                                                                                                printf("\nDisease : %s",p.disease);
                                                                                                                printf("\nEarlier History : ");
                                                                                                                puts(p.history);
printf("\nDetails of treatment given and medicine prescribed:");
printf("\nDATE\t\tTREATMENT GIVEN\t\tMEDICINE PRESCRIBED\n");
printf("%s\t\t %s\t\t %s\n",p.date,p.treatment,p.med);
                                                                                                                printf("\nName of the Doctor : ");
                                                                                                                puts(p.doc_name);

                                                                                                }
                                                                                }
                                                                 printf("\n----------------------------------------------------");
                                                                 printf("\nSearch another Entry(Y/N): ");
                                                                 fflush(stdin);
                                                                 another=getche();
                                                                }
                                                                break;

/* LISTING OF ALL RECORDS */

                                                case '4':
                                                                clrscr();
                                                                rewind(fp);
                                                                while(fread(&p,recsize,1,fp)==1)
                                                                {
                                                                                printf("\nRegistration Number of the Patient : ");
                                                                                puts(p.regn);
                                                                                printf("\nName of the Patient : ");
                                                                                puts(p.name);
                                                                                printf("\nName of the Guardian : ");
                                                                                puts(p.fname);
                                                                                printf("\nAge : %d",p.age);
                                                                                printf("\nGender : %c",p.gender);
                                                                                printf("\nBlood group: %s",p.bg);
printf("\nAddress  : %d,%s,%s,%s",p.a.hno,p.a.street,p.a.city,p.a.state);
                                                                                printf("\nphone number : +91-%s",p.ph);
                                                                                printf("\nDisease : %s",p.disease);
                                                                                printf("\nEarlier History : ");
                                                                                puts(p.history);
printf("\nDetails of treatment given and medicine prescribed:");
printf("\nDATE\t\t TREATMENT GIVEN\t\t\t MEDICINE PRESCRIBED\n");
                                                                                printf("%s\t %s\t\t %s\n",p.date,p.treatment,p.med);
                                                                                printf("\nName of the Doctor : ");
                                                                                puts(p.doc_name);

                                                                                printf("\n----------------------------------------------------\n");

                                                                }
                                                                getch();
                                                                break;

/* DELETION OF RECORD */

                                case '5':
                                clrscr();
                                another='Y';
                                                                while(another=='Y'||another=='y')
                                                                {
printf("\nEnter the Registration number of the Patient to be deleted: ");
                                                                                fflush(stdin);
                                                                                scanf("%s",reg);
                                                                                ft=fopen("temp.DAT","wb+");
                                                                                rewind(fp);
                                                                                while(fread(&p,recsize,1,fp)==1)
                                                                                {
                                                                                                if(strcmp(p.regn,reg)!=0)
                                                                                                fwrite(&p,recsize,1,ft);
                                                                                                else
printf("\nThe Record has been Deleted Successfully.");
                                                                                }

                                                                                fclose(fp);
                                                                                fclose(ft);
                                                                                remove("pat.DAT");
                                                                                rename("temp.DAT","pat.DAT");
                                                                                fp=fopen("pat.DAT","rb+");

                                                                                printf("\nDelete another record?(Y/N): ");
                                                                                fflush(stdin);
                                                                                another=getche();
                                                                }
                                                 break;

                case '6':
                                {
                                fclose(fp);
                                clrscr();
                                menu();
                                }
                                break;
                  }
                }
}

/* MODULE  3 */
/* EMPLOYEE */

void emp()
{
                FILE *fs,*fx;
                char more,c;
                char id[20],s_name[40];
                int iF=0;
                long int recsize1;
                struct staff s;

                fs=fopen("emp.DAT","rb+");
                if(fs==NULL)
                {
                                fs=fopen("emp.DAT","wb+");
                                if(fs==NULL)
                                {
                                                puts("\nSorry!! Cannot open file");
                                                exit(1);
                                }
                }
                recsize1=sizeof(s);
                while(1)
                {
                                clrscr();

/* DISPLAY OF OPTIONS */

                                scrhd();
                                printf("\n\t\t\t*EMPLOYEE*\n");
                                printf("\n\t\t[1] Add an Entry");
                                printf("\n\t\t[2] Modify Existing One");
                                printf("\n\t\t[3] Search an Entry");
                                printf("\n\t\t[4] Listing of all records");
                                printf("\n\t\t[5] Delete an Entry");
                                printf("\n\t\t[6] Main Menu");
                                printf("\n\n\t\t>>>>Enter your choice here: ");
                                fflush(stdin);
                                c=getche();

                                switch(c)
                                {

/* ADDITION OF RECORDS */

                                                case '1':
                                                                clrscr();
                                                                fseek(fs,0,SEEK_END);
                                                                more='Y';
                                                                while(more=='Y'||more=='y')
                                                                {
                                                                u:
                                                                printf("\n\n\nEnter the UID of the Employee: ");
                                                                fflush(stdin);
                                                                scanf("%s",id);
                                                                rewind(fs);

/* CHECKING FOR UNIQUE ID */

                                                                while(fread(&s,recsize1,1,fs)==1)
                                                                {

                                                                                if(strcmp(s.uid,id)==0)
                                                                                {
                                                                                                iF=1;
printf("\n\t\tTHIS UID ALREADY EXISTS. ENTER ANOTHER ONE");
                                                                                                goto u;
                                                                                }
                                                                }
                                                                if(iF==0||fread(&s,recsize1,1,fs)==0)
                                                                {
                                                                                fseek (fs,0,SEEK_END);
                                                                                strcpy(s.uid,id);
                                                                                fflush(stdin);
                                                                                printf("\nEnter the name of the Employee: ");
                                                                                gets(s.name);
                                                                                printf("\nEnter the name of the Guardian: ");
                                                                                fflush(stdin);
                                                                                gets(s.fname);
printf("\nEnter the gender of the employee(M.male or F.female): ");
                                                                                scanf("%c",&s.gender);
                                                                                printf("\nEnter the Blood group of the Employee: ");
                                                                                fflush(stdin);
                                                                                scanf("%s",s.bg);
                                                                                printf("\nEnter the age of the Employee: ");
                                                                                scanf("%d",&s.age);
                                                                                printf("\nEnter the Salary of the Employee: ");
                                                                                scanf("%lf",&s.salary);
                                                                                printf("\nEnter the address of the Employee:\n");
                                                                                printf("\n\tEnter the house number: ");
                                                                                scanf("%d",&s.b.hno);
                                                                                fflush(stdin);
                                                                                printf("\n\tEnter the street/colony: ");
                                                                                scanf("%s",s.b.street);
                                                                                printf("\n\tEnter the city: ");
                                                                                fflush(stdin);
                                                                                scanf("%s",s.b.city);
                                                                                printf("\n\tEnter the state: ");
                                                                                fflush(stdin);
                                                                                scanf("%s",s.b.state);
                                                                                printf("\nEnter the phone number of the Employee: ");
                                                                                fflush(stdin);
                                                                                scanf("%s",s.ph);
                                                                                fflush(stdin);
                                                                                printf("\nEnter the Designation: ");
                                                                                gets(s.desig);

                                                                                fwrite(&s,recsize1,1,fs);
                                                                                printf("\n----------------------------------------------------");
                                                                                printf("\nWant to add entry of the another Employee(Y/N): ");
                                                                                fflush(stdin);
                                                                                more=getche();
                                                                }
                                                }
                                                                break;

/* MODIFICATION OF EXISTING RECORDS */

                                                case '2':
                                                                clrscr();
                                                                more='Y';
                                                                while(more=='Y'||more=='y')
                                                                {
                                                                                printf("\nEnter the UID of the patient to modify: ");
                                                                                scanf("%s",id);
                                                                                rewind(fs);
                                                                                while(fread(&s,recsize1,1,fs)==1)
                                                                                {
                                                                                                if(strcmp(s.uid,id)==0)
                                                                                                {
                                                                                                                fflush(stdin);
printf("\nEnter the new name of the Employee: ");
                                                                                                                gets(s.name);

                                                                                                                fflush(stdin);
printf("\nEnter the new name of the Guardian: ");
                                                                                                                gets(s.fname);

                                                                                                                fflush(stdin);
printf("\nEnter the new Blood group of the Employee: ");
                                                                                                                scanf("%s",s.bg);
printf("\nEnter the new age of the Employee: ");
                                                                                                                scanf("%d",&s.age);
printf("\nEnter the new Salary of the Employee: ");
                                                                                                                scanf("%lf",&s.salary);
printf("\nEnter the new address of the Employee:\n");
                                                                                                                printf("\n\tEnter the house number: ");
                                                                                                                scanf("%d",&s.b.hno);
                                                                                                                fflush(stdin);
                                                                                                                printf("\n\tEnter the street/colony: ");
                                                                                                                scanf("%s",s.b.street);
                                                                                                                printf("\n\tEnter the city: ");
                                                                                                                fflush(stdin);
                                                                                                                scanf("%s",s.b.city);
                                                                                                                printf("\n\tEnter the state: ");
                                                                                                                fflush(stdin);
                                                                                                                scanf("%s",s.b.state);
printf("\nEnter the new phone number of the Employee: ");                fflush(stdin);
                                                                                                                scanf("%s",s.ph);
                                                                                                                fseek(fs,-recsize1,SEEK_CUR);
                                                                                                                fwrite(&s,recsize1,1,fs);
                                                                                                                break;
                                                                                                }
                                                                                }
                                                                                 printf("\n----------------------------------------------------");
                                                                                 printf("\nModify another Record(Y/N): ");
                                                                                 fflush(stdin);
                                                                                 more=getche();
                                                                }
                                                                break;

/*SEARCHING A PARTICULAR ENTRY BY NAME*/

                                                case '3':
                                                clrscr();
                                                                more='Y';
                                                                while(more=='Y'||more=='y')
                                                                {
                                                                                printf("\nEnter name to search: ");
                                                                                gets(s_name);
                                                                                rewind(fs);
                                                                                while(fread(&s,recsize1,1,fs)==1)
                                                                                {
                                                                                                if(strcmp(s.name,s_name)==0)
                                                                                                {
                                                                                                                printf("\nUID of the Employee : ");
                                                                                                                puts(s.uid);
                                                                                                                printf("\nName of the Employee : ");
                                                                                                                puts(s.name);
                                                                                                                printf("\nName of the Guardian : ");
                                                                                                                puts(s.fname);
                                                                                                                printf("\nAge : %d",s.age);
                                                                                                                printf("\nSalary: %lf",s.salary);
                                                                                                                printf("\nGender : %c",s.gender);
                                                                                                                printf("\nBlood Group : ");
                                                                                                                puts(s.bg);
printf("\nAddress  : %d,%s,%s,%s",s.b.hno,s.b.street,s.b.city,s.b.state);
                                                                                                                printf("\nphone number : +91-%s",s.ph);
                                                                                                                printf("\nDesignation : %s",s.desig);
                                                                                                }
                                                                                }
                                                                 printf("\n----------------------------------------------------");
                                                                 printf("\nSearch another Entry(Y/N): ");
                                                                 fflush(stdin);
                                                                 more=getche();
                                                                }
                                                                break;

/* LISTING OF ALL RECORDS */

                                                case '4':
                                                                clrscr();
                                                                rewind(fs);
                                                                while(fread(&s,recsize1,1,fs)==1)
                                                                {
                                                                                printf("\nUID of the Employee : ");
                                                                                puts(s.uid);
                                                                                printf("\nName of the Employee : ");
                                                                                puts(s.name);
                                                                                printf("\nName of the Guardian : ");
                                                                                puts(s.fname);
                                                                                printf("\nAge : %d",s.age);
                                                                                printf("\nSalary: %lf",s.salary);
                                                                                printf("\nGender : %c",s.gender);
                                                                                printf("\nBlood Group : ");
                                                                                puts(s.bg);
printf("\nAddress  : %d,%s,%s,%s",s.b.hno,s.b.street,s.b.city,s.b.state);
                                                                                printf("\nphone number : +91-%s",s.ph);
                                                                                printf("\nDesignation : %s",s.desig);

                                                                                printf("\n----------------------------------------------------\n");

                                                                }
                                                                getch();
                                                                break;

/* DELETION OF RECORD */

                                case '5':
                                clrscr();
                                more='Y';
                                                                while(more=='Y'||more=='y')
                                                                {
                                                                                printf("\nEnter the UID of the Employee to be deleted: ");
                                                                                scanf("%s",id);
                                                                                fx=fopen("tem.DAT","wb+");
                                                                                rewind(fs);
                                                                                while(fread(&s,recsize1,1,fs)==1)
                                                                                {
                                                                                                if(strcmp(s.uid,id)!=0)
                                                                                                fwrite(&s,recsize1,1,fx);
                                                                                                else
printf("\nThe Record has been Deleted Successfully.");
                                                                                }

                                                                                fclose(fs);
                                                                                fclose(fx);
                                                                                remove("emp.DAT");
                                                                                rename("tem.DAT","emp.DAT");
                                                                                fs=fopen("emp.DAT","rb+");
                                                                                printf("\nDelete another record?(Y/N): ");
                                                                                fflush(stdin);
                                                                                more=getche();
                                                                }


                case '6':
                                {
                                fclose(fs);
                                clrscr();
                                menu();
                                }
                                break;
                  }
                }
}

/*           MODULE 4          */
/* INVENTORY */

void inv()
{
                FILE *fi,*fy;
                char a,m;
                char i_name[40];
                int iF=0,j=1;
                long int recsize2;
                struct inventory v;

                fi=fopen("inv.DAT","rb+");
                if(fi==NULL)
                {
                                fi=fopen("inv.DAT","wb+");
                                if(fi==NULL)
                                {
                                                puts("\nSorry!! Cannot open file");
                                                exit(1);
                                }
                }
                recsize2=sizeof(v);
                while(1)
                {
                                clrscr();

/* DISPLAY OF OPTIONS */

                                scrhd();
                                printf("\n\t\t\t*INVENTORY*\n");
                                printf("\n\t\t[1] Add an Entry for Item");
                                printf("\n\t\t[2] Modify Existing Entry");
                                printf("\n\t\t[3] Search an Entry");
                                printf("\n\t\t[4] Listing of all Entries");
                                printf("\n\t\t[5] Delete an Entry");
                                printf("\n\t\t[6] Main Menu");
                                printf("\n\n\t\t>>>>Enter your choice here: ");
                                fflush(stdin);
                                m=getche();

                                switch(m)
                                {

/* ADDITION OF RECORDS */

                                                case '1':
                                                                clrscr();
                                                                fseek(fi,0,SEEK_END);
                                                                a='Y';
                                                                while(a=='Y'||a=='y')
                                                                {
                                                                x:
                                                                printf("\n\n\nEnter the Name of the Item: ");
                                                                scanf("%s",i_name);
                                                                rewind(fi);

/* CHECKING FOR UNIQUENESS OF NAME */

                                                                while(fread(&v,recsize2,1,fi)==1)
                                                                {

                                                                                if(strcmp(v.name,i_name)==0)
                                                                                {
                                                                                                iF=1;
printf("\n\t\tTHIS ITEM ALREADY EXISTS. ENTER ANOTHER ONE");
                                                                                                goto x;
                                                                                }
                                                                }
                                                                if(iF==0||fread(&v,recsize2,1,fi)==0)
                                                                {
                                                                                fseek (fi,0,SEEK_END);
                                                                                strcpy(v.name,i_name);
                                                                                fflush(stdin);
                                                                                printf("\nEnter the Date of purchase: ");
                                                                                scanf("%s",v.dop);
                                                                                printf("\nEnter the Quantity of the Item: ");
                                                                                scanf("%d",&v.qnty);
                                                                                printf("\nEnter the price of One Item: ");
                                                                                scanf("%f",&v.price);
                                                                                v.amount=v.qnty*v.price;
printf("\nThe amount of %d %s is = %f",v.qnty,v.name,v.amount);
                                                                                fwrite(&v,recsize2,1,fi);
                                                                                printf("\n----------------------------------------------------");
                                                                                printf("\nWant to add entry of the another Item(Y/N): ");
                                                                                fflush(stdin);
                                                                                a=getche();
                                                                }
                                                }
                                                break;

/* MODIFICATION OF EXISTING RECORDS */

                                                case '2':
                                                                clrscr();
                                                                a='Y';
                                                                while(a=='Y'||a=='y')
                                                                {
                                                                                printf("\nEnter the name of the item to modify: ");
                                                                                scanf("%s",i_name);
                                                                                rewind(fi);
                                                                                while(fread(&v,recsize2,1,fi)==1)
                                                                                {
                                                                                                if(strcmp(v.name,i_name)==0)
                                                                                                {
                                                                                                                fflush(stdin);
printf("\nEnter the new name of the Item: ");
                                                                                                                gets(v.name);
printf("\nEnter the new Date of purchase: ");
                                                                                                                scanf("%s",v.dop);
printf("\nEnter the new Quantity of the Item: ");
                                                                                                                scanf("%d",&v.qnty);
printf("\nEnter the new price of One Item: ");
                                                                                                                scanf("%f",&v.price);
                                                                                                                v.amount=v.qnty*v.price;
printf("\nThe new amount of %d %s is = %f",v.qnty,v.name,v.amount);

                                                                                                                fseek(fi,-recsize2,SEEK_CUR);
                                                                                                                fwrite(&v,recsize2,1,fi);
                                                                                                                break;
                                                                                                }
                                                                                }
                                                                                 printf("\n----------------------------------------------------");
                                                                                 printf("\nModify another Record(Y/N): ");
                                                                                 fflush(stdin);
                                                                                 a=getche();
                                                                }
                                                                break;

/*SEARCHING A PARTICULAR ENTRY BY NAME*/

                                                case '3':
                                                clrscr();
                                                                a='Y';
                                                                while(a=='Y'||a=='y')
                                                                {
                                                                                printf("\nEnter name of item to search: ");
                                                                                gets(i_name);
                                                                                rewind(fi);
                                                                                while(fread(&v,recsize2,1,fi)==1)
                                                                                {
                                                                                                if(strcmp(v.name,i_name)==0)
                                                                                                {
                                                                                                                printf("\nThe Name of the Item: ");
                                                                                                                puts(v.name);
printf("\nEnter the Date of purchase: %s",v.dop);
                                                                                                                printf("\nQuantity of the Item: %d",v.qnty);
                                                                                                                printf("\nPrice of One Item: %f",v.price);
                                                                                                                v.amount=v.qnty*v.price;
printf("\nThe amount of %d %s is = %f",v.qnty,v.name,v.amount);
                                                                                                }
                                                                                }
                                                                 printf("\n----------------------------------------------------");
                                                                 printf("\nSearch another Entry(Y/N): ");
                                                                 fflush(stdin);
                                                                 a=getche();
                                                                }
                                                                break;

/* LISTING OF ALL RECORDS */

                                                case '4':
                                                                clrscr();
                                                                printf("S.No.\t ITEM\t DOP\t\t QUANTITY\t PRICE\t\t AMOUNT\n");
printf("-----------------------------------------------------------------------------\n");
                                                                rewind(fi);
                                                                while(fread(&v,recsize2,1,fi)==1)
                                                                {
printf("%d\t %s\t %s\t %d\t\t Rs.%f\t Rs.%f\n",j,v.name,v.dop,v.qnty,v.price,v.amount);
                                                                                j++;
                                                                }
                                                                getch();
                                                                break;

/* DELETION OF RECORD */

                                case '5':
                                clrscr();
                                a='Y';
                                                                while(a=='Y'||a=='y')
                                                                {
                                                                                printf("\nEnter the name of the Item to be deleted: ");
                                                                                scanf("%s",i_name);
                                                                                fy=fopen("temporary.DAT","wb+");
                                                                                rewind(fi);
                                                                                while(fread(&v,recsize2,1,fi)==1)
                                                                                {
                                                                                                if(strcmp(v.name,i_name)!=0)
                                                                                                fwrite(&v,recsize2,1,fy);
                                                                                                else
printf("\nThe Record has been Deleted Successfully.");
                                                                                }

                                                                                fclose(fi);
                                                                                fclose(fy);
                                                                                remove("inv.DAT");
                                                                                rename("temporary.DAT","inv.DAT");
                                                                                fi=fopen("inv.DAT","rb+");
                                                                                printf("\nDelete another record?(Y/N): ");
                                                                                fflush(stdin);
                                                                                a=getche();
                                                                }


                case '6':
                                {
                                fclose(fi);
                                clrscr();
                                menu();
                                }
                                break;
                  }
                }
}

/* MODULE 5 */
/* ABOUT THE PROGRAM */

void about()
{
                char n;
                clrscr();
                gotoxy(10,3);
                printf("####This program is developed to maintain records of Patients,Doctors");
                gotoxy(10,4);
                printf("Employees and Inventory items in a hospital.");
                gotoxy(10,7);
                printf("####Developed  By:");
                gotoxy(10,8);
                printf("TANZIN AHAMMAD\n\n");
                printf("\t\t>>>>Press any key: ");
                n=getche();
                clrscr();
                menu();
}

/* END OF THE PROGRAM */
