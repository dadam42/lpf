NAME=libft_printf.a#
SRCS_DIRS=srcs#
ADD_SRCS=#Not handled
OBJS_DIR=objs#
INC_DIRS=srcs/includes#
HEADER_DIR=includes#
INSTALL_HEADER=srcs/includes/ft_printf.h#
LIBS_DIRS=libs/libft#
LIBS=ft#
INC_LIBS=libs/libft/includes#
MY_CFLAGS=-Wall -Wextra#
MODULES=libft#
CC=gcc#
########
LDFLAGS+=$(LIBS_DIRS:%=-L%)#
LDLIBS+=$(LIBS:%=-l%)#
CFLAGS+=$(MY_CFLAGS)#
CPPFLAGS+=$(INC_DIRS:%=-I%) $(INC_LIBS:%=-I%)#
SRCS=$(foreach mdir, $(SRCS_DIRS),$(wildcard $(mdir)/**/*.c))#
SRCS_DIRS_=$(sort $(dir $(SRCS)))#
SRCS_=$(sort $(notdir $(SRCS)))#
define mydef
$1=$2
endef
#$(if $(OBJS_DIR),$(info toto),$(info echo tata)) << wtf?
OBJS=$(SRCS_:%.c=$(OBJS_DIR)/%.o)#
VPATH+=$(SRCS_DIRS_) $(OBJS_DIR)#
HEADER_NAME=$(notdir $(INSTALL_HEADER))#

.PHONY: all#
all: $(NAME)#

$(NAME):$(OBJS) libft#
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	cp $(INSTALL_HEADER) $(HEADER_DIR)/$(HEADER_NAME)

$(OBJS_DIR)/%.o: %.c#
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

.PHONY: clean#
clean:#
	$(RM) $(OBJS)

.PHONY: fclean#
fclean: clean#
	$(RM) $(NAME)
	$(RM) $(HEADER_DIR)/$(HEADER_NAME)

.PHONY: re#
re: fclean all#

.PHONY: libft
libft:
	$(MAKE) -C libs/libft

#define addmodrule
#.PHONY: $1
#$1:
#	$(MAKE) -C $1
#endef
#$(foreach mod,$(MODULES),$(call addmodrule,$(mod)))#
