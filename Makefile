# Let's make something.

TARGET := libeasydata.a

SRC_DIRS := source
INC_DIRS := include

SRCS := $(shell find $(SRC_DIRS) -name "*.cpp")
OBJS += $(filter %.o, $(patsubst %.cpp, %.o, $(SRCS)))

CPPFLAGS := -Wall -Wextra -Werror -std=c++17 -Og
CPPFLAGS += $(foreach dir, $(INC_DIRS), -I$(dir))

.PHONY: all clean

all: $(TARGET)

clean:
	-rm -rf $(TARGET) $(OBJS)

$(TARGET): $(OBJS)
	$(AR) -rcs $(TARGET) $(OBJS)