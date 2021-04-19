CC =  gcc
CFLAGS=-I.
RM = rm
RMFLAGS = -rf
DEPS = colors.h step1.h
OBJ = step1.o main.o 
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

game:  $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	$(RM) $(RMFLAGS) $(OBJ)

