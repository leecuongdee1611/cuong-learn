add_library(MathLib MathFunc.cpp)

# state that anybody linking to us needs to include the current source dir
# to find MatFunc.h, while we don't
target_include_directories(MathLib
	INTERFACE
		${CMAKE_CURRENT_SOURCE_DIR}
)
