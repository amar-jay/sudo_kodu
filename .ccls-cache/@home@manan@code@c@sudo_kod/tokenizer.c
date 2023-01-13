#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define TOKEN_LEN 3
#define MAX_CAP 1000
char store_key[MAX_CAP][MAX_CAP] =  {};
char store_value[MAX_CAP][MAX_CAP] =  {};
size_t store_n = 0;

bool start_declare = false;
bool start_set = false;
bool start_print = false;

void tokenizer(char *ptr) {
  // if previous line is declare
      if (start_declare == true) {
	strcpy(store_key[store_n], ptr);
	strcpy(store_value[store_n], "");
	++store_n;
	start_declare = false;
	return;
    }

  // if set in current line
    if (start_set == true) {
      char *key = strtok(ptr, "=");
    //TODO: perform arithmetric operations
      char *val = strtok(NULL, "");

      for (size_t i = 0; i<=store_n; i++) {
	if (strcmp(store_key[i], ptr) == 0) {
//	  printf("setting val %s\n", ptr);
	  strcpy(store_value[i],val); 
	}
      }
	start_set = false;
	return;
    }
      
    if (start_print == true) {
      for (size_t i = 0; i<=store_n; ++i) {
//	printf(">>%s: %s\n", store_key[i], ptr);
	if (strcmp(store_key[i], ptr) == 0) {
	printf("%s: %s\n", store_key[i], store_value[i]);
	start_print = false;
	return;
	}
      }
      
      start_print = false;
      return;
    }

      // for declarations
      if (strcmp("DECLARE", ptr) == 0){
	start_declare = true;
	return;
      }

      // for setting values 
      if (strcmp("SET", ptr) == 0){
	start_set = true;
	return;
      }

      // for printing values 
      if (strcmp("PRINT", ptr) == 0){
	start_print = true;
	return;
      }
}
