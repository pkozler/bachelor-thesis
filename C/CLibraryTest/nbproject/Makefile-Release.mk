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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/2078953063/ArrayList.o \
	${OBJECTDIR}/_ext/2078953063/Arrays.o \
	${OBJECTDIR}/_ext/2078953063/Boolean.o \
	${OBJECTDIR}/_ext/2078953063/Byte.o \
	${OBJECTDIR}/_ext/2078953063/Character.o \
	${OBJECTDIR}/_ext/2078953063/Collections.o \
	${OBJECTDIR}/_ext/2078953063/Double.o \
	${OBJECTDIR}/_ext/2078953063/Float.o \
	${OBJECTDIR}/_ext/2078953063/Integer.o \
	${OBJECTDIR}/_ext/2078953063/LinkedList.o \
	${OBJECTDIR}/_ext/2078953063/List.o \
	${OBJECTDIR}/_ext/2078953063/Long.o \
	${OBJECTDIR}/_ext/2078953063/Math_.o \
	${OBJECTDIR}/_ext/2078953063/Scanner.o \
	${OBJECTDIR}/_ext/2078953063/Short.o \
	${OBJECTDIR}/_ext/2078953063/StringBuilder.o \
	${OBJECTDIR}/_ext/2078953063/StringTokenizer.o \
	${OBJECTDIR}/_ext/2078953063/String_.o \
	${OBJECTDIR}/_ext/2078953063/System.o \
	${OBJECTDIR}/_ext/2078953063/TestObject.o \
	${OBJECTDIR}/PrintStreamTest.o \
	${OBJECTDIR}/ScannerTest.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/test.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1 \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f3 \
	${TESTDIR}/TestFiles/f4 \
	${TESTDIR}/TestFiles/f8 \
	${TESTDIR}/TestFiles/f5 \
	${TESTDIR}/TestFiles/f6 \
	${TESTDIR}/TestFiles/f7 \
	${TESTDIR}/TestFiles/f9 \
	${TESTDIR}/TestFiles/f10 \
	${TESTDIR}/TestFiles/f11 \
	${TESTDIR}/TestFiles/f12 \
	${TESTDIR}/TestFiles/f13 \
	${TESTDIR}/TestFiles/f14 \
	${TESTDIR}/TestFiles/f15 \
	${TESTDIR}/TestFiles/f16

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/clibrarytest.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/clibrarytest.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/clibrarytest ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/2078953063/ArrayList.o: ../CLibrary/ArrayList.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/ArrayList.o ../CLibrary/ArrayList.c

${OBJECTDIR}/_ext/2078953063/Arrays.o: ../CLibrary/Arrays.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/Arrays.o ../CLibrary/Arrays.c

${OBJECTDIR}/_ext/2078953063/Boolean.o: ../CLibrary/Boolean.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/Boolean.o ../CLibrary/Boolean.c

${OBJECTDIR}/_ext/2078953063/Byte.o: ../CLibrary/Byte.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/Byte.o ../CLibrary/Byte.c

${OBJECTDIR}/_ext/2078953063/Character.o: ../CLibrary/Character.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/Character.o ../CLibrary/Character.c

${OBJECTDIR}/_ext/2078953063/Collections.o: ../CLibrary/Collections.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/Collections.o ../CLibrary/Collections.c

${OBJECTDIR}/_ext/2078953063/Double.o: ../CLibrary/Double.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/Double.o ../CLibrary/Double.c

${OBJECTDIR}/_ext/2078953063/Float.o: ../CLibrary/Float.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/Float.o ../CLibrary/Float.c

${OBJECTDIR}/_ext/2078953063/Integer.o: ../CLibrary/Integer.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/Integer.o ../CLibrary/Integer.c

${OBJECTDIR}/_ext/2078953063/LinkedList.o: ../CLibrary/LinkedList.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/LinkedList.o ../CLibrary/LinkedList.c

${OBJECTDIR}/_ext/2078953063/List.o: ../CLibrary/List.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/List.o ../CLibrary/List.c

${OBJECTDIR}/_ext/2078953063/Long.o: ../CLibrary/Long.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/Long.o ../CLibrary/Long.c

${OBJECTDIR}/_ext/2078953063/Math_.o: ../CLibrary/Math_.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/Math_.o ../CLibrary/Math_.c

${OBJECTDIR}/_ext/2078953063/Scanner.o: ../CLibrary/Scanner.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/Scanner.o ../CLibrary/Scanner.c

${OBJECTDIR}/_ext/2078953063/Short.o: ../CLibrary/Short.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/Short.o ../CLibrary/Short.c

