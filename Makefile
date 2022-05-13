CXXFLAGS := -std=c++11 -Wall -Werror -ggdb -O0 -lstdc++ -D_GLIBCXX_USE_CXX11_ABI=1

SOURCES := $(wildcard *.cpp)
OBJS := $(SOURCES:%.cpp=%.o)

TARGET := make

.PHONY : all
all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY : clean
clean :
	rm -rf $(TARGET) $(OBJS)
