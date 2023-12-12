#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<stdint.h>
#include<stdbool.h>

int main(int argc, char *argv[])
{
if (argc != 2)
{
    printf("Usage ./recover IMAGE \n");
    return 1;
}
char *input = argv[1];
FILE *infile = fopen(input,"r");
if(infile == NULL)
{
    printf("Unable to open file\n");
    return 1;
}
int block_counter = 0;
FILE *outfile = NULL;
char filename[8];
uint8_t buffer[512];

while (fread(buffer, 512, 1, infile))
{
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2]== 0xff &&(buffer[3] & 0xf0)== 0xe0)
    {
        if (outfile != 0)
        {
            fclose(outfile);
        }
        sprintf(filename, "%03i.jpg", block_counter);
        outfile = fopen(filename,"w");
        block_counter++;

    }
if (outfile != 0)
    {
        fwrite(buffer, 512, 1,outfile);
    }

}
fclose(infile);
fclose(outfile);
    return 0;
}