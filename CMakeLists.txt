cmake_minimum_required (VERSION 3.0)
project (SoundMixrEffect)

set (CMAKE_CXX_STANDARD 17)

add_subdirectory(PluginBase)

file(GLOB_RECURSE SOURCE
  ./source/Effect.cpp
)

add_library(SoundMixrEffect SHARED
  ${SOURCE}
)

target_include_directories(SoundMixrEffect PUBLIC
  PluginBase/include
  PluginBase/libs/json/include
)