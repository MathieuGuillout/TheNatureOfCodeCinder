CC=g++

OPTIONS=-m32 -arch i386
FRAMEWORKS=-framework Cocoa -framework IOKit -framework Accelerate -framework AudioToolbox -framework AudioUnit -framework CoreAudio -framework CoreVideo -framework CoreServices -framework QTKit -framework OpenGL -framework QuickTime -framework AppKit -framework Cocoa -framework CoreData -framework Foundation
LIBRARIES=-L ${CINDER_PATH}/lib -L ${CINDER_PATH}/lib/macosx
XLINKERS=-XLinker ${CINDER_PATH}/lib/libcinder_d.a
HINCLUDES=-I ${CINDER_PATH}/boost -I $(CINDER_PATH)/include -I /System/Library/Frameworks -I include/
INCLUDES=-l cinder -l cinder_d -l z -l png14 -l pixman-1 -l cairo -l boost_thread -l boost_system -l boost_filesystem -l boost_date_time

SRCS=$(wildcard src/*.cpp)
OBJS=$(patsubst src/%.cpp,obj/%.o, $(SRCS))
TOPDIR := $(shell pwd)
BINDIR := $(TOPDIR)/bin
OBJDIR := $(TOPDIR)/obj

all: app

app:$(OBJS)
	$(shell [ -d "$(BINDIR)" ] || mkdir -p $(BINDIR))
	$(CC) $(OPTIONS) $(LIBRARIES) $(HINCLUDES) $(INCLUDES) $(XLINKERS) $(FRAMEWORKS) $(OBJS) -o bin/app 
	bin/./app

obj/%.o: src/%.cpp
	$(shell [ -d "$(OBJDIR)" ] || mkdir -p $(OBJDIR))
	$(CC) $(OPTIONS) $(LIBRARIES) $(HINCLUDES) -c $< -o $@

clean:
	rm -rf $(BINDIR)
	rm -rf $(OBJDIR)
