CFLAGS := -Wall -Werror -std=c++17
CXX := g++

TARGET := bin/testProg

SOURCES := $(wildcard src/*.cpp)

OBJ := $(patsubst src/%.cpp, obj/%.o, $(SOURCES))


all:$(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CFLAGS) -o $(TARGET) $(OBJ)

obj/%.o: src/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	find . -name "*.o" -exec rm '{}' \;
	find . -name "*.d" -exec rm '{}' \;
	find . -name "*.a" -exec rm '{}' \;
	find ./bin -type f -name "main" -exec rm -f '{}' \;
	find ./bin -type f -name "test" -exec rm -f '{}' \;
	find . -name "geometry" -exec rm {} \;
	find . -name "geometry-test" -exec rm {} \;

format:
	cd src; find . -name "*.cpp" -exec clang-format -i {} \;
	cd src; find . -name "*.h" -exec clang-format -i {} \;

.PHONY: clean test run all
