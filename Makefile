CXX = g++
CXXFLAGS = -Wall -Wextra
SRCS = main.cpp \
		tokenizer/tokenizer.cpp
OBJS = $(SRCS:.cpp=.o)

TARGET = json_parser


all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(TARGET)

.PHONY: all clean
