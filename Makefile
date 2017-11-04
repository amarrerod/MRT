CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
CC_FLAGS	:= -g -std=c++11

mrt:
			g++ $(CC_FLAGS) $(CPP_FILES) -o $@ $^
clean:
			rm mrt