CC=g++
CFLAGS = -std=c++2a -g -Wall
TARGET = XOR_LINKED_LIST

all : $(TARGET)

$(TARGET):.$(TARGET).o .main.o
	$(CC) $(CFLAGS) $^ -o $@
.$(TARGET).o : $(TARGET).cc $(TARGET).hpp
	$(CC) $(CFLAGS) -c $< -o $@
.main.o : main.cc $(TARGET).hpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : clean
clean:
	rm -f $(TARGET) *.o *.gch .*.o .*.gch

