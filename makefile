#dotandanino@gmail.com

CXX=clang++
CXXFLAGS=-std=c++2a -Wall -Wextra
TARGET=main
SRCS=Graph.cpp Queue.cpp MinHeap.cpp Algorithms.cpp UnionFind.cpp
HEADERS=Graph.hpp Algorithms.hpp Queue.hpp MinHeap.hpp UnionFind.hpp
OBJS=$(SRCS:.cpp=.o)
TEST_TARGET=test_run
TEST_SRC = test.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)
all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(OBJS) main.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) main.o

$(TEST_TARGET): $(OBJS) $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJ) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@
valgrind: $(TARGET) $(TEST_TARGET)
#	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TEST_TARGET)
test: $(TEST_TARGET)
	./$(TEST_TARGET)
clean:
	rm -f $(OBJS) $(TARGET) $(TEST_TARGET)
.PHONY: all clean valgrind

