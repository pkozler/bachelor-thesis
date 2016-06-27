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
	${OBJECTDIR}/_ext/1078017383/ArrayList.o \
	${OBJECTDIR}/_ext/1078017383/Arrays.o \
	${OBJECTDIR}/_ext/1078017383/Boolean.o \
	${OBJECTDIR}/_ext/1078017383/Byte.o \
	${OBJECTDIR}/_ext/1078017383/Character.o \
	${OBJECTDIR}/_ext/1078017383/Collections.o \
	${OBJECTDIR}/_ext/1078017383/Double.o \
	${OBJECTDIR}/_ext/1078017383/Float.o \
	${OBJECTDIR}/_ext/1078017383/Integer.o \
	${OBJECTDIR}/_ext/1078017383/LinkedList.o \
	${OBJECTDIR}/_ext/1078017383/List.o \
	${OBJECTDIR}/_ext/1078017383/Long.o \
	${OBJECTDIR}/_ext/1078017383/Math_.o \
	${OBJECTDIR}/_ext/1078017383/Scanner.o \
	${OBJECTDIR}/_ext/1078017383/Short.o \
	${OBJECTDIR}/_ext/1078017383/StringBuilder.o \
	${OBJECTDIR}/_ext/1078017383/StringTokenizer.o \
	${OBJECTDIR}/_ext/1078017383/String_.o \
	${OBJECTDIR}/_ext/1078017383/System.o \
	${OBJECTDIR}/_ext/1078017383/TestObject.o \
	${OBJECTDIR}/_ext/1078017383/TestObjectComparator.o \
	${OBJECTDIR}/PrintStreamTest.o \
	${OBJECTDIR}/ScannerTest.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/test.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f12 \
	${TESTDIR}/TestFiles/f16 \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f3 \
	${TESTDIR}/TestFiles/f6 \
	${TESTDIR}/TestFiles/f15 \
	${TESTDIR}/TestFiles/f4 \
	${TESTDIR}/TestFiles/f5 \
	${TESTDIR}/TestFiles/f7 \
	${TESTDIR}/TestFiles/f13 \
	${TESTDIR}/TestFiles/f8 \
	${TESTDIR}/TestFiles/f14 \
	${TESTDIR}/TestFiles/f9 \
	${TESTDIR}/TestFiles/f10 \
	${TESTDIR}/TestFiles/f1 \
	${TESTDIR}/TestFiles/f11

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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cpplibrarytest.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cpplibrarytest.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cpplibrarytest ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/1078017383/ArrayList.o: ../CppLibrary/ArrayList.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/ArrayList.o ../CppLibrary/ArrayList.cpp

${OBJECTDIR}/_ext/1078017383/Arrays.o: ../CppLibrary/Arrays.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/Arrays.o ../CppLibrary/Arrays.cpp

${OBJECTDIR}/_ext/1078017383/Boolean.o: ../CppLibrary/Boolean.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/Boolean.o ../CppLibrary/Boolean.cpp

${OBJECTDIR}/_ext/1078017383/Byte.o: ../CppLibrary/Byte.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/Byte.o ../CppLibrary/Byte.cpp

${OBJECTDIR}/_ext/1078017383/Character.o: ../CppLibrary/Character.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/Character.o ../CppLibrary/Character.cpp

${OBJECTDIR}/_ext/1078017383/Collections.o: ../CppLibrary/Collections.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/Collections.o ../CppLibrary/Collections.cpp

${OBJECTDIR}/_ext/1078017383/Double.o: ../CppLibrary/Double.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/Double.o ../CppLibrary/Double.cpp

${OBJECTDIR}/_ext/1078017383/Float.o: ../CppLibrary/Float.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/Float.o ../CppLibrary/Float.cpp

${OBJECTDIR}/_ext/1078017383/Integer.o: ../CppLibrary/Integer.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/Integer.o ../CppLibrary/Integer.cpp

${OBJECTDIR}/_ext/1078017383/LinkedList.o: ../CppLibrary/LinkedList.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/LinkedList.o ../CppLibrary/LinkedList.cpp

${OBJECTDIR}/_ext/1078017383/List.o: ../CppLibrary/List.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/List.o ../CppLibrary/List.cpp

${OBJECTDIR}/_ext/1078017383/Long.o: ../CppLibrary/Long.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/Long.o ../CppLibrary/Long.cpp

${OBJECTDIR}/_ext/1078017383/Math_.o: ../CppLibrary/Math_.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/Math_.o ../CppLibrary/Math_.cpp

${OBJECTDIR}/_ext/1078017383/Scanner.o: ../CppLibrary/Scanner.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/Scanner.o ../CppLibrary/Scanner.cpp

