##
## EPITECH PROJECT, 2023
## panoramix
## File description:
## Makefile
##

CXX						=				gcc

## ===========================================================
## ===========================[VAR]===========================
## ===========================================================

NAME					=				panoramix

NAME_TEST				=				unit_test

NAME_FUNC_TEST			=				## a shell file

## ===========================================================
## ===========================[SRC]===========================
## ===========================================================

MAIN 			=						main.c

SRC				=						error.c		\
										print.c		\
										actions.c	\
										setAll.c	\
										villager.c	\
										druid.c		\
										panoramix.c	\

BUILDDIR 				= 				build

OBJ_SRC 				= 	$(patsubst %.c, $(BUILDDIR)/%.o, $(SRC) $(MAIN))

$(BUILDDIR)/%.o: 	src/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

TEST_SRC		=	##	tests/unit_tests/						\

## ===========================================================
## =========================[OPTIONS]=========================
## ===========================================================

RM						=				rm -f

CFLAGS					=				-Wall 							\
 										-Wextra							\

TESTFLAGS				=				-lcriterion --coverage

MATHFLAGS				=				-lm

THREDINGFLAGS			=				-lpthread

## ===========================================================
## ==========================[RULES]==========================
## ===========================================================

## ==========================[CORE]===========================

all: $(NAME)

$(NAME):	$(OBJ_SRC)
	$(CXX) -o $(NAME) $(OBJ_SRC) $(CFLAGS) $(THREDINGFLAGS)

debug: re
debug: CFLAGS += -g3

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
	gcc -o unit_tests tests/tests.c $(CFLAGS)  -lm --coverage -lcriterion

tests_run:	fclean $(OBJ_SRC)
			$(CXX) -o $(NAME_TEST) $(OBJ_SRC) $(TEST_SRC) $(TESTFLAGS) $(CFLAGS)
			./$(NAME_TEST)
			gcovr --exclude tests/
			gcovr --exclude tests/ --branches

## ===========================================================
## ===========================[PHONY]=========================
## ===========================================================

.PHONY: all debug clean fclean tests_run unit_tests fclean_tests
