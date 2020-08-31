#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TSIZE 45

int main()
{
    size_t content_size;
    char filename[TSIZE] = "/etc/apt/apt.conf.d/20auto-upgrades";
    FILE *file;
    if ((file = fopen(filename, "r")) == NULL)
    {
        printf("ERROR: Cannot open file.\n");
        exit(EXIT_FAILURE);
    }

    /* find end */
    fseek(file, 0, SEEK_END);

    content_size = ftell(file);

    char *content_buffer = (char *)malloc(content_size);
    if (content_buffer == NULL)
    {
        printf("ERROR: malloc() failed.\n");
        exit(EXIT_FAILURE);
    }

    rewind(file);   /* set to start */

    fread(content_buffer, content_size, 1, file);

    printf("content_buffer : %s\n", content_buffer);

    printf("%s\n", strchr(content_buffer, '1'));
    char *find;
    find = strchr(content_buffer, '1');
    if (find)
        *find = '0';

    // printf("%s\n", strchr(content_buffer, '0'));

    // printf("%s\n", strrchr(content_buffer, '1'));
    find = strrchr(content_buffer, '1');
    if (find)
        *find = '0';

    FILE *file_to_write;
    if ((file_to_write = fopen(filename, "w")) == NULL)
    {
        printf("ERROR: Cannot open file.\n");
        exit(EXIT_FAILURE);
    }
    fwrite(content_buffer, content_size, 1, file_to_write);
    // printf("%s\n", strrchr(content_buffer, '1'));

    return 0;
}