${OBJECTDIR}/_ext/2078953063/StringBuilder.o: ../CLibrary/StringBuilder.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/StringBuilder.o ../CLibrary/StringBuilder.c

${OBJECTDIR}/_ext/2078953063/StringTokenizer.o: ../CLibrary/StringTokenizer.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/StringTokenizer.o ../CLibrary/StringTokenizer.c

${OBJECTDIR}/_ext/2078953063/String_.o: ../CLibrary/String_.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/String_.o ../CLibrary/String_.c

${OBJECTDIR}/_ext/2078953063/System.o: ../CLibrary/System.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/System.o ../CLibrary/System.c

${OBJECTDIR}/_ext/2078953063/TestObject.o: ../CLibrary/TestObject.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/TestObject.o ../CLibrary/TestObject.c

${OBJECTDIR}/PrintStreamTest.o: PrintStreamTest.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PrintStreamTest.o PrintStreamTest.c

${OBJECTDIR}/ScannerTest.o: ScannerTest.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ScannerTest.o ScannerTest.c

${OBJECTDIR}/main.o: main.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/test.o: test.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/test.o test.c

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/ArrayListTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/ArraysTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f3: ${TESTDIR}/tests/BooleanTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f4: ${TESTDIR}/tests/ByteTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f4 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f8: ${TESTDIR}/tests/CharacterTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f8 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f5: ${TESTDIR}/tests/CollectionsTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f5 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f6: ${TESTDIR}/tests/DoubleTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f6 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f7: ${TESTDIR}/tests/FloatTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f7 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f9: ${TESTDIR}/tests/IntegerTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f9 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f10: ${TESTDIR}/tests/LinkedListTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f10 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f11: ${TESTDIR}/tests/LongTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f11 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f12: ${TESTDIR}/tests/MathTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f12 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f13: ${TESTDIR}/tests/ShortTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f13 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f14: ${TESTDIR}/tests/StringBuilderTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f14 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f15: ${TESTDIR}/tests/StringTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f15 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f16: ${TESTDIR}/tests/StringTokenizerTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f16 $^ ${LDLIBSOPTIONS} 


${TESTDIR}/tests/ArrayListTest.o: tests/ArrayListTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ArrayListTest.o tests/ArrayListTest.c


${TESTDIR}/tests/ArraysTest.o: tests/ArraysTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ArraysTest.o tests/ArraysTest.c


${TESTDIR}/tests/BooleanTest.o: tests/BooleanTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/BooleanTest.o tests/BooleanTest.c


${TESTDIR}/tests/ByteTest.o: tests/ByteTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ByteTest.o tests/ByteTest.c


${TESTDIR}/tests/CharacterTest.o: tests/CharacterTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/CharacterTest.o tests/CharacterTest.c


${TESTDIR}/tests/CollectionsTest.o: tests/CollectionsTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/CollectionsTest.o tests/CollectionsTest.c


${TESTDIR}/tests/DoubleTest.o: tests/DoubleTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/DoubleTest.o tests/DoubleTest.c


${TESTDIR}/tests/FloatTest.o: tests/FloatTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/FloatTest.o tests/FloatTest.c


${TESTDIR}/tests/IntegerTest.o: tests/IntegerTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/IntegerTest.o tests/IntegerTest.c


${TESTDIR}/tests/LinkedListTest.o: tests/LinkedListTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/LinkedListTest.o tests/LinkedListTest.c


${TESTDIR}/tests/LongTest.o: tests/LongTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/LongTest.o tests/LongTest.c


${TESTDIR}/tests/MathTest.o: tests/MathTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/MathTest.o tests/MathTest.c


${TESTDIR}/tests/ShortTest.o: tests/ShortTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ShortTest.o tests/ShortTest.c


${TESTDIR}/tests/StringBuilderTest.o: tests/StringBuilderTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/StringBuilderTest.o tests/StringBuilderTest.c


${TESTDIR}/tests/StringTest.o: tests/StringTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/StringTest.o tests/StringTest.c


${TESTDIR}/tests/StringTokenizerTest.o: tests/StringTokenizerTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/StringTokenizerTest.o tests/StringTokenizerTest.c


${OBJECTDIR}/_ext/2078953063/ArrayList_nomain.o: ${OBJECTDIR}/_ext/2078953063/ArrayList.o ../CLibrary/ArrayList.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/2078953063/ArrayList.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/ArrayList_nomain.o ../CLibrary/ArrayList.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/2078953063/ArrayList.o ${OBJECTDIR}/_ext/2078953063/ArrayList_nomain.o;\
	fi

