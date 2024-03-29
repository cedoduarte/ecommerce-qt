cmake_minimum_required(VERSION 3.5)

project(ecommerce-qt VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Network)

set(PROJECT_SOURCES
        main.cpp
        widgets/screens/mainwindow.cpp
        widgets/screens/mainwindow.h
        widgets/screens/mainwindow.ui
        widgets/screens/logindialog.h
        widgets/screens/logindialog.cpp
        widgets/screens/logindialog.ui
        widgets/components/countrycombobox.cpp
        widgets/components/countrycombobox.h

        shared/qnetlib/qflexiblejsonobject.cpp
        shared/qnetlib/qflexiblejsonobject.h
        shared/qnetlib/qnetaccessmanager.cpp
        shared/qnetlib/qnetaccessmanager.h
        shared/qnetlib/qnetrequest.cpp
        shared/qnetlib/qnetrequest.h
        shared/constants.h
        shared/constants.cpp
        shared/interfaces.h
        shared/interfaces.cpp
        shared/store.h
        shared/store.cpp

        res.qrc
)

qt_add_resources(PROJECT_SOURCES res.qrc)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ecommerce-qt
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ecommerce-qt APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(ecommerce-qt SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(ecommerce-qt
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(ecommerce-qt PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(ecommerce-qt PRIVATE Qt${QT_VERSION_MAJOR}::Network)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.ecommerce-qt)
endif()
set_target_properties(ecommerce-qt PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS ecommerce-qt
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ecommerce-qt)
endif()
