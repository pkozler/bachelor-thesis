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
	${OBJECTDIR}/String.o \
	${OBJECTDIR}/StringBuilder.o \
	${OBJECTDIR}/StringTokenizer.o \
	${OBJECTDIR}/System.o \
	${OBJECTDIR}/TestObject.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/test.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f3 \
	${TESTDIR}/TestFiles/f4 \
	${TESTDIR}/TestFiles/f5 \
	${TESTDIR}/TestFiles/f6 \
	${TESTDIR}/TestFiles/f7 \
	${TESTDIR}/TestFiles/f8 \
	${TESTDIR}/TestFiles/f9 \
	${TESTDIR}/TestFiles/f10 \
	${TESTDIR}/TestFiles/f11 \
	${TESTDIR}/TestFiles/f12 \
	${TESTDIR}/TestFiles/f1 \
	${TESTDIR}/TestFiles/f15 \
	${TESTDIR}/TestFiles/f16 \
	${TESTDIR}/TestFiles/f17 \
	${TESTDIR}/TestFiles/f18

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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${TESTDIR}/TestFiles/f14.exe

${TESTDIR}/TestFiles/f14.exe: ${OBJECTFILES}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c} -o ${TESTDIR}/TestFiles/f14 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/ArrayList.o: ArrayList.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ArrayList.o ArrayList.c

${OBJECTDIR}/Arrays.o: Arrays.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Arrays.o Arrays.c

${OBJECTDIR}/Boolean.o: Boolean.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Boolean.o Boolean.c

${OBJECTDIR}/Byte.o: Byte.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Byte.o Byte.c

${OBJECTDIR}/Character.o: Character.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Character.o Character.c

${OBJECTDIR}/Collections.o: Collections.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Collections.o Collections.c

${OBJECTDIR}/Double.o: Double.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Double.o Double.c

${OBJECTDIR}/Float.o: Float.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Float.o Float.c

${OBJECTDIR}/Integer.o: Integer.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Integer.o Integer.c

${OBJECTDIR}/LinkedList.o: LinkedList.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LinkedList.o LinkedList.c

${OBJECTDIR}/List.o: List.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/List.o List.c

${OBJECTDIR}/Long.o: Long.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Long.o Long.c

${OBJECTDIR}/Math_.o: Math_.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Math_.o Math_.c

${OBJECTDIR}/Scanner.o: Scanner.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Scanner.o Scanner.c

${OBJECTDIR}/Short.o: Short.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Short.o Short.c

${OBJECTDIR}/String.o: String.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/String.o String.c

${OBJECTDIR}/StringBuilder.o: StringBuilder.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/StringBuilder.o StringBuilder.c

${OBJECTDIR}/StringTokenizer.o: StringTokenizer.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/StringTokenizer.o StringTokenizer.c

${OBJECTDIR}/System.o: System.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/System.o System.c

${OBJECTDIR}/TestObject.o: TestObject.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TestObject.o TestObject.c

${OBJECTDIR}/main.o: main.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/test.o: test.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/test.o test.c

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/ArrayListTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f3: ${TESTDIR}/tests/ArraysTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f4: ${TESTDIR}/tests/BooleanTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f4 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f5: ${TESTDIR}/tests/ByteTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f5 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f6: ${TESTDIR}/tests/CharacterTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f6 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f7: ${TESTDIR}/tests/CollectionsTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f7 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f8: ${TESTDIR}/tests/DoubleTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f8 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f9: ${TESTDIR}/tests/FloatTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f9 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f10: ${TESTDIR}/tests/IntegerTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f10 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f11: ${TESTDIR}/tests/LinkedListTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f11 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f12: ${TESTDIR}/tests/LongTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f12 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/MathTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f15: ${TESTDIR}/tests/ShortTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f15 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f16: ${TESTDIR}/tests/StringBuilderTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f16 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f17: ${TESTDIR}/tests/StringTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f17 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f18: ${TESTDIR}/tests/StringTokenizerTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f18 $^ ${LDLIBSOPTIONS} 


${TESTDIR}/tests/ArrayListTest.o: tests/ArrayListTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ArrayListTest.o tests/ArrayListTest.c


${TESTDIR}/tests/ArraysTest.o: tests/ArraysTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ArraysTest.o tests/ArraysTest.c


${TESTDIR}/tests/BooleanTest.o: tests/BooleanTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/BooleanTest.o tests/BooleanTest.c


${TESTDIR}/tests/ByteTest.o: tests/ByteTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ByteTest.o tests/ByteTest.c


