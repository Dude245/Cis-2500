CC          =	gcc
# Flags that are sent to the compiler
# Do not change these
CFLAGS      =	-Wall -ansi -pedantic -g


#Directories where the compiler can find things
INCLUDES    = -Iinclude


# add directory names here if you want to separate files by directories
BINDIR = bin/
SRCDIR = src/

#Put the names of your source code file in the lines below.  

SOURCE = $(SRCDIR)main.c $(SRCDIR)musicRecord.c $(SRCDIR)fileParser.c

#The list of object files is below.  The object file names here must match the file names of your source code 
# except with .o instead of .c.   Make changes as appropriate


OBJS    = main.o musicRecord.o fileParser.o


#The names of the binary programs that will be produced.  
#
PROGNAME = $(BINDIR)labExe


default : labLink

labLink: labCompile
	$(CC)  -o $(PROGNAME) $(OBJS) $(LIBS)

labCompile: 
	$(CC) $(CFLAGS) -c $(SOURCE) $(INCLUDES)

clean:
	@ rm *.o
