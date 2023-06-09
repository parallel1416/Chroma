cmake_minimum_required(VERSION 3.5)

project(Chroma VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

set(TS_FILES Chroma_zh_CN.ts)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        startmenu.h
        startmenu.cpp
        character.h character.cpp
        dialogbox.h dialogbox.cpp
        scene.h scene.cpp
        mybtn.h mybtn.cpp
        globalvar.h globalvar.cpp
        map.h map.cpp
        item.h item.cpp
        backpack.cpp backpack.h
        battle.cpp battle.h
        battle_panel.cpp battle_panel.h
        battle_scene.cpp battle_scene.h
        resources.qrc
        setting.h setting.cpp
        backpack1.qrc
        ${TS_FILES}
)

set(UI_FILES
    bp.ui
)

qt6_wrap_ui(UI_HEADERS ${UI_FILES})


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Chroma
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Chroma APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(Chroma SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Chroma
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(Chroma PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(Chroma PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS Chroma
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Chroma)
endif()

find_package(Qt6 REQUIRED COMPONENTS Multimedia)
target_link_libraries(Chroma PRIVATE Qt6::Multimedia)
find_package(Qt6 REQUIRED COMPONENTS MultimediaWidgets)
target_link_libraries(Chroma PRIVATE Qt6::MultimediaWidgets)