${TESTDIR}/tests/CharacterTest.o: tests/CharacterTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/CharacterTest.o tests/CharacterTest.c


${TESTDIR}/tests/CollectionsTest.o: tests/CollectionsTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/CollectionsTest.o tests/CollectionsTest.c


${TESTDIR}/tests/DoubleTest.o: tests/DoubleTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/DoubleTest.o tests/DoubleTest.c


${TESTDIR}/tests/FloatTest.o: tests/FloatTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/FloatTest.o tests/FloatTest.c


${TESTDIR}/tests/IntegerTest.o: tests/IntegerTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/IntegerTest.o tests/IntegerTest.c


${TESTDIR}/tests/LinkedListTest.o: tests/LinkedListTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/LinkedListTest.o tests/LinkedListTest.c


${TESTDIR}/tests/LongTest.o: tests/LongTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/LongTest.o tests/LongTest.c


${TESTDIR}/tests/MathTest.o: tests/MathTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/MathTest.o tests/MathTest.c


${TESTDIR}/tests/ShortTest.o: tests/ShortTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ShortTest.o tests/ShortTest.c


${TESTDIR}/tests/StringBuilderTest.o: tests/StringBuilderTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/StringBuilderTest.o tests/StringBuilderTest.c


${TESTDIR}/tests/StringTest.o: tests/StringTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/StringTest.o tests/StringTest.c


${TESTDIR}/tests/StringTokenizerTest.o: tests/StringTokenizerTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/StringTokenizerTest.o tests/StringTokenizerTest.c


${OBJECTDIR}/ArrayList_nomain.o: ${OBJECTDIR}/ArrayList.o ArrayList.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ArrayList.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ArrayList_nomain.o ArrayList.c;\
	else  \
	    ${CP} ${OBJECTDIR}/ArrayList.o ${OBJECTDIR}/ArrayList_nomain.o;\
	fi

${OBJECTDIR}/Arrays_nomain.o: ${OBJECTDIR}/Arrays.o Arrays.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Arrays.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Arrays_nomain.o Arrays.c;\
	else  \
	    ${CP} ${OBJECTDIR}/Arrays.o ${OBJECTDIR}/Arrays_nomain.o;\
	fi

${OBJECTDIR}/Boolean_nomain.o: ${OBJECTDIR}/Boolean.o Boolean.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Boolean.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Boolean_nomain.o Boolean.c;\
	else  \
	    ${CP} ${OBJECTDIR}/Boolean.o ${OBJECTDIR}/Boolean_nomain.o;\
	fi

${OBJECTDIR}/Byte_nomain.o: ${OBJECTDIR}/Byte.o Byte.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Byte.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Byte_nomain.o Byte.c;\
	else  \
	    ${CP} ${OBJECTDIR}/Byte.o ${OBJECTDIR}/Byte_nomain.o;\
	fi

${OBJECTDIR}/Character_nomain.o: ${OBJECTDIR}/Character.o Character.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Character.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Character_nomain.o Character.c;\
	else  \
	    ${CP} ${OBJECTDIR}/Character.o ${OBJECTDIR}/Character_nomain.o;\
	fi

${OBJECTDIR}/Collections_nomain.o: ${OBJECTDIR}/Collections.o Collections.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Collections.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Collections_nomain.o Collections.c;\
	else  \
	    ${CP} ${OBJECTDIR}/Collections.o ${OBJECTDIR}/Collections_nomain.o;\
	fi

${OBJECTDIR}/Double_nomain.o: ${OBJECTDIR}/Double.o Double.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Double.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Double_nomain.o Double.c;\
	else  \
	    ${CP} ${OBJECTDIR}/Double.o ${OBJECTDIR}/Double_nomain.o;\
	fi

${OBJECTDIR}/Float_nomain.o: ${OBJECTDIR}/Float.o Float.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Float.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Float_nomain.o Float.c;\
	else  \
	    ${CP} ${OBJECTDIR}/Float.o ${OBJECTDIR}/Float_nomain.o;\
	fi

${OBJECTDIR}/Integer_nomain.o: ${OBJECTDIR}/Integer.o Integer.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Integer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Integer_nomain.o Integer.c;\
	else  \
	    ${CP} ${OBJECTDIR}/Integer.o ${OBJECTDIR}/Integer_nomain.o;\
	fi

