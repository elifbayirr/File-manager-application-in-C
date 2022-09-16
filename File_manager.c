#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000      //for append_text function
#define LINE_LEN 200  //for pause function

void create_new_file(); //function prototypes
void delete_file();
void rename_file();
void copy_file();
void carry_file();
void append_text();
void insert();
void remove_all_text();
void pause();

int main()
{
   char command[20];  //for the string we get from the user
        //commands, what can be done in the program and information, etc.
	    printf("\n===========================================================\n");
		printf("~  WELCOME TO 'isu_filemanager' FILE MANAGER APPLICATION  ~\n");
		printf("===========================================================\n\n");
		printf("Commands you can use to get information\n");
		printf("----------------------------------------\n");
		printf("● help\n● create/h\n● delete/h\n● rename/h\n● copy/h\n● carry/h\n● append/h\n● remove/h\n● pause/h\n");
		printf("If you already know our app or don't want to get help;\n--> create , delete , rename , copy , carry , append , remove, pause\n\n");
		printf("Type exit to exit the application !\n\n");
		
        while(1){
        //we are using loop because we want our user to be able to do an action again after doing an action    
        
		printf("Enter the command you want to use:\n");
		scanf("%s",command);
		    //We created this place to provide general help when the user types "help".
		    if (strcmp(command, "help")==0){
		        printf("\n● Create a new file ---> for help create/h\n");
		        printf("● Delete an existing file ---> for help delete/h\n");
		        printf("● Rename an existing file ---> for help rename/h\n");
		        printf("● Copy a file ---> for help copy/h\n");
		        printf("● Move a file from one folder to another ---> for help carry/h\n");
		        printf("● For append text to the end of a file ---> for help append/h\n");
		        printf("● For remove all text to the a file ---> for help remove/h\n\n");
		    }
		    //"command_name/h" should be used to get help. For the operation you want to do, it is sufficient to enter the command_name.
            else if(strcmp(command,"create/h")==0){
                printf("\nThe create command allows you to create a new file.\n");
                printf("When you run the create command, it will ask you for a name for the new file you will create.");
                printf("After you name it, your file with the name you gave will be created.\n");
                printf("Write create for create a new file.\n\n");
            }
            else if(strcmp(command,"create")==0){
                create_new_file();
            }
            else if(strcmp(command,"delete/h")==0){
               printf("\nThe delete command will allow you to delete an existing file.\n");
               printf("When you run your delete command, it will ask you for the name of the file you want to delete.\n");
               printf("You must want to delete an existing file. If a file does not exist, you cannot delete it \n");
               printf("Write delete for delete an existing file.\n\n");
            }
             else if(strcmp(command,"delete")==0){
                delete_file();
            }
            else if(strcmp(command,"rename/h")==0){
                printf("\nThe rename command is there to rename the existing file \nWhen you start the rename command,");
                printf("you must first enter the name of your old file, that is, the file you want to rename.\n");
                printf("Then you have to enter the new name you want that file to have.\n");
                printf("Write rename for rename an existing file.\n\n");
            }
             else if(strcmp(command,"rename")==0){
                rename_file();
            }
            else if(strcmp(command,"copy/h")==0){
                printf("\nThe copy command is a command that allows you to copy your files.\n");
                printf("When we start the program with the copy command, we must first enter the name of the file we want to copy.\n");
                printf("Then we have to enter it on which file we want to copy it or with which file name we want it to be.\n");
                printf("Write copy for copy a file.\n\n");
            }
            else if(strcmp(command,"copy")==0){
                copy_file();
            }
            else if(strcmp(command,"carry/h")==0){
                printf("\nThe carry command is a command that allows you to move your files from one folder to another.\n");
                printf("Write carry for move a file from one folder to another.\n\n");
            }
            else if(strcmp(command,"carry")==0){
                carry_file();
            }
            else if(strcmp(command,"append/h")==0){
                printf("\nThe append command allows you to append text to the end of your file.\n");
                printf("When you run your append command it will ask for the name of the file you want to append text to.\n");
                printf("After you enter the name of your file, it will ask you for the text you want to append.\n");
                printf("Write append for append text to the end of a file.\n\n");
            }
            else if(strcmp(command,"append")==0){
                append_text();
            }
            else if((strcmp(command,"insert/h")==0)){
                printf("\nThis function will allow you to add text after the desired file, the desired character number.\n");
                printf("First of all, it will ask for the name of the file you want to add.\n");
                printf("Secondly, it will ask you which character number of the text you want to add after the number.\n");
                printf("Write insert for insert text to a specific position of a file.\n\n");
            }
            else if((strcmp(command,"insert")==0)){
                insert();
            }
            else if(strcmp(command,"remove/h")==0){
                printf("\nThe remove command allows you to remove all the text inside your file.\n"); 
                printf("When you run your remove command, it asks for the name of the file in which you want to remove all the text.\n");
                printf("Write remove to remove all the text inside an existing file.\n\n");
            }
            else if(strcmp(command,"remove")==0){
                remove_all_text();
            }
            else if(strcmp(command,"pause/h")==0){
                printf("\nThe pause command ensures that all the text in your file is written by line number.\n");
                printf("It allows us to see the data content, that is, the text, together with the line number at the beginning of the page.\n");
                printf("Write pause to see the data content of a file line by line.\n\n");
            }
            else if(strcmp(command,"pause")==0){
                pause();
            }
            else if(strcmp(command,"exit")==0){ //The part where your loop ends, that is, it allows the user to exit the program by typing "exit".
                break; //breaking the cycle
            }
            else{
                //The part where we warn the user when a command is entered other than the commands that the user has specified
                printf("\nYou entered the wrong command please get help using the help command !\n\n");
            }
		}
}

