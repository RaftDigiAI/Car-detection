cmake_minimum_required(VERSION 3.16)

project(CarPrice VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

include_directories(src/
                    qml/)

qt_add_executable(appCarPrice
    src/main.cpp
)

qt_add_qml_module(appCarPrice
    URI CarPrice
    VERSION 1.0
    QML_FILES qml/Main.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appCarPrice PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appCarPrice
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appCarPrice
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appCarPrice
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)