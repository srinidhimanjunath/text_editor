#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#define LSIZ 128
#define RSIZ 10
int i,j,ec,fg,ec2;
char cap[100];
char fn[20],e,c;
FILE *fp1,*fp2,*fp;
void Create();
void Append();
void Delete();
void Display();
int main()
{
 do {
  printf("\n\t\t***** TEXT EDITOR *****");
  printf("\n\n\tMENU:\n\t-----\n ");
  printf("\n\t1.CREATE\n\t2.DISPLAY\n\t3.APPEND\n\t4.DELETE\n\t5.Capitalize\n\t6.Copy\n\t7.Exit\n\t");
  printf("\n\tEnter your choice: ");
  scanf("%d",&ec);
  switch(ec)
  {
   case 1:
     Create();
     break;
   case 2:
     Display();
     break;
   case 3:
     Append();
     break;
   case 4:
     Delete();
     break;
   case 5:
     //to_array();

     //printf("%s",cap);
     Capitalize();
     break;
   case 6:
       copy();
       break;

   case 7:
     exit(0);
  }
 }while(1);
 return 0;
}
void Create()
{
 fp1=fopen("temp.txt","w");
 printf("\n\tEnter the text and press '.' to save\n\n\t");
 while(1)
 {
  c=getchar();
  fputc(c,fp1);
  if(c == '.')
  {
   fclose(fp1);
   printf("\n\tEnter then new filename: ");
   scanf("%s",fn);
   fp1=fopen("temp.txt","r");
   fp2=fopen(fn,"w");
   while(!feof(fp1))
   {
    c=getc(fp1);
    putc(c,fp2);
   }
   fclose(fp2);
   break;
  }}
}
void Display()
{
  printf("\n\tEnter the file name: ");
  scanf("%s",fn);
  fp1=fopen(fn,"r");
  if(fp1==NULL)
  {
   printf("\n\tFile not found!");
   goto end1;
  }
  while(!feof(fp1))
  {
   c=getc(fp1);
   printf("%c",c);
  }
end1:
  fclose(fp1);
  printf("\n\n\tPress any key to continue...");
  getch();
}
void Delete()
{
  printf("\n\tEnter the file name: ");
  scanf("%s",fn);
  fp1=fopen(fn,"r");
  if(fp1==NULL)
  {
   printf("\n\tFile not found!");
   goto end2;
  }
  fclose(fp1);
  if(remove(fn)==0)
  {
   printf("\n\n\tFile has been deleted successfully!");
   goto end2;
  }
  else
   printf("\n\tError!\n");
end2: printf("\n\n\tPress any key to continue...");
  getch();
}
void Append()
{
  printf("\n\tEnter the file name: ");
  scanf("%s",fn);
  fp1=fopen(fn,"r");
  if(fp1==NULL)
  {
   printf("\n\tFile not found!");
   goto end3;
  }
  while(!feof(fp1))
  {
   c=getc(fp1);
   printf("%c",c);
  }
  fclose(fp1);
  printf("\n\tType the text and press 'Ctrl+S' to append.\n");
  fp1=fopen(fn,"a");
  while(1)
  {
   c=getch();
   if(c==19)
    goto end3;
   if(c==13)
   {
    c='\n';
    printf("\n\t");
    fputc(c,fp1);
   }
   else
   {
    printf("%c",c);
    fputc(c,fp1);
   }
  }
end3: fclose(fp1);
  getch();
}

void to_array(){
    char line[RSIZ][LSIZ];
	char fname[20];
    FILE *fptr = NULL;
    int i = 0;
    int tot = 0;
    printf("\n\n Read the file and store the lines into an array :\n");
	printf("------------------------------------------------------\n");
	printf(" Input the filename to be opened : ");
	scanf("%s",fname);

    fptr = fopen(fname, "r");
    while(fgets(line[i], LSIZ, fptr))
	{
        line[i][strlen(line[i])] = '\0';
        i++;
    }
    tot = i;
	printf("\n The content of the file %s  are : \n",fname);
    for(i = 0; i < tot; ++i)
    {
        printf(" %s\n", line[i]);
    }
     printf("\n");
    return 0;
}
void copy(){
   char ch, source_file[20], target_file[20];
   FILE *source, *target;

   printf("Enter name of file to copy\n");
   scanf("%s",source_file);

   source = fopen(source_file, "r");

   if (source == NULL)
   {
      printf("Press any key to exit...\n");
      exit(EXIT_FAILURE);
   }

   printf("Enter name of target file\n");
   scanf("%s",target_file);

   target = fopen(target_file, "w");

   if (target == NULL)
   {
      fclose(source);
      printf("Press any key to exit...\n");
      exit(EXIT_FAILURE);
   }

   while ((ch = fgetc(source)) != EOF)
      fputc(ch, target);

   printf("File copied successfully.\n");

   fclose(source);
   fclose(target);

   return 0;

}

void Capitalize(){
         FILE*f1;
        // char arr_1[100];
         //int i=1;
         char ch,fname[20],d;
         f1=fopen(fname,"w");
         printf("\nEnter File Name :");
         scanf("%s",& fname);
         f1=fopen(fname,"r");
         if(f1==NULL)
            {
                  printf("File can't be Opened");
                  exit(0);
             }
                  while(ch!=EOF)
                         {
                               d=toupper(ch);
                               printf("%c",d);
                               ch=fgetc(f1);
                         }
           //                printf("%s",arr_1);
                              fclose(f1);
                              getch();


}