void create_new_file(){
    
    FILE* fp; //FILE for this file returns a pointer to the file stream.
    char fname[20];
    
    printf("Enter the name of the file you want to create :\n");
    scanf("%s",fname); //We get characters for the file with the name the user wants to create.
    printf("\n");
    
    fp=fopen(fname,"w");  //"w" meaning create file to write
    
    if(fp==0){ // In case "fopen()" fails.
        printf("Sorry, your file cannot be created..\n");
    }
    else{
        printf("File has been created.\n\n");
    }
}

void delete_file(){
    
    int f;
    char file[20];
    
    printf("Enter the name of the existing file you want to delete:\n");
    scanf("%s",file); //// get the name of the file to be removed
    printf("\n");
    
    f=remove(file); //deletes the given filename so that it is no longer accessible.
    
    if(f==0){ //the state it succeeds in is "fp" is now null
        printf("%s file has been successfully deleted.\n\n",file);
    }
    else{ //failure
        printf("Your file cannot be deleted.\n");
        perror("Error"); //We put it to let the user know what the problem is.Like no file with that name or the user does not have access to that file .
    }
}

void rename_file(){
    
    char old_name[20]; 
    char new_name[20];

    printf("Enter old file name:");
    scanf("%s",old_name);   //get the name of the file you want to rename

    printf("Enter new file name:");
    scanf("%s",new_name);   //new name for the file

    if(rename(old_name,new_name)==0){ //rename() is changes the name of a file.
        printf("File renamed successfully.\n");
    }
    else{
        printf("Unable to rename files. Please check files exist and you have permissions to modify files.\n");
    }
}

void copy_file(){
    
   char ch;
   char source_file[20]; //the file you want to copy.
   char target_file[20]; //its copy
   FILE *source;
   FILE *target;

   printf("Enter name of file to copy\n");
   scanf("%s",source_file);
   
   source=fopen(source_file,"r"); //We open our source file in read mode (r).

   if(source==NULL){  //source_file is NULL
      printf("The file may not exist or is corrupt.\n");
      exit(0);
   }

   printf("Enter name of target file\n");
   scanf("%s",target_file);

   target=fopen(target_file,"w");  //Since it will be written here, we are looking for the copied things in write mode"w".

   if(target==NULL){ //target_file is NULL
      fclose(source);
      printf("Failed attempt.\n");
      exit(0);
   }
    
   //Reads a fluid character.
   while((ch=fgetc(source))!=EOF) // !=EOF means if not end of file (continue if not end of file)
        fputc(ch,target);
        //Writes to the stream indicated by the parameter and advances the stream position indicator to the next position
        // ch is the character value to write to the stream
        

   printf("File copied successfully.\n");
   //close the files after the process is finished
   fclose(source);
   fclose(target);
}

void carry_file(){
    
    size_t len = 0 ;
    char first_location[50]  ;
    char second_location[50] ;
    
    char buffer[BUFSIZ] = { '\0' } ;
    
    //we're getting a path to his file. attention is not the name
    printf("Enter the location where the file already exists (path) :  ");
    scanf("%s",first_location);   
    
    printf("Enter the location where you want the file to be found (path) :  ");
    scanf("%s",second_location);
    
                                                                // When we open a file with "rb" flag,
    FILE* in = fopen( first_location, "rb" ) ;                  //opens a binary system file for reading,file must exist.
    FILE* out = fopen( second_location, "wb" ) ;                // When we open a file with the "wb" flag,
                                                                // creates a binary system file for writing.
    if( in == NULL || out == NULL )                             
    {  //if one of the files is NULL
        perror( "An error occured while opening files!!!" ) ;  
        in = out = 0 ;
    }
    else    
    {
        while( (len = fread( buffer, BUFSIZ, 1, in)) > 0 )      // We used the fread/fwrite functions to 
        {                                                       // read/write data from/to the file opened by the fopen function.
            fwrite( buffer, BUFSIZ, 1, out ) ;                  //for us to move the file along with its contents
        }
        fclose(in) ;
        fclose(out) ;
        
        if(remove(first_location)){   //to delete it from our old location
            printf( "File successfully moved.\n" ) ;
        }
        else{
            printf( "  " ) ;
        }
    }    
}

