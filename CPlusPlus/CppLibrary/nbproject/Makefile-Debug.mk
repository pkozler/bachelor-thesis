#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Cygwin-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/ArrayList.o \
	${OBJECTDIR}/Arrays.o \
	${OBJECTDIR}/Boolean.o \
	${OBJECTDIR}/Byte.o \
	${OBJECTDIR}/Character.o \
	${OBJECTDIR}/Collections.o \
	${OBJECTDIR}/Double.o \
	${OBJECTDIR}/Float.o \
	${OBJECTDIR}/Integer.o \
	${OBJECTDIR}/LinkedList.o \
	${OBJECTDIR}/List.o \
	${OBJECTDIR}/Long.o \
	${OBJECTDIR}/Math_.o \
	${OBJECTDIR}/Scanner.o \
	${OBJECTDIR}/Short.o \
	${OBJECTDIR}/StringBuilder.o \
	${OBJECTDIR}/StringTokenizer.o \
	${OBJECTDIR}/String_.o \
	${OBJECTDIR}/System.o \
	${OBJECTDIR}/TestObject.o \
	${OBJECTDIR}/TestObjectComparator.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/test.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f13 \
	${TESTDIR}/TestFiles/f16 \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f3 \
	${TESTDIR}/TestFiles/f5 \
	${TESTDIR}/TestFiles/f15 \
	${TESTDIR}/TestFiles/f4 \
	${TESTDIR}/TestFiles/f6 \
	${TESTDIR}/TestFiles/f7 \
	${TESTDIR}/TestFiles/f14 \
	${TESTDIR}/TestFiles/f8 \
	${TESTDIR}/TestFiles/f1 \
	${TESTDIR}/TestFiles/f9 \
	${TESTDIR}/TestFiles/f11 \
	${TESTDIR}/TestFiles/f10 \
	${TESTDIR}/TestFiles/f12

# C Compiler Flags
CFLAGS=-std=c11 -lm -O2

# CC Compiler Flags
CCFLAGS=-std=c++11 -lm -O2
CXXFLAGS=-std=c++11 -lm -O2

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${TESTDIR}/TestFiles/f18.exe

${TESTDIR}/TestFiles/f18.exe: ${OBJECTFILES}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f18 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/ArrayList.o: ArrayList.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ArrayList.o ArrayList.cpp

${OBJECTDIR}/Arrays.o: Arrays.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Arrays.o Arrays.cpp

${OBJECTDIR}/Boolean.o: Boolean.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Boolean.o Boolean.cpp

${OBJECTDIR}/Byte.o: Byte.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Byte.o Byte.cpp

${OBJECTDIR}/Character.o: Character.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Character.o Character.cpp

${OBJECTDIR}/Collections.o: Collections.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Collections.o Collections.cpp

${OBJECTDIR}/Double.o: Double.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Double.o Double.cpp

${OBJECTDIR}/Float.o: Float.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Float.o Float.cpp

${OBJECTDIR}/Integer.o: Integer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Integer.o Integer.cpp

${OBJECTDIR}/LinkedList.o: LinkedList.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LinkedList.o LinkedList.cpp

${OBJECTDIR}/List.o: List.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/List.o List.cpp

${OBJECTDIR}/Long.o: Long.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Long.o Long.cpp

${OBJECTDIR}/Math_.o: Math_.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Math_.o Math_.cpp

${OBJECTDIR}/Scanner.o: Scanner.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Scanner.o Scanner.cpp

${OBJECTDIR}/Short.o: Short.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Short.o Short.cpp

${OBJECTDIR}/StringBuilder.o: StringBuilder.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/StringBuilder.o StringBuilder.cpp

${OBJECTDIR}/StringTokenizer.o: StringTokenizer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/StringTokenizer.o StringTokenizer.cpp

${OBJECTDIR}/String_.o: String_.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/String_.o String_.cpp

${OBJECTDIR}/System.o: System.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/System.o System.cpp

${OBJECTDIR}/TestObject.o: TestObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TestObject.o TestObject.cpp

