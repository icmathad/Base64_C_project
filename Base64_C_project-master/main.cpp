#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
//#include "cassandra.h"
//#include "../headers/other.h"
#include "C:/Users/staff/Desktop/base64.h"
size_t fileLen;

//void ReadFile(const char *name)
int main()
{
  FILE *file;
  unsigned char *buffer;
  char *lobi;
	char *name ="C:/Users/staff/Desktop/lion.jpg";
  //Open file                                                                                                                                                                                                
  file = fopen(name , "rb");
  if (!file)
    {
      fprintf(stderr, "Unable to open file %s", name);
      return -1;
    }

  //Get file length                                                                                                                                                                                          
  fseek(file, 0, SEEK_END);
  fileLen=ftell(file);
  fseek(file, 0, SEEK_SET);

  //Allocate memory                                                                                                                                                                                          
 buffer=(unsigned char *)malloc(fileLen+1);
  if (!buffer)
    {
      fprintf(stderr, "Memory error!");
      fclose(file);
      return -1;
    }

  //Read file contents into buffer                                                                                                                                                                           
  fread(buffer, fileLen, 1, file);
  size_t output_length = 0; // note *NOT* a pointer
  lobi = base64_encode(buffer, fileLen, output_length); // note address-of operator
  printf("%s\n", lobi);
  fclose(file);
  //insert_blob(buffer);
  //free(buffer);
}
