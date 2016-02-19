# This is a template makefile for the future programming projects

program_Name := myprogram
program_C_SRCS := $(wildcard *.c)
program_CXX_SRCS := $(wildcard *.cpp)
program_C_OBJS := ${program_C_SRCS:.c=.o}
program_CXX_OBJS := ${program_CXX_SRCS:.cpp=.o}
program_OBJS := $(program_C_OBJS) $(program_CXX_OBJS)
program_INCLUDE_DIRS := /usr/local/Cellar/glm/0.9.7.1/include \
						/usr/local/Cellar/glew/1.13.0/include \
						/usr/local/Cellar/glfw3/3.1.2/include
program_LIBRARY_DIRS := /System/Library/Frameworks/OpenGL.framework/Libraries \
						 /usr/local/Cellar/glm/0.9.7.1/lib \
						 /usr/local/Cellar/glew/1.13.0/lib \
						 /usr/local/Cellar/glfw3/3.1.2/lib

program_LIBRARIES := GL GLU GLEW glfw3 m objc stdc++ 

CPPFLAGS += -framework GLUT
CPPFLAGS += -framework OpenGL
CPPFLAGS += $(foreach includedir, $(program_INCLUDE_DIRS),-I$(includedir))
LDFLAGS += $(foreach librarydir, $(program_LIBRARY_DIRS),-L$(librarydir))
LDFLAGS += $(foreach library, $(program_LIBRARIES),-l$(library))

.PHONY: all clean distclean

all: $(program_Name)

$(program_Name): $(program_OBJS)
	$(LINK.cc) $(program_OBJS) -o $(program_Name)

clean:
	@- $(RM) $(program_Name)
	@- $(RM) $(program_OBJS)

distclean: clean

define OBJECT_DEPENDS_ON_CORRESPONDING_HEADER
	$(1) : ${1:.o=.h}
endef
	$(foreach object_file,$(program_OBJS),$(eval$(call OBJECT_DEPENDS_ON_CORRESPONDING_HEADER,$(object_file))))


