

add_library(projectinfo projectinfomodule.cpp include/projectinfomodule.h)
target_include_directories(projectinfo PUBLIC include)
target_link_libraries(projectinfo PUBLIC displayservice)

add_executable(project_info_dev module_dev.cpp)
target_link_libraries(project_info_dev PUBLIC projectinfo)