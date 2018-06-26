#ifndef __MAKEFILE_TREE__
#define __MAKEFILE_TREE__

#include <string>

const std::string makefileTree_1 = "\
include $(COMMON)\n\
\n\
SRCS = $(wildcard *.cpp)\n\
\n\
OBJS = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRCS))\n\
\n\
.PHONY : all\n\
all : _header $(OBJS)\n";

const std::string makefileTree_2 = "\
	@$(PRINT_DEPTH)printf \"$(LABEL_COLOR)╚══$(NO_COLOR)\\n\"\n\
\n\
.PHONY : _header\n\
_header :\n\
	@$(PRINT_DEPTH_HEADER)printf \"$(LABEL_COLOR)";

const std::string makefileTree_3 = "$(NO_COLOR)\\n\"\n\
\n\
$(OBJS) : CMD = $(CC) $(INCLUDE_DIRS) $(COMPILER_FLAGS) -c $< -o $@\n\
\n\
$(OBJS) : $(OBJ_DIR)/%.o : %.cpp\n\
	@$(PRINT_DEPTH)printf \"$(LABEL_COLOR)╠═$(NO_COLOR)\";$(PRINT)\n\
\n\
.PHONY : tree\n\
tree : _header\n\
	@$(LIST)\n";

const std::string makefileTree_4 = "\
	@$(PRINT_DEPTH)printf \"$(LABEL_COLOR)╚══$(NO_COLOR)\\n\"";

#endif //__MAKEFILE_TREE__