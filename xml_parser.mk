# Makefile for xml_parser

CXX = g++
CXXFLAGS = -std=c++11 -Wall -I/usr/include/libxml2

# Use the correct library path for libcurl-4.dll in Cygwin
LIBS = -lxml2 -L/usr/bin -lcurl-4

TARGET = xml_parser
SRC_XML_PARSER = xml_parser.cpp

all: $(TARGET)

xml_parser: $(SRC_XML_PARSER)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC_XML_PARSER) $(LIBS)

clean:
	rm -f $(TARGET)