${OBJECTDIR}/TestObjectComparator.o: TestObjectComparator.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TestObjectComparator.o TestObjectComparator.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/test.o: test.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/test.o test.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f13: ${TESTDIR}/tests/ArrayListTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}  -std=c++11 -lm -O2 -o ${TESTDIR}/TestFiles/f13 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f16: ${TESTDIR}/tests/ArraysTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f16 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/BooleanTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f3: ${TESTDIR}/tests/ByteTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f5: ${TESTDIR}/tests/CharacterTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f5 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f15: ${TESTDIR}/tests/CollectionsTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f15 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f4: ${TESTDIR}/tests/DoubleTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f4 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f6: ${TESTDIR}/tests/FloatTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f6 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f7: ${TESTDIR}/tests/IntegerTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f7 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f14: ${TESTDIR}/tests/LinkedListTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f14 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f8: ${TESTDIR}/tests/LongTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f8 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/MathTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f9: ${TESTDIR}/tests/ShortTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f9 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f11: ${TESTDIR}/tests/StringBuilderTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f11 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f10: ${TESTDIR}/tests/StringTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f10 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f12: ${TESTDIR}/tests/StringTokenizerTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f12 $^ ${LDLIBSOPTIONS} 


${TESTDIR}/tests/ArrayListTest.o: tests/ArrayListTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ArrayListTest.o tests/ArrayListTest.cpp


${TESTDIR}/tests/ArraysTest.o: tests/ArraysTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -I. -std=c++11 -lm -O2 -std=c++11 -lm -O2 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ArraysTest.o tests/ArraysTest.cpp


${TESTDIR}/tests/BooleanTest.o: tests/BooleanTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/BooleanTest.o tests/BooleanTest.cpp


${TESTDIR}/tests/ByteTest.o: tests/ByteTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ByteTest.o tests/ByteTest.cpp


