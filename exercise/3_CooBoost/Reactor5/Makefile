# version 1
# hello: main.cpp printhello.cpp factorial.cpp
# 	g++ -o hello main.cc printhello.cpp factorial.cpp



# version2
#CXX = g++
#TARGET = hello
#OBJ = main.o printhello.o factorial.o
#
#$(TARGET): $(OBJ)
#	$(CXX) -o $(TARGET) $(OBJ)
#
#main.o: main.cpp
#	$(CXX) -c main.cpp
#
#printhello.o: printhello.cpp
#	$(CXX) -c printhello.cpp
#
#factorial.o: factorial.cpp
#	$(CXX) -c factorial.cpp


#version3
#CXX = g++
#TARGET = hello
#OBJ = main.o printhello.o factorial.o
#
#CXXFLAGS = -c -Wall
#
#$(TARGET): $(OBJ)
#	$(CXX) $(CXXFLAGS) $^ -o $@
#
#%.o: %.cpp
#	$(CXX) $(CXXFLAGS) $< -o $@
#
#.PHONY: clean
#clean:
#	rm -f *.o $(TARGET)


#version4
CXX = g++
TARGET = Server
SRC1 = $(wildcard *.cpp)
SRC2 = $(wildcard *.cc)

SRC = $(SRC1) $(SRC2)

OBJ1 = $(patsubst %.cpp, %.o,$(SRC1))
OBJ2 = $(patsubst %.cc, %.o, $(SRC2))

OBJ = $(OBJ1) $(OBJ2)

CXXFLAGS = -c -Wall

$(TARGET): $(OBJ)
	$(CXX)  $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ 

%.o: %.cc
	$(CXX) $(CXXFLAGS) $< -o $@


.PHONY: clean
clean:
	rm -f *.o $(TARGET)		



# 定义编译器
#CXX = g++
#
## 定义目标文件名
#TARGET = Server
#
## 查找所有的 .cpp 和 .cc 源文件
#SRC1 = $(wildcard *.cpp)
#SRC2 = $(wildcard *.cc)
#
## 合并所有源文件
#SRC = $(SRC1) $(SRC2)
#
## 生成对应的 .o 目标文件列表
#OBJ = $(patsubst %.cpp, %.o, $(SRC1)) $(patsubst %.cc, %.o, $(SRC2))
#
## 编译选项
#CXXFLAGS = -Wall
#
## 目标规则
#$(TARGET): $(OBJ)
#	$(CXX) $(OBJ) -o $@
#
## 编译规则
#%.o: %.cpp
#	$(CXX) $(CXXFLAGS) -c $< -o $@
#
#%.o: %.cc
#	$(CXX) $(CXXFLAGS) -c $< -o $@
#
## 清理规则
#.PHONY: clean
#clean:
#	rm -f *.o $(TARGET)
