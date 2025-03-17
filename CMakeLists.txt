cmake_minimum_required(VERSION 3.20)

project(passgen LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(passgen  src/main.cpp                        
                        src/basic_password_generator.h
                        src/composite_password_generator.h
                        src/digit_generator.h
                        src/password_generator.h
                        src/symbol_generator.h
                        src/letter_generator.h)

include(GNUInstallDirs)
install(TARGETS passgen
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)