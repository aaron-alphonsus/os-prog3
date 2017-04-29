# Use the GNU C/C++ compiler:
CC = gcc
CPP = g++

#FLAGS
CFLAGS = -std=c++11

#OBJECT FILES
OBJS = fcfs.o sstf.o scan.o c_scan.o look.o c_look.o disk_sched.o

#TARGET FILES
TARGET = disk_sched

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CPP) -o $(TARGET) $(OBJS)

fcfs.o: fcfs.cpp disk_sched.h
	$(CPP) -c fcfs.cpp

sstf.o: sstf.cpp disk_sched.h
	$(CPP) -c sstf.cpp

scan.o: scan.cpp disk_sched.h
	$(CPP) -c scan.cpp

c_scan.o: c_scan.cpp disk_sched.h
	$(CPP) -c c_scan.cpp

look.o: look.cpp disk_sched.h
	$(CPP) -c look.cpp

c_look.o: c_look.cpp disk_sched.h
	$(CPP) -c c_look.cpp

disk_sched.o: disk_sched.cpp disk_sched.h
	$(CPP) -c disk_sched.cpp

clean:
	$(RM) *.o *~ $(TARGET)
