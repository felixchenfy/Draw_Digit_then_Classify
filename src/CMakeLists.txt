

add_executable(GUI_main GUI_main.cpp)

add_library( mylib_GUI SHARED
    GUI_lib.cpp
    GUI_button.cpp
)
add_library( mylib_classifier SHARED
    digit_classifier.cpp
)

target_link_libraries( GUI_main
    mylib_GUI
    mylib_classifier
    ${THIRD_PARTY_LIBS}
)

