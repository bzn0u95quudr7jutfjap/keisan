cmake_minimum_required(VERSION 3.5)
project(keisan)

set(SOURCES 
  quelle/main.c
)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} inc/)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
target_link_libraries(${PROJECT_NAME} -lm)


