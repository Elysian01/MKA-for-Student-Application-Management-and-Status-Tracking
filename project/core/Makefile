CC = g++
CFLAGS = -ldl

SRC = core.cpp
OUT = core

all: $(OUT)

$(OUT): $(SRC)
	$(CC) -o $(OUT) $(SRC) $(CFLAGS)

clean:
	rm -f $(OUT)
