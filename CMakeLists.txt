cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

PROJECT("lightning")

set(EXE_NAME ${PROJECT_NAME})
set(LIB_NAME ${PROJECT_NAME})


find_package(VTK REQUIRED)
find_package(OpenGL REQUIRED)
find_package(Qt5 COMPONENTS Widgets OpenGL REQUIRED)


include(${VTK_USE_FILE})

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)




set(UI_FILES
    mainwindow.ui
)

# Headers wirth Q_OBJECTs
set(EXE_QT_HEADERS
    mainwindow.h
)

# Headers without Q_OBJECT  
set(EXE_HEADERS
    model-node.h
)

# All source files
set(EXE_SOURCE
    main.cpp
    mainwindow.cpp
    node.cpp
)


# Create headers from .ui files with moc
#qt5_wrap_ui(AUTOGEN_UI_SOURCE ${UI_FILES} )

# CMAKE_AUTOMOC in ON so the MOC headers will be automatically wrapped.  
add_executable(${PROJECT_NAME} ${EXE_SOURCE} ${EXE_HPP} ${EXE_QT_HPP})

target_include_directories(${LIB_NAME} PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${sotm_INCLUDE_DIRS}
  ${Qt5Widgets_INCLUDE_DIRS}
  ${Qt5Core_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME} PUBLIC Qt5::Widgets Qt5::OpenGL ${OPENGL_LIBRARIES} ${VTK_LIBRARIES})

