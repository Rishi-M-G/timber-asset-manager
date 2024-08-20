# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\TimberAssetManager_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TimberAssetManager_autogen.dir\\ParseCache.txt"
  "TimberAssetManager_autogen"
  )
endif()
