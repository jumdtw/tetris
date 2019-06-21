CC = g++
CFLAG = -Wall -g --input-charset=cp932 --exec-charset=cp932
OBJ = main.o
HEADER = main.hpp 
TARGET = tetris


$(TARGET): $(OBJ) $(HEADER) Makefile
	$(CC) $(CFLAG) -o $(TARGET) $(OBJ)

%.o: %.cpp $(HEADER) Makefile 
	$(CC) $*.cpp -c -o $*.o

run : $(TARGET) Makefile
	$(TARGET)

clean :
	del $(OBJ)