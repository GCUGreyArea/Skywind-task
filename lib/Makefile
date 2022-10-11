
NAME  = task

CXSRC = $(shell find src -name *.cpp)
CSRC  = $(shell find src -name *.c)
UNAME = $(shell uname)

OBJ := $(patsubst %.cpp,$(BUILD)/%.o,$(CXSRC)) $(patsubst %.c,$(BUILD)/%.o,$(CSRC))

BUILD = build
LIBDIR = .

BASIC := $(BUILD)/src/Basic
NUMBERS := $(BUILD)/src/Numbers

TARGET  = lib$(NAME).a
LIBDIR  =  .
INSTALL = /usr/local/lib
HDRINST = /usr/local/include

OBJ   := $(patsubst %.cpp,$(BUILD)/%.o,$(CXSRC)) $(patsubst %.c,$(BUILD)/%.o,$(CSRC))
UNAME := $(shell uname -s)

ifeq ($(UNAME), Darwin)
CC       = cc
CXX      = c++
CFLAGS   = -std=c11 -Wall -g -fsanitize=address -I$(LIBDIR)/src
CXXFLAGS = -std=c++17 -Wall -g -fsanitize=address -I$(LIBDIR)/src
else
CC     = gcc
CXX    = g++
CFLAGS   = -std=c11 -Wall -fPIC -fsanitize=address -I$(LIBDIR)/src
CXXFLAGS = -std=c++17 -Wall -fPIC -fsanitize=address -I$(LIBDIR)/src
endif


all: $(TARGET)

$(TARGET) : build $(OBJ)
	ar rcs build/$(TARGET) $(OBJ)
	ranlib build/$(TARGET)

build :
	mkdir -p $(BASIC)
	mkdir -p $(NUMBERS)

$(BUILD)/%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD)/%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

clean:
	rm -rf $(BUILD)
