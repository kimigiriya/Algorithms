cmake_minimum_required (VERSION 3.8)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Algorithms")

#add_executable (Algorithms "Algorithms.cpp" "Algorithms.h")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/PrimeNumbers.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/EnglishAlphabet.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/RussianAlphabet.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/RandomWords.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/RussianArentRandomWords.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

set(SOURSES
		Algorithms.cpp
)

set(HEADERS
		Algorithms.h
)

add_executable(Algorithms ${SOURSES} ${HEADERS})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Algorithms PROPERTY CXX_STANDARD 20)
endif()


