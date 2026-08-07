files=main.c dynamic_array.c linked_list.c queue.c stack.c
CC=gcc
WarningFlags=
ExeName=data_structures

clean: run
	rm data_structures.exe

run: build
	$(ExeName).exe
build:
	$(CC) $(files) $(WarningFlags) -o $(ExeName)

