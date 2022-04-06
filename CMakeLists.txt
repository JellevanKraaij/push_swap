cmake_minimum_required(VERSION 3.23.0)

project(push_swap)
set (EXEC_NAME_CHECKER checker)
set (EXEC_NAME_SOLVER push_swap)

#compiler settings:
set (CMAKE_C_FLAGS "-Wall -Werror -Wextra")
set (CMAKE_C_FLAGS_DEBUG "-g -fsanitize=address") #cmake -DCMAKE_BUILD_TYPE=DEBUG to add debug flags
set (CMAKE_EXPORT_COMPILE_COMMANDS ON) #vscode include path checking

#norm rules so flclean and re work
add_custom_target(fclean make clean)
add_custom_target(re make clean COMMAND make)

#add libs
add_subdirectory(lib/libft)
add_subdirectory(lib/get_next_line)


#explicit src files locations
set (SRCS_CHECKER
	src_checker/main.c
	src_checker/input_parsing.c
	src_checker/vars.c
	src_checker/utils/errors.c
	src_checker/utils/ft_atoi_p.c
	src_checker/instructions/push.c
	src_checker/instructions/reverse_rotate.c
	src_checker/instructions/swap.c
	src_checker/instructions/rotate.c
	src_checker/stack_functions/lststack_ctors.c
	src_checker/stack_functions/lststack_imp.c
)

set (SRCS_SOLVER
	src_solver/main.c
	src_solver/small_solvers.c
	src_solver/solver_insertion.c
	src_solver/solver_insertion_helpers.c
	src_solver/solver_radix.c
	src_solver/input_parsing.c
	src_solver/vars.c
	src_solver/utils/errors.c
	src_solver/utils/ft_atoi_p.c
	src_solver/utils/biggest2.c
	src_solver/instructions/push.c
	src_solver/instructions/reverse_rotate.c
	src_solver/instructions/swap.c
	src_solver/instructions/rotate.c
	src_solver/instructions/convert_steps.c
	src_solver/instructions/execute_steps.c
	src_solver/stack_functions/lststack_ctors.c
	src_solver/stack_functions/lststack_imp.c
)

#compile checker
add_executable(${EXEC_NAME_CHECKER} ${SRCS_CHECKER})

#add include dir to checker
target_include_directories(${EXEC_NAME_CHECKER} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include_checker)

#link libs to checker
target_link_libraries(${EXEC_NAME_CHECKER} PRIVATE ft)
target_link_libraries(${EXEC_NAME_CHECKER} PRIVATE get_next_line)


#compile solver
add_executable(${EXEC_NAME_SOLVER} ${SRCS_SOLVER})

#add include dir to solver
target_include_directories(${EXEC_NAME_SOLVER} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include_solver)

#link libft to solver
target_link_libraries(${EXEC_NAME_SOLVER} PRIVATE ft)