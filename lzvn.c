/*
 * Created..: 31 October 2014
 * Filename.: lzvn.c
 * Author...: Pike R. Alpha
 * Enhancer.: Andy Vandijck
 * Purpose..: Command line tool to LZVN compress / decompress a file.
 */

#include "FastCompression.h"

#include <string.h>

//==============================================================================

int main(int argc, const char * argv[])
{
	FILE *fp							= NULL;

	unsigned char * fileBuffer			= NULL;
	unsigned char * uncompressedBuffer	= NULL;
	unsigned char * bufend				= NULL;

	unsigned long fileLength = 0;
    unsigned long byteshandled = 0;

	size_t compsize = 0;

	if (argc != 4)
	{
		printf("Usage (encode): %s -e <infile> <outfile>\n", argv[0]);
        printf("Usage (decode): %s -d <infile> <outfile>\n", argv[0]);

        return -1;
	} else {
        if (!strncmp(argv[1], "-e", 2))
        {
            fp = fopen(argv[2], "rb");
            
            if (fp == NULL)
            {
                printf("Error: Opening of %s failed... exiting\nDone.\n", argv[2]);
                return -1;
            } else {
                fseek(fp, 0, SEEK_END);
                fileLength = ftell(fp);
                
                printf("fileLength: %ld\n", fileLength);
                
                fseek(fp, 0, SEEK_SET);
                
                fileBuffer = malloc(fileLength);
                
                if (fileBuffer == NULL)
                {
                    printf("ERROR: Failed to allocate file buffer... exiting\nAborted!\n\n");
                    fclose(fp);
                    return -1;
                } else {
                    fread(fileBuffer, fileLength, 1, fp);
                    fclose(fp);
                    
                    size_t workSpaceSize = lzvn_encode_work_size();
                    printf("workSpaceSize: %ld \n", workSpaceSize);
                    
                    void * workSpace = malloc(workSpaceSize);
                    
                    if (workSpace == NULL)
                    {
                        printf("ERROR: Failed to allocate workspace... exiting\nAborted!\n\n");
                        return -1;
                    } else {
                        printf("workSpace declared\n");
                        
                        if (fileLength > workSpaceSize)
                        {
                            workSpaceSize = fileLength;
                        }
                        
                        uncompressedBuffer = (void *)malloc(workSpaceSize);
                        
                        if (uncompressedBuffer == NULL)
                        {
                            printf("ERROR: Failed to allocate uncompressed buffer... exiting\nAborted!\n\n");
                            return -1;
                        } else {
                            size_t outSize = lzvn_encode(uncompressedBuffer, workSpaceSize, (u_int8_t *)fileBuffer, (size_t)fileLength, workSpace);
                            
                            printf("outSize: %ld\n", outSize);
                            
                            free(workSpace);
                            
                            if (outSize != 0)
                            {
                                bufend = uncompressedBuffer + outSize;
                                compsize = bufend - uncompressedBuffer;
                                
                                printf("compsize: %ld\n", compsize);
                                
                                fp = fopen (argv[3], "wb");
                                fwrite(uncompressedBuffer, outSize, 1, fp);
                                fclose(fp);
                            }
                        }
                        
                        free(fileBuffer);
                        free(uncompressedBuffer);
                        
                        return 0;
                    }
                }
            }
        } else if (!strncmp(argv[1], "-d", 2)) {
            fp = fopen(argv[2], "rb");
            {
                if (fp == NULL)
                {
                    printf("Error: Opening of %s failed... exiting\nDone.\n", argv[2]);
                    return -1;
                } else {
                    fseek(fp, 0, SEEK_END);
                    fileLength = ftell(fp);
                    
                    printf("fileLength: %ld\n", fileLength);
                    
                    fseek(fp, 0, SEEK_SET);
                    
                    fileBuffer = malloc(fileLength);
                    
                    if (fileBuffer == NULL)
                    {
                        printf("ERROR: Failed to allocate file buffer... exiting\nAborted!\n\n");
                        fclose(fp);
                        return -1;
                    } else {
                        fread(fileBuffer, fileLength, 1, fp);
                        fclose(fp);
                        fp = fopen(argv[3], "wb");
                        if (fp == NULL)
                        {
                            printf("Error: Opening of %s failed... exiting\nDone.\n", argv[3]);
                            return -1;
                        } else {
                            size_t workSpaceSize = lzvn_encode_work_size();
                            printf("workSpaceSize: %ld \n", workSpaceSize);
                            uncompressedBuffer = malloc(workSpaceSize);
                            if (uncompressedBuffer == NULL)
                            {
                                printf("ERROR: Failed to allocate uncompressed buffer... exiting\nAborted!\n\n");
                                return -1;
                            } else {
                                
                                while ((compsize = lzvn_decode(uncompressedBuffer, workSpaceSize, fileBuffer, fileLength)) > 0)
                                {
                                    fwrite(uncompressedBuffer, 1, compsize, fp);
                                    fileBuffer += workSpaceSize;
                                    byteshandled += workSpaceSize;
                                }

                                fileBuffer -= byteshandled;
                                free(fileBuffer);
                                free(uncompressedBuffer);

                                printf("Uncompressed size: %ld\n", ftell(fp));
                                fclose(fp);
                                
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

	return -1;
}
