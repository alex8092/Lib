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

OS = $(shell uname -s)

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
ifeq ($(OS),Darwin)
	@makedepend $(CFLAGS) -- $(SRCS) > Makefile.deps 2> /dev/null
else
	@makedepend -- $(CFLAGS) -- $(SRCS) -f- > Makefile.deps 2> /dev/null
endif
	@\vim Makefile.deps -c '%s/src\//obj\//g' -c wq

.PHONY: clean fclean all re test run tests/test.bin
# DO NOT DELETE

src/ft_strstr.o: include/ft_common.h /usr/include/unistd.h
src/ft_strstr.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ft_strstr.o: /usr/include/getopt.h
src/ft_memalloc.o: include/ft_common.h /usr/include/unistd.h
src/ft_memalloc.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ft_memalloc.o: /usr/include/getopt.h /usr/include/stdlib.h
src/ft_memalloc.o: /usr/include/alloca.h
src/ft_findinarray.o: include/ft_common.h /usr/include/unistd.h
src/ft_findinarray.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ft_findinarray.o: /usr/include/getopt.h
src/ft_strsub.o: include/ft_common.h /usr/include/unistd.h
src/ft_strsub.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ft_strsub.o: /usr/include/getopt.h /usr/include/stdlib.h
src/ft_strsub.o: /usr/include/alloca.h
src/ft_putendl.o: include/ft_common.h /usr/include/unistd.h
src/ft_putendl.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ft_putendl.o: /usr/include/getopt.h
src/ft_sort.o: include/ft_common.h /usr/include/unistd.h
src/ft_sort.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ft_sort.o: /usr/include/getopt.h /usr/include/string.h
src/ft_sort.o: /usr/include/xlocale.h
src/ft_strjoin.o: include/ft_common.h /usr/include/unistd.h
src/ft_strjoin.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ft_strjoin.o: /usr/include/getopt.h /usr/include/stdlib.h
src/ft_strjoin.o: /usr/include/alloca.h
src/ft_putnendl_fd.o: include/ft_common.h /usr/include/unistd.h
src/ft_putnendl_fd.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ft_putnendl_fd.o: /usr/include/getopt.h
src/ft_bzero.o: include/ft_common.h /usr/include/unistd.h
src/ft_bzero.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ft_bzero.o: /usr/include/getopt.h
src/ft_putendl_fd.o: include/ft_common.h /usr/include/unistd.h
src/ft_putendl_fd.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ft_putendl_fd.o: /usr/include/getopt.h
src/ft_getnextline.o: include/ft_common.h /usr/include/unistd.h
src/ft_getnextline.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ft_getnextline.o: /usr/include/getopt.h /usr/include/stdlib.h
src/ft_getnextline.o: /usr/include/alloca.h
src/ft_strdup.o: include/ft_common.h /usr/include/unistd.h
src/ft_strdup.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ft_strdup.o: /usr/include/getopt.h /usr/include/stdlib.h
src/ft_strdup.o: /usr/include/alloca.h /usr/include/stdint.h
src/ft_itoa.o: include/ft_common.h /usr/include/unistd.h
src/ft_itoa.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ft_itoa.o: /usr/include/getopt.h /usr/include/stdlib.h
src/ft_itoa.o: /usr/include/alloca.h
src/ft_putstr_fd.o: include/ft_common.h /usr/include/unistd.h
src/ft_putstr_fd.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ft_putstr_fd.o: /usr/include/getopt.h
src/ft_putnstr.o: include/ft_common.h /usr/include/unistd.h
src/ft_putnstr.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ft_putnstr.o: /usr/include/getopt.h
src/ft_memcpy.o: include/ft_common.h /usr/include/unistd.h
src/ft_memcpy.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ft_memcpy.o: /usr/include/getopt.h /usr/include/stdint.h
src/ft_strlen.o: include/ft_common.h /usr/include/unistd.h
src/ft_strlen.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ft_strlen.o: /usr/include/getopt.h /usr/include/limits.h
src/ft_strlen.o: /usr/include/stdint.h /usr/include/stdio.h
src/ft_strlen.o: /usr/include/libio.h /usr/include/_G_config.h
src/ft_strlen.o: /usr/include/wchar.h
src/ft_putnbr.o: include/ft_common.h /usr/include/unistd.h
src/ft_putnbr.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ft_putnbr.o: /usr/include/getopt.h
src/ft_atoi.o: include/ft_common.h /usr/include/unistd.h
src/ft_atoi.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ft_atoi.o: /usr/include/getopt.h
src/ft_strcmp.o: include/ft_common.h /usr/include/unistd.h
src/ft_strcmp.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ft_strcmp.o: /usr/include/getopt.h /usr/include/stdint.h
src/ft_putchar_fd.o: include/ft_common.h /usr/include/unistd.h
src/ft_putchar_fd.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ft_putchar_fd.o: /usr/include/getopt.h
src/ft_strsplit.o: include/ft_common.h /usr/include/unistd.h
src/ft_strsplit.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ft_strsplit.o: /usr/include/getopt.h /usr/include/stdlib.h
src/ft_strsplit.o: /usr/include/alloca.h
src/ft_putnstr_fd.o: include/ft_common.h /usr/include/unistd.h
src/ft_putnstr_fd.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ft_putnstr_fd.o: /usr/include/getopt.h
src/ft_memdup.o: include/ft_common.h /usr/include/unistd.h
src/ft_memdup.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ft_memdup.o: /usr/include/getopt.h /usr/include/stdlib.h
src/ft_memdup.o: /usr/include/alloca.h
src/ft_putnendl.o: include/ft_common.h /usr/include/unistd.h
src/ft_putnendl.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ft_putnendl.o: /usr/include/getopt.h
src/ft_strchr.o: include/ft_common.h /usr/include/unistd.h
src/ft_strchr.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ft_strchr.o: /usr/include/getopt.h /usr/include/stdlib.h
src/ft_strchr.o: /usr/include/alloca.h /usr/include/stdint.h
src/ft_putchar.o: include/ft_common.h /usr/include/unistd.h
src/ft_putchar.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ft_putchar.o: /usr/include/getopt.h
src/ft_strndup.o: include/ft_common.h /usr/include/unistd.h
src/ft_strndup.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ft_strndup.o: /usr/include/getopt.h /usr/include/stdlib.h
src/ft_strndup.o: /usr/include/alloca.h
src/ft_putstr.o: include/ft_common.h /usr/include/unistd.h
src/ft_putstr.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ft_putstr.o: /usr/include/getopt.h
src/ft_strncpy.o: include/ft_common.h /usr/include/unistd.h
src/ft_strncpy.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ft_strncpy.o: /usr/include/getopt.h
src/ft_putnbr_fd.o: include/ft_common.h /usr/include/unistd.h
src/ft_putnbr_fd.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ft_putnbr_fd.o: /usr/include/getopt.h
src/ft_strcpy.o: include/ft_common.h /usr/include/unistd.h
src/ft_strcpy.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ft_strcpy.o: /usr/include/getopt.h
src/ft_memset.o: include/ft_common.h /usr/include/unistd.h
src/ft_memset.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ft_memset.o: /usr/include/getopt.h /usr/include/stdint.h
src/ft_strnjoin.o: include/ft_common.h /usr/include/unistd.h
src/ft_strnjoin.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ft_strnjoin.o: /usr/include/getopt.h /usr/include/stdlib.h
src/ft_strnjoin.o: /usr/include/alloca.h
