#include "file_utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

/************************************************************************
 * This function implements the opening and closing of a file by 
 * dynamically allocating memory. If the file does not exist or if 
 * enough memory is not allocated, then it results in 
 * an error. 
 *
 * @author Isfar Baset
 * @version September 19, 2018
 ************************************************************************/
int read_file(char* filename, char **buffer) {
  
  // Opening the file
  FILE* fin;
  fin = fopen(filename, "r");

 
  // Obtaining size of the file
  struct stat st;
  stat(filename, &st);
  int size = st.st_size;
  
  // Dynamically allocating memory for the file 
  *buffer = (char*) malloc(size * sizeof(char));
  
 // Checking if file exists 
  if(fin){ 

  fread(*buffer, size, 1, fin);
  }

 // Error handling dynamic allocation of memory
 // This was discussed with Maazen Ashgar
 // If enough memory was not allocated, an error message is generated
 // an the program is exited  
 else if(buffer == NULL){
  fprintf(stderr, "OUT OF MEMORY.\n");
  exit(1);
  }
 
 // If file does not exist, show error message and close program
 else{
  fprintf( stderr, "FILE DOES NOT EXIST.\n" );
  exit(EXIT_FAILURE);
  }

  // Closing the file
  fclose(fin);

  // Returning the size of the file 
  return size;
 }

int write_file(char* filename, char* buffer, int size) {
  
  // Creating a file    
  FILE* fout;
  fout = fopen(filename, "w");

  // The new file will contain the information stored in buffer 
  fwrite(buffer, (size + 1) , 1, fout);
      
  // Close the file
  fclose(fout);
      
  return 0;
 }