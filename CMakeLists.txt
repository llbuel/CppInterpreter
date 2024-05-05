cmake_minimum_required(VERSION 3.19 FATAL_ERROR)

project(
    clab
    LANGUAGES CXX
)

include(FetchContent)

set(wxBUILD_SHARED OFF)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    add_compile_options(/W4 /WX)
endif()

message(STATUS "Fetching wxWidgets...")

find_package(wxWidgets COMPONENTS core base aui REQUIRED)

if(NOT wxWidgets_FOUND)
    message(STATUS "wxWidgets libraries not found. Fetching wxWidgets...")

    FetchContent_Declare(
        wxWidgets
        GIT_REPOSITORY https://github.com/wxWidgets/wxWidgets.git
        GIT_SHALLOW ON
    )

    FetchContent_GetProperties(wxWidgets)
    if(NOT wxWidgets_POPULATED)
        FetchContent_Populate(wxWidgets)
        add_subdirectory(${wxWidgets_SOURCE_DIR} ${wxWidgets_BINARY_DIR})
    endif()
else()
    include(${wxWidgets_USE_FILE})
endif()

file(GLOB SOURCES "src/*.cpp")

if(APPLE)
    add_executable(clab MACOSX_BUNDLE ${SOURCES})
    set_target_properties(clab PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist)
elseif(WIN32)
    add_executable(clab WIN32 ${SOURCES} clab.exe.manifest)
else()
    add_executable(clab ${SOURCES})
endif()

target_compile_features(clab PRIVATE cxx_std_11)
target_link_libraries(clab PRIVATE ${wxWidgets_LIBRARIES})

target_include_directories(clab PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

set_target_properties(clab PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin
)