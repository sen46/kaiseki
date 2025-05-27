NAME = LinearAlgebra.a

SRCS = LinearAlgebra.cpp

OBJS = $(SRCS:.cpp=.o)

CC = g++
CFLAGS = -Wall -Wextra
AR = ar rcs
RM = rm -f


%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
