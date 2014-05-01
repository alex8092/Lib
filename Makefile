CC = gcc

NAME = lib/libft.a

DEBUG = false

CFLAGS = -Wall -Wextra -Iinclude -march=native

ifeq ($(DEBUG),true)
	CFLAGS += -g3
else
	CFLAGS += -O3
endif

LDFLAGS = -lft -Llib -Iinclude -march=native

SRCS = $(shell find src -name "*.c")

HEADERS = $(shell find include -name "*.h")

OBJS = $(patsubst src/%,obj/%,$(SRCS:.c=.o))

OBJS_DIR = $(addsuffix .dir,$(OBJS))

SRCS_TEST = $(shell find tests -name "*.c")

all: Makefile.deps $(OBJS_DIR) $(NAME)

test: tests/test.bin

run: test
	./tests/test.bin

tests/test.bin:
	gcc -o tests/test.bin $(SRCS_TEST) $(CFLAGS) $(LDFLAGS)

$(NAME): $(OBJS)
	mkdir -p $(dir $@)
	ar rc $@ $(OBJS)
	ranlib $@

-include Makefile.deps

obj/%.dir:
	@mkdir -p $(dir $@)

obj/%.o: src/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf obj

fclean: clean
	rm -rf lib

re: fclean all

Makefile.deps: $(SRCS) $(HEADERS)
	@makedepend $(CFLAGS) -- $(SRCS) > Makefile.deps 2> /dev/null
	@\vim Makefile.deps -c '%s/src\//obj\//g' -c wq

.PHONY: clean fclean all re test run tests/test.bin
