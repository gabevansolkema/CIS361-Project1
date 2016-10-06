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
void initializeEncryptArray(char key[], char encrypt[]);

// Initialize the decrypt array with appropriate substitute letters based on the encrypt array
void initializeDecryptArray(char encypt[], char decrypt[]);

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

	char encrypt[26], decrypt[26];
	char *key;
	FILE *fin, *fout;
		
	printf("\n"); 

	// Assigns files from arguments
	fin = fopen(argv[3], "r");
  	fout = fopen(argv[4], "w");
  	if (fin ==  NULL || fout == NULL) {
		printf("Usage: option, key, infile, outfile\n");
    		printf("File could not be opened\n\n");
    		exit(1);
  	}

	key = removeDuplicates(argv[2]);
//	if (strlen(key) > 26) { 
//		printf("Usage: option, key, infile, outfile\n");
//		printf("Key cannot be greater than 26 characters\n\n");
//		exit(1);
//	}	
	
//	printf("\nOriginal key: %s\n", argv[2]);
//	printf("New key without duplicate characters: %s\n", key);	

	// Initializes encrypt and decrypt arrays
	initializeEncryptArray(key, encrypt);
	initializeDecryptArray(encrypt, decrypt);

	// Processes input based on option argument
       	if (*argv[1] == '1') {
                processInput(fin, fout, encrypt);
	} else if (*argv[1] == '2') {
		processInput(fin, fout, decrypt);
	} else {
		printf("Here is the option you gave: %s\n", argv[1]);
		printf("Usage: option, key, infile, outfile\n");  
		printf("Option not recognized\n");
		printf("Option: 1 for encryption, 2 for decryption\n");
		exit(1);
	}
	
	fclose(fin);
	fclose(fout);
//	printf("encrypted array: %s\n\n", encrypt);	

}


// Searches array for duplicate letter
// Returns 1 if target found, returns 0 if target not found
int targetFound(char charArray[], int num, char target){
	int x;
	for(x = 0; x < strlen(charArray); x++){
        	if(x < num && charArray[x] == target)
              		return 1;
	}

	return 0;  
}


// Returns array of chars without duplicates
char* removeDuplicates(char word []) {
  	char *key = malloc(sizeof(char) * 26);
  	int x;
	int z = 0;

  	for(x=0; x < strlen(word); x++) {
    		if(targetFound(word, x, word[x]) != 1) {
			if (islower(word[x])) {
				printf("Usage: option, key, infile, outfile\n");
				printf("Key needs to be uppercase\n\n");
				exit(1);
			}

			key[z] = word[x];
			z++;
		}
  	}	
  	key[z] = '\0';

  	return key;
}


// Initializes the encrypt array
void initializeEncryptArray(char key[], char encrypt[]) {
	int x;
	int z = 0;

	for(x=0; x < 26; x++) {
		// Goes through key array and assigns values to encrypt array
		if(x < strlen(key)) {
			encrypt[x] = key[x];
		} else {
			// Starts at back of alphabet and checks to see if character is in key
			// If character is not in key, assign value to to encrypt array 
			if (!targetFound(key, 27, 90 - z)) { 
				encrypt[x] = 90 - z;
			} else { 
				// If nothing is added to encrypt array, do not change x position
				x--;
			}

			// Changes letter to be put in array
			z++;
		}
	} 

	encrypt[x] = '\0';
}


// Initializes the decrypt array using the encrypt array
void initializeDecryptArray(char encrypt[], char decrypt[]) {
	int x;
	
	for (x = 0; x < 26; x++) { 
		decrypt[encrypt[x] - 65] = x + 65;
	} 

	decrypt[x] = '\0';
}


// Process input based on option
// Reads a file in and writes a file out
// Uses either the decrypt or encrypt array 
void processInput(FILE * inf, FILE * outf, char substitute[]){
	char ch;

	while (fscanf(inf, "%c", &ch) != EOF) {
		if(!isalpha(ch)) {
			fprintf(outf, "%c", ch);
		} else {
			if (islower(ch)) 
				ch = ch - 32;
			fprintf(outf, "%c", substitute[ch - 65]);
		}
      }

}







