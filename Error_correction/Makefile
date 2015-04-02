INC_DIR:=./include/ ./include/Sock_epoll_h/ ./include/Thid_pool_h/
SRC_DIR:=./src/ ./src/Sock_epoll/ ./src/Thid_pool/
SRCS:=$(wildcard ./src/*.cpp) $(wildcard ./src/Sock_epoll/*.cpp) $(wildcard ./src/Thid_pool/*.cpp)
LIBS:= -lpthread
CXX:=g++
CXXFLAGS:= -Wall -g -std=c++11 -lpthread $(addprefix -I, $(INC_DIR) )
EXE:=./bin/main
$(EXE):$(SRCS)
	$(CXX) -o $(EXE) $(SRCS) $(CXXFLAGS)

clean:
	rm -rf $(EXE)
	rm -rf $(OBJS)
