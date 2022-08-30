# add uint test
# define function
function(mosqdb_test test_file link_file)
    # get file name
    get_filename_component(test_target_name ${test_file} NAME_WE)
    add_executable(${test_target_name} ${test_file})
    target_link_libraries(${test_target_name} ${link_file})
    add_test(NAME ${test_target_name} COMMAND ${test_target_name})
endfunction(mosqdb_test)

#add_executable(demo_test demo_test.cpp)
#target_link_libraries(demo_test solution)
#add_test(NAME demo_test COMMAND demo_test)

mosqdb_test(demo_test.cpp solution)
mosqdb_test(slice_test.cpp mosqdb)
