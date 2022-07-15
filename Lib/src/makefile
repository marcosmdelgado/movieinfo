################################################################################
#                                                                              
# Description..:  makefile                                                
# Author......: Marcos M. Delgado                                               
# Commets:  Libs Project
#                                                                              
################################################################################          


########################################
# Directories                          
########################################

LibDir	= ..
SrcDir	= $(LibDir)/src
IncDir	= $(LibDir)/include
ObjDir	= $(LibDir)/obj
OutDir	= $(LibDir)/obj

# External lib
IncExternalDir = $(IncDir)/external
ObjExternalDir = $(ObjDir)/external

# Utilities lib
SrcUtilitiesDir = $(SrcDir)/utilities
IncUtilitiesDir = $(IncDir)/utilities
ObjUtilitiesDir = $(ObjDir)/utilities
OutUtilitiesDir = $(OutDir)/utilities

########################################
# Files                            
########################################

# External
IncJson   = $(IncExternalDir)/json.hpp
#ObjJson   = $(ObjUtilitiesDir)/json.o

# Utilities
IncRating     = $(IncUtilitiesDir)/Rating.h
IncMovie     = $(IncUtilitiesDir)/Movie.h
IncRestOMDB     = $(IncUtilitiesDir)/RestOMDB.h

SrcRating     = $(SrcUtilitiesDir)/Rating.cpp
SrcMovie     = $(SrcUtilitiesDir)/Movie.cpp
SrcRestOMDB     = $(SrcUtilitiesDir)/RestOMDB.cpp

ObjRating   = $(ObjUtilitiesDir)/Rating.o
ObjMovie    = $(ObjUtilitiesDir)/Movie.o
ObjRestOMDB   = $(ObjUtilitiesDir)/RestOMDB.o
			
########################################
# Compilation and linking directives
########################################

####################
# External libraries
####################
#SOCKET = -lsocket -lnsl
#THREAD = -lpthread
#STANDERC = -lc
#REALTIME = -lrt
CURL = -curl

####################
# Compiler
####################

#CC	= gcc
CC	= g++

####################
# Build directives 
####################
DEFINES		= -DBASICS_LIBRARY
CFLAGS		= -pipe -O2 -Wall -Wextra -fPIC $(DEFINES)
CXXFLAGS	= -pipe -O2 -std=gnu++1z -Wall -Wextra -fPIC $(DEFINES)
INCLUDES 	= -I$(IncDir) -I$(IncExternalDir) -I$(IncUtilitiesDir) 

####################
# Messages      
####################
MSG_COMP = @echo "\n -> Compiling objetct: $@ "
MSG_FINAL = @echo "\n -> Generated $@ objetcts!"
SKIP_TEXT_LINE   = @echo "\n"

########################################
# Projects
########################################
all: utilities

########################################
# Dependencies
########################################

## Utilities
DepRating = $(SrcRating) $(IncRating) 

DepMovie = $(SrcMovie) $(IncMovie) \
				$(ObjRating) $(DepRating)

DepRestOMDB = $(SrcRestOMDB) $(IncRestOMDB) $(IncJson) \
				$(ObjMovie) $(DepMovie) \
				$(ObjRating) $(DepRating) 
						
DepUtilities = $(ObjRestOMDB) $(DepRestOMDB) $(IncJson) \
				$(ObjMovie) $(DepMovie) \
				$(ObjRating) $(DepRating) 
			
			
########################################
# Compilation
########################################

$(ObjRating): $(DepRating)
	$(MSG_COMP)	
	$(CC) -c $(CXXFLAGS) $(INCLUDES) $(SrcRating) -o $(ObjRating)
#	$(SKIP_TEXT_LINE)
	
$(ObjMovie): $(DepMovie)
	$(MSG_COMP)	
	$(CC) -c $(CXXFLAGS) $(INCLUDES) $(SrcMovie) -o $(ObjMovie)
#	$(SKIP_TEXT_LINE)	
		
$(ObjRestOMDB): $(DepRestOMDB)
	$(MSG_COMP)	
	$(CC) -c $(CXXFLAGS) $(INCLUDES) $(SrcRestOMDB) -o $(ObjRestOMDB)
#	$(SKIP_TEXT_LINE)	
			

utilities:	$(DepUtilities)
		$(MSG_FINAL)
		$(SKIP_TEXT_LINE)
		
clean:
	rm -f $(OutUtilitiesDir)/*.o
		
