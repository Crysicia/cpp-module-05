CFLAGS	= -std=c++98 -pedantic -Wall -Werror -Wextra
CXX		= c++
NAME	= bureaucrat.out
OBJS	= $(SRCS:.cpp=.o)
RM		= rm -f
SRCS	= main.cpp \
		  Bureaucrat.cpp

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)