${OBJECTDIR}/_ext/2078953063/Arrays_nomain.o: ${OBJECTDIR}/_ext/2078953063/Arrays.o ../CLibrary/Arrays.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/2078953063/Arrays.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/Arrays_nomain.o ../CLibrary/Arrays.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/2078953063/Arrays.o ${OBJECTDIR}/_ext/2078953063/Arrays_nomain.o;\
	fi

${OBJECTDIR}/_ext/2078953063/Boolean_nomain.o: ${OBJECTDIR}/_ext/2078953063/Boolean.o ../CLibrary/Boolean.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/2078953063/Boolean.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/Boolean_nomain.o ../CLibrary/Boolean.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/2078953063/Boolean.o ${OBJECTDIR}/_ext/2078953063/Boolean_nomain.o;\
	fi

${OBJECTDIR}/_ext/2078953063/Byte_nomain.o: ${OBJECTDIR}/_ext/2078953063/Byte.o ../CLibrary/Byte.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/2078953063/Byte.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/Byte_nomain.o ../CLibrary/Byte.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/2078953063/Byte.o ${OBJECTDIR}/_ext/2078953063/Byte_nomain.o;\
	fi

${OBJECTDIR}/_ext/2078953063/Character_nomain.o: ${OBJECTDIR}/_ext/2078953063/Character.o ../CLibrary/Character.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/2078953063/Character.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/Character_nomain.o ../CLibrary/Character.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/2078953063/Character.o ${OBJECTDIR}/_ext/2078953063/Character_nomain.o;\
	fi

${OBJECTDIR}/_ext/2078953063/Collections_nomain.o: ${OBJECTDIR}/_ext/2078953063/Collections.o ../CLibrary/Collections.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/2078953063/Collections.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/Collections_nomain.o ../CLibrary/Collections.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/2078953063/Collections.o ${OBJECTDIR}/_ext/2078953063/Collections_nomain.o;\
	fi

${OBJECTDIR}/_ext/2078953063/Double_nomain.o: ${OBJECTDIR}/_ext/2078953063/Double.o ../CLibrary/Double.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/2078953063/Double.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/Double_nomain.o ../CLibrary/Double.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/2078953063/Double.o ${OBJECTDIR}/_ext/2078953063/Double_nomain.o;\
	fi

${OBJECTDIR}/_ext/2078953063/Float_nomain.o: ${OBJECTDIR}/_ext/2078953063/Float.o ../CLibrary/Float.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/2078953063/Float.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/Float_nomain.o ../CLibrary/Float.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/2078953063/Float.o ${OBJECTDIR}/_ext/2078953063/Float_nomain.o;\
	fi

${OBJECTDIR}/_ext/2078953063/Integer_nomain.o: ${OBJECTDIR}/_ext/2078953063/Integer.o ../CLibrary/Integer.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/2078953063/Integer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/Integer_nomain.o ../CLibrary/Integer.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/2078953063/Integer.o ${OBJECTDIR}/_ext/2078953063/Integer_nomain.o;\
	fi

${OBJECTDIR}/_ext/2078953063/LinkedList_nomain.o: ${OBJECTDIR}/_ext/2078953063/LinkedList.o ../CLibrary/LinkedList.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/2078953063/LinkedList.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/LinkedList_nomain.o ../CLibrary/LinkedList.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/2078953063/LinkedList.o ${OBJECTDIR}/_ext/2078953063/LinkedList_nomain.o;\
	fi

${OBJECTDIR}/_ext/2078953063/List_nomain.o: ${OBJECTDIR}/_ext/2078953063/List.o ../CLibrary/List.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/2078953063/List.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/List_nomain.o ../CLibrary/List.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/2078953063/List.o ${OBJECTDIR}/_ext/2078953063/List_nomain.o;\
	fi

${OBJECTDIR}/_ext/2078953063/Long_nomain.o: ${OBJECTDIR}/_ext/2078953063/Long.o ../CLibrary/Long.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/2078953063/Long.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/Long_nomain.o ../CLibrary/Long.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/2078953063/Long.o ${OBJECTDIR}/_ext/2078953063/Long_nomain.o;\
	fi

${OBJECTDIR}/_ext/2078953063/Math__nomain.o: ${OBJECTDIR}/_ext/2078953063/Math_.o ../CLibrary/Math_.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/2078953063/Math_.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/Math__nomain.o ../CLibrary/Math_.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/2078953063/Math_.o ${OBJECTDIR}/_ext/2078953063/Math__nomain.o;\
	fi

