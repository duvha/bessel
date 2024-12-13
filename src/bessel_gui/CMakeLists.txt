set(PROJECT_SOURCES
    main.cpp
    bessel.cpp
    besselview.cpp
    graph.cpp
)

qt_add_executable(Bessel
        ${PROJECT_SOURCES}
)

target_link_libraries(Bessel PRIVATE Qt6::Widgets)

target_link_libraries(Bessel PRIVATE m)

set_target_properties(Bessel PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)
