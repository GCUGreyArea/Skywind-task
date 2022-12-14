NAME	= task
TARGET  = test_$(NAME)

CXXSRC = $(wildcard src/*.cpp)
CSRC   = $(wildcard src/*.c)

LIB     = lib$(NAME).a
BUILD   = build
LIBDIR  = ../lib
LIBDEP  = $(LIBDIR)/$(BUILD)/$(LIB)

CXXOBJ    := $(patsubst %.cpp,$(BUILD)/%.o,$(CXXSRC))
COBJ      := $(patsubst %.c,$(BUILD)/%.o,$(CSRC))


LIBRARIES := -lgtest -lpthread -lglog
UNAME     := $(shell uname -s)

ifeq ($(UNAME), Darwin)
CC       = cc
CXX      = c++
CFLAGS   = -std=c11 -Wall -g -fsanitize=address -I$(LIBDIR)/src -I..
CXXFLAGS = -std=c++17 -Wall -g -fsanitize=address -I$(LIBDIR)/src -I..
else
CC     = gcc
CXX    = g++
CFLAGS   = -std=c11 -Wall -fPIC -fsanitize=address -I$(LIBDIR)/src -I..
CXXFLAGS = -std=c++17 -Wall -fPIC -fsanitize=address -I$(LIBDIR)/src -I..
endif


all: $(TARGET) $(OBJ) $(COBJ) $(LIBDEP)

$(TARGET) : build $(CXXOBJ) $(COBJ)
	$(CXX) $(CXXFLAGS) $(CXXOBJ) $(COBJ) -o $(BUILD)/$(TARGET) -l$(NAME) -L$(LIBDIR)/build $(LIBRARIES)

build:
	mkdir -p "$(BUILD)/src"

$(LIBDEP) :
	cd $(LIBDIR) && make

$(BUILD)/%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD)/%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD)