void append_text(){
    
  FILE *source;
  int n;
  char text[MAX];
  char source_file[MAX];
  
	printf("\nEnter filename to append text at the end of the file:\n");
	scanf("%s",source_file);		
	
    source=fopen(source_file, "a");                                             // When we open a file with "a" flag,
    printf("Enter the text you want to append:\n");                             // opens a text file for appending
    scanf("%d", &n);                    
    // creates a new file if there is no file with that name
    if(source==NULL){
        printf("\nUnable to open '%s' file.\n", source_file);
        printf("Please check whether you have write privilege.\n");
        exit(0);
    }
    
    int i;
    for(i=0;i<n+1;i++){
    fgets(text,sizeof text,stdin);                                  // Reading the text char from the keyboard with the fgets() function
    fputs(text,source);                                             // The fputs() function writes the string denoted by "text" to the file denoted by "source".
    }
    fclose(source);
    
    //we display the inserted version of the text to the user
	source=fopen(source_file,"r");                                  // When we open a file with "r" flag,
	printf("Appended text to the file (%s) is:\n",source_file);     // opens a text file for reading, file must exist.
	char text1;                                                     
	text1=fgetc(source);
	while(text1!=EOF){
		printf("%c",text1);
		text1=fgetc(source);
	}
    printf("\n");
    fclose(source);
}

void insert (){
    
    char buffer[10];  //this is the message we added              
    fpos_t file_pos;    // the pointer to an fpos_t object for fgetpos func.                    
    int th_character; //the "int" value that holds which character to put in.
    FILE* fp; 
    char fname[20];  //for file name
    
    printf("Enter the name of the file you want to insert :\n");   
    scanf("%s",fname);             //we want the name of the file I want to add.
    
    fp = fopen(fname, "rb+" );     //Open a binary file for both reading and writing. (The file must exist.)  
    
    if(fp!=0){     //if "fb" does not become null.
        
         printf("After which character of your text do you want to add ? :\n");
         scanf("%d",&th_character);        //we get which character I want to add to the user's 
         printf("Enter you want to insert text\n");
         scanf("%s",buffer);         
         fseek(fp, (th_character), SEEK_SET );  //the information in any of the files can be read
         //the new location is from the beginning of the file for SEEK_SET
         fgetpos(fp, &file_pos );     
         //retrieves the active file location from the fp parameter value and writes it to the file_pos parameter variable
         fwrite(buffer,sizeof(buffer),1,fp);
         //buffer as many values as id1 in the size structure located in the memory indicated by the memory to the file indicated by fp
         //the 1 parameter determines how many data are written.
         fclose(fp);  
    }
   else 
       printf("Unfortunately, your file cannot be opened.\n");
}

void remove_all_text(){

    FILE *source;
    char source_file[20];
  
    printf("\nEnter the name of the file you want to remove all text from:\n"); //We can do this with fopen() "w" mode.
    scanf("%s",source_file);                                                    //When we open a file with the "w" flag,
    if((source=fopen(source_file,"w"))==NULL){                                  //it normally creates an empty file for writing.
      printf("\nUnable to open '%s' file.\n", source_file);                     //But if a file with the same name already exists,
      exit(0);                                                                  //its contents are deleted and the file becomes an empty file.
    }
    fclose(source);
}

void pause(){
    
    int line_num;                   // line counting
    char string[LINE_LEN];          // global variable 200 access
    FILE *fp;
    char source_file[20];
    
    printf("\nEnter the name of the file:\n"); 
    scanf("%s",source_file);
    
    if((fp=fopen(source_file,"r"))==NULL) {    //the file fails in read mode.
        printf("\nUnable to open '%s' file.\n",source_file);  
        exit(0);  
    }
    
    line_num =0;
    while(fgets(string,LINE_LEN,fp)!=NULL){    
        line_num++;
        printf("Line %d: %s", line_num,string);
        printf("\n");
    }
}
