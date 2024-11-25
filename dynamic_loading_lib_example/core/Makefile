CXX = g++
CXXFLAGS = -std=c++17 -ldl
CORE_SRC = core.cpp
CORE_OUT = core

all: $(CORE_OUT)

$(CORE_OUT): $(CORE_SRC)
	$(CXX) $(CXXFLAGS) -o $(CORE_OUT) $(CORE_SRC)

clean:
	rm -f $(CORE_OUT)