${OBJECTDIR}/_ext/2078953063/Scanner_nomain.o: ${OBJECTDIR}/_ext/2078953063/Scanner.o ../CLibrary/Scanner.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/2078953063/Scanner.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/Scanner_nomain.o ../CLibrary/Scanner.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/2078953063/Scanner.o ${OBJECTDIR}/_ext/2078953063/Scanner_nomain.o;\
	fi

${OBJECTDIR}/_ext/2078953063/Short_nomain.o: ${OBJECTDIR}/_ext/2078953063/Short.o ../CLibrary/Short.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/2078953063/Short.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/Short_nomain.o ../CLibrary/Short.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/2078953063/Short.o ${OBJECTDIR}/_ext/2078953063/Short_nomain.o;\
	fi

${OBJECTDIR}/_ext/2078953063/StringBuilder_nomain.o: ${OBJECTDIR}/_ext/2078953063/StringBuilder.o ../CLibrary/StringBuilder.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/2078953063/StringBuilder.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/StringBuilder_nomain.o ../CLibrary/StringBuilder.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/2078953063/StringBuilder.o ${OBJECTDIR}/_ext/2078953063/StringBuilder_nomain.o;\
	fi

${OBJECTDIR}/_ext/2078953063/StringTokenizer_nomain.o: ${OBJECTDIR}/_ext/2078953063/StringTokenizer.o ../CLibrary/StringTokenizer.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/2078953063/StringTokenizer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/StringTokenizer_nomain.o ../CLibrary/StringTokenizer.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/2078953063/StringTokenizer.o ${OBJECTDIR}/_ext/2078953063/StringTokenizer_nomain.o;\
	fi

${OBJECTDIR}/_ext/2078953063/String__nomain.o: ${OBJECTDIR}/_ext/2078953063/String_.o ../CLibrary/String_.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/2078953063/String_.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/String__nomain.o ../CLibrary/String_.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/2078953063/String_.o ${OBJECTDIR}/_ext/2078953063/String__nomain.o;\
	fi

${OBJECTDIR}/_ext/2078953063/System_nomain.o: ${OBJECTDIR}/_ext/2078953063/System.o ../CLibrary/System.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/2078953063/System.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/System_nomain.o ../CLibrary/System.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/2078953063/System.o ${OBJECTDIR}/_ext/2078953063/System_nomain.o;\
	fi

${OBJECTDIR}/_ext/2078953063/TestObject_nomain.o: ${OBJECTDIR}/_ext/2078953063/TestObject.o ../CLibrary/TestObject.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/2078953063
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/2078953063/TestObject.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2078953063/TestObject_nomain.o ../CLibrary/TestObject.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/2078953063/TestObject.o ${OBJECTDIR}/_ext/2078953063/TestObject_nomain.o;\
	fi

${OBJECTDIR}/PrintStreamTest_nomain.o: ${OBJECTDIR}/PrintStreamTest.o PrintStreamTest.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/PrintStreamTest.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PrintStreamTest_nomain.o PrintStreamTest.c;\
	else  \
	    ${CP} ${OBJECTDIR}/PrintStreamTest.o ${OBJECTDIR}/PrintStreamTest_nomain.o;\
	fi

${OBJECTDIR}/ScannerTest_nomain.o: ${OBJECTDIR}/ScannerTest.o ScannerTest.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ScannerTest.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ScannerTest_nomain.o ScannerTest.c;\
	else  \
	    ${CP} ${OBJECTDIR}/ScannerTest.o ${OBJECTDIR}/ScannerTest_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.c;\
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
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/test_nomain.o test.c;\
	else  \
	    ${CP} ${OBJECTDIR}/test.o ${OBJECTDIR}/test_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f3 || true; \
	    ${TESTDIR}/TestFiles/f4 || true; \
	    ${TESTDIR}/TestFiles/f8 || true; \
	    ${TESTDIR}/TestFiles/f5 || true; \
	    ${TESTDIR}/TestFiles/f6 || true; \
	    ${TESTDIR}/TestFiles/f7 || true; \
	    ${TESTDIR}/TestFiles/f9 || true; \
	    ${TESTDIR}/TestFiles/f10 || true; \
	    ${TESTDIR}/TestFiles/f11 || true; \
	    ${TESTDIR}/TestFiles/f12 || true; \
	    ${TESTDIR}/TestFiles/f13 || true; \
	    ${TESTDIR}/TestFiles/f14 || true; \
	    ${TESTDIR}/TestFiles/f15 || true; \
	    ${TESTDIR}/TestFiles/f16 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/clibrarytest.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