${OBJECTDIR}/LinkedList_nomain.o: ${OBJECTDIR}/LinkedList.o LinkedList.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/LinkedList.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LinkedList_nomain.o LinkedList.c;\
	else  \
	    ${CP} ${OBJECTDIR}/LinkedList.o ${OBJECTDIR}/LinkedList_nomain.o;\
	fi

${OBJECTDIR}/List_nomain.o: ${OBJECTDIR}/List.o List.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/List.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/List_nomain.o List.c;\
	else  \
	    ${CP} ${OBJECTDIR}/List.o ${OBJECTDIR}/List_nomain.o;\
	fi

${OBJECTDIR}/Long_nomain.o: ${OBJECTDIR}/Long.o Long.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Long.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Long_nomain.o Long.c;\
	else  \
	    ${CP} ${OBJECTDIR}/Long.o ${OBJECTDIR}/Long_nomain.o;\
	fi

${OBJECTDIR}/Math__nomain.o: ${OBJECTDIR}/Math_.o Math_.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Math_.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Math__nomain.o Math_.c;\
	else  \
	    ${CP} ${OBJECTDIR}/Math_.o ${OBJECTDIR}/Math__nomain.o;\
	fi

${OBJECTDIR}/Scanner_nomain.o: ${OBJECTDIR}/Scanner.o Scanner.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Scanner.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Scanner_nomain.o Scanner.c;\
	else  \
	    ${CP} ${OBJECTDIR}/Scanner.o ${OBJECTDIR}/Scanner_nomain.o;\
	fi

${OBJECTDIR}/Short_nomain.o: ${OBJECTDIR}/Short.o Short.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Short.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Short_nomain.o Short.c;\
	else  \
	    ${CP} ${OBJECTDIR}/Short.o ${OBJECTDIR}/Short_nomain.o;\
	fi

${OBJECTDIR}/String_nomain.o: ${OBJECTDIR}/String.o String.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/String.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/String_nomain.o String.c;\
	else  \
	    ${CP} ${OBJECTDIR}/String.o ${OBJECTDIR}/String_nomain.o;\
	fi

${OBJECTDIR}/StringBuilder_nomain.o: ${OBJECTDIR}/StringBuilder.o StringBuilder.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/StringBuilder.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/StringBuilder_nomain.o StringBuilder.c;\
	else  \
	    ${CP} ${OBJECTDIR}/StringBuilder.o ${OBJECTDIR}/StringBuilder_nomain.o;\
	fi

${OBJECTDIR}/StringTokenizer_nomain.o: ${OBJECTDIR}/StringTokenizer.o StringTokenizer.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/StringTokenizer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/StringTokenizer_nomain.o StringTokenizer.c;\
	else  \
	    ${CP} ${OBJECTDIR}/StringTokenizer.o ${OBJECTDIR}/StringTokenizer_nomain.o;\
	fi

${OBJECTDIR}/System_nomain.o: ${OBJECTDIR}/System.o System.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/System.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/System_nomain.o System.c;\
	else  \
	    ${CP} ${OBJECTDIR}/System.o ${OBJECTDIR}/System_nomain.o;\
	fi

${OBJECTDIR}/TestObject_nomain.o: ${OBJECTDIR}/TestObject.o TestObject.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/TestObject.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TestObject_nomain.o TestObject.c;\
	else  \
	    ${CP} ${OBJECTDIR}/TestObject.o ${OBJECTDIR}/TestObject_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.c;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

${OBJECTDIR}/test_nomain.o: ${OBJECTDIR}/test.o test.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/test.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/test_nomain.o test.c;\
	else  \
	    ${CP} ${OBJECTDIR}/test.o ${OBJECTDIR}/test_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f3 || true; \
	    ${TESTDIR}/TestFiles/f4 || true; \
	    ${TESTDIR}/TestFiles/f5 || true; \
	    ${TESTDIR}/TestFiles/f6 || true; \
	    ${TESTDIR}/TestFiles/f7 || true; \
	    ${TESTDIR}/TestFiles/f8 || true; \
	    ${TESTDIR}/TestFiles/f9 || true; \
	    ${TESTDIR}/TestFiles/f10 || true; \
	    ${TESTDIR}/TestFiles/f11 || true; \
	    ${TESTDIR}/TestFiles/f12 || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	    ${TESTDIR}/TestFiles/f15 || true; \
	    ${TESTDIR}/TestFiles/f16 || true; \
	    ${TESTDIR}/TestFiles/f17 || true; \
	    ${TESTDIR}/TestFiles/f18 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${TESTDIR}/TestFiles/f14.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
