cmake_minimum_required(VERSION 3.16)
project(Experiment_5)

set(CMAKE_CXX_STANDARD 14)

aux_source_directory(. DIR_SRCS)
add_executable(Experiment_5 ${DIR_SRCS})