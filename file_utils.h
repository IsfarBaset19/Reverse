#ifndef HEADER_FILE
#define HEADER_FILE
/************************************************************************
 * This file contains the function signatures and include guards
 *
 * @author Isfar Baset
 * @version Semptember 19, 2018
 ************************************************************************/
      int read_file(char* filename, char **buffer);
      
      int write_file(char* filename, char *buffer, int size);
 #endif