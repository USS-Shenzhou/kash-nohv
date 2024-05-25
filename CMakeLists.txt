cmake_minimum_required(VERSION 3.5)

project(kash-nohv VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "D:/Qt/6.6.3/msvc2019_64/lib/cmake")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

if (MSVC)
    add_compile_options(/Zc:__cplusplus)
else ()
    add_compile_options(-fmodules-ts)
endif()

include_directories(
        "include"
        "src"
        "cmake-build-debug/kash-nohv_autogen"
        "libs/aliyun-oss-cpp-sdk/include"
        "libs/aliyun-oss-cpp-sdk/lib"
)

set(PROJECT_SOURCES
        src/oss/OssManager.ixx
        src/oss/Endpoints.ixx
        src/oss/module.ixx

        src/main.cpp

        src/gui/window/kashnohv.cpp
        include/gui/window/kashnohv.h
        src/gui/window/kashnohv.ui

        include/gui/window/loginsplashdialog.h
        src/gui/window/loginsplashdialog.cpp
        src/gui/window/loginsplashdialog.ui

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(kash-nohv
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        resources/resources.qrc
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET kash-nohv APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(kash-nohv SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(kash-nohv
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(kash-nohv
        PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
        debug ${CMAKE_SOURCE_DIR}/libs/aliyun-oss-cpp-sdk/lib/debug/alibabacloud-oss-cpp-sdk.lib
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.kash-nohv)
endif()
set_target_properties(kash-nohv PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS kash-nohv
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(kash-nohv)
endif()
