CC=clang
CFLAGS=-c -std=c99 -ggdb -Wall
LDFLAGS=-lreadline -lcurses
SOURCES=src/main.c src/lancxilo.c src/malmiksilo.c src/internfunkciaro.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=komandilo

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f src/*.o
