#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Checklist
// open a file
// create our own version of strcpy that copies a line using the constraints of a compiler
//      remove spaces (isspace), stop at '//', make sure to zero out memory ( dest[i] = source[i]; )
//      use pointers rather than indexing arrays


char *parseAcommand(char *hackline, const char *src) {

// char array of length 16 (initiallizes the first line of command)
char newline[16];
newline[0] = '0';
// whatever number is given in binary just input binary number

}


char *parseCcommand(char *hackline, const char *src) {

    // begin the C command hack string
    char newline[16];
    newline[0] = '1';
    newline[1] = '1';
    newline[2] = '1';



    // for spaces 10, 11, and 12...if statements for the destinations (if there's no '=' then there's no destination)
        // when an = sign is spotted check the previous spaces for any of the destinations
    if (strstr(src, '=') != NULL) { // if it contains '='

    // check for the destination options and give the binary for each
}


    // for remaining spaces if there's no semi-colon then there's no jump
        // use if statements for that
    if (strstr(src, ';') != NULL) { // if it contains ';' 
    
}
    // newline[3] = anything compared to M is a 1 else 0
    // for spaces 4 - 9 go through each if statement in the comparisons section



}


char *strcpy_nospace(char *dest, const char *src) {

    int i = 0; // array index
    int j = 0;

    while(src[i] != '\0') {
        if (!isspace(src[i])) {
            dest[j] = src[i];
            j++;
        }
        i++;
    }
    
    dest[j] = '\0';
}


int main(int argc, char** argv)
{
if (argc < 3) {
        puts("Less than 3 arguments detected");
        puts("Usage: ./assembler input.asm output.hack");
        return 0;
}


  FILE * pFile;
  FILE * qFile;
  char mystring[100];
  char mystring2[100];

  pFile = fopen (argv[1] , "r");
  qFile = fopen (argv[2], "w");

  if (pFile == NULL) perror ("Error opening file");
  else { 
  while (fgets(mystring, 100, pFile) != NULL) {

      strcpy_nospace(mystring2, mystring);

        if (mystring2[0] == '@') {
            fputs("A_COMMAND\n", qFile);
        }
        if (mystring2[0] == '(') {
            fputs("L_COMMAND\n", qFile);
        }
        if (mystring2[0] == 'D' || mystring2[0] == 'A' || mystring2[0] == 'M' || mystring2[0] == '0'){
            fputs("C_COMMAND\n", qFile);
        }
    }
    fclose (pFile);
    fclose (qFile);

  } 
  return 0;
  // char c [100];
  // strcpy_nospace(c, "This is a string with spaces");
  // puts(c);

}

// int main() {
//     printf("Hello, World!");
//     return 0;
// }