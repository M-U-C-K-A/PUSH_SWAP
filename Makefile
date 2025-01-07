NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = src
RULESDIR = rules
OBJDIR = objs
INCDIR = includes

SRCS = $(addprefix $(SRCDIR)/, main.c utils.c turksort.c finalize.c) \
       $(addprefix $(RULESDIR)/, rules_push.c rules_reverse.c rules_rotate.c rules_swap.c)

OBJS = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Compilation de $(NAME) terminée."

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR)/%.o: $(RULESDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)
	@echo "Dossier $(OBJDIR) supprimé."

fclean: clean
	@rm -f $(NAME)
	@echo "Exécutable $(NAME) supprimé."

re: fclean all

.PHONY: all clean fclean re
