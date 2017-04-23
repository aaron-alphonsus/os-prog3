# Use the GNU C/C++ compiler:
CC = gcc
CPP = g++

#OBJECT FILES
OBJS = disk_sched.o

#TARGET FILES
TARGET = disk_sched

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CPP) -o $(TARGET) $(OBJS)

disk_sched.o: disk_sched.cpp
	$(CPP) -c disk_sched.cpp

clean:
	$(RM) *.o *~ $(TARGET)