${TESTDIR}/tests/CharacterTest.o: tests/CharacterTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -I. `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/CharacterTest.o tests/CharacterTest.cpp


${TESTDIR}/tests/CollectionsTest.o: tests/CollectionsTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/CollectionsTest.o tests/CollectionsTest.cpp


${TESTDIR}/tests/DoubleTest.o: tests/DoubleTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/DoubleTest.o tests/DoubleTest.cpp


${TESTDIR}/tests/FloatTest.o: tests/FloatTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/FloatTest.o tests/FloatTest.cpp


${TESTDIR}/tests/IntegerTest.o: tests/IntegerTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/IntegerTest.o tests/IntegerTest.cpp


${TESTDIR}/tests/LinkedListTest.o: tests/LinkedListTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/LinkedListTest.o tests/LinkedListTest.cpp


${TESTDIR}/tests/LongTest.o: tests/LongTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/LongTest.o tests/LongTest.cpp


${TESTDIR}/tests/MathTest.o: tests/MathTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/MathTest.o tests/MathTest.cpp


${TESTDIR}/tests/ShortTest.o: tests/ShortTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ShortTest.o tests/ShortTest.cpp


${TESTDIR}/tests/StringBuilderTest.o: tests/StringBuilderTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/StringBuilderTest.o tests/StringBuilderTest.cpp


${TESTDIR}/tests/StringTest.o: tests/StringTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/StringTest.o tests/StringTest.cpp


${TESTDIR}/tests/StringTokenizerTest.o: tests/StringTokenizerTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/StringTokenizerTest.o tests/StringTokenizerTest.cpp


${OBJECTDIR}/ArrayList_nomain.o: ${OBJECTDIR}/ArrayList.o ArrayList.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ArrayList.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ArrayList_nomain.o ArrayList.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ArrayList.o ${OBJECTDIR}/ArrayList_nomain.o;\
	fi

${OBJECTDIR}/Arrays_nomain.o: ${OBJECTDIR}/Arrays.o Arrays.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Arrays.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Arrays_nomain.o Arrays.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Arrays.o ${OBJECTDIR}/Arrays_nomain.o;\
	fi

${OBJECTDIR}/Boolean_nomain.o: ${OBJECTDIR}/Boolean.o Boolean.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Boolean.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Boolean_nomain.o Boolean.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Boolean.o ${OBJECTDIR}/Boolean_nomain.o;\
	fi

${OBJECTDIR}/Byte_nomain.o: ${OBJECTDIR}/Byte.o Byte.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Byte.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Byte_nomain.o Byte.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Byte.o ${OBJECTDIR}/Byte_nomain.o;\
	fi

${OBJECTDIR}/Character_nomain.o: ${OBJECTDIR}/Character.o Character.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Character.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Character_nomain.o Character.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Character.o ${OBJECTDIR}/Character_nomain.o;\
	fi

${OBJECTDIR}/Collections_nomain.o: ${OBJECTDIR}/Collections.o Collections.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Collections.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Collections_nomain.o Collections.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Collections.o ${OBJECTDIR}/Collections_nomain.o;\
	fi

${OBJECTDIR}/Double_nomain.o: ${OBJECTDIR}/Double.o Double.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Double.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Double_nomain.o Double.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Double.o ${OBJECTDIR}/Double_nomain.o;\
	fi

${OBJECTDIR}/Float_nomain.o: ${OBJECTDIR}/Float.o Float.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Float.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Float_nomain.o Float.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Float.o ${OBJECTDIR}/Float_nomain.o;\
	fi

${OBJECTDIR}/Integer_nomain.o: ${OBJECTDIR}/Integer.o Integer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Integer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Integer_nomain.o Integer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Integer.o ${OBJECTDIR}/Integer_nomain.o;\
	fi

${OBJECTDIR}/LinkedList_nomain.o: ${OBJECTDIR}/LinkedList.o LinkedList.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/LinkedList.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LinkedList_nomain.o LinkedList.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/LinkedList.o ${OBJECTDIR}/LinkedList_nomain.o;\
	fi

${OBJECTDIR}/List_nomain.o: ${OBJECTDIR}/List.o List.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/List.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/List_nomain.o List.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/List.o ${OBJECTDIR}/List_nomain.o;\
	fi

${OBJECTDIR}/Long_nomain.o: ${OBJECTDIR}/Long.o Long.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Long.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Long_nomain.o Long.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Long.o ${OBJECTDIR}/Long_nomain.o;\
	fi

${OBJECTDIR}/Math__nomain.o: ${OBJECTDIR}/Math_.o Math_.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Math_.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Math__nomain.o Math_.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Math_.o ${OBJECTDIR}/Math__nomain.o;\
	fi

${OBJECTDIR}/Scanner_nomain.o: ${OBJECTDIR}/Scanner.o Scanner.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Scanner.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Scanner_nomain.o Scanner.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Scanner.o ${OBJECTDIR}/Scanner_nomain.o;\
	fi

${OBJECTDIR}/Short_nomain.o: ${OBJECTDIR}/Short.o Short.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Short.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Short_nomain.o Short.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Short.o ${OBJECTDIR}/Short_nomain.o;\
	fi

${OBJECTDIR}/StringBuilder_nomain.o: ${OBJECTDIR}/StringBuilder.o StringBuilder.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/StringBuilder.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/StringBuilder_nomain.o StringBuilder.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/StringBuilder.o ${OBJECTDIR}/StringBuilder_nomain.o;\
	fi

${OBJECTDIR}/StringTokenizer_nomain.o: ${OBJECTDIR}/StringTokenizer.o StringTokenizer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/StringTokenizer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/StringTokenizer_nomain.o StringTokenizer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/StringTokenizer.o ${OBJECTDIR}/StringTokenizer_nomain.o;\
	fi

${OBJECTDIR}/String__nomain.o: ${OBJECTDIR}/String_.o String_.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/String_.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/String__nomain.o String_.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/String_.o ${OBJECTDIR}/String__nomain.o;\
	fi

${OBJECTDIR}/System_nomain.o: ${OBJECTDIR}/System.o System.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/System.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/System_nomain.o System.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/System.o ${OBJECTDIR}/System_nomain.o;\
	fi

${OBJECTDIR}/TestObject_nomain.o: ${OBJECTDIR}/TestObject.o TestObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/TestObject.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TestObject_nomain.o TestObject.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/TestObject.o ${OBJECTDIR}/TestObject_nomain.o;\
	fi

${OBJECTDIR}/TestObjectComparator_nomain.o: ${OBJECTDIR}/TestObjectComparator.o TestObjectComparator.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/TestObjectComparator.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TestObjectComparator_nomain.o TestObjectComparator.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/TestObjectComparator.o ${OBJECTDIR}/TestObjectComparator_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

${OBJECTDIR}/test_nomain.o: ${OBJECTDIR}/test.o test.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/test.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/test_nomain.o test.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/test.o ${OBJECTDIR}/test_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f13 || true; \
	    ${TESTDIR}/TestFiles/f16 || true; \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f3 || true; \
	    ${TESTDIR}/TestFiles/f5 || true; \
	    ${TESTDIR}/TestFiles/f15 || true; \
	    ${TESTDIR}/TestFiles/f4 || true; \
	    ${TESTDIR}/TestFiles/f6 || true; \
	    ${TESTDIR}/TestFiles/f7 || true; \
	    ${TESTDIR}/TestFiles/f14 || true; \
	    ${TESTDIR}/TestFiles/f8 || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	    ${TESTDIR}/TestFiles/f9 || true; \
	    ${TESTDIR}/TestFiles/f11 || true; \
	    ${TESTDIR}/TestFiles/f10 || true; \
	    ${TESTDIR}/TestFiles/f12 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${TESTDIR}/TestFiles/f18.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
