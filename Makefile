# Compiler
CC = gcc

# Compiler flags
CFLAGS = `pkg-config --cflags gtk+-3.0`

# Libraries
LIBS = `pkg-config --libs gtk+-3.0`

# Source file
SRC = gtk_example.c

# Output binary
OUT = gtk_example

# Build rule
all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LIBS)

# Clean rule
clean:
	rm -f $(OUT)
 
