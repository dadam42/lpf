TARGET=libft_printf.a
INSTALL_DIR=includes
TARGET_DIR=.
HEADER_TO_INSTALL=ft_printf.h
SRCS=srcs/convs/conv_c.c srcs/convs/conv_d.c srcs/convs/conv_error.c srcs/convs/conv_num.c srcs/convs/conv_p.c srcs/convs/conv_pe.c srcs/convs/conv_s.c srcs/convs/conv_str.c srcs/convs/conv_u.c srcs/convs/conv_ubase.c srcs/convs/conv_xl.c srcs/convs/conv_xu.c srcs/format/format_rules.c srcs/output_field/output_field.c srcs/parser/pf_parser.c srcs/pf_exec.c srcs/pf_functions.c srcs/t_out_buffer/t_out_buffer.c
CFLAGS=-Wall -Wextra -Werror
CPPFLAGS=-Isrcs/includes -Ilibs/libft/includes
OBJS=$(SRCS:%.c=%.o)
LIBS=libft
LIBS_DIR=libs
LIBS_INCLUDE=libft/includes

DEP_DIR=.dep
DEP_FLAGS=-MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d

.PHONY: all
all: $(LIBS) $(TARGET) install

$(TARGET): $(OBJS)
	ar rc $(TARGET) $(OBJS)
	ranlib $(TARGET)

.PHONY: install
install:
	cp srcs/includes/$(HEADER_TO_INSTALL) $(INSTALL_DIR)/$(HEADER_TO_INSTALL)

.PHONY: uninstall
uninstall:
	rm -f $(INSTALL_DIR)/$(HEADER_TO_INSTALL)

.PHONY: clean
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBS_DIR)/libft clean

.PHONY: fclean
fclean: clean
	rm -f $(TARGET)
	$(MAKE) -C $(LIBS_DIR)/libft fclean

.PHONY: libft
libft:
	$(MAKE) -C $(LIBS_DIR)/libft

#%.o:%.c
#%.o:%.c $(DEP_DIR)/%.d | $(DEP_DIR)
#	$(CC) $(DEP_FLAGS) $(CFLAGS) $(CPPFLAGS) -c $<

$(DEP_DIR): ; @mkdir -p $@

DEPFILES:= $(SRCS:%.c=$(DEPDIR)/%.d)
$(DEPFILES):

include $(wildcard $(DEPFILES))
