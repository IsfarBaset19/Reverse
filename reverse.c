 #include "file_utils.h"
 #include <stdlib.h>
 #include <stdio.h>
 #include <sys/stat.h>

/************************************************************************
 * Here the contents of the given file are reversed and stored in a 
 * new file
 *
 * @author Isfar Baset
 * @version September 19, 2018
 ************************************************************************/
 int main(int argc, char** argv) {
      
  /** This pointer of type char holds the contents of the given file */
  char* buffer;
  
  /** Size of the input file */
  int sizeoffile;

  // Reading the file opened by the user and storing the size of it 
  // argv[1] is the input file 
  sizeoffile = read_file(argv[1], &buffer);

  // Dynamic allocation of memory for the reversed file 
  char* ptr = malloc(sizeoffile * sizeof(char));
    
  // Error handling dynamic allocation of memory
  // This was discussed with Maazen Ashgar
  // If enough memory was not allocated, an error message is generated
  // and the program is exited   
  if (ptr == NULL) {
   
   fprintf(stderr, "Ran out of memory.\n");
   exit(1);
  
  }
      
  // Reverseing the contents of the file using a for loop
  for(int i = 0; i <= sizeoffile; i++){
   
   ptr[i] = buffer[sizeoffile - i - 1];
  
  }
   
  // A new file with the reversed content from the old file is made 
  // argv[2] is the output file      
   write_file(argv[2], ptr, sizeoffile);

   return 0;
 }     