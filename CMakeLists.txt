

list(APPEND CMAKE_PREFIX_PATH ../../build/install)



# Using 3.9 to get a modern version of FindOpenGL.cmake
cmake_minimum_required (VERSION 3.9) 

# Dependencies that are auto-downloaded, built, and installed for you will go here.  So, you 
# may use this even if not planning to install this particular project on your system.
if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT OR "${CMAKE_INSTALL_PREFIX}" STREQUAL "")
    set (CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "default install path" FORCE )
endif()

list(APPEND CMAKE_MODULE_PATH  ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_INSTALL_PREFIX})
list(INSERT CMAKE_PREFIX_PATH 0 ${CMAKE_INSTALL_PREFIX})


set(CMAKE_CXX_STANDARD 17)
    if(COMMAND cmake_policy)
      cmake_policy(SET CMP0003 NEW)
    endif(COMMAND cmake_policy)
add_definitions(-D_HAS_STD_BYTE=0)

#---------------------- Source for this Project ----------------------

project(MinVR-Volume)

message(STATUS "==== BUILDING ${PROJECT_NAME}")
message(STATUS "Using install prefix: ${CMAKE_INSTALL_PREFIX}")

option(WITH_TEEM "Adds support of nrrd files through teem" OFF)


set(source_files
  main.cpp
  VolumeVisualizationApp.cpp
  LoadDataAction.cpp
  Shader.cpp
  Volume.cpp
  VolumeSliceRenderer.cpp
  VolumeSliceShader.cpp
  VolumeRaycastRenderer.cpp
  VolumeRaycastShader.cpp
  glm.cpp
  FrameBufferObject.cpp
  DepthTexture.cpp
  #NarragansettBay/Glider.cpp
  #NarragansettBay/Labels.cpp
  #NarragansettBay/Tool.cpp 
  #NarragansettBay/LoadGliderDataAction.cpp 
  #NarragansettBay/VRFontHandler.cpp
  transferfunction/transfer_function_widget.cpp
  transferfunction/transfer_function_multichannel_widget.cpp
  ArcBall.cpp
  HelperFunctions.cpp
)

set(header_files
  VolumeVisualizationApp.h
  LoadDataAction.h
  Shader.h
  Volume.h
  VolumeSliceRenderer.h
  VolumeSliceShader.h
  VolumeRaycastRenderer.h
  VolumeRaycastShader.h
  glm.h
  FrameBufferObject.h
  DepthTexture.h
  #NarragansettBay/Glider.h
  #NarragansettBay/Labels.h
  #NarragansettBay/Tool.h 
  #NarragansettBay/LoadGliderDataAction.h 
  #NarragansettBay/VRFontHandler.h
  transferfunction/transfer_function_widget.h
  transferfunction/transfer_function_multichannel_widget.h
  transferfunction/embedded_colormaps.h
  ArcBall.h
  HelperFunctions.h
)


#---------------------- Find & Add Dependencies ----------------------

set(EXTERNAL_CMAKE_SCRIPTS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# MinVR (linked with an imported cmake target so no need to specify include dirs)
find_package(MinVR REQUIRED)
find_package(ImguiVR REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
FIND_PACKAGE(glm REQUIRED )
FIND_PACKAGE(OpenCV REQUIRED )
#FIND_PACKAGE(FTGL REQUIRED )
#FIND_PACKAGE(PNG REQUIRED )
#FIND_PACKAGE(ZLIB REQUIRED )
#FIND_PACKAGE(Freetype REQUIRED) # if it fails, check this:

#set(GLE_INCLUDE_DIR "" CACHE FILEPATH "GLE include directory")
#set(GLE_LIBRARY "" CACHE FILEPATH "GLE library")

include_directories(
  ${OPENGL_INCLUDE_DIR}
  ${MINVR_INCLUDE_DIR}
  ${GLM_INCLUDE_DIRS}
  ${GLEW_INCLUDE_DIRS}
#  ${GLE_INCLUDE_DIR}
#  ${FTGL_INCLUDE_DIR}
#  ${FREETYPE_INCLUDE_DIRS}
)



set(LIBRARIES
	ImguiVR
	${OpenCV_LIBS}
	${GLM_LIBRARIES}
	${GLEW_LIBRARY}
	${OPENGL_LIBRARY}
#	${FTGL_LIBRARIES}
	#${ZLIB_LIBRARIES}
#	${GLE_LIBRARY}
	#${PNG_LIBRARIES}
#	${FREETYPE_LIBRARIES}
)

if(WITH_TEEM)
	FIND_PACKAGE(Teem REQUIRED )
	include(${Teem_USE_FILE})
	set(LIBRARIES 
		${LIBRARIES} 
		teem)
	add_definitions(-DWITH_TEEM)
	set(header_files
		${header_files}
		LoadNrrdAction.h
	)
	set(source_files
		${source_files}
		LoadNrrdAction.cpp
	)
endif()


#---------------------- Define the Target ----------------------

add_executable(${PROJECT_NAME} ${source_files} ${header_files})

target_link_libraries(${PROJECT_NAME} PUBLIC MinVR::MinVR ${LIBRARIES})

