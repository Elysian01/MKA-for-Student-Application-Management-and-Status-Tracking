CXX = g++
CXXFLAGS = -std=c++17 -ldl
LDFLAGS = -ldl

# Directories
CORE_DIR = .
HEADER_DIR = $(CORE_DIR)/headers
IMPLEMENTATION_DIR = $(CORE_DIR)/implementations

# Core source files 
CORE_SRC = $(IMPLEMENTATION_DIR)/StudentApplicationSubmission.cpp \
               $(IMPLEMENTATION_DIR)/DocumentVerification.cpp \
               $(IMPLEMENTATION_DIR)/ApplicationStatusTracker.cpp \
               $(IMPLEMENTATION_DIR)/StudentDashboard.cpp \
               $(IMPLEMENTATION_DIR)/Microkernel.cpp \
               $(IMPLEMENTATION_DIR)/core.cpp

CORE_OUT = core_obj


all: $(CORE_OUT)


$(CORE_OUT): $(CORE_SRC)
	$(CXX) $(CXXFLAGS) -o $(CORE_OUT) $(CORE_SRC)

clean:
	rm -f $(CORE_OUT)