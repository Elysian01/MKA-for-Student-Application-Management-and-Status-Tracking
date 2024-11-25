CXX = g++
CXXFLAGS = -shared -fPIC
PLUGIN_SOURCES = SendEmailNotification.cpp SendSMSNotification.cpp
SO_DIR = so

all: $(SO_DIR) $(addprefix $(SO_DIR)/, $(PLUGIN_SOURCES:.cpp=.so))

$(SO_DIR):
	mkdir -p $(SO_DIR)

$(SO_DIR)/%.so: %.cpp | $(SO_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -rf $(SO_DIR)
