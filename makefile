
# définition des commandes utilisées
CC = gcc
RM = rm -f
# déclaration des options du compilateur
CFLAGS = -Wall
CPPFLAGS = -I src/include

# définition des fichiers et dossiers
PROGNAME = etud
VERSION = 1.0
distdir = $(PROGNAME)-$(VERSION)
HEADERS = 
SOURCES = src/main.c src/appli.c src/etud.c
OBJ = $(SOURCES:.c=.o)

all: $(PROGNAME)

$(PROGNAME): $(OBJ)
	$(CC) $(OBJ) -o $(PROGNAME)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) src/*.o
