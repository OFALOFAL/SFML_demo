cmake_minimum_required(VERSION 3.22)
project(PoruszaniePoRenderze_ALGITP)

set(CMAKE_CXX_STANDARD 20)

add_executable(PoruszaniePoRenderze_ALGITP src/main.cpp src/Engine.cpp headers/Engine.h src/input.cpp src/draw.cpp src/player.cpp headers/player.h src/update.cpp src/grass.cpp headers/grass.h src/redGrass.cpp headers/redGrass.h)

include_directories(headers /usr/include c:/PoruszaniePoRenderze_ALGITP/include)

set(SFML_ROOT c:/SFML)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(PoruszaniePoRenderze_ALGITP ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Copy dlls to build
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()
