cmake_minimum_required (VERSION 3.8)

project(LoggerLib VERSION 1.0 DESCRIPTION "Logger library with interface and console coloring")

include(GNUInstallDirs)
include(InstallRequiredSystemLibraries)

file(GLOB FILES "include/*.h" "src/*.cpp")
add_library(LoggerLib SHARED ${FILES})

set_target_properties(
	LoggerLib PROPERTIES 
	VERSION ${PROJECT_VERSION}
	SOVERSION 1
	PUBLIC_HEADER include/Logger.h
)

configure_file(LoggerLib.pc.in LoggerLib.pc @ONLY)

target_include_directories(LoggerLib 
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/src
)

if(WIN32)
	set(LIBRARY_RUNTIME RUNTIME)
else()
	set(LIBRARY_RUNTIME LIBRARY)
endif()

install(
	TARGETS LoggerLib
	${LIBRARY_RUNTIME} DESTINATION ${CMAKE_INSTALL_LIBDIR}
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
	FILES ${CMAKE_BINARY_DIR}/LoggerLib/LoggerLib.pc
	DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig
)
