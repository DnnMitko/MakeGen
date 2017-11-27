#ifndef __MAKEFILE_MAIN__
#define __MAKEFILE_MAIN__

#include <string>

std::string strMakefileMain_1 = "\
export COMMON = $(PWD)/Makefile_Common\n\
\n\
include $(COMMON)\n\
\n\
.NOTPARALLEL :\n\
\n\
MAKEFLAGS += -Otarget\n\
\n\
SRCDIR = ";

std::string strMakefileMain_2 = "\
\n\
export OBJ_DIR = $(PWD)/";

std::string strMakefileMain_3 = "\
\n\
LINKER_FLAGS = ";

std::string strMakefileMain_4 = "\
\n\
EXE = ";

std::string strMakefileMain_5 = "\
\n\
# ============================================================================================\n\
\n\
.PHONY : all\n\
all : $(OBJ_DIR) _submodules $(EXE)\n\
\n\
$(OBJ_DIR) :\n\
	@mkdir $(OBJ_DIR)\n\
\n\
.PHONY : _submodules\n\
_submodules :\n\
	@$(MAKE) --no-print-directory -C $(SRCDIR)\n\
\n\
$(EXE) : CMD = $(CC) $(OBJ_DIR)/*.o $(LINKER_FLAGS) -o $(EXE)\n\
\n\
$(EXE) :\n\
	@$(PRINT_DEPTH_HEADER)printf \"$(LABEL_COLOR)═══[Linking executable]════$(NO_COLOR)\\n\"\n\
	@$(PRINT_DEPTH)printf \"$(LABEL_COLOR)╠═$(NO_COLOR)\";$(PRINT_EXE)\n\
	@$(PRINT_DEPTH)printf \"$(LABEL_COLOR)╚══$(NO_COLOR)\\n\"\n\
\n\
# ============================================================================================\n\
\n\
.PHONY : help\n\
help : TARGET_COLOR = \033[01;35m\n\
\n\
help :\n\
	@printf \"$(TARGET_COLOR)\\\"all\\\" or leave blank$(LABEL_COLOR):\\n\\n\
    1. Builds source files.\\n\\n\
    2. If there is no executable, links one together.$(NO_COLOR)\\n\\n\"\n\
	@printf \"$(TARGET_COLOR)\\\"link\\\"$(LABEL_COLOR):\\n\\n\
    1. Deletes executable.\\n\\n\
    2. Links executable.$(NO_COLOR)\\n\\n\"\n\
	@printf \"$(TARGET_COLOR)\\\"relink\\\"$(LABEL_COLOR):\\n\\n\
    1. Deletes executable.\\n\n\
    2. Builds source files.\\n\n\
    3. Links executable.$(NO_COLOR)\n\n\"\n\
	@printf \"$(TARGET_COLOR)\\\"nolink\\\"$(LABEL_COLOR):\\n\n\
    1. Builds source files.$(NO_COLOR)\n\n\"\n\
	@printf \"$(TARGET_COLOR)\\\"tree\\\"$(LABEL_COLOR):\\n\n\
    1. Print source tree.$(NO_COLOR)\\n\\n\"\n\
	@printf \"$(TARGET_COLOR)\\\"clean\\\"$(LABEL_COLOR):\\n\n\
    1. Deletes executable.\\n\n\
    2. Deletes objects directory.$(NO_COLOR)\\n\\n\"\n\
	@printf \"$(TARGET_COLOR)\\\"delete_executable\\\"$(LABEL_COLOR):\\n\n\
    1. Deletes executable.$(NO_COLOR)\\n\\n\"\n\
	@printf \"$(TARGET_COLOR)\\\"delete_objects\\\"$(LABEL_COLOR):\\n\n\
    1. Deletes objects directory.$(NO_COLOR)\\n\\n\"\n\
\n\
# ============================================================================================\n\
\n\
.PHONY : link\n\
link : _headerClean delete_executable _footerClean $(EXE)\n\
\n\
# ============================================================================================\n\
\n\
.PHONY : relink\n\
relink : _headerClean delete_executable _footerClean all\n\
\n\
# ============================================================================================\n\
\n\
.PHONY : nolink\n\
nolink : $(OBJ_DIR) _submodules\n\
\n\
# ============================================================================================\n\
\n\
.PHONY : tree\n\
tree :\n\
	@$(MAKE) --no-print-directory -C $(SRCDIR) tree\n\
\n\
# ============================================================================================\n\
\n\
.PHONY : clean\n\
clean : _headerClean delete_executable delete_objects _footerClean\n\
\n\
.PHONY : _headerClean\n\
_headerClean :\n\
	@$(PRINT_DEPTH_HEADER)printf \"$(LABEL_COLOR)════════[Cleaning]═════════$(NO_COLOR)\\n\"\n\
\n\
.PHONY : delete_executable\n\
delete_executable : CMD = rm $(EXE)\n\
\n\
delete_executable :\n\
	@-$(PRINT_DEPTH)printf \"$(LABEL_COLOR)╠═$(NO_COLOR)\";$(PRINT_EXE)\n\
\n\
.PHONY : delete_objects\n\
delete_objects : CMD = rm -r $(OBJ_DIR)\n\
\n\
delete_objects : $(OBJ_DIR)\n\
	@$(PRINT_DEPTH)printf \"$(LABEL_COLOR)╠═$(NO_COLOR)\";$(PRINT_EXE)\n\
\n\
.PHONY : _footerClean\n\
_footerClean :\n\
	@$(PRINT_DEPTH)printf \"$(LABEL_COLOR)╚══$(NO_COLOR)\\n\"\n\
\n\
# ============================================================================================";

#endif //__MAKEFILE_MAIN__