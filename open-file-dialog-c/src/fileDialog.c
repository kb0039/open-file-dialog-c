#include <stdlib.h>
#include <stdio.h>
#define MAXSIZE 65535 


/**
 * Create a content path
 */

char fileData[MAXSIZE];

/**
 * Create a file path
 */

char filePath[];


/**
 * Main program  
 */
int main(){

 fileRead();

}


/**
 * Import *txt files and initialize fileData
 */
void fileRead(){


//Define inputFile

FILE *inputFile = popen("zenity --file-selection --file-filter=""*.txt"" ", "r");

//Catch inputFile error

if (inputFile  == NULL){

 perror("Input file is invalid. Please try again");
exit(0);

}

//Remove Null Character
fgets(filePath,MAXSIZE,inputFile);
char *p = filePath;
p[strlen(p)-1] = 0;
printf("%s", filePath);
pclose(inputFile);

//Define outputFile

FILE *outputFile = fopen(filePath, "r");

//Catch outputFile error
if (outputFile == NULL) {
perror("Output file is invalid. Please try again");
exit(0);
}


//Print fileData
while(fgets(fileData, sizeof(fileData) ,outputFile)){

     
      puts(fileData);

		
	} 
//Close the outputFile
fclose(outputFile);



}
