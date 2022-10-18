#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void add_student_record();
void student_record();
void search_student_Record();
void delete_Student_Record();

struct student
{
    char first_name[20];
    char last_name[20];
    int roll_no;
    int class;
    char Course[20];
    char vill[20];
    float per;
};

int main()
{
    
    int choice;
    while(choice!=4)
    {   
        printf("\t\t\t=====STUDENT DATABASE MANAGEMENT SYSTEM=====");
        printf("\n\n\n\t\t\t\t     1. Add Student Record\n");
        printf("\t\t\t\t     2. Students Records\n");
        printf("\t\t\t\t     3. Search Student Record\n");
        printf("\t\t\t\t     4. Delete Student Record\n");
        printf("\t\t\t\t    _______\n");
        printf("\t\t\t\t     ");
        printf("Enter the choice what you want to perform : ");
        scanf("%d",&choice);
    
        switch(choice)
        {
            case 1:
                system("cls");
                add_student_record();
                system("cls");
                break;
            case 2: 
                system("cls");
                student_record();
                system("cls");
                break;
            case 3:
                system("cls");
                search_student_Record();
                system("cls");
                break;
            case 4:
                system("cls");
                delete_Student_Record();
                system("cls");
                break;
            default:
                system("cls");
                getch();
                printf("\n\t\t\t\t\tEnter a valid number\n\n");
                printf("\t\t\t\tPress any key to continue.......");
                getch();
                system("cls");
                break;
        }
  
    }
    getch();
}
void add_student_record()
{
    char another;
    FILE *fp;
    struct student info;
   do{
       system("cls");
       printf("\t\t\t\t=======Add Students Info=======\n\n\n"); 
       fp=fopen("information.txt","a"); 
       printf("\n\t\t\tEnter First Name     : ");
       scanf("%s",&info.first_name);
       printf("\n\t\t\tEnter Last Name     : ");
       scanf("%s",&info.last_name);
       printf("\n\t\t\tEnter Class  : ");
       scanf("%d",&info.class);
       printf("\n\t\t\tEnter Roll-No       : ");
       scanf("%d",&info.roll_no);
       printf("\n\t\t\tEnter Course : ");
       scanf("%s",&info.Course);
       printf("\n\t\t\tEnter Address(Village/City)   : ");
       scanf("%s",&info.vill);
       printf("\n\t\t\tEnter Percentage    : ");
       scanf("%f",&info.per);
       printf("\n\t\t\t____________\n");
       
      if(fp==NULL)
        {
            fprintf(stderr,"can't open file");
        }
      else
        {
            printf("\t\t\tRecord stored successfuly\n");
        }
    
        fwrite(&info, sizeof(struct student), 1, fp); 
        fclose(fp);
    
        printf("\t\t\tYou want to add another record?((y,Y)/(n,N)) : ");
        scanf("%s",&another);
    
    }while(another=='y'||another=='Y');
}

void student_record()
{
    FILE *fp;
    struct student info;
    fp=fopen("information.txt","r");
    
    printf("\t\t\t\t=======STUDENTS RECORD=======\n\n\n");
      
    if(fp==NULL)
    {    
        fprintf(stderr,"can't open file\n");
    }
    else
    {
        printf("\t\t\t\tRECORDS :\n");
        printf("\t\t\t\t_____\n\n");
    }
        
        while(fread(&info,sizeof(struct student),1,fp))
        {
            printf("\n\t\t\t\t Student Name  : %s %s",info.first_name,info.last_name);
            printf("\n\t\t\t\t Class         : %d",info.class);
            printf("\n\t\t\t\t Roll NO       : %d",info.roll_no);
            printf("\n\t\t\t\t Course        : %s",info.Course);
            printf("\n\t\t\t\t Village/City  : %s",info.vill);
            printf("\n\t\t\t\t Percentage    : %f",info.per);
            printf("\n\t\t\t\t ____________\n");
        }
        fclose(fp);
        printf("\t\t\tPress any key to go main menu : ");
        getch();
}

void search_student_Record()
{
    struct student info;
    FILE *fp;
    int class,roll_no,found=0;
     
    fp=fopen("information.txt","r");

    printf("\t\t\t\t=======SEARCH STUDENTS RECORD=======\n\n\n");
    printf("\t\t\tEnter tne Class in which He/She study : ");
    scanf("%d",&class);
    printf("\t\t\tEnter the roll no : ");
    scanf("%d",&roll_no);
     
    while(fread(&info,sizeof(struct student),1,fp)>0)
    {    if(info.class==class)
        {
            if(info.roll_no==roll_no)
            {
                found=1;
                printf("\n\n\t\t\tStudent Name : %s %s",info.first_name,info.last_name);
                printf("\n\t\t\tClass          : %d",info.class);
                printf("\n\t\t\tRoll NO        : %d",info.roll_no);
                printf("\n\t\t\tC0urse         : %s",info.Course);
                printf("\n\t\t\tAddress        : %s",info.vill);
                printf("\n\t\t\tPercentage     : %f",info.per);
                printf("\n\t\t\t______________\n");
            }
            }  
    }
     
    if(!found)
    {
       printf("\n\t\t\tRecord not found\n");
    }
  
    fclose(fp);
    printf("\t\t\tPress any key to go main menu : ");
    getch();    
}

void delete_Student_Record()
{
    struct student info;
    FILE *fp, *fp1;   
    int roll_no,found=0;

    int class;

    printf("\t\t\t\t=======DELETE STUDENTS RECORD=======\n\n\n");
    fp=fopen("information.txt","r");
    fp1=fopen("temp.txt","w");
    printf("\t\t\t\tEnter the Class  : ");
    scanf("%d",&class);
    printf("\t\t\t\tEnter the roll no : ");
    scanf("%d",&roll_no);
    if(fp==NULL)
      {
         fprintf(stderr,"There is not any file present\n");
         exit(0);
      }
    
    while(fread(&info,sizeof(struct student),1,fp))
    {
        if(info.class == class)
        {
            if(info.roll_no == roll_no)
            {
            found=1;
            }
        }
        else
        {
           fwrite(&info,sizeof(struct student),1,fp1);
        }
    }
     fclose(fp);
     fclose(fp1);

    if(!found)
    {
          printf("\n\t\t\t\tRecord not found\n");
    }
    if(found)
    { 
        remove("information.txt");
        rename("temp.txt","information.txt");    
        printf("\n\t\t\t\tRecord deleted succesfully\n");
    }
  printf("\t\t\tPress any key to go main menu : ");
  getch();
}