${OBJECTDIR}/_ext/1078017383/Short.o: ../CppLibrary/Short.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/Short.o ../CppLibrary/Short.cpp

${OBJECTDIR}/_ext/1078017383/StringBuilder.o: ../CppLibrary/StringBuilder.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/StringBuilder.o ../CppLibrary/StringBuilder.cpp

${OBJECTDIR}/_ext/1078017383/StringTokenizer.o: ../CppLibrary/StringTokenizer.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/StringTokenizer.o ../CppLibrary/StringTokenizer.cpp

${OBJECTDIR}/_ext/1078017383/String_.o: ../CppLibrary/String_.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/String_.o ../CppLibrary/String_.cpp

${OBJECTDIR}/_ext/1078017383/System.o: ../CppLibrary/System.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/System.o ../CppLibrary/System.cpp

${OBJECTDIR}/_ext/1078017383/TestObject.o: ../CppLibrary/TestObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/TestObject.o ../CppLibrary/TestObject.cpp

${OBJECTDIR}/_ext/1078017383/TestObjectComparator.o: ../CppLibrary/TestObjectComparator.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/TestObjectComparator.o ../CppLibrary/TestObjectComparator.cpp

${OBJECTDIR}/PrintStreamTest.o: PrintStreamTest.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PrintStreamTest.o PrintStreamTest.cpp

${OBJECTDIR}/ScannerTest.o: ScannerTest.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ScannerTest.o ScannerTest.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/test.o: test.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/test.o test.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f12: ${TESTDIR}/tests/ArrayListTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f12 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f16: ${TESTDIR}/tests/ArraysTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f16 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/BooleanTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f3: ${TESTDIR}/tests/ByteTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f6: ${TESTDIR}/tests/CharacterTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f6 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f15: ${TESTDIR}/tests/CollectionsTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f15 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f4: ${TESTDIR}/tests/DoubleTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f4 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f5: ${TESTDIR}/tests/FloatTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f5 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f7: ${TESTDIR}/tests/IntegerTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f7 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f13: ${TESTDIR}/tests/LinkedListTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f13 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f8: ${TESTDIR}/tests/LongTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f8 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f14: ${TESTDIR}/tests/MathTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f14 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f9: ${TESTDIR}/tests/ShortTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f9 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f10: ${TESTDIR}/tests/StringBuilderTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f10 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/StringTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f11: ${TESTDIR}/tests/StringTokenizerTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f11 $^ ${LDLIBSOPTIONS} 


${TESTDIR}/tests/ArrayListTest.o: tests/ArrayListTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ArrayListTest.o tests/ArrayListTest.cpp


${TESTDIR}/tests/ArraysTest.o: tests/ArraysTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ArraysTest.o tests/ArraysTest.cpp


${TESTDIR}/tests/BooleanTest.o: tests/BooleanTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/BooleanTest.o tests/BooleanTest.cpp


${TESTDIR}/tests/ByteTest.o: tests/ByteTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ByteTest.o tests/ByteTest.cpp


${TESTDIR}/tests/CharacterTest.o: tests/CharacterTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/CharacterTest.o tests/CharacterTest.cpp


${TESTDIR}/tests/CollectionsTest.o: tests/CollectionsTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/CollectionsTest.o tests/CollectionsTest.cpp


${TESTDIR}/tests/DoubleTest.o: tests/DoubleTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/DoubleTest.o tests/DoubleTest.cpp


${TESTDIR}/tests/FloatTest.o: tests/FloatTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/FloatTest.o tests/FloatTest.cpp


${TESTDIR}/tests/IntegerTest.o: tests/IntegerTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/IntegerTest.o tests/IntegerTest.cpp


${TESTDIR}/tests/LinkedListTest.o: tests/LinkedListTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/LinkedListTest.o tests/LinkedListTest.cpp


${TESTDIR}/tests/LongTest.o: tests/LongTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/LongTest.o tests/LongTest.cpp


${TESTDIR}/tests/MathTest.o: tests/MathTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/MathTest.o tests/MathTest.cpp


${TESTDIR}/tests/ShortTest.o: tests/ShortTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ShortTest.o tests/ShortTest.cpp


${TESTDIR}/tests/StringBuilderTest.o: tests/StringBuilderTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/StringBuilderTest.o tests/StringBuilderTest.cpp


${TESTDIR}/tests/StringTest.o: tests/StringTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/StringTest.o tests/StringTest.cpp


${TESTDIR}/tests/StringTokenizerTest.o: tests/StringTokenizerTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/StringTokenizerTest.o tests/StringTokenizerTest.cpp


${OBJECTDIR}/_ext/1078017383/ArrayList_nomain.o: ${OBJECTDIR}/_ext/1078017383/ArrayList.o ../CppLibrary/ArrayList.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1078017383/ArrayList.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/ArrayList_nomain.o ../CppLibrary/ArrayList.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1078017383/ArrayList.o ${OBJECTDIR}/_ext/1078017383/ArrayList_nomain.o;\
	fi

