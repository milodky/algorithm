TARGET := kalah
CC := g++
SRCS := KalahContainers.cpp
HDRS := KalahContainers.h
CXXFLAGS := -std=c++11
OBJS := $(SRCS:.cpp=.o)
$(TARGET): $(OBJS)
	$(CC)  -o $(CFLAGS) $@ $(OBJS)

$(OBJS) : $(HDRS)

.PHONY: clean run
run:
	make
	./${TARGET}

clean:
	-rm *.o
	-rm ${TARGET}
