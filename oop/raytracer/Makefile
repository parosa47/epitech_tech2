##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

CXX						=				g++

## ===========================================================
## ===========================[VAR]===========================
## ===========================================================

NAME					=				raytracer

NAME_TEST				=				unit_test

NAME_FUNC_TEST			=				## a shell file

## ===========================================================
## ===========================[SRC]===========================
## ===========================================================

MAIN 			=						main.cpp

SRC				=						SFML/printIMG.cpp							\
										AComponent/camera/Camera.cpp				\
										AComponent/sphere/sphere.cpp				\
										../Vector/Vector.cpp				\

BUILDDIR 				= 				build

OBJ_SRC 				= 				$(patsubst %.cpp, $(BUILDDIR)/%.o, $(SRC) $(MAIN))

$(BUILDDIR)/%.o: 	src/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) -c -o $@ $<

TEST_SRC		=	##	tests/unit_tests/						\

## ===========================================================
## =========================[OPTIONS]=========================
## ===========================================================

RM						=				rm -f

CFLAGS					=

CXXFLAGS				=				-std=c++20 									\
 										-Wall 										\
 										-Wextra										\
										$(addprefix -I./, $(CPPFLAGS_HEADERS))		\

TESTFLAGS				=				-lcriterion --coverage

SFMLFLAGS				=				-lsfml-graphics -lsfml-window -lsfml-system

MATHFLAGS				=				-lm

## ===========================================================
## ==========================[RULES]==========================
## ===========================================================

## ==========================[CORE]===========================

all: $(NAME)

$(NAME):	$(OBJ_SRC)
	$(CXX) -o $(NAME) $(OBJ_SRC) $(CXXFLAGS) $(SFMLFLAGS) $(MATHFLAGS)

debug: re
debug: CXXFLAGS += -g3

## ===========================================================
## =======================[DOCS]=============================
## ===========================================================

docs:
	doxygen Doxyfile
	cd docs/latex && make pdf && make && mv refman.pdf ../../
	mv refman.pdf doc.pdf
	mv doc.pdf ./doc
	firefox docs/html/index.html

## ===========================================================
## =======================[CLEAN]=============================
## ===========================================================

clean:
	$(RM) $(OBJ_SRC)
	$(RM) *.gcno *.gcda vgcore*

fclean: clean
	$(RM) $(NAME) $(NAME_TEST)
	if test -d docs; then \
        rm -r docs; \
    fi

fclean_tests:
	$(RM) unit_tests
	$(RM) *gcda
	$(RM) *gcno

re: fclean all clean

## ===========================================================
## =======================[TESTS]=============================
## ===========================================================

unit_tests:    $(NAME) fclean
	gcc -o unit_tests tests/tests.c $(CXXFLAGS)  -lm --coverage -lcriterion

tests_run:	fclean $(OBJ_SRC)
			$(CXX) -o $(NAME_TEST) $(OBJ_SRC) $(TEST_SRC) $(TESTFLAGS) $(CXXFLAGS)
			./$(NAME_TEST)
			gcovr --exclude tests/
			gcovr --exclude tests/ --branches

## ===========================================================
## ===========================[PHONY]=========================
## ===========================================================

.PHONY: all debug clean fclean tests_run unit_tests fclean_tests
