CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c99
LDFLAGS=

SRCDIR=.
OBJDIR=obj
BINDIR=bin

LISTEINT_SRC=$(SRCDIR)/turcqListeInt.c
EXO1_SRC=$(SRCDIR)/turcqExo1.c

LISTEINT_OBJ=$(OBJDIR)/turcqListeInt.o
EXO1_OBJ=$(OBJDIR)/turcqExo1.o

EXE=$(BINDIR)/turcqExo1

.PHONY: all clean

all: $(EXE)

$(EXE): $(LISTEINT_OBJ) $(EXO1_OBJ)
	@mkdir -p $(BINDIR)
	$(CC) $(LDFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(BINDIR) savelist.bin