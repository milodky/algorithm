TARGET := kalah
CC := g++
SRCS := KalahContainers.cpp
HDRS := KalahContainers.h

OBJS := $(SRCS:.cpp=.o)
$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

$(OBJS) : $(HDRS)

.PHONY: clean run
run:
	make
	./${TARGET}

clean:
	-rm *.o
	-rm ${TARGET}
