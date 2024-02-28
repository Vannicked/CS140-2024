#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


// Checklist
// open a file
// create our own version of strcpy that copies a line using the constraints of a compiler
//      remove spaces (isspace), stop at '//', make sure to zero out memory ( dest[i] = source[i]; )
//      use pointers rather than indexing arrays


// cuts strings at equal sign
void cut_string_at_equal(const char *str, char *part1, char *part2) {
  const char *equal_sign = strchr(str, '=');

  // Check if there's an '=' sign
  if (equal_sign == NULL) {
    // No '=' found, copy the entire string to part1 and leave part2 empty
    strcpy(part1, str);
    part2[0] = '\0';
    return;
  }

  // Copy the part before the '=' sign (excluding the '=')
  strncpy(part1, str, equal_sign - str);
  part1[equal_sign - str] = '\0'; // Add null terminator

  // Copy the part after the '=' sign (including the '=')
  strcpy(part2, equal_sign);
}

void cut_string_at_semi(const char *str, char *part1, char *part2) {
  const char *semi_sign = strchr(str, ';');

  // Check if there's an '=' sign
  if (semi_sign == NULL) {
    // No '=' found, copy the entire string to part1 and leave part2 empty
    strcpy(part1, str);
    part2[0] = '\0';
    return;
  }

  // Copy the part before the '=' sign (excluding the '=')
  strncpy(part1, str, semi_sign - str);
  part1[semi_sign - str] = '\0'; // Add null terminator

  // Copy the part after the '=' sign (including the '=')
  strcpy(part2, semi_sign);
}



char *parseAcommand(char *hackline, const char *src) {

// char array of length 16 (initiallizes the first line of command)
char newline[16];
newline[0] = '0';
// whatever number is given in binary just input binary number

}


