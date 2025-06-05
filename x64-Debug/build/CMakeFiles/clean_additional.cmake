# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "EGMServer\\CMakeFiles\\EGMServerSharedLibs_autogen.dir\\AutogenUsed.txt"
  "EGMServer\\CMakeFiles\\EGMServerSharedLibs_autogen.dir\\ParseCache.txt"
  "EGMServer\\EGMServerSharedLibs_autogen"
  "EGMServer\\test\\CMakeFiles\\Test_EGMServer_autogen.dir\\AutogenUsed.txt"
  "EGMServer\\test\\CMakeFiles\\Test_EGMServer_autogen.dir\\ParseCache.txt"
  "EGMServer\\test\\Test_EGMServer_autogen"
  )
endif()
