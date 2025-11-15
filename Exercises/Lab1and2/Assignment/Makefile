CC=g++ #Name of compiler
FLAGS=-std=c++20 -w #Compiler flags (the s makes it silent)
TARGET=AnalyseData_program #Executable name
OBJECTS=CustomFunctions.o AnalyseData.o
LIBS=-I ../../GNUplot/ -lboost_iostreams

#First target in Makefile is default
${TARGET}:${OBJECTS} #Make target from objects
	@echo "Linking..."
	${CC} ${FLAGS} ${OBJECTS} ${LIBS} -o ${TARGET}
	@make clean

CustomFunctions.o : CustomFunctions.cxx
	${CC} ${FLAGS} ${LIBS} -c CustomFunctions.cxx
	
AnalyseData.o : AnalyseData.cxx
	${CC} ${FLAGS} ${LIBS} -c AnalyseData.cxx


clean: #No targets just run shell command to rm object files and emacs backups
	@rm -f *.o *~

cleantarget: #Delete the exectuable
	@rm -f ${TARGET}