char *parseCcommand(char *hackline, const char *src) {

    // begin the C command hack string
    char newline[16];
    char dest[10];
    char jump[10];
    char extra[10];
    newline[0] = '1';
    newline[1] = '1';
    newline[2] = '1';


    // DESTINATIONS
    // for spaces 10, 11, and 12...if statements for the destinations (if there's no '=' then there's no destination)

    if (strstr(src, "=") != NULL) { // if it contains '='

        cut_string_at_equal(src, dest, extra);

        if (strstr(dest, 'M') != NULL) {// if M exists
        
            newline[12] = '1';
        
        }
        if (strstr(dest, 'A') != NULL) {// if A exists
        
            newline[10] = '1';
        
        }
        if (strstr(dest, 'D') != NULL) {// if D exists
        
            newline[11] = '1';
        
        }
    // check for the destination options and give the binary for each
        
}


    // for remaining spaces if there's no semi-colon then there's no jump
        // use if statements for that
    if (strstr(src, ';') != NULL) { // if it contains ';' 

        cut_string_at_semi(src, jump, extra);

        // COMPARISON (jump is the comparison)

        if (strstr(jump, 'M') != NULL) {
            newline[3] = '1';
            if (str(jump == 'M')) {
                newline[4] = '1';
                newline[5] = '1';
                newline[6] = '0';
                newline[7] = '0';
                newline[8] = '0';
                newline[9] = '0';
            }
            if (str(jump == "!M")) {
                newline[4] = '1';
                newline[5] = '1';
                newline[6] = '0';
                newline[7] = '0';
                newline[8] = '0';
                newline[9] = '1';
            }
            if (str(jump == "-M")) {
                newline[4] = '1';
                newline[5] = '1';
                newline[6] = '0';
                newline[7] = '0';
                newline[8] = '1';
                newline[9] = '1';
            }
            if (str(jump == "M+1")) {
                newline[4] = '1';
                newline[5] = '1';
                newline[6] = '0';
                newline[7] = '1';
                newline[8] = '1';
                newline[9] = '1';
            }
            if (str(jump == "M-1")) {
                newline[4] = '1';
                newline[5] = '1';
                newline[6] = '0';
                newline[7] = '0';
                newline[8] = '1';
                newline[9] = '0';
            }
            if (str(jump == "D+M")) {
                newline[4] = '0';
                newline[5] = '0';
                newline[6] = '0';
                newline[7] = '0';
                newline[8] = '1';
                newline[9] = '0';
            }
            if (str(jump == "D-M")) {
                newline[4] = '0';
                newline[5] = '1';
                newline[6] = '0';
                newline[7] = '0';
                newline[8] = '1';
                newline[9] = '1';
            }
            if (str(jump == "M-D")) {
                newline[4] = '0';
                newline[5] = '0';
                newline[6] = '0';
                newline[7] = '1';
                newline[8] = '1';
                newline[9] = '1';
            }
            if (str(jump == "D&M")) {
                newline[4] = '0';
                newline[5] = '0';
                newline[6] = '0';
                newline[7] = '0';
                newline[8] = '0';
                newline[9] = '0';
            }
            if (str(jump == "D|M")) {
                newline[4] = '0';
                newline[5] = '1';
                newline[6] = '0';
                newline[7] = '1';
                newline[8] = '0';
                newline[9] = '1';
            }
            
            }
        else {

            newline[3] = '0';

            if (str(jump == '0')) {
                newline[4] = '1';
                newline[5] = '0';
                newline[6] = '1';
                newline[7] = '0';
                newline[8] = '1';
                newline[9] = '0'; 
            }
            if (str(jump == '1')) {
                newline[4] = '1';
                newline[5] = '1';
                newline[6] = '1';
                newline[7] = '1';
                newline[8] = '1';
                newline[9] = '1';
            }
            if (str(jump == "-1")) {
                newline[4] = '1';
                newline[5] = '1';
                newline[6] = '1';
                newline[7] = '0';
                newline[8] = '1';
                newline[9] = '0';
            }
            if (str(jump == 'D')) {
                newline[4] = '0';
                newline[5] = '0';
                newline[6] = '1';
                newline[7] = '1';
                newline[8] = '0';
                newline[9] = '0';
            }
            if (str(jump == 'A')) {
                newline[4] = '1';
                newline[5] = '1';
                newline[6] = '0';
                newline[7] = '0';
                newline[8] = '0';
                newline[9] = '0';
            }
            if (str(jump == "!D")) {
                newline[4] = '0';
                newline[5] = '0';
                newline[6] = '1';
                newline[7] = '1';
                newline[8] = '1';
                newline[9] = '1';
            }
            if (str(jump == "!A")) {
                newline[4] = '1';
                newline[5] = '1';
                newline[6] = '0';
                newline[7] = '0';
                newline[8] = '1';
                newline[9] = '1';
            }
            if (str(jump == "D+1")) {
                newline[4] = '0';
                newline[5] = '1';
                newline[6] = '1';
                newline[7] = '1';
                newline[8] = '1';
                newline[9] = '1';
            }
            if (str(jump == "A+1")) {
                newline[4] = '1';
                newline[5] = '1';
                newline[6] = '0';
                newline[7] = '1';
                newline[8] = '1';
                newline[9] = '1';
            }
            if (str(jump == "D-1")) {
                newline[4] = '0';
                newline[5] = '0';
                newline[6] = '1';
                newline[7] = '1';
                newline[8] = '1';
                newline[9] = '0';
            }
            if (str(jump == "A-1")) {
                newline[4] = '1';
                newline[5] = '1';
                newline[6] = '0';
                newline[7] = '0';
                newline[8] = '1';
                newline[9] = '0';
            }
            if (str(jump == "D+A")) {
                newline[4] = '0';
                newline[5] = '0';
                newline[6] = '0';
                newline[7] = '0';
                newline[8] = '1';
                newline[9] = '0';
            }
            if (str(jump == "D-A")) {
                newline[4] = '0';
                newline[5] = '1';
                newline[6] = '0';
                newline[7] = '0';
                newline[8] = '1';
                newline[9] = '1';
            }
            if (str(jump == "A-D")) {
                newline[4] = '0';
                newline[5] = '0';
                newline[6] = '0';
                newline[7] = '1';
                newline[8] = '1';
                newline[9] = '1';
            }
            if (str(jump == "D&A")) {
                newline[4] = '0';
                newline[5] = '0';
                newline[6] = '0';
                newline[7] = '0';
                newline[8] = '0';
                newline[9] = '0';
            }
            if (str(jump == "D|A")) {
                newline[4] = '0';
                newline[5] = '1';
                newline[6] = '0';
                newline[7] = '1';
                newline[8] = '0';
                newline[9] = '1';
            }
        

        if (strstr(extra, "JGT") != NULL) {// if JGT exists (BUT MAJOR DIFFERECNE is that we take in what's after the split)
        
            newline[13] = '0';
            newline[14] = '0';
            newline[15] = '1';
        
        }
        if (strstr(extra, "JEQ") != NULL) {// if JGT exists (BUT MAJOR DIFFERECNE is that we take in what's after the split)
        
            newline[13] = '0';
            newline[14] = '1';
            newline[15] = '0';
        
        }if (strstr(extra, "JGE") != NULL) {// if JGT exists (BUT MAJOR DIFFERECNE is that we take in what's after the split)
        
            newline[13] = '0';
            newline[14] = '1';
            newline[15] = '1';
        
        }if (strstr(extra, "JLT") != NULL) {// if JGT exists (BUT MAJOR DIFFERECNE is that we take in what's after the split)
        
            newline[13] = '1';
            newline[14] = '0';
            newline[15] = '0';
        
        }if (strstr(extra, "JNE") != NULL) {// if JGT exists (BUT MAJOR DIFFERECNE is that we take in what's after the split)
        
            newline[13] = '1';
            newline[14] = '0';
            newline[15] = '1';
        
        }if (strstr(extra, "JLE") != NULL) {// if JGT exists (BUT MAJOR DIFFERECNE is that we take in what's after the split)
        
            newline[13] = '1';
            newline[14] = '1';
            newline[15] = '0';
        
        }if (strstr(extra, "JMP") != NULL) {// if JGT exists (BUT MAJOR DIFFERECNE is that we take in what's after the split)
        
            newline[13] = '1';
            newline[14] = '1';
            newline[15] = '1';
        
        } else {
            newline[13] = '0';
            newline[14] = '0';
            newline[15] = '0';
        }
    
}
    // newline[3] = anything compared to M is a 1 else 0
    // for spaces 4 - 9 go through each if statement in the comparisons section

    if (strstr(src, ';') != NULL)


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