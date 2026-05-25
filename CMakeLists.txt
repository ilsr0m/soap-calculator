cmake_minimum_required(VERSION 3.16)

project(soap-calculator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(APPLICATION_NAME SoapCalculator)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

set(CORE_SOURCES
    src/core/soap_core.cpp
    src/core/soap_core.h
    src/core/input_builder.cpp
    src/core/input_builder.h

    src/app/app-settings/app_settings.h
    src/app/app-settings/app_settings.cpp
)

set(INTERFACE_SOURCES
    src/interfaces/repository-interface/irepository.h
    src/interfaces/repository-interface/json-interface/ijson_repository.cpp
    src/interfaces/repository-interface/json-interface/ijson_repository.h
)

set(SERVICE_SOURCES
    src/services/json-service/json_loader.cpp
    src/services/json-service/json_loader.h
    src/services/database-service/database.cpp
    src/services/database-service/database.h
)
set(MODELS
    src/models/base_model.h
    src/models/lipid-model/lipid_model.cpp
    src/models/lipid-model/lipid_model.h
    src/models/acid-model/acid_model.cpp
    src/models/acid-model/acid_model.h
    src/models/additive-model/additive_model.cpp
    src/models/additive-model/additive_model.h
    src/models/filter-proxy-model/ingredient_filter_proxy_model.h
)

set(INCLUDES
    include/soap_params.h
    include/utils.h
    include/roles/model_roles.h
)

set(OTHER_FILES
    data/repository.json
    resources/resources.qrc
)

qt_add_executable(${APPLICATION_NAME}
    src/app/main.cpp
    ${INCLUDES}
    ${CORE_SOURCES}
    ${SERVICE_SOURCES}
    ${MODELS}
    ${INTERFACE_SOURCES}
    ${OTHER_FILES}
)

qt_add_resources(${APPLICATION_NAME}
    PREFIX "/"
        FILES
            resources/icons/search.svg
            resources/icons/info.svg
            resources/icons/edit.svg
            resources/icons/settings.svg
            resources/icons/check.svg
)

target_include_directories(${APPLICATION_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include/roles
        ${CMAKE_CURRENT_SOURCE_DIR}/src/services/json-service
        ${CMAKE_CURRENT_SOURCE_DIR}/src/services/database-service
        ${CMAKE_CURRENT_SOURCE_DIR}/src/interfaces/repository-interface
        ${CMAKE_CURRENT_SOURCE_DIR}/src/interfaces/repository-interface/json-interface
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core
        ${CMAKE_CURRENT_SOURCE_DIR}/src/models
        ${CMAKE_CURRENT_SOURCE_DIR}/src/models/acid-model
        ${CMAKE_CURRENT_SOURCE_DIR}/src/models/additive-model
        ${CMAKE_CURRENT_SOURCE_DIR}/src/models/lipid-model
        ${CMAKE_CURRENT_SOURCE_DIR}/src/models/filter-proxy-model
        ${CMAKE_CURRENT_SOURCE_DIR}/src/app/app-settings
)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES
    src/app/main.cpp
    ${INCLUDES}
    ${CORE_SOURCES}
    ${INTERFACE_SOURCES}
    ${MODELS}
    ${SERVICE_SOURCES}
    ${DATA_FILES}
    ${OTHER_FILES}
)

set(BASE_COMPONENTS
    qml/components/base/BaseButton.qml
    qml/components/base/BaseCheckbox.qml
)

set(PANELS_COMPONENTS
    qml/components/panels/ingredient-panel/ingredient-components/IngredientTitle.qml
    qml/components/panels/ingredient-panel/ingredient-components/IngredientSearch.qml
    qml/components/panels/ingredient-panel/ingredient-components/IngredientView.qml
    qml/components/panels/ingredient-panel/ingredient-components/IngredientButtons.qml
    qml/components/panels/ingredient-panel/IngredientPanel.qml
)

set_source_files_properties(qml/themes/Theme.qml
    PROPERTIES
        QT_QML_SINGLETON_TYPE TRUE
)

qt_add_qml_module(${APPLICATION_NAME}
    URI SoapCalculator
    VERSION 1.0
    QML_FILES
        qml/Main.qml
        ${BASE_COMPONENTS}
        ${PANELS_COMPONENTS}
        qml/themes/Theme.qml 
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(${APPLICATION_NAME} PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(${APPLICATION_NAME}
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS ${APPLICATION_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
