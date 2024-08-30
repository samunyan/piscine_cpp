# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 11:05:16 by samunyan          #+#    #+#              #
#    Updated: 2023/10/26 02:09:47 by samunyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project files
NAME		=	mutant
SRCS		=	main.cpp
OBJS		=	$(SRCS:.cpp=.o)
HEADERS		=	MutantStack.hpp

# Compiler flags
SYSTEM		 := $(shell uname)
ifeq ($(SYSTEM),Linux)
CXX			=	clang++
else
CXX			= 	c++
endif
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98

# Debug build settings
DBGDIR = debug
DBGEXE = $(DBGDIR)/$(NAME)
DBGOBJS = $(addprefix $(DBGDIR)/, $(OBJS))
DBGCXXFLAGS = $(CXXFLAGS) $(FLAGS)

# Release build settings
RELDIR = .
RELEXE = $(RELDIR)/$(NAME)
RELOBJS = $(addprefix $(RELDIR)/, $(OBJS))
RELCXXFLAGS = $(CXXFLAGS)

.PHONY:		all release clean fclean re debug prep

# Default build
all:		release

# Release rules
release:	$(RELEXE)

$(RELEXE):	$(RELOBJS) $(HEADERS)
			@$(CXX) $(RELCXXFLAGS) $(RELOBJS) -o $@
			@test -z '$(filter %.o,$?)' || echo $(BGreen)√$(Color_Off)$(BBlue)Compilation done. \
												Usage:$(BGreen)$(UGreen)$(RELEXE) $(Color_Off);

$(RELDIR)/%.o: %.cpp $(HEADERS)
			@$(CXX) $(RELCXXFLAGS) -c $< -o $@

# Debug rules
.FORCE:
			@rm -f $(RELOBJS) $(DBGOBJS)

$(FLAGS):	.FORCE

debug:		prep $(DBGEXE)

$(DBGEXE):	$(FLAGS) $(DBGOBJS) $(HEADERS)
			@echo $(BYellow)Debugging with following flags: $(FLAGS)$(Color_Off);
			@$(CXX) $(DBGCXXFLAGS) $(DBGOBJS) -o $(DBGEXE)
			@test -z '$(filter %.o,$?)' || echo $(BGreen)√$(Color_Off)$(BBlue)Compilation done. \
												Usage:$(BGreen)$(UGreen)./$(DBGEXE) $(Color_Off);

$(DBGDIR)/%.o: %.cpp $(HEADERS)
			@$(CXX) $(DBGCXXFLAGS) -c $< -o $@

# Other rules
prep:
			@mkdir -p $(DBGDIR)

clean:
			@rm -f $(RELOBJS) $(DBGOBJS)
			@rm -rf $(DBGDIR)
			@echo $(BGreen)√$(Color_Off)$(BBlue)Object files removed.$(Color_Off);

fclean:		clean
			@rm -f $(RELEXE) $(DBGEXE)
			@echo $(BGreen)√$(Color_Off)$(BBlue)Executable removed.$(Color_Off);

re:			fclean all

# Colors
## Reset
Color_Off='\033[0m'       # Text Reset
## Regular Colors
Black='\033[0;30m'        # Black
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Blue='\033[0;34m'         # Blue
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan
White='\033[0;37m'        # White
## Bold
BBlack='\033[1;30m'       # Black
BRed='\033[1;31m'         # Red
BGreen='\033[1;32m'       # Green
BYellow='\033[1;33m'      # Yellow
BBlue='\033[1;34m'        # Blue
BPurple='\033[1;35m'      # Purple
BCyan='\033[1;36m'        # Cyan
BWhite='\033[1;37m'       # White
## Underline
UBlack='\033[4;30m'       # Black
URed='\033[4;31m'         # Red
UGreen='\033[4;32m'       # Green
UYellow='\033[4;33m'      # Yellow
UBlue='\033[4;34m'        # Blue
UPurple='\033[4;35m'      # Purple
UCyan='\033[4;36m'        # Cyan
UWhite='\033[4;37m'       # White
## Background
On_Black='\033[40m'       # Black
On_Red='\033[41m'         # Red
On_Green='\033[42m'       # Green
On_Yellow='\033[43m'      # Yellow
On_Blue='\033[44m'        # Blue
On_Purple='\033[45m'      # Purple
On_Cyan='\033[46m'        # Cyan
On_White='\033[47m'       # White
## Bold High Intensity
BIBlack='\033[1;90m'      # Black
BIRed='\033[1;91m'        # Red
BIGreen='\033[1;92m'      # Green
BIYellow='\033[1;93m'     # Yellow
BIBlue='\033[1;94m'       # Blue

