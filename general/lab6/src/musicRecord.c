#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "musicRecord.h"


/* this function must allocate memory and initialize a struct musicRecord and 
return a pointer to the new record.  It must return NULL if there is an error in the 
initialization  or memory allocation */

struct musicRecord * initRecord(char * theArtist, char* theTitle, int min, int sec, char* theGenre ) 
{
    struct musicRecord *theRecord = malloc(sizeof(struct musicRecord));  
    if (theRecord !=NULL)
    {
   /*  theRecord->artist= malloc(sizeof(char)*100);	
     strcpy(theRecord->artist, theArtist);
     */
     theRecord-> artist=*theArtist;	
    /* theRecord-> title=*theTitle;	
     theRecord-> minutesLong=min;	
     theRecord-> secondsLong=sec;	
     theRecord-> genre=*theGenre;	
     */

    return (theRecord);
    }
    else return(NULL);

}

/*this function must free all of the memory allocated for a single musicRecord struct */
void freeRecord(struct musicRecord * toBeFreed){
  /*add code here */
	
}

/*this function should return a nicely formatted char* that can be printed with 
printf.  The method should not do the printing, just the formatting.  Try using
sprintf to help you.  strcat will also work.  Judi used strlen with all the struct members to calculate the size 
of the buffer required before using sprintf*/

char * printMusicRecord (struct musicRecord * toBePrinted)
{
  char * printBuf;
 printBuf=malloc(sizeof (char) *200);

  return(printBuf);
}

/* this function should calculate and return the length of a playlist (in seconds) of a list
of music records.  You'll have to do some time-math. */

int playlistLength (struct musicRecord ** theList){
  int length;
  /*given an array of musicRecords, write the code to calculate the length of the playlist to the nearest second*/
  return (length);
}
