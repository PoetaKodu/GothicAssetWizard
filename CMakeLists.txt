cmake_minimum_required(VERSION 3.25)

project(GothicAssetWizard VERSION 0.1.0 LANGUAGES CXX)
set(APP_NAME GothicAssetWizard)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE BACKEND_SOURCES
	"Backend/src/*.cpp"
	"Backend/src/*.hpp"
)

# Remove Windows-only sources if not on Windows
if (NOT WIN32)
	file(GLOB_RECURSE BACKEND_SOURCES_WIN32_ONLY
		"Backend/src/*.Windows.cpp"
	)
	list(REMOVE_ITEM BACKEND_SOURCES ${BACKEND_SOURCES_WIN32_ONLY})
endif()

add_executable(${APP_NAME} ${BACKEND_SOURCES} Icon.rc)

# A very important step
# Apparently the MSVC doesn't default to UTF-8 encoding of source files.
if (MSVC)
	target_compile_options(${APP_NAME} PRIVATE /source-charset:utf-8)
endif()

set_target_properties(${APP_NAME} PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/bin/Debug
	LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/bin/Debug
	ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/bin/Debug
	RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/bin/Release
	LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/bin/Release
	ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/bin/Release
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/UBytesAppPlatform)
target_link_libraries(${APP_NAME} AppPlatform)


# Libraries

## RapidJSON
target_include_directories(${APP_NAME} PUBLIC "thirdparty/rapidjson/include")

## fmt 10.0.0
add_subdirectory("thirdparty/fmt" EXCLUDE_FROM_ALL)
target_link_libraries(${APP_NAME} fmt::fmt)