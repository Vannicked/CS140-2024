#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "map.h"

int memoryCounter = 16;

void string_splitter(const char *str, char *part1, char *part2, char search) {
    const char *index = strchr(str, search);
    // Copy the part before the search sign
    strncpy(part1, str, index - str);
    part1[index - str] = '\0'; // Add null terminator
    // Copy the part after the search sign
    strcpy(part2, index + 1);
}

void parse_L_command(const char *src, map symbolTable, int nextLine){
    char label[100];
    char buffer[100];
    char buffer2[10];
    char buffer3[10];
    string_splitter(src, buffer2, buffer, '(');
    string_splitter(buffer, label, buffer2, ')');
    sprintf(buffer3, "%d", nextLine);
    insertKey(symbolTable, label, buffer3);
}


void parse_A_command(const char *src, const map symbolTable, char *hackFinal) {
    // remove @ sign
    char assemblyLine[100];
    char buffer[10];
    string_splitter(src, buffer, assemblyLine, '@');
    int srcInt;
    // 0 or int
    if(atoi(assemblyLine) != 0 || assemblyLine[0] == '0'){
        srcInt = atoi (assemblyLine);
    }
    // label or symbol
    else if(containsKey(symbolTable, assemblyLine)>=0){
        srcInt = atoi (lookupKey(symbolTable, assemblyLine));
    }
    else{
        char buffer3[10];
        sprintf(buffer3, "%d", memoryCounter);
        insertKey(symbolTable, assemblyLine, buffer3);
        srcInt = memoryCounter;
        memoryCounter++;
    }

    char hackLine[17];
    int n = 15;
    hackLine[16] = '\0';
    hackLine[0]='0';
    while(n>0){
        hackLine[n] = '0';
        hackLine[n] = srcInt%2 + '0';
        srcInt = srcInt/2;
        n--;
    }
    strcpy(hackFinal, hackLine);
}

void parse_C_command(const char *src, const map compMap, const map jumpMap, char *hackFinal) {
    // always starts 111
    char hackLine[20];
    strcpy(hackLine, "111");
    char dest[10];
    char comp[10];
    char jump[10];
    // determine structure
    if(strstr(src, "=") != NULL){ // dest=comp
        // split dest and comp
        string_splitter(src, dest, comp, '=');
        // add comp bits
        strcat(hackLine, lookupKey(compMap, comp));
        // add dest bits
        if(strstr(dest, "A")){
            strcat(hackLine, "1");
        }
        else{
            strcat(hackLine, "0");
        }
        if(strstr(dest, "D")){
            strcat(hackLine, "1");
        }
        else{
            strcat(hackLine, "0");
        }
        if(strstr(dest, "M")){
            strcat(hackLine, "1");
        }
        else{
            strcat(hackLine, "0");
        }
        // add jump bits
        strcat(hackLine, "000");
    }
    else if(strstr(src, ";") != NULL){// comp;jmp
        // split comp and jump
        string_splitter(src, comp, jump, ';');
        // add comp bits
        strcat(hackLine, lookupKey(compMap, comp));
        //add dest bits
        strcat(hackLine,"000");
        //add jump bits
        strcat(hackLine, lookupKey(jumpMap, jump));
    }

    strcpy(hackFinal, hackLine);
}

