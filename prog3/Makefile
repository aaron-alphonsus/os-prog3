# Use the GNU C/C++ compiler:
CC = gcc
CPP = g++

#OBJECT FILES
OBJS = fcfs.o disk_sched.o

#TARGET FILES
TARGET = disk_sched

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CPP) -o $(TARGET) $(OBJS)

fcfs.o: fcfs.cpp disk_sched.h
	$(CPP) -c fcfs.cpp

disk_sched.o: disk_sched.cpp disk_sched.h
	$(CPP) -c disk_sched.cpp

clean:
	$(RM) *.o *~ $(TARGET)
