
cmake_minimum_required(VERSION 3.15)

project (httpserver LANGUAGES CXX)

# set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 11)

add_executable(${PROJECT_NAME}
        src/main.cc
        mongoose/mongoose.cc
    )

include_directories(mongoose)

file( COPY ../../mongoose.h  DESTINATION  ${CMAKE_CURRENT_SOURCE_DIR}/mongoose)
file( COPY ../../mongoose.c  DESTINATION  ${CMAKE_CURRENT_SOURCE_DIR}/mongoose)
file( RENAME ${CMAKE_CURRENT_SOURCE_DIR}/mongoose/mongoose.c ${CMAKE_CURRENT_SOURCE_DIR}/mongoose/mongoose.cc)

