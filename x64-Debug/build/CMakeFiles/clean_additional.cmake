# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "3DCalib\\CMakeFiles\\CalibrationWizard_autogen.dir\\AutogenUsed.txt"
  "3DCalib\\CMakeFiles\\CalibrationWizard_autogen.dir\\ParseCache.txt"
  "3DCalib\\CalibrationWizard_autogen"
  "EGMServer\\CMakeFiles\\EGMServerSharedLibs_autogen.dir\\AutogenUsed.txt"
  "EGMServer\\CMakeFiles\\EGMServerSharedLibs_autogen.dir\\ParseCache.txt"
  "EGMServer\\EGMServerSharedLibs_autogen"
  "EGMServer\\test\\CMakeFiles\\Test_EGMServer_autogen.dir\\AutogenUsed.txt"
  "EGMServer\\test\\CMakeFiles\\Test_EGMServer_autogen.dir\\ParseCache.txt"
  "EGMServer\\test\\Test_EGMServer_autogen"
  "Laser\\CMakeFiles\\LaserLib_autogen.dir\\AutogenUsed.txt"
  "Laser\\CMakeFiles\\LaserLib_autogen.dir\\ParseCache.txt"
  "Laser\\LaserLib_autogen"
  "ui\\CMakeFiles\\UILib_autogen.dir\\AutogenUsed.txt"
  "ui\\CMakeFiles\\UILib_autogen.dir\\ParseCache.txt"
  "ui\\UILib_autogen"
  "utility2\\CMakeFiles\\Utility_2_autogen.dir\\AutogenUsed.txt"
  "utility2\\CMakeFiles\\Utility_2_autogen.dir\\ParseCache.txt"
  "utility2\\Utility_2_autogen"
  )
endif()
