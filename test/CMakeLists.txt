

add_executable(test_digit_classifier test_digit_classifier.cpp)

target_link_libraries( test_digit_classifier
    mylib_classifier
    ${THIRD_PARTY_LIBRARIES}
)

