TARGET = task

BUILD	   = build
TESTDIR    = test
BENCHDIR   = benchmark
LIBDIR     = lib
DOXYDIR	   = docs
BUILD      = build

TESTTARGET = $(TESTDIR)/$(BUILD)/test_$(TARGET)
BNCTARGET  = $(BENCHDIR)/$(BUILD)/benchmark_$(TARGET)
LIBTARGET  = $(LIBDIR)/$(BUILD)/lib$(TARGET).a
DOCTARGET  = $(DOXYDIR)/generated

SRC = $(shell find src -name '*.cpp')

OBJ := $(patsubst %.cpp,$(BUILD)/%.o,$(SRC))

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

ARGS =

all: $(LIBTARGET) $(TESTTARGET) $(BNCTARGET) $(TARGET)

$(TARGET) : build $(LIBTARGET) $(TESTTARGET) $(BENCHTARGET) $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(BUILD)/$(TARGET) -lpthread -lhs -l$(TARGET) -I$(LIBDIR) -L$(LIBDIR)/build $(LIBTARGET)

build :
	mkdir -p "$(BUILD)/src"

$(LIBTARGET) :
	cd $(LIBDIR) && make

$(TESTTARGET) : $(LIBTARGET)
	cd $(TESTDIR) && make

$(BNCTARGET) : $(LIB)
	cd $(BENCHDIR) && make

$(DOCTARGET) :
	cd $(DOXYDIR) && make

$(BUILD)/%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD)/%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) -c $< -o $@

clean:
	cd $(DOXYDIR) && make clean
	cd $(BENCHDIR) && make clean
	cd $(TESTDIR) && make clean
	cd $(LIBDIR) && make clean
	rm -rf $(BUILD)


install: $(TARGET)
	cp $(TARGET) $(INSTDIR)

valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)

docs: $(DOCTARGET)
	cd $(DOXYDIR) && doxygen Doxyfile

test: $(TESTTARGET)
	cd $(LIBDIR) && make
	cd $(TESTDIR) && make
	$(TESTTARGET)

benchmark: $(BNCTARGET)
	cd $(LIBDIR) && make
	cd $(BENCHDIR) && make
	$(BNCTARGET)

runtest:
	cd $(TESTDIR) && make run

runbench:
	cd $(BENCHDIR) && make run

run:
	./$(TARGET) $(ARGS)

project:
	cd $(LIBDIR) && make
	cd $(TESTDIR) && make
	cd $(BENCHDIR) && make
	make

help:
	@echo "\n\n"
	@echo "============================================================================================="
	@echo "Run: 'make' to build the project"
	@echo "Run: 'make test' to build and run unit tests"
	@echo "Run: 'make benchmark' to build and run unit tests - currently no benchmarks are implemented"
	@echo "Run: 'make runtest' to run the unit tests"
	@echo "Run: 'make runbench' to run the benchmarks - currently no benchmarks are implemented"
	@echo "Run: 'make doxygen' to build doxygen documentation\n"
	@echo "This project depends on:\n"
	@echo "\tGoogles test framework availible at https://github.com/google/googletest"
	@echo "\tGoogles benchmark framework availible at https://github.com/google/benchmark"
	@echo "\tcpp-yaml availible at https://github.com/jbeder/yaml-cpp"
	@echo "============================================================================================="
	@echo "\n\n"

