
CC = gcc
C_FLAGS = -Wall
DEPS = 

C_FILE = $(wildcard *.c)
FILE_BASENAME = $(basename $(C_FILE) )
OBJ = $(addsuffix .o, $(FILE_BASENAME))


main: $(OBJ)
	$(CC) -o main $^ $(C_FLAGS)

%.o: %.c $(DEPS)
	$(CC) -c $< $(C_FLAGS)

build_all_obj:
	$(CC) -c $(C_FILE) $(C_FLAGS)


clean:
	rm $(OBJ)
	rm main


print_obj:
	@echo $(OBJ)




# For example, consider the following declaration:
# 
# all: library.cpp main.cpp
# 
# In this case:
# 
#     $@ evaluates to all
#     $< evaluates to library.cpp
#     $^ evaluates to library.cpp main.cpp

