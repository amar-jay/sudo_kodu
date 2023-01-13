#include <stdio.h>
#include <string.h>
#include "tokenizer.c" 

#define MAX_LEN 256

int main(int argc, char **argv)
{
    FILE* fp;
    char* arg = argv[1];

    fp = fopen(arg, "r");
    if (fp == NULL) {
      perror("HATA: ");
      return 1;
    }

    char buffer[MAX_LEN];
  // fgets -> tip FILE'dan string tipe dönüştürür
    while (fgets(buffer, MAX_LEN, fp))
    {
        // Remove trailing newline
        buffer[strcspn(buffer, "\n")] = 0;

	// kelime kelime parçalayın
	char* ptr = strtok(buffer, " ");
	// her kelime okuyun
	while (ptr != NULL){
	  
//	puts(ptr);
	tokenizer(ptr);

	ptr = strtok(NULL, " ");
	}
	// strtok okumak için -> https://www.bilgigunlugum.net/prog/cprog/c_stdkut/string/strtok
        //printf("%s\n", buffer);
    }

    fclose(fp);
    return 0;
}
