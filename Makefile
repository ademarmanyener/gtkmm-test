CXX = g++
CXXFLAGS = -Wall -Werror `pkg-config --cflags --libs gtkmm-3.0` -rdynamic -l sqlite3 
SOURCES = src/*.cpp
EXEC = testout

build:
	@$(CXX) $(SOURCES) $(CXXFLAGS) -o $(EXEC).out
