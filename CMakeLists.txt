cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

file(READ "${CMAKE_CURRENT_SOURCE_DIR}/version.txt" VERSION_FILE_CONTENTS)
string(STRIP "${VERSION_FILE_CONTENTS}" VERSION_FILE_CONTENTS)
set(DSDK_VERSION "${VERSION_FILE_CONTENTS}" CACHE STRING "Set version name")
set(DSDK_PACKAGE "dsdk" CACHE STRING "Set package name")
string(REPLACE "v" "" DSDK_VERSION "${DSDK_VERSION}")
string(REGEX REPLACE "[.+-]" ";" DSDK_VERSION_LIST ${DSDK_VERSION})
list(GET DSDK_VERSION_LIST 0 DSDK_VERSION_MAJOR)
list(GET DSDK_VERSION_LIST 1 DSDK_VERSION_MINOR)
list(GET DSDK_VERSION_LIST 2 DSDK_VERSION_PATCH)

project(plugify-plugin-deadlock-sdk
    VERSION "${DSDK_VERSION_MAJOR}.${DSDK_VERSION_MINOR}.${DSDK_VERSION_PATCH}"
    DESCRIPTION "Deadlock SDK plugin for Plugify ecosystem"
    HOMEPAGE_URL "https://github.com/untrustedmodders"
    LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

file(GLOB_RECURSE CORE_SOURCES
    "src/core/*.cpp"
)

file(GLOB_RECURSE EXPORT_SOURCES
    "src/export/*.cpp"
)

set(VENDOR_SOURCES
    "external/safetyhook/safetyhook.cpp"
    "external/safetyhook/Zydis.c"
    "external/sourcesdk/tier1/convar.cpp"
    "external/sourcesdk/tier1/keyvalues3.cpp"
    "external/sourcesdk/tier1/bitbuf.cpp"
    "external/sourcesdk/tier1/newbitbuf.cpp"
    "external/sourcesdk/entity2/entityidentity.cpp"
    "external/sourcesdk/entity2/entitysystem.cpp"
    "external/sourcesdk/entity2/entitykeyvalues.cpp"
)

set(PROTOBUF_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external/sourcesdk/thirdparty/protobuf/src")
set(PROTOBUF_LITE_SOURCES
    "${PROTOBUF_SRC_DIR}/google/protobuf/any_lite.cc"
    "${PROTOBUF_SRC_DIR}/google/protobuf/arena.cc"
    "${PROTOBUF_SRC_DIR}/google/protobuf/arenastring.cc"
    "${PROTOBUF_SRC_DIR}/google/protobuf/arenaz_sampler.cc"
    "${PROTOBUF_SRC_DIR}/google/protobuf/extension_set.cc"
    "${PROTOBUF_SRC_DIR}/google/protobuf/generated_enum_util.cc"
    "${PROTOBUF_SRC_DIR}/google/protobuf/generated_message_tctable_lite.cc"
    "${PROTOBUF_SRC_DIR}/google/protobuf/generated_message_util.cc"
    "${PROTOBUF_SRC_DIR}/google/protobuf/implicit_weak_message.cc"
    "${PROTOBUF_SRC_DIR}/google/protobuf/inlined_string_field.cc"
    "${PROTOBUF_SRC_DIR}/google/protobuf/io/coded_stream.cc"
    "${PROTOBUF_SRC_DIR}/google/protobuf/io/io_win32.cc"
    "${PROTOBUF_SRC_DIR}/google/protobuf/io/strtod.cc"
    "${PROTOBUF_SRC_DIR}/google/protobuf/io/zero_copy_stream.cc"
    "${PROTOBUF_SRC_DIR}/google/protobuf/io/zero_copy_stream_impl.cc"
    "${PROTOBUF_SRC_DIR}/google/protobuf/io/zero_copy_stream_impl_lite.cc"
    "${PROTOBUF_SRC_DIR}/google/protobuf/map.cc"
    "${PROTOBUF_SRC_DIR}/google/protobuf/message_lite.cc"
    "${PROTOBUF_SRC_DIR}/google/protobuf/parse_context.cc"
    "${PROTOBUF_SRC_DIR}/google/protobuf/repeated_field.cc"
    "${PROTOBUF_SRC_DIR}/google/protobuf/repeated_ptr_field.cc"
    "${PROTOBUF_SRC_DIR}/google/protobuf/stubs/bytestream.cc"
    "${PROTOBUF_SRC_DIR}/google/protobuf/stubs/common.cc"
    "${PROTOBUF_SRC_DIR}/google/protobuf/stubs/int128.cc"
    "${PROTOBUF_SRC_DIR}/google/protobuf/stubs/status.cc"
    "${PROTOBUF_SRC_DIR}/google/protobuf/stubs/statusor.cc"
    "${PROTOBUF_SRC_DIR}/google/protobuf/stubs/stringpiece.cc"
    "${PROTOBUF_SRC_DIR}/google/protobuf/stubs/stringprintf.cc"
    "${PROTOBUF_SRC_DIR}/google/protobuf/stubs/structurally_valid.cc"
    "${PROTOBUF_SRC_DIR}/google/protobuf/stubs/strutil.cc"
    "${PROTOBUF_SRC_DIR}/google/protobuf/stubs/time.cc"
    "${PROTOBUF_SRC_DIR}/google/protobuf/wire_format_lite.cc"
)

add_library(protobuf-lite STATIC ${PROTOBUF_LITE_SOURCES})
target_include_directories(protobuf-lite PUBLIC "${PROTOBUF_SRC_DIR}")
set_target_properties(protobuf-lite PROPERTIES
    CXX_STANDARD 17
    MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
)
if(MSVC)
    target_compile_options(protobuf-lite PRIVATE /wd4244 /wd4267 /wd4018 /wd4146 /wd4065 /wd4506)
endif()

add_library(${PROJECT_NAME} SHARED
    ${CORE_SOURCES}
    ${EXPORT_SOURCES}
    ${VENDOR_SOURCES}
)

target_include_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${CMAKE_CURRENT_SOURCE_DIR}/external"
    "${CMAKE_CURRENT_SOURCE_DIR}/external/protobuf"
    "${CMAKE_CURRENT_SOURCE_DIR}/external/sourcesdk/thirdparty/protobuf/src"
    "${CMAKE_CURRENT_SOURCE_DIR}/external/plugify/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/external/safetyhook"
    "${CMAKE_CURRENT_SOURCE_DIR}/external/sourcesdk/public"
    "${CMAKE_CURRENT_SOURCE_DIR}/external/sourcesdk/public/tier0"
    "${CMAKE_CURRENT_SOURCE_DIR}/external/sourcesdk/public/tier1"
    "${CMAKE_CURRENT_SOURCE_DIR}/external/sourcesdk/public/mathlib"
    "${CMAKE_CURRENT_SOURCE_DIR}/external/sourcesdk/public/entity2"
    "${CMAKE_CURRENT_SOURCE_DIR}/external/sourcesdk/public/engine"
    "${CMAKE_CURRENT_SOURCE_DIR}/external/sourcesdk/public/appframework"
    "${CMAKE_CURRENT_SOURCE_DIR}/external/sourcesdk/common"
    "${CMAKE_CURRENT_SOURCE_DIR}/external/sourcesdk/game/shared"
    "${CMAKE_CURRENT_SOURCE_DIR}/external/sourcesdk/interfaces"
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
    _CRT_SECURE_NO_WARNINGS=1
    _SILENCE_ALL_CXX23_DEPRECATION_WARNINGS=1
    DSDK_VERSION="1.0.0"
    DSDK_PACKAGE="dsdk"
    COMPILER_MSVC=1
    COMPILER_MSVC64=1
    PLATFORM_64BITS=1
    X64BITS=1
    DEADLOCK=1
    PLATFORM_WINDOWS=1
    PLUGIFY_IS_DEBUG=$<IF:$<CONFIG:Debug>,true,false>
)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W3 /Zc:preprocessor /permissive- /Zc:__cplusplus /wd4190)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
        LINK_FLAGS "/MAP"
    )
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wno-attributes)
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE
    protobuf-lite
    "${CMAKE_CURRENT_SOURCE_DIR}/external/sourcesdk/lib/win64/tier0.lib"
)

# Configure manifest from template and copy assets
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/plugify-plugin-deadlock-sdk.pplugin.in"
    "${CMAKE_CURRENT_BINARY_DIR}/plugify-plugin-deadlock-sdk.pplugin"
)

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/signatures.jsonc"
    "${CMAKE_CURRENT_BINARY_DIR}/signatures.jsonc"
    COPYONLY
)

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/settings.jsonc"
    "${CMAKE_CURRENT_BINARY_DIR}/settings.jsonc"
    COPYONLY
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_BINARY_DIR}/plugify-plugin-deadlock-sdk.pplugin"
        "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugify-plugin-deadlock-sdk.pplugin"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/signatures.jsonc"
        "$<TARGET_FILE_DIR:${PROJECT_NAME}>/signatures.jsonc"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/settings.jsonc"
        "$<TARGET_FILE_DIR:${PROJECT_NAME}>/settings.jsonc"
)
