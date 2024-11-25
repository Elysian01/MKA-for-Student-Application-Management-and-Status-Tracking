CC = g++
CFLAGS = -shared -fPIC

PLUGINS = notification_manager priority_application_plugin

all: $(PLUGINS)

notification_manager: notification_manager.cpp
	$(CC) -o notification_manager.so notification_manager.cpp $(CFLAGS)

priority_application_plugin: priority_application_plugin.cpp
	$(CC) -o priority_application_plugin.so priority_application_plugin.cpp $(CFLAGS)

clean:
	rm -f *.so
