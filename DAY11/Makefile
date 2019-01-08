CC=g++
#CFLAGS = -std=c++2a -g -Wall -I /usr/local/boost-1.69.0/include -L /usr/local/boost-1.69.0/lib -lboost_system -lboost_filesystem -lboost_thread-mt
CFLAGS = -std=c++2a -g -Wall
TARGET = JOB_SCHEDULER

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

CC=g++
CFLAGS = -std=c++2a -g -Wall
TARGET = DICTIONARY_QUERRY

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

