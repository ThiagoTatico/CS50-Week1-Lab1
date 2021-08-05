// Recovers lost images in file
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Constants
const int JPG_BLOCK = 512;

// Types
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check command line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    
    
    // Open forensic image file and check if it is valid
    FILE *lost_image = fopen(argv[1], "r");
    if (lost_image == NULL)
    {
        printf("Could not open file\n");
        return 1;
    }
    
    
    // Variables, file for recording and allocation of space for the buffer where each block will be stored
    BYTE buffer[JPG_BLOCK];
    FILE *found_image;
    char file_name[8];
    int file_number = 0;
    
    // Reading the file
    while (fread(buffer, JPG_BLOCK, 1, lost_image) == 1)
    {
        // Check if it's a jpg header
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // First jpg
            if (file_number != 0)
            {
                fclose(found_image);
            }
            sprintf(file_name, "%03i.jpg", file_number++);
            found_image = fopen(file_name, "w");
            fwrite(buffer, JPG_BLOCK, 1, found_image);
        }
        // Keep recording until you find the next jpg
        else if (file_number > 0)
        {
            fwrite(buffer, JPG_BLOCK, 1, found_image);
        }
    }
    
    // Close files
    fclose(lost_image);
    fclose(found_image);
}