${OBJECTDIR}/_ext/1078017383/Arrays_nomain.o: ${OBJECTDIR}/_ext/1078017383/Arrays.o ../CppLibrary/Arrays.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1078017383/Arrays.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/Arrays_nomain.o ../CppLibrary/Arrays.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1078017383/Arrays.o ${OBJECTDIR}/_ext/1078017383/Arrays_nomain.o;\
	fi

${OBJECTDIR}/_ext/1078017383/Boolean_nomain.o: ${OBJECTDIR}/_ext/1078017383/Boolean.o ../CppLibrary/Boolean.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1078017383/Boolean.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/Boolean_nomain.o ../CppLibrary/Boolean.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1078017383/Boolean.o ${OBJECTDIR}/_ext/1078017383/Boolean_nomain.o;\
	fi

${OBJECTDIR}/_ext/1078017383/Byte_nomain.o: ${OBJECTDIR}/_ext/1078017383/Byte.o ../CppLibrary/Byte.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1078017383/Byte.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/Byte_nomain.o ../CppLibrary/Byte.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1078017383/Byte.o ${OBJECTDIR}/_ext/1078017383/Byte_nomain.o;\
	fi

${OBJECTDIR}/_ext/1078017383/Character_nomain.o: ${OBJECTDIR}/_ext/1078017383/Character.o ../CppLibrary/Character.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1078017383/Character.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/Character_nomain.o ../CppLibrary/Character.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1078017383/Character.o ${OBJECTDIR}/_ext/1078017383/Character_nomain.o;\
	fi

${OBJECTDIR}/_ext/1078017383/Collections_nomain.o: ${OBJECTDIR}/_ext/1078017383/Collections.o ../CppLibrary/Collections.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1078017383/Collections.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/Collections_nomain.o ../CppLibrary/Collections.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1078017383/Collections.o ${OBJECTDIR}/_ext/1078017383/Collections_nomain.o;\
	fi

${OBJECTDIR}/_ext/1078017383/Double_nomain.o: ${OBJECTDIR}/_ext/1078017383/Double.o ../CppLibrary/Double.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1078017383/Double.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/Double_nomain.o ../CppLibrary/Double.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1078017383/Double.o ${OBJECTDIR}/_ext/1078017383/Double_nomain.o;\
	fi

${OBJECTDIR}/_ext/1078017383/Float_nomain.o: ${OBJECTDIR}/_ext/1078017383/Float.o ../CppLibrary/Float.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1078017383/Float.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/Float_nomain.o ../CppLibrary/Float.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1078017383/Float.o ${OBJECTDIR}/_ext/1078017383/Float_nomain.o;\
	fi

${OBJECTDIR}/_ext/1078017383/Integer_nomain.o: ${OBJECTDIR}/_ext/1078017383/Integer.o ../CppLibrary/Integer.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1078017383/Integer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/Integer_nomain.o ../CppLibrary/Integer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1078017383/Integer.o ${OBJECTDIR}/_ext/1078017383/Integer_nomain.o;\
	fi

${OBJECTDIR}/_ext/1078017383/LinkedList_nomain.o: ${OBJECTDIR}/_ext/1078017383/LinkedList.o ../CppLibrary/LinkedList.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1078017383/LinkedList.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/LinkedList_nomain.o ../CppLibrary/LinkedList.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1078017383/LinkedList.o ${OBJECTDIR}/_ext/1078017383/LinkedList_nomain.o;\
	fi

${OBJECTDIR}/_ext/1078017383/List_nomain.o: ${OBJECTDIR}/_ext/1078017383/List.o ../CppLibrary/List.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1078017383/List.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/List_nomain.o ../CppLibrary/List.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1078017383/List.o ${OBJECTDIR}/_ext/1078017383/List_nomain.o;\
	fi

${OBJECTDIR}/_ext/1078017383/Long_nomain.o: ${OBJECTDIR}/_ext/1078017383/Long.o ../CppLibrary/Long.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1078017383/Long.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/Long_nomain.o ../CppLibrary/Long.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1078017383/Long.o ${OBJECTDIR}/_ext/1078017383/Long_nomain.o;\
	fi

${OBJECTDIR}/_ext/1078017383/Math__nomain.o: ${OBJECTDIR}/_ext/1078017383/Math_.o ../CppLibrary/Math_.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1078017383/Math_.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/Math__nomain.o ../CppLibrary/Math_.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1078017383/Math_.o ${OBJECTDIR}/_ext/1078017383/Math__nomain.o;\
	fi

