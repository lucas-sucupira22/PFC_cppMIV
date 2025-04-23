cmake_minimum_required(VERSION 3.16)

project(cppMIV VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appcppMIV
    main.cpp
    CommandController.h CommandController.cpp
    DownloadController.h DownloadController.cpp
    Readingcontroller.h ReadingController.cpp
    GeneralToolsController.h GeneralToolsController.cpp
)

qt_add_qml_module(appcppMIV
    URI cppMIV
    VERSION 1.0
    QML_FILES
        Main.qml
        QML_FILES BotaoMudarPagina.qml
        QML_FILES HomePage.qml
        QML_FILES ReportPage.qml
        QML_FILES ReadingPage.qml
        QML_FILES DownloadPage.qml
        QML_FILES CommandPage.qml
        QML_FILES AnalysisPage.qml
        QML_FILES functions.js
        QML_FILES
        QML_FILES
        SOURCES CommandController.h CommandController.cpp
        SOURCES DownloadController.h DownloadController.cpp
        SOURCES ReadingController.h ReadingController.cpp
        QML_FILES
        RESOURCES
        RESOURCES
        RESOURCES
        SOURCES GeneralToolsController.h GeneralToolsController.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appcppMIV PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appcppMIV
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appcppMIV
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appcppMIV
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