void strcpy_nospace(char *dest, const char *src) {

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


int main(int argc, char** argv){
if (argc < 3) {
        puts("Less than 3 arguments detected");
        puts("Usage: ./assembler input.asm output.hack");
        return 0;
}
// building the comp map
map compMap = createMap(100);
insertKey(compMap, "0", "0101010");
insertKey(compMap, "1", "0111111");
insertKey(compMap, "-1", "0111010");
insertKey(compMap, "D", "0001100");
insertKey(compMap, "A", "0110000");
insertKey(compMap, "!D", "0001101");
insertKey(compMap, "!A", "0110001");
insertKey(compMap, "-D", "0001111");
insertKey(compMap, "-A", "0110011");
insertKey(compMap, "D+1", "0011111");
insertKey(compMap, "A+1", "0110111");
insertKey(compMap, "D-1", "0001110");
insertKey(compMap, "A-1", "0110010");
insertKey(compMap, "D+A", "0000010");
insertKey(compMap, "D-A", "0010011");
insertKey(compMap, "A-D", "0000111");
insertKey(compMap, "D&A", "0000000");
insertKey(compMap, "D|A", "0010101");
insertKey(compMap, "M", "1110000");
insertKey(compMap, "!M", "1110001");
insertKey(compMap, "-M", "1110011");
insertKey(compMap, "M+1", "1110111");
insertKey(compMap, "M-1", "1110010");
insertKey(compMap, "D+M", "1000010");
insertKey(compMap, "D-M", "1010011");
insertKey(compMap, "M-D", "1000111");
insertKey(compMap, "D&M", "1000000");
insertKey(compMap, "D|M", "1010101");

// building the jump map
map jumpMap = createMap(10);
insertKey(jumpMap,"JGT", "001");
insertKey(jumpMap,"JEQ", "010");
insertKey(jumpMap,"JGE", "011");
insertKey(jumpMap,"JLT", "100");
insertKey(jumpMap,"JNE", "101");
insertKey(jumpMap,"JLE", "110");
insertKey(jumpMap,"JMP", "111");
//building symbol table
map symbolTable = createMap(2000);
insertKey(symbolTable,"R0","0");
insertKey(symbolTable,"R1","1");
insertKey(symbolTable,"R2","2");
insertKey(symbolTable,"R3","3");
insertKey(symbolTable,"R4","4");
insertKey(symbolTable,"R5","5");
insertKey(symbolTable,"R6","6");
insertKey(symbolTable,"R7","7");
insertKey(symbolTable,"R8","8");
insertKey(symbolTable,"R9","9");
insertKey(symbolTable,"R10","10");
insertKey(symbolTable,"R11","11");
insertKey(symbolTable,"R12","12");
insertKey(symbolTable,"R13","13");
insertKey(symbolTable,"R14","14");
insertKey(symbolTable,"R15","15");
insertKey(symbolTable,"SP","0");
insertKey(symbolTable,"LCL","1");
insertKey(symbolTable,"ARG","2");
insertKey(symbolTable,"THIS","3");
insertKey(symbolTable,"THAT","4");
insertKey(symbolTable,"SCREEN","16384");
insertKey(symbolTable,"KBD","24576");

// declaring files, strings, line counter, memory counter
FILE * pFile;
FILE * qFile;
FILE * lFile;
char mystring[100];
char mystring2[100];
int lineCounter = 0;
char hackFinal[18];

pFile = fopen (argv[1] , "r");
lFile = fopen (argv[1] , "r");
qFile = fopen (argv[2], "w");

if (pFile == NULL) perror ("Error opening file");
else { 
    // loop for l commands
    while (fgets(mystring, 100, lFile) != NULL) {
        strcpy_nospace(mystring2, mystring);
        if (mystring2[0] == '(') {
            parse_L_command(mystring2, symbolTable, lineCounter);
        }
        else if(mystring2[0] == '@' || mystring2[0] == 'D' || mystring2[0] == 'A' || mystring2[0] == 'M' || mystring2[0] == '0'){
            lineCounter++;
        }
    }
    // loop for a and c commands
    while (fgets(mystring, 100, pFile) != NULL) {

        strcpy_nospace(mystring2, mystring);

        if (mystring2[0] == '@') {
            parse_A_command(mystring2, symbolTable, hackFinal);
            fputs(hackFinal, qFile);
            fputs("\n", qFile);        
        }
        if (mystring2[0] == 'D' || mystring2[0] == 'A' || mystring2[0] == 'M' || mystring2[0] == '0'){
            // fputs("PARSED C\n", qFile);
            parse_C_command(mystring2, compMap, jumpMap, hackFinal);
            fputs(hackFinal, qFile);
            fputs("\n", qFile);
        }
    }
        fclose (pFile);
        fclose (qFile);
        freeMap(compMap);
        freeMap(symbolTable);
        freeMap(jumpMap);
}    
return 0;
}