add_test( [==[GraphRead: Simple, Directed Pentagon]==] /workspaces/cs2251/proj/final_project/build/test [==[GraphRead: Simple\, Directed Pentagon]==]  )
set_tests_properties( [==[GraphRead: Simple, Directed Pentagon]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs2251/proj/final_project/build)
add_test( [==[GraphRead: Simple, Directed Tree]==] /workspaces/cs2251/proj/final_project/build/test [==[GraphRead: Simple\, Directed Tree]==]  )
set_tests_properties( [==[GraphRead: Simple, Directed Tree]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs2251/proj/final_project/build)
add_test( [==[file_match: same file]==] /workspaces/cs2251/proj/final_project/build/test [==[file_match: same file]==]  )
set_tests_properties( [==[file_match: same file]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs2251/proj/final_project/build)
add_test( [==[file_match: 1 line different]==] /workspaces/cs2251/proj/final_project/build/test [==[file_match: 1 line different]==]  )
set_tests_properties( [==[file_match: 1 line different]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs2251/proj/final_project/build)
add_test( [==[file_match: num lines different]==] /workspaces/cs2251/proj/final_project/build/test [==[file_match: num lines different]==]  )
set_tests_properties( [==[file_match: num lines different]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs2251/proj/final_project/build)
add_test( [==[file_match: deleted line]==] /workspaces/cs2251/proj/final_project/build/test [==[file_match: deleted line]==]  )
set_tests_properties( [==[file_match: deleted line]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs2251/proj/final_project/build)
add_test( [==[write: unmodified graph]==] /workspaces/cs2251/proj/final_project/build/test [==[write: unmodified graph]==]  )
set_tests_properties( [==[write: unmodified graph]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs2251/proj/final_project/build)
add_test( [==[write: after adding nodes, edges]==] /workspaces/cs2251/proj/final_project/build/test [==[write: after adding nodes\, edges]==]  )
set_tests_properties( [==[write: after adding nodes, edges]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs2251/proj/final_project/build)
add_test( [==[Kosaraju: Simple, Directed Pentagon]==] /workspaces/cs2251/proj/final_project/build/test [==[Kosaraju: Simple\, Directed Pentagon]==]  )
set_tests_properties( [==[Kosaraju: Simple, Directed Pentagon]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs2251/proj/final_project/build)
add_test( [==[Kosaraju: Simple, Directed Tree]==] /workspaces/cs2251/proj/final_project/build/test [==[Kosaraju: Simple\, Directed Tree]==]  )
set_tests_properties( [==[Kosaraju: Simple, Directed Tree]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs2251/proj/final_project/build)
add_test( [==[dijkstra: directed cycle]==] /workspaces/cs2251/proj/final_project/build/test [==[dijkstra: directed cycle]==]  )
set_tests_properties( [==[dijkstra: directed cycle]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs2251/proj/final_project/build)
add_test( [==[dijkstra: perfect tree (two sources)]==] /workspaces/cs2251/proj/final_project/build/test [==[dijkstra: perfect tree (two sources)]==]  )
set_tests_properties( [==[dijkstra: perfect tree (two sources)]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs2251/proj/final_project/build)
set( test_TESTS [==[GraphRead: Simple, Directed Pentagon]==] [==[GraphRead: Simple, Directed Tree]==] [==[file_match: same file]==] [==[file_match: 1 line different]==] [==[file_match: num lines different]==] [==[file_match: deleted line]==] [==[write: unmodified graph]==] [==[write: after adding nodes, edges]==] [==[Kosaraju: Simple, Directed Pentagon]==] [==[Kosaraju: Simple, Directed Tree]==] [==[dijkstra: directed cycle]==] [==[dijkstra: perfect tree (two sources)]==])
