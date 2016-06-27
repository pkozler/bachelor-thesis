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
	${OBJECTDIR}/_ext/941196391/ScannerTest.o \
	${OBJECTDIR}/_ext/941196391/test.o \
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
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/scannertest ${OBJECTFILES} ${LDLIBSOPTIONS}

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

${OBJECTDIR}/_ext/941196391/ScannerTest.o: ../CLibraryTest/ScannerTest.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/941196391
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/941196391/ScannerTest.o ../CLibraryTest/ScannerTest.c

${OBJECTDIR}/_ext/941196391/test.o: ../CLibraryTest/test.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/941196391
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/941196391/test.o ../CLibraryTest/test.c

${OBJECTDIR}/main.o: main.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

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
