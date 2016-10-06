// Gabe VanSolkema

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Remove duplicate characters in array word and return the result string
char * removeDuplicates(char word []);

// Search the first num characters in array charArray for character target
// Return a non-zero integer if found, otherwise, return 0
int targetFound(char charArray[], int num, char target);

// Initialize the encrypt array with appropriate cipher letters according to the given key
void initializeEncyptArray(char key[], char encrypt[]);

// Initialize the decrypt array with appropriate substitute letters based on the encrypt array
void initializeDecyptArray(char encypt[], char decrypt[]);

// Process data from the input file and write the result to the output file
// Pass the encrypt array to parameter substitute if encryption is intended
// Pass the decrypt array to parameter substitute if decryption is intended
void processInput(FILE * inf, FILE * outf, char substitute[]);

/*
 *
 * MAIN
 *
 */
int main(int argc, char *argv[]) {

	int choice;
	char encrypt[26], decrypt[26];
	char *key;

	choice = atoi(argv[1]);
	key = removeDuplicates(argv[2]);
	
	//removeDuplicates(key);
	printf("\nOriginal key: %s\n", argv[2]);
	printf("New key without duplicate characters: %s\n\n", key);	


}

//helper to search array and find duplicate letter
int targetFound(char charArray[], int num, char target){
	int x;
	for(x=0; x < strlen(charArray); x++){
        	if(x < num && charArray[x] == target)
              		return 1;
	}

	return 0;  
}

// Returns array of chars without duplicates
char* removeDuplicates(char word []) {
  	char *key = malloc(sizeof(char) * 26);
  	int z = 0;
	int x = 0;

  	for(x=0; x < strlen(word); x++) {
    		if(targetFound(word, x, word[x]) != 1) {
      			//z++;
			key[z++] = word[x];
		}
  	}	
  	key[z] = '\0';

  	return key;
}
