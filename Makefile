# Let's make something.

TARGET := libeasydata.a

SRC_DIRS := source
INC_DIRS := include

SRCS := $(shell find $(SRC_DIRS) -name "*.c") $(shell find $(SRC_DIRS) -name "*.cpp")

OBJS := $(filter %.o, $(patsubst %.c, %.o, $(shell find $(SRC_DIRS) -name "*.c")))
OBJS += $(filter %.o, $(patsubst %.cpp, %.o, $(shell find $(SRC_DIRS) -name "*.cpp")))

CPPFLAGS := -Wall -Wextra -Og
CPPFLAGS += $(foreach dir, $(INC_DIRS), -I$(dir))

.PHONY: all clean

all: $(TARGET)

clean:
	-rm -rf $(TARGET) $(OBJS)

$(TARGET): $(OBJS)
	$(AR) -rcs $(TARGET) $(OBJS)