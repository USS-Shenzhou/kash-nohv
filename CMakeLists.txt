cmake_minimum_required(VERSION 3.5)

project(kash-nohv VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "D:/Qt/6.6.3/msvc2019_64/lib/cmake")
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

include_directories(
        "include"
        "src"
        "cmake-build-debug/kash-nohv_autogen/include"
        "src/oss"
        "src/util"
        "cmake-build-debug"
        "C:/Users/Tony Yu/.vcpkg-clion/vcpkg/packages/aliyun-oss-c-sdk_x64-windows/include"
        "C:/Users/Tony Yu/.vcpkg-clion/vcpkg/packages/apr_x64-windows/include"
        "C:/Users/Tony Yu/.vcpkg-clion/vcpkg/packages/apr-util_x64-windows/include"
        "C:/Users/Tony Yu/.vcpkg-clion/vcpkg/packages/curl_x64-windows/include"
        "libs/mxml"
)

add_executable(kash-nohv
        include/util/ThreadHelper.h
        src/util/ThreadHelper.cpp

        include/oss/EndPoints.h
        src/oss/Endpoints.cpp
        include/oss/OssManager.h
        src/oss/OssManager.cpp

        src/main.cpp

        include/gui/window/kashnohv.h
        src/gui/window/kashnohv.cpp
        include/gui/window/kashnohv.ui

        include/gui/window/loginsplashdialog.h
        src/gui/window/loginsplashdialog.cpp
        include/gui/window/loginsplashdialog.ui
        resources/resources.qrc
)

target_link_libraries(kash-nohv
        PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
        PRIVATE "C:/Users/Tony Yu/.vcpkg-clion/vcpkg/packages/aliyun-oss-c-sdk_x64-windows/lib/oss_c_sdk.lib"
        PRIVATE "C:/Users/Tony Yu/.vcpkg-clion/vcpkg/packages/apr_x64-windows/lib/libapr-1.lib"
        PRIVATE "C:/Users/Tony Yu/.vcpkg-clion/vcpkg/packages/apr-util_x64-windows/lib/libaprutil-1.lib"
        PRIVATE "C:/Users/Tony Yu/.vcpkg-clion/vcpkg/packages/curl_x64-windows/lib/libcurl.lib"
        PRIVATE "${PROJECT_SOURCE_DIR}/libs/mxml/mxml1.lib"
        PRIVATE "D:/Windows Kits/10/Lib/10.0.22000.0/um/x64/WS2_32.Lib"
)

if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER cn.uss-shenzhou.kash-nohv)
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
