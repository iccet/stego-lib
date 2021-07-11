project(LangelaarTests LANGUAGES CXX)

include(subdirlist)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

SUBDIRLIST(SUBDIRS ${PROJECT_SOURCE_DIR})

foreach(subdir ${SUBDIRS})
  add_subdirectory(${subdir})
endforeach()
