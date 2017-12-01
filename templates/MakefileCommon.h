#ifndef __MAKEFILE_COMMON__
#define __MAKEFILE_COMMON__

#include <string>

const std::string makefileCommon = "\
SHELL                := /bin/bash\n\
\n\
NO_COLOR             := \\033[0m\n\
OK_COLOR             := \\033[01;32m\n\
ERR_COLOR            := \\033[01;31m\n\
WARN_COLOR           := \\033[01;33m\n\
FILE_COLOR           := \\033[01;36m\n\
LABEL_COLOR          := \\033[01;34m\n\
\n\
OK_STR               = $(OK_COLOR)[OK]$(NO_COLOR)\n\
ERR_STR              = $(ERR_COLOR)[ERRORS]$(NO_COLOR)\n\
WARN_STR             = $(WARN_COLOR)[WARNINGS]$(NO_COLOR)\n\
FILE_STR             = $(FILE_COLOR)$<$(NO_COLOR)\n\
EXE_STR              = $(FILE_COLOR)$@$(NO_COLOR)\n\
\n\
PADDING              = awk '{ printf \"%-33s %-10s\\n\",$$1, $$2; }'\n\
\n\
WARN_BORDER          = for (( i=0; i<$(SCREEN_WIDTH); i++)); do printf \"$(WARN_COLOR)═$(NO_COLOR)\"; done && printf \"\\n\"\n\
ERR_BORDER           = for (( i=0; i<$(SCREEN_WIDTH); i++)); do printf \"$(ERR_COLOR)═$(NO_COLOR)\"; done && printf \"\\n\"\n\
\n\
ERR_MSG              = printf \"$(FILE_STR) $(ERR_STR)\\n\" | $(PADDING) && $(ERR_BORDER) && printf \"$(CMD)\\n$$LOG\\n\" && $(ERR_BORDER) && false\n\
WARN_MSG             = printf \"$(FILE_STR) $(WARN_STR)\\n\" | $(PADDING) && $(WARN_BORDER) && printf \"$(CMD)\\n$$LOG\\n\" && $(WARN_BORDER)\n\
OK_MSG               = printf \"$(FILE_STR) $(OK_STR)\\n\" | $(PADDING)\n\
\n\
ERR_MSG_EXE          = printf \"$(EXE_STR) $(ERR_STR)\\n\" | $(PADDING) && $(ERR_BORDER) && printf \"$(CMD)\\n$$LOG\\n\" && $(ERR_BORDER) && false\n\
WARN_MSG_EXE         = printf \"$(EXE_STR) $(WARN_STR)\\n\" | $(PADDING) && $(WARN_BORDER) && printf \"$(CMD)\\n$$LOG\\n\" && $(WARN_BORDER)\n\
OK_MSG_EXE           = printf \"$(EXE_STR) $(OK_STR)\\n\" | $(PADDING)\n\
\n\
PRINT                = LOG=$$($(CMD) 2>&1) ; if [ $$? -eq 1 ]; then $(ERR_MSG); elif [ \"$$LOG\" != \"\" ]; then $(WARN_MSG); else $(OK_MSG); fi;\n\
\n\
PRINT_EXE            = LOG=$$($(CMD) 2>&1) ; if [ $$? -eq 1 ]; then $(ERR_MSG_EXE); elif [ \"$$LOG\" != \"\" ]; then $(WARN_MSG_EXE); else $(OK_MSG_EXE); fi;\n\
\n\
PRINT_DEPTH          = for (( i=1; i<$(MAKELEVEL); i++)); do printf \"$(LABEL_COLOR)║  $(NO_COLOR)\"; done;\n\
\n\
PRINT_DEPTH_HEADER   = if [ $(MAKELEVEL) -gt 1 ]; then for (( i=2; i<$(MAKELEVEL); i++)); do printf \"$(LABEL_COLOR)║  $(NO_COLOR)\"; done && printf \"$(LABEL_COLOR)╠══$(NO_COLOR)\"; else printf \"$(LABEL_COLOR)╔$(NO_COLOR)\"; fi; if [ $(MAKELEVEL) -gt 1 ]; then printf \"$(LABEL_COLOR)╦$(NO_COLOR)\"; fi;\n\
\n\
LIST                 = $(foreach file, $(SRCS), $(PRINT_DEPTH)printf \"$(LABEL_COLOR)╠═$(NO_COLOR)$(FILE_COLOR)$(file)$(NO_COLOR)\\n\";)\n\
\n\
CC = g++\n\
\n\
COMPILER_FLAGS       := ";

#endif //__MAKEFILE_COMMON__