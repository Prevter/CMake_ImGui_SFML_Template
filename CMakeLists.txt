cmake_minimum_required (VERSION 3.15)

project (
	Template
	LANGUAGES CXX
	VERSION 1.0
)

add_executable (
	${CMAKE_PROJECT_NAME}
	"src/main.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 20)
endif()

# ImGui
include (FetchContent)
FetchContent_Declare (
  imgui
  GIT_REPOSITORY https://github.com/ocornut/imgui
  GIT_TAG ff1567e2406797cbd1a3ef3d716888d6c3a66bd7
)

FetchContent_MakeAvailable (imgui)

message(STATUS "Fetching ImGui-SFML...")

set(IMGUI_DIR ${imgui_SOURCE_DIR})
set(IMGUI_SFML_FIND_SFML OFF)
set(IMGUI_SFML_IMGUI_DEMO ON)

add_subdirectory(dependencies/imgui-sfml)

# SFML
set (SFML_STATIC_LIBRARIES TRUE)
add_subdirectory (dependencies/sfml)


target_link_libraries (
	${CMAKE_PROJECT_NAME}
	sfml-system sfml-window sfml-graphics sfml-network sfml-audio
	ImGui-SFML::ImGui-SFML
)
