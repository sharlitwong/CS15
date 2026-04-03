#########################################################
#                    PROJECT 3: Zap Makefile            #
#########################################################
# Charlotte Wong (cwong22)

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS  = -g3
#LDFLAGS  = -g3 -lncurses

#zap rule, makes the executable
zap: main.o HuffmanCoder.o HuffmanTreeNode.o ZapUtil.o
	$(CXX) $(LDFLAGS) -o zap $^

#minpq_example rule, makes the executable
minpq_example: minpq_example.o HuffmanTreeNode.o
	$(CXX) ${LDFLAGS} -o minpq_example $^

#This rule builds minpq_example.o
minpq_example.o: minpq_example.cpp HuffmanTreeNode.h
	$(CXX) $(CXXFLAGS) -c minpq_example.cpp

#ZapUtilExample rule, makes the executable
ZapUtilExample: ZapUtilExample.o HuffmanTreeNode.o ZapUtil.o
	$(CXX) ${LDFLAGS} -o ZapUtilExample $^

#This rule builds ZapUtilExample.o
ZapUtilExample.o: ZapUtilExample.cpp HuffmanTreeNode.h ZapUtil.h
	$(CXX) $(CXXFLAGS) -c ZapUtilExample.cpp

#This rule builds main.o
main.o: main.cpp HuffmanCoder.h
	$(CXX) $(CXXFLAGS) -c main.cpp

#This rule builds HuffmanCoder.o
HuffmanCoder.o: HuffmanCoder.cpp HuffmanCoder.h
	$(CXX) $(CXXFLAGS) -c HuffmanCoder.cpp

#This rule builds phaseOne.o
phaseOne.o: phaseOne.cpp phaseOne.h
	$(CXX) $(CXXFLAGS) -c phaseOne.cpp

# The below rule will be used by unit_test.
unit_test: unit_test_driver.o HuffmanCoder.o HuffmanTreeNode.o ZapUtil.o
	$(CXX) $(CXXFLAGS) $^

##
## Here is a special rule that removes all .o files besides the provided ones 
## (ZapUtil.o and HuffmanTreeNode.o), all temporary files 
## (ending with ~), and a.out produced by running unit_test. First, we find
## all .o files that are not provided files, then we run rm -f on each found
## file using the -exec find flag. Second, we delete the temporary files
## and a.out. @ is used to suppress stdout.
## 
## You do not need to modify or further comment this rule!
##
clean:
	@find . -type f \( \
		-name '*.o' ! -name 'HuffmanTreeNode.o' \
		! -name 'ZapUtil.o' \) -exec rm -f {} \;
	@rm -f *~ a.out

