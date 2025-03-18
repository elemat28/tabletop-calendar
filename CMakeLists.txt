cmake_minimum_required(VERSION 3.10.0)
project(tabletopCalendar VERSION 0.1.0 LANGUAGES C CXX)

enable_testing()
add_executable(epaper wrappers/epaper/main.c)
add_library(waveshare_eink STATIC wrappers/epaper/waveshare_eink.c wrappers/epaper/include/waveshare_eink.h dependencies/e-Paper/RaspberryPi_JetsonNano/c/lib/Config/DEV_Config.h dependencies/e-Paper/RaspberryPi_JetsonNano/c/lib/Config/DEV_Config.c dependencies/e-Paper/RaspberryPi_JetsonNano/c/lib/e-Paper/EPD_7in3f.h dependencies/e-Paper/RaspberryPi_JetsonNano/c/lib/e-Paper/EPD_7in3f.c dependencies/e-Paper/RaspberryPi_JetsonNano/c/lib/GUI/GUI_Paint.c dependencies/e-Paper/RaspberryPi_JetsonNano/c/lib/GUI/GUI_Paint.h )
target_include_directories(waveshare_eink PUBLIC wrappers/epaper/include dependencies dependencies/e-Paper/RaspberryPi_JetsonNano/c/lib/Config dependencies/e-Paper/RaspberryPi_JetsonNano/c/lib/e-Paper dependencies/e-Paper/RaspberryPi_JetsonNano/c/lib/GUI )
target_compile_definitions(waveshare_eink PUBLIC RPI=1 USE_LGPIO_LIB=1)
target_link_libraries(waveshare_eink PUBLIC lgpio)
target_link_libraries(epaper PUBLIC waveshare_eink)


add_subdirectory(src)
add_subdirectory(tests)



include(CTest)
enable_testing()

