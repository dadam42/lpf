NAME=libftprintf.a
INSTALL_DIR=includes
INSTALL_DIR?=.
SRCS_DIR=srcs
HEADERS_DIR=$(SRCS_DIR)/includes
SRCS_FILES=srcs/convs/conv_c.c srcs/convs/conv_d.c srcs/convs/conv_error.c srcs/convs/conv_num.c srcs/convs/conv_p.c srcs/convs/conv_pe.c srcs/convs/conv_s.c srcs/convs/conv_str.c srcs/convs/conv_u.c srcs/convs/conv_ubase.c srcs/convs/conv_xl.c srcs/convs/conv_xu.c srcs/convs/conv_n.c srcs/format/format_rules.c srcs/output_field/output_field.c srcs/parser/pf_parser.c srcs/pf_exec.c srcs/pf_functions.c srcs/t_out_buffer/t_out_buffer.c
OBJS_DIR=objs#
ifndef OBJS_DIR
OBJS_DIR=$(SRCS_DIR)
endif
OBJS_FILES=$(SRCS_FILES:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
#Handling dependancies : 
DEP_DIR_ROOT=.dep
DEP_FILES=$(SRCS_FILES:$(SRCS_DIR)/%.c=$(DEP_DIR_ROOT)/%.d)
DEP_DIRS_ =$(dir $(DEP_FILES))
uniq=$(if $1,$(firstword $1) $(call uniq,$(filter-out $(firstword $1),$1)))
DEP_DIRS=$(sort $(call uniq,$(DEP_DIRS_)))
DEP_FLAGS= -MT $@ -MMD -MP -MF $(DEP_DIR_ROOT)/$*.d
#Redefining Compilation process to handle dependancies:
COMPILE.c=$(CC) $(DEP_FLAGS) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c
CFLAGS=-Wall -Wextra -Werror
CPPFLAGS=-I$(HEADERS_DIR)
#Handling additional libraries
LIBS=libft
LIBS_HEADERS_DIRS=libft/includes
LIBS_=$(LIBS:lib%=-l%)
CPPFLAGS+=$(foreach hdir,$(LIBS_HEADERS_DIRS),-I$(hdir))

define librule
$1.a: ; $(MAKE) -C $1
endef

.PHONY: all
all: $(LIBS:%=%.a) $(NAME) install

$(NAME):$(OBJS_FILES)
	ar rc $(NAME) $(OBJS_FILES)
	ranlib $(NAME)

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c $(DEP_DIR_ROOT)/%.d | depdirs objdirs
	$(COMPILE.c) $(OUTPUT_OPTION) $<

.PHONY: install
install:
	cp srcs/includes/ft_printf.h $(INSTALL_DIR)

.PHONY:clean
clean:
	rm -f $(OBJS_FILES)

.PHONY:depclean
depclean:
	rm -rf $(DEP_DIR_ROOT)	

.PHONY:fclean
fclean:clean depclean
	rm -f $(NAME)
	rm -f $(INSTALL_DIR)/ft_printf.h
	$(foreach ldir,$(LIBS),$(MAKE) -C $(ldir) fclean;)

$(foreach ldir,$(LIBS),$(call librule,$(ldir)))

.PHONY:re
re:fclean all

.PHONY: depdirs
depdirs: ; @$(foreach mydir,$(DEP_DIRS),mkdir -p $(mydir);)

.PHONY: objdirs
objdirs: ; @$(foreach mydir,$(DEP_DIRS),mkdir -p $(mydir:$(DEP_DIR_ROOT)/%=$(OBJS_DIR)/%);)
$(DEP_FILES):

include $(wildcard $(DEP_FILES))
