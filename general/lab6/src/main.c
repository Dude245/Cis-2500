#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "musicRecord.h"
#include "fileParser.h"

#define BUFFER 100

int main(int argc, char *argv[]) {
    FILE *inputFile = NULL;
    char * inputLine, *formattedOutput = NULL;
    char performer[BUFFER], title[BUFFER], charMin[10], charSec[10], genre[BUFFER];
    int min, sec, i;
    int numRecords = 0;
    struct musicRecord ** musicList;

    if (argc != 3) {
        /*comment here */
        printf("usage: %s nameOfInputFile numberOfRecords\n", argv[0]);
    } else {
        /*comment here*/
        inputFile = openFile(argv[1]);
        numRecords = (int) strtol(argv[2], NULL, 10);
        musicList = malloc(sizeof (struct musicRecord*) *numRecords);
    }


    if ((inputLine != NULL) && (inputFile != NULL)) {
        for (i = 0; i < numRecords; i++) {
            inputLine = readNextLine(inputFile);

            if (inputLine != NULL) {
                printf("inputLine: %s \n", inputLine);
                strcpy(performer, getNextToken(inputLine));
                printf("Performer: %s\n",performer);
                strcpy(title, getNextToken(NULL));
                printf("Title: %s\n",title);
                strcpy(charMin, getNextToken(NULL));
                printf("charMin: %s\n",charMin);
                strcpy(charSec, getNextToken(NULL));
                 printf("charSec: %s\n",charSec);
                strcpy(genre, getNextToken(NULL));
                 printf("genre: %s\n",genre);
                min = (int) strtol(charMin, NULL, 10);
                sec = (int) strtol(charSec, NULL, 10);
                musicList[i] = initRecord(performer, title, min, sec, genre);
                free(inputLine);
		printf("Music List: %s\n", musicList[i]);
            }
            formattedOutput = printMusicRecord(musicList[i]);
            

        }

        /* here you should add the section of the code that prints out the length
        of the playlist  You'll have to convert from seconds to minutes/seconds.*/



        /*  for(i=0; i<numRecords; i++)
          {
            in this loop you need to write the code to free the structs and the music list 
        
        
          }
        
         */
    }


    return (0);
}
