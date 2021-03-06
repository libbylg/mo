CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(mo)


# Include the sub directorys to build
ADD_SUBDIRECTORY(examples)
ADD_SUBDIRECTORY(plugins)


#   Define some global options
OPTION(DEBUG "Generate symbols for debug" OFF)


#   All headers
SET(HRDS
    mo.h
    mo_utils.h
    mo_list.h
    mo_map.h
    )
SET_SOURCE_FILES_PROPERTIES(${HRDS} PROPERTIES HEADER_FILE_ONLY YES)



#   Define some vars, they will be used leter
SET(SRCS
    mo.c
    mo_utils.c
    mo_stream_file.c
    mo_stream_string.c
    mo_list.c
    mo_map.c
    ${HRDS}
    )
SET(INCS .)
SET(CCDEFS -DMO_EXPORTS)


#   Need the debug symbols or not
IF    (DEBUG)
    LIST(APPEND CCDEFS -DDEBUG)
ELSE  (DEBUG)
    LIST(APPEND CCDEFS -DNDEBUG)
ENDIF (DEBUG)


#   Sprcial the language to c++ for VC
IF   (MSVC)
    SET_SOURCE_FILES_PROPERTIES(${SRCS} PROPERTIES LANGUAGE CXX)
ENDIF(MSVC)


#   Special the include dirs and defines
INCLUDE_DIRECTORIES(${INCS})
ADD_DEFINITIONS(${CCDEFS})


#   Defined the targets
ADD_LIBRARY(mo        SHARED ${SRCS})
ADD_LIBRARY(mo-static STATIC ${SRCS})


#   Set the output dirs
SET_TARGET_PROPERTIES(mo        PROPERTIES LIBRARY_OUTPUT_DIRECTORY_DEBUG   ${PROJECT_SOURCE_DIR}/out)
SET_TARGET_PROPERTIES(mo        PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG   ${PROJECT_SOURCE_DIR}/out)
SET_TARGET_PROPERTIES(mo        PROPERTIES ARCHIVE_OUTPUT_DIRECTORY_DEBUG   ${PROJECT_SOURCE_DIR}/out)
SET_TARGET_PROPERTIES(mo-static PROPERTIES ARCHIVE_OUTPUT_DIRECTORY_DEBUG   ${PROJECT_SOURCE_DIR}/out)
SET_TARGET_PROPERTIES(mo-static PROPERTIES ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/out)
