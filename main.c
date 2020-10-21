#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void create_new();
void ReadFile();
void Datetime();
void addNew();
void rnm_remove();
void fileSize();

struct file{
char Date[12];
char time[6];
};

FILE *fp;
char fname[25];
char ar[10000];

void Datetime( )
    {
        fflush(stdin);
        struct file f;
        printf("\n\t\t\t\tEnter Date:");
        gets(f.Date);
        printf("\n\t\t\t\tEnter Time:");
        gets(f.time);
        fprintf(fp,"\n%s  ",f.Date);
        fprintf(fp,"%s",f.time);
    }


void create_new( ){
     fflush(stdin);
     system("cls");
     system("color F0");
     printf("\n\n\t\t\t\t*********************************************");
    printf("\n\t\t\t\t\t\tCreate new File\n");
    printf("\n\t\t\t\t*********************************************");
            printf("\n\t\t\t\tEnter file name :");
            gets(fname);
            fp=fopen(fname,"w");

             if(fp==NULL)
                {
                    printf("\n\t\t\t\tFile failed to open");
                }
             else
                {
                  printf("\n\t\t\t\tThe file is now opened..........");
                 fflush(stdin);
        printf("\n\t\t\t\tEnter context to store in file!\n");
        printf("\n\t\t\t\t");
        gets(ar);
        Datetime();
        fprintf(fp,"\n%s\n",ar);
        fclose(fp);
        printf("\n\t\t\t\t\t\tPress any key to exit");
         return 0;
    }
}


void ReadFile(){
    system("cls");
    system("color F0");
     printf("\n\n\t\t\t\t*********************************************");
    printf("\n\t\t\t\t\t\tOpen an Existing file\n");
    printf("\n\t\t\t\t*********************************************");
     printf("\n\t\t\t\tEnter file name :");
                scanf("%s",fname);
                fp=fopen(fname,"r+");
              if(fp==NULL)
              {
                  printf("\n\t\t\t\tFile not found");
              }
              else{
                   while(fgets(ar,10000,fp)!=NULL)
                   {
                        printf("\n\t\t\t\t%s",ar);
                   }
              }
}


void addNew(){
    system("cls");
    system("color F0");
    printf("\n\n\t\t\t\t*********************************************");
    printf("\n\t\t\t\tAdd new data in an existing file\n");
    printf("\n\t\t\t\t*********************************************");
     printf("\n\t\t\t\tEnter file name :");
            scanf("%s",fname);
            fp=fopen(fname,"a+");
            if(fp==NULL)
            {
               printf("\n\t\t\t\tFile doesn't exist");
            }else{
                fflush(stdin);
                  printf("\n\t\t\t\tEnter Context here:");
                    gets(ar);
                    Datetime();
               fprintf(fp,"\n%s\n",ar);
                fclose(fp);
            }
}

void rnm_remove(){
    system("cls");
    system("color F0");
    printf("\n\n\t\t\t\t*********************************************");
    printf("\n\t\t\t\t\t\tRename and remove file\n");
    printf("\n\t\t\t\t*********************************************");
    printf("\n\n\t\t\t\t1. To rename file press 1\n");
            printf("\n\t\t\t\t2. To remove file press 2\n");
             int choice;
             printf("\n\t\t\t\tEnter choice :");
            scanf("%d",&choice);
            switch(choice)
            {
            case 1:
                 printf("\n\t\t\t\tFile name :");
                 scanf("%s",fname);
            int value;
            char new_name[25];
            printf("\n\t\t\t\tNew Name of file :");
            scanf("%s",new_name);
            value=rename(fname,new_name);
            if(!value)
                printf("\n\t\t\t\t%s","******File name changed successfully******\n");
            else
                perror("\n\t\t\t\tError");
                break;
            case 2:
                printf("\n\t\t\t\tFile name :");
            scanf("%s",fname);
            if(remove(fname)==0)
                printf("\n\t\t\t\t******Removed successfully******");
            else
                printf("\n\t\t\t\tUnable to delete file");
            }

}

void fileSize(){
    system("cls");
    system("color F0");
    printf("\n\n\t\t\t\t*********************************************");
    printf("\n\t\t\t\t\t\tFind size of file\n");
    printf("\n\t\t\t\t*********************************************");
     printf("\n\t\t\t\tEnter file name :");
            scanf("%s",fname);
            fp=fopen(fname,"r");
            if (fp == NULL) {
        printf("\n\t\t\t\tFile Not Found!\n");
    }
    else{
            fseek(fp, 0L, SEEK_END);
    long int res = ftell(fp);
    printf("\t\t\t\t%ld bytes",res);
    fclose(fp);
    }
}

int main()
{
    int num;
    printf("\n\n\t\t\t\t*********************************************");
    printf("\n\t\t\t\t\t\tFile handling\n");
    printf("\n\t\t\t\t*********************************************");
    printf("\n\t\t\t\t1. To create new file press 1\n");
    printf("\n\t\t\t\t2. To open an existing file to Read only press 2\n");
    printf("\n\t\t\t\t3. To open an existing file to Write only press 3\n");
    printf("\n\t\t\t\t4. To Rename and Remove file press 4\n");
    printf("\n\t\t\t\t5. To find the size of file press 5\n");
    printf("\n\t\t\t\t6. Exit press 6\n");
    printf("\n\t\t\t\tEnter your choice:");
    scanf("%d",&num);


    switch(num)
    {
        case 1:
           create_new();
           break;

        case 2:
            ReadFile();
              break;
        case 3:
           addNew();
            break;

        case 4:
            rnm_remove();
            break;

        case 5:
           fileSize();
            break;

        case 6:
            printf("\n\n\n\t\t\t\t\t****Thankyou for using****");
            exit(0);
 }
    return 0;
}
