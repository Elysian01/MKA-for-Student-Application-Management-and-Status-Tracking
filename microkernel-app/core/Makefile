CXX = g++
CXXFLAGS = -std=c++17 -ldl
LDFLAGS = -ldl

# Directories
CORE_DIR = .
HEADER_DIR = $(CORE_DIR)/headers
IMPLEMENTATION_DIR = $(CORE_DIR)/implementations


# Automatically detect all .cpp files in the implementation directory
CORE_SRC = $(wildcard $(IMPLEMENTATION_DIR)/*.cpp)

# Manual Linking of Core source files 
# CORE_SRC = $(IMPLEMENTATION_DIR)/StudentApplicationSubmission.cpp \
#                $(IMPLEMENTATION_DIR)/DocumentVerification.cpp \
#                $(IMPLEMENTATION_DIR)/ApplicationStatusTracker.cpp \
#                $(IMPLEMENTATION_DIR)/StudentDashboard.cpp \
#                $(IMPLEMENTATION_DIR)/PluginLoader.cpp \
#                $(IMPLEMENTATION_DIR)/NotificationPluginLoader.cpp \
#                $(IMPLEMENTATION_DIR)/StatisticsPluginLoader.cpp \
#                $(IMPLEMENTATION_DIR)/Microkernel.cpp \
#                $(IMPLEMENTATION_DIR)/core.cpp


CORE_OUT = core_obj

# Build target
all: $(CORE_OUT)

# Linking step
$(CORE_OUT): $(CORE_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Clean target
clean:
	rm -f $(CORE_OUT)
