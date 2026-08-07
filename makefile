project=main
CC=gcc

clean_all:run
	@rm $(project).i
	@rm $(project).s
	@rm $(project).o

run: a.exe
	@echo "***************** RUNNING *****************"
	@./a.exe
$(project).i: $(project).c
	@echo "***************** PRE-PROCESSING *****************"
	@$(CC) $(project).c -E -o $(project).i

$(project).s: $(project).i
	@echo "***************** COMPILING *****************"
	@$(CC) $(project).i -S -o $(project).s

$(project).o: $(project).s
	@echo "***************** ASSEMBLING *****************"
	@$(CC) $(project).s -c

a.exe: $(project).o
	@echo "***************** LINKING *****************"
	@$(CC) $(project).o


