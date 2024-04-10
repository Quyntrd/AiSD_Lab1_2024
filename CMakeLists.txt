cmake_minimum_required (VERSION 3.11)

project (Set-v1 CXX)

set(CMAKE_CXX_STANDARD 23)

if (MSVC)

	set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)

	if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
		string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4" )
	endif()
endif()

add_library(Set-v1 SHARED "src/BST.cpp")

target_include_directories(Set-v1 PUBLIC "src")
add_executable (Set-v1-main "app/main.cpp")
add_executable (Set-v1-time "app/time_calculation.cpp")
target_link_libraries(Set-v1-main Set-v1)
target_link_libraries(Set-v1-time Set-v1)

