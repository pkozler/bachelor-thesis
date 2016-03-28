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
	${OBJECTDIR}/Math.o \
	${OBJECTDIR}/Scanner.o \
	${OBJECTDIR}/Short.o \
	${OBJECTDIR}/String.o \
	${OBJECTDIR}/StringBuilder.o \
	${OBJECTDIR}/StringTokenizer.o \
	${OBJECTDIR}/System.o \
	${OBJECTDIR}/TestObject.o \
	${OBJECTDIR}/TestObjectComparator.o \
	${OBJECTDIR}/main.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cpplibrary.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cpplibrary.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cpplibrary ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/ArrayList.o: ArrayList.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ArrayList.o ArrayList.cpp

${OBJECTDIR}/Arrays.o: Arrays.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Arrays.o Arrays.cpp

${OBJECTDIR}/Boolean.o: Boolean.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Boolean.o Boolean.cpp

${OBJECTDIR}/Byte.o: Byte.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Byte.o Byte.cpp

${OBJECTDIR}/Character.o: Character.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Character.o Character.cpp

${OBJECTDIR}/Collections.o: Collections.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Collections.o Collections.cpp

${OBJECTDIR}/Double.o: Double.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Double.o Double.cpp

${OBJECTDIR}/Float.o: Float.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Float.o Float.cpp

${OBJECTDIR}/Integer.o: Integer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Integer.o Integer.cpp

${OBJECTDIR}/LinkedList.o: LinkedList.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LinkedList.o LinkedList.cpp

${OBJECTDIR}/List.o: List.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/List.o List.cpp

${OBJECTDIR}/Long.o: Long.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Long.o Long.cpp

${OBJECTDIR}/Math.o: Math.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Math.o Math.cpp

${OBJECTDIR}/Scanner.o: Scanner.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Scanner.o Scanner.cpp

${OBJECTDIR}/Short.o: Short.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Short.o Short.cpp

${OBJECTDIR}/String.o: String.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/String.o String.cpp

${OBJECTDIR}/StringBuilder.o: StringBuilder.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/StringBuilder.o StringBuilder.cpp

${OBJECTDIR}/StringTokenizer.o: StringTokenizer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/StringTokenizer.o StringTokenizer.cpp

${OBJECTDIR}/System.o: System.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/System.o System.cpp

${OBJECTDIR}/TestObject.o: TestObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TestObject.o TestObject.cpp

${OBJECTDIR}/TestObjectComparator.o: TestObjectComparator.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TestObjectComparator.o TestObjectComparator.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cpplibrary.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
