GCC := g++
OUTPUT := example
SOURCES := $(wildcard *.cpp)
CCFLAGS := -std=c++11 -phtread

all: $(OUTPUT)

$(OUTPUT):
	$(GCC) -o(OUTPUT) $(CCFLAGS) $(SOURCES)

clean:
	rm $(OUTPUT)

.PHONY: all