## Below we define some variables for the compiler we use, as well as the flags
## used during compilation and linking.
## Later, if we wish to change the compiler or flags, we can do so in one place
## (by changing these variable values) rather than changing it in many places
## in the Makefile.
## Variable names are conventionally all upper cased.
## By convention, the variable CXX is used for the C++ compiler.
## By convention, the variable CXXFLAGS is used for C++ compilation flags.
## By convention, the variable LDFLAGS is used for linking flags.
CXX      = clang++
CXXFLAGS = -g -Wall -Wextra
LDFLAGS  = -g

## We can reference variables with ${VARIABLE_NAME}.
## The $@ variable refers to the name of the rule target (final_program here)
## The $^ variable refers to the list of prerequisites (after the colon)
## The $< variable refers to the *first* prerequisite
final_program: Point.o Rectangle.o main.o
	${CXX} ${LDFLAGS} -o $@ $^
## dollar sign, brackets then variable name *invokes* the variable

## make knows that, when we have a target named X.o
## and a dependency named X.cpp, it should use CXX
## and CXX flags to compile X.cpp into X.o.
## All we need to do is provide the correct dependencies!
Point.o:     Point.cpp Point.h
Rectangle.o: Rectangle.cpp Rectangle.h Point.h
main.o:      main.cpp Point.h Rectangle.h

## It's common to have a "clean" rule that removes
## the exectuable file, .o files, and any temporary files.
clean:
	rm -f final_program *.o *~