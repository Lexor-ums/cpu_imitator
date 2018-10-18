TEMPLATE += app
TARGET = final.e
DESTDIR = ../bin

SOURCES += \
    src/main.cpp \
    src/SimpleTask/SimpleTask.cpp \
    src/Scheduler/Scheduler.cpp \
    src/ConfigReader/ConfigReader.cpp \
    src/TaskCreator/TaskCreator.cpp \
    src/Instructions/Instructions.cpp \
    src/Exceptions/OpenException/OpenFileException.cpp \
    src/Exceptions/BaseException.cpp \
    src/Exceptions/ParseException/ParseException.cpp \
    src/SharedMemory/SharedMemory.cpp \
    src/Instructions/InstructionsCreator/InstructionsCreator.cpp \
    src/Instructions/InstructionsExecutor/InstructionsExecutor.cpp \
    src/Exceptions/BadValueException/BadValueException.cpp \
    src/InstructionsParser/InstructionsParser.cpp \
    src/Exceptions/StructureException/BadStructureException.cpp

DISTFILES +=

HEADERS += \
    src/SimpleTask/SimpleTask.h \
    src/Scheduler/Scheduler.h \
    src/ConfigReader/ConfigReader.h \
    src/TaskCreator/TaskCreator.h \
    src/Instructions/Instructions.h \
    src/Exceptions/OpenException/OpenFileException.h \
    src/Exceptions/BaseException.h \
    src/Exceptions/ParseException/ParseException.h \
    src/Instructions/BaseInstruction.h \
    src/SharedMemory/SharedMemory.h \
    src/Instructions/InstructionsCreator/InstructionsCreator.h \
    src/Instructions/InstructionsExecutor/InstructionsExecutor.h \
    src/Exceptions/BadValueException/BadValueException.h \
    src/InstructionsParser/InstructionsParser.h \
    src/Common/TaskConfig.h \
    src/Exceptions/StructureException/BadStructureException.h

INCLUDEPATH +=  src/SimpleTask \
    src/Scheduler \
    src/SharedMemory \
    src/ConfigReader \
    src/TaskCreator \
    src/Instructions \
    src/Instructions/InstructionsCreator \
    src/Instructions/InstructionsExecutor \
    src/Exceptions \
    src/Common \
    src/Exceptions/OpenException \
    src/Exceptions/BadValueException \
    src/InstructionParser\
    src/InstructionsParser\
    src/Exceptions/ParseException \
    src/Exceptions/StructureException
QMAKE_CXXFLAGS += -std=c++14
