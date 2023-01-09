# E89 Pedagogical & Technical Lab
# project:     rev
# created on:  2023-01-05 - 09:34 +0100
# 1st author:  martin.leroy - martin.leroy
# description: makefile

NAME	=	printf.a

SRCS	=	src/main.c	\
		src/dprintf.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -Werror -Iinclude/

LDFLAGS	+=

RM	=	rm -vf

CC	:=	gcc

ifdef RELEASE
CFLAGS += -O2
endif

ifdef DEBUG
CFLAGS += -g
endif

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

test:
	$(CC) $(CFLAGS) src/main.c printf.a -o printf

exe:
	make
	make test
	./printf 2> /dev/null
	./printf 1> /dev/null
	make fclean

save:
	git status
	git add Makefile src/*.c include/*.h
	git commit -m "$(NAME) Sauvegarde"
	git push

clear:
	rm src/*.c~ include/*~

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

# Theses rules do not directly map to a specific file
.PHONY: all clear clean fclean re save
