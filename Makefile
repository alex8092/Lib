CC = gcc

NAME = libft.a

DEBUG = false

CFLAGS = -Wall -Wextra -Iinclude

ifeq ($(DEBUG),true)
	CFLAGS += -g3
else
	CFLAGS += -O3
endif

LDFLAGS = 
SRCS = $(shell find src -name "*.c")

HEADERS = $(shell find include -name "*.h")

OBJS = $(patsubst src/%,obj/%,$(SRCS:.c=.o))

OBJS_DIR = $(addsuffix .dir,$(OBJS))

all: Makefile.deps $(OBJS_DIR) $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $(OBJS) $(LDFLAGS)
	ranlib $@

-include Makefile.deps

obj/%.dir:
	@mkdir -p $(dir $@)

obj/%.o: src/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all

Makefile.deps: $(SRCS) $(HEADERS)
	@makedepend -- $(CFLAGS) -- $(SRCS) -f- > Makefile.deps 2> /dev/null
	@\vim Makefile.deps -c '%s/src\//obj\//g' -c wq

.PHONY: clean fclean all re deps
