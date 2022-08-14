#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE");
        return 1;
    }
    else
    {
        char *filename  = argv[1];
        FILE *file = fopen(filename, "r");
        if(file == NULL)
        {
            printf("Unable to open file %s\n",filename);
            return 1;
        }
        BYTE buffer[512];
        FILE *jpgimg = NULL;
        char images[10];
        int count  = 0;
        while (fread(&buffer, sizeof(buffer), 1, file) == 1)
        {
            if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                if(!(count==0))
                {
                    fclose(jpgimg);
                }
                sprintf(images, "%03i.jpg", count);
                jpgimg = fopen(images, "w");
                count++;
            }
            if(!(count == 0))
            {
                fwrite(&buffer, sizeof(buffer), 1, jpgimg);
            }
        }
        fclose(file);
        fclose(jpgimg);
        return 0;
    }
}