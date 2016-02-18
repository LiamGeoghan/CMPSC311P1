# make file
#environments

CC=gcc
CFLAGS=-I. -c -g 
LINKARGS=-lm
LIBS=-lm

#files
OBJECT_FILES=	wordc.o 

#productions
all : wordc

wordc : $(OBJECT_FILES)
	$(CC) $(LINKARGS) $(OBJECT_FILES) -o $@ $(LIBS)

wordc.o : wordc.c wordc.h
	$(CC) $(CFLAGS) $< -o $@


inputfile: input1.txt   input2.txt  input3.txt 

countoutputfile : output1-count.txt  output2-count.txt output3-count.txt 

runtimeoutputfile:  output1-runtime.txt output2-runtime.txt output3-runtime.txt


testoutput1.txt: input1.txt wordc
	./wordc  input1.txt  output1-count.txt output1-runtime.txt

testoutput2.txt : input2.txt wordc
	./wordc  input2.txt  output2-count.txt output2-runtime.txt

testoutput3.txt : input3.txt wordc
	./wordc  input3.txt  output3-count.txt output3-runtime.txt

clean : 
	rm -f wordc $(OBJECT_FILES)
