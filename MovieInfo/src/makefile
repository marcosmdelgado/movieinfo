################################################################################
#                                                                              
# Description..:  makefile                                                
# Author......: Marcos M. Delgado                                               
# Commets:  MovieInfo Project
#                                                                              
################################################################################          


########################################
# Directories                          
########################################

AppDir	= ..
SrcAppDir	= $(AppDir)/src
IncAppDir	= $(AppDir)/include
ObjAppDir	= $(AppDir)/obj
OutAppDir	= $(AppDir)/bin

LibDir	= ../../Lib
IncLibDir	= $(LibDir)/include
ObjLibDir	= $(LibDir)/obj
MakeLibDir =  $(LibDir)/src

# External lib
IncExternalDir = $(IncLibDir)/external
ObjExternalDir = $(ObjLibDir)/external

# Lib Utilities
IncUtilitiesDir = $(IncLibDir)/utilities
ObjUtilitiesDir = $(ObjLibDir)/utilities

########################################
# Files                            
########################################

# External

IncJson   = $(IncExternalDir)/json.hpp

# Utilities

IncRating     = $(IncUtilitiesDir)/Rating.h
IncMovie     = $(IncUtilitiesDir)/Movie.h
IncRestOMDB     = $(IncUtilitiesDir)/RestOMDB.h

ObjRating   = $(ObjUtilitiesDir)/Rating.o
ObjMovie    = $(ObjUtilitiesDir)/Movie.o
ObjRestOMDB   = $(ObjUtilitiesDir)/RestOMDB.o

# MovieInfo

SrcMovieInfo	= $(SrcAppDir)/MovieInfo.cpp
ObjMovieInfo = $(ObjAppDir)/MovieInfo.o 

# Objetcs
		
ObjsUtilities	= 	$(ObjRating) $(ObjMovie) $(ObjRestOMDB) 
ObjsMovieInfo =  $(ObjMovieInfo)
			
########################################
# Compilation and linking directives
########################################

####################
# External libraries
####################
EXT_LIBS   =  -lrt -lcurl

####################
# Messages      
####################
MSG_COMP = @echo "\n -> Compiling objetct: $@ "
MSG_LINK = @echo "\n--> Generating executable: $@"
MSG_FINAL = @echo "\n -> Generated $@ objetcts!"
SKIP_TEXT_LINE   = @echo "\n"

MSG_MOV = @echo " -> Movendo objeto: $@ \n"
MSG_COPY_OBJECTS= @echo " -> Copiando objetos $@"
MSG_COPY_INCLUDES= @echo " -> Copiando cabeçalhos $@"
MSG_COPY_IMAGES= @echo " -> Copiando imagens $@"
MSG_COPY_BIN= @echo " -> Copiando executáveis $@"

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
INCLUDES 	= -I$(IncAppDir) -I$(IncExternalDir) -I$(IncUtilitiesDir) 
LFLAGS        = -Wl,-O1 

########################################
# Projects
########################################

all: movieinfo

########################################
# Dependencies
########################################

DepMovieInfo =  $(SrcMovieInfo) $(IncMovieInfo) \
				$(ObjRestOMDB) $(IncRestOMDB) $(IncJson) \
				$(ObjMovie) $(IncMovie) \
				$(ObjRating) $(IncRating)
				
DepLibsMovieInfo =  $(ObjMovieInfo) \
				$(ObjRestOMDB) $(IncRestOMDB) $(IncJson) \
				$(ObjMovie) $(IncMovie) \
				$(ObjRating) $(IncRating)
				
########################################
# Compilation
########################################

$(ObjRating): 
	cd $(MakeLibDir) && $(MAKE) 
		
$(ObjMovie): 
	cd $(MakeLibDir) && $(MAKE) 

$(ObjRestOMDB): 
	cd $(MakeLibDir) && $(MAKE) 

$(ObjMovieInfo): $(DepMovieInfo)
	$(MSG_COMP)	
	$(CC) -c $(CXXFLAGS) $(INCLUDES) $(SrcMovieInfo) -o $(ObjMovieInfo)
	$(SKIP_TEXT_LINE)	
				
########################################
# Linkagem                             #
########################################

movieinfo:  $(DepLibsMovieInfo) 
	$(MSG_LINK) 
	$(SKIP_TEXT_LINE)
	$(CC) $(LFLAGS) -o $(OutAppDir)/movieinfo $(ObjsMovieInfo) $(ObjsUtilities)  $(EXT_LIBS)
	$(MSG_FINAL)
	$(SKIP_TEXT_LINE)	

clean:
	rm -f $(OutAppDir)/*
	rm -f $(ObjAppDir)/*.o

allclean:
	rm -f $(OutAppDir)/*
	rm -f $(ObjAppDir)/*.o
	rm -f $(ObjUtilitiesDir)/*.o
