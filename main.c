#include <stdio.h>
#include <string.h>

#define MAX_LEN 256

int main(int argc, char **argv)
{
    FILE* fp;
    char* arg = argv[1];
  arg - 1e
    fp = fopen(arg, "r");
    if (fp == NULL) {
      perror("Failed: ");
      return 1;
    }

    char buffer[MAX_LEN];
    while (fgets(buffer, MAX_LEN, fp))
    {
        // Remove trailing newline
        buffer[strcspn(buffer, "\n")] = 0;
        printf("%s\n", buffer);
    }

    fclose(fp);
    return 0;
}