${OBJECTDIR}/_ext/1078017383/Scanner_nomain.o: ${OBJECTDIR}/_ext/1078017383/Scanner.o ../CppLibrary/Scanner.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1078017383/Scanner.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/Scanner_nomain.o ../CppLibrary/Scanner.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1078017383/Scanner.o ${OBJECTDIR}/_ext/1078017383/Scanner_nomain.o;\
	fi

${OBJECTDIR}/_ext/1078017383/Short_nomain.o: ${OBJECTDIR}/_ext/1078017383/Short.o ../CppLibrary/Short.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1078017383/Short.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/Short_nomain.o ../CppLibrary/Short.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1078017383/Short.o ${OBJECTDIR}/_ext/1078017383/Short_nomain.o;\
	fi

${OBJECTDIR}/_ext/1078017383/StringBuilder_nomain.o: ${OBJECTDIR}/_ext/1078017383/StringBuilder.o ../CppLibrary/StringBuilder.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1078017383/StringBuilder.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/StringBuilder_nomain.o ../CppLibrary/StringBuilder.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1078017383/StringBuilder.o ${OBJECTDIR}/_ext/1078017383/StringBuilder_nomain.o;\
	fi

${OBJECTDIR}/_ext/1078017383/StringTokenizer_nomain.o: ${OBJECTDIR}/_ext/1078017383/StringTokenizer.o ../CppLibrary/StringTokenizer.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1078017383/StringTokenizer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/StringTokenizer_nomain.o ../CppLibrary/StringTokenizer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1078017383/StringTokenizer.o ${OBJECTDIR}/_ext/1078017383/StringTokenizer_nomain.o;\
	fi

${OBJECTDIR}/_ext/1078017383/String__nomain.o: ${OBJECTDIR}/_ext/1078017383/String_.o ../CppLibrary/String_.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1078017383/String_.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/String__nomain.o ../CppLibrary/String_.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1078017383/String_.o ${OBJECTDIR}/_ext/1078017383/String__nomain.o;\
	fi

${OBJECTDIR}/_ext/1078017383/System_nomain.o: ${OBJECTDIR}/_ext/1078017383/System.o ../CppLibrary/System.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1078017383/System.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/System_nomain.o ../CppLibrary/System.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1078017383/System.o ${OBJECTDIR}/_ext/1078017383/System_nomain.o;\
	fi

${OBJECTDIR}/_ext/1078017383/TestObject_nomain.o: ${OBJECTDIR}/_ext/1078017383/TestObject.o ../CppLibrary/TestObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1078017383/TestObject.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/TestObject_nomain.o ../CppLibrary/TestObject.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1078017383/TestObject.o ${OBJECTDIR}/_ext/1078017383/TestObject_nomain.o;\
	fi

${OBJECTDIR}/_ext/1078017383/TestObjectComparator_nomain.o: ${OBJECTDIR}/_ext/1078017383/TestObjectComparator.o ../CppLibrary/TestObjectComparator.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1078017383/TestObjectComparator.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/TestObjectComparator_nomain.o ../CppLibrary/TestObjectComparator.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1078017383/TestObjectComparator.o ${OBJECTDIR}/_ext/1078017383/TestObjectComparator_nomain.o;\
	fi

${OBJECTDIR}/PrintStreamTest_nomain.o: ${OBJECTDIR}/PrintStreamTest.o PrintStreamTest.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/PrintStreamTest.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PrintStreamTest_nomain.o PrintStreamTest.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/PrintStreamTest.o ${OBJECTDIR}/PrintStreamTest_nomain.o;\
	fi

${OBJECTDIR}/ScannerTest_nomain.o: ${OBJECTDIR}/ScannerTest.o ScannerTest.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ScannerTest.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ScannerTest_nomain.o ScannerTest.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ScannerTest.o ${OBJECTDIR}/ScannerTest_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.cpp;\
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
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/test_nomain.o test.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/test.o ${OBJECTDIR}/test_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f12 || true; \
	    ${TESTDIR}/TestFiles/f16 || true; \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f3 || true; \
	    ${TESTDIR}/TestFiles/f6 || true; \
	    ${TESTDIR}/TestFiles/f15 || true; \
	    ${TESTDIR}/TestFiles/f4 || true; \
	    ${TESTDIR}/TestFiles/f5 || true; \
	    ${TESTDIR}/TestFiles/f7 || true; \
	    ${TESTDIR}/TestFiles/f13 || true; \
	    ${TESTDIR}/TestFiles/f8 || true; \
	    ${TESTDIR}/TestFiles/f14 || true; \
	    ${TESTDIR}/TestFiles/f9 || true; \
	    ${TESTDIR}/TestFiles/f10 || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	    ${TESTDIR}/TestFiles/f11 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cpplibrarytest.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
