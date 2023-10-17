cmake_minimum_required(VERSION 3.16)

project(CarPrice VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.3 REQUIRED COMPONENTS Quick Multimedia Svg)

qt_standard_project_setup()

add_compile_definitions(QT_NO_DEBUG_OUTPUT)

include_directories(src/
    qml/
    headers/
    third-party/tensorflow
    third-party/flatbuffers/include
    third-party/tflite-support/
    third-party/abseil-cpp
    third-party/protobuf/src
)

qt_add_executable(appCarPrice
    src/main.cpp
    headers/definedmodels.hpp
    resource.qrc

    headers/tfmodel.h src/tfmodel.cpp
    headers/abstractobjectdetectionmodel.h src/abstractobjectdetectionmodel.cpp
    headers/tfmodelworker.h src/tfmodelworker.cpp
    headers/constants/general.hpp headers/constants/model.hpp
)

qt_add_qml_module(appCarPrice
    URI CarPrice
    VERSION 1.0
    QML_FILES qml/Main.qml
    RESOURCES resource.qrc
    SOURCES headers/videohandler.h src/videohandler.cpp
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

# Import tensorflow-lite library for it need set property(where located library),
# add and link it using `tensorflowlite` name.
#add_library(tensorflowlite SHARED IMPORTED)

add_library(tensorflowlite SHARED IMPORTED)
add_library(tensorflowlite_gpu_delegate SHARED IMPORTED)

if (ANDROID)
    if (${ANDROID_ABI} STREQUAL "x86_64")
        message("Will be build android x86_64")
        # Setup tensorflowlite property
        set_property(TARGET tensorflowlite PROPERTY
            IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/tensorflow-lite/x86_64/libtensorflowlite.so)
        # Setup tensorflowlite deleagte property
        set_property(TARGET tensorflowlite_gpu_delegate PROPERTY
            IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/tensorflow-lite/x86_64/libtensorflowlite_gpu_delegate.so)

        # Copy files
        file(GLOB libraries
            "${CMAKE_SOURCE_DIR}/lib/tensorflow-lite/x86_64/*")
        file(COPY ${libraries}
            DESTINATION ${CMAKE_BINARY_DIR}/android-build/libs/x86_64/)
    elseif (${ANDROID_ABI} STREQUAL "arm64-v8a")
        message("Will be build android arm64-v8a")
        # Set tensorflowlite property
        set_property(TARGET tensorflowlite PROPERTY
            IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/tensorflow-lite/arm64/libtensorflowlite.so)
        # Set tensorflowlite deleagte property
        set_property(TARGET tensorflowlite_gpu_delegate PROPERTY
            IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/tensorflow-lite/arm64/libtensorflowlite_gpu_delegate.so)

        # Copy files
        file(GLOB libraries
            "${CMAKE_SOURCE_DIR}/lib/tensorflow-lite/arm64/*")
        file(COPY ${libraries}
            DESTINATION ${CMAKE_BINARY_DIR}/android-build/libs/arm64-v8a)
    else ()
        message(WARNING "Not impleted yet.")
    endif()
else ()
    set_property(TARGET tensorflowlite PROPERTY
        IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/tensorflow-lite/linux/libtensorflowlite.so)
    message(DEBUG "Will be build desktop")
endif()

target_link_libraries(appCarPrice
    PRIVATE Qt6::Quick
    Qt6::Multimedia
    Qt6::Svg
    tensorflowlite
    tensorflowlite_gpu_delegate
)

include(GNUInstallDirs)
install(TARGETS appCarPrice
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
