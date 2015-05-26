#ifndef MUSIC_RECORD_H
#define MUSIC_RECORD_H

/* this struct is intended to hold information about a single song or tune.  
artist is the name of the group/singer/band/etc
title is the name of the song or tune
minutesLong and secondsLong are used together to represent the length of the song
or tune (i.e. 2 minutes 5 seconds)
genre represents the type of music.  
for the purposes of this lab, limit genre to rock, folk, classical
*/
struct musicRecord {
	char *artist;
	char *title;
	int minutesLong;
	int secondsLong;
	char *genre;
};


struct musicRecord * initRecord(char * theArtist, char* theTitle, int min, int sec, char* genre);

void freeRecord(struct musicRecord * toBeFreed);

char * printMusicRecord (struct musicRecord * toBePrinted);



int playlistLength (struct musicRecord ** theList);



#endif
