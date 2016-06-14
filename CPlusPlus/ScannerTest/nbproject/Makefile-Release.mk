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
	${OBJECTDIR}/_ext/1078017383/test.o \
	${OBJECTDIR}/ScannerTest.o \
	${OBJECTDIR}/main.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/scannertest.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/scannertest.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/scannertest ${OBJECTFILES} ${LDLIBSOPTIONS}

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

${OBJECTDIR}/_ext/1078017383/test.o: ../CppLibrary/test.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1078017383
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1078017383/test.o ../CppLibrary/test.cpp

${OBJECTDIR}/ScannerTest.o: ScannerTest.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ScannerTest.o ScannerTest.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/scannertest.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
