CONVS=c s d xl xu u i p

define conv.fake.exe.rule
conv_$1.fake.exe: ft_printf.c;gcc -I../includes -I../libs/libft/includes -Wall -Wextra -Werror -DCONV_$(shell echo $1 | tr a-z A-Z) -DFAKE ft_printf.c -lft_printf -L.. -lft -L../libs/libft -o conv_$1.fake.exe
 
endef

define conv.fake.rule
conv_$1.fake:conv_$1.fake.exe
	./conv_$1.fake.exe > conv_$1.fake

endef

define conv.orig.exe.rule
conv_$1.orig.exe:ft_printf.c
	gcc -I../includes -I../libs/libft/includes -Wall -Wextra -Werror -DCONV_$(shell echo $1 | tr a-z A-Z) -DORIG ft_printf.c -lft_printf -L.. -lft -L../libs/libft -o conv_$1.orig.exe

endef

define conv.orig.rule
conv_$1.orig:conv_$1.orig.exe
	./conv_$1.orig.exe > conv_$1.orig

endef

define conv.both.exe.rule
conv_$1.both.exe:
	gcc -I../includes -I../libs/libft/includes -Wall -Wextra -Werror -DCONV_$(shell echo $1 | tr a-z A-Z) -DORIG -DFAKE ft_printf.c -lft_printf -L.. -lft -L../libs/libft -o conv_$1.both.exe

endef

define test.rule
test_$1:conv_$1.both.exe conv_$1.fake conv_$1.orig
	diff -U 1 conv_$1.fake conv_$1.orig > $$@

endef

define result.rule
$1_result:test_$1 
	./conv_$1.both.exe | less
	less test_$1

endef

FILES=$(CONVS:%=conv_%.fake.exe) $(CONVS:%=conv_%.fake) $(CONVS:%=conv_%.orig.exe) $(CONVS:%=conv_%.orig) $(CONVS:%=conv_%.both.exe) $(CONVS:%=test_%) simple

simple:simple.c
	gcc -g -I../includes -Wall -Wextra -Werror simple.c -lft_printf -L.. -lft -L../libs/libft -o simple

$(foreach conv,$(CONVS),$(eval $(call conv.fake.exe.rule,$(conv))))

$(foreach conv,$(CONVS),$(eval $(call conv.fake.rule,$(conv))))

$(foreach conv,$(CONVS),$(eval $(call conv.orig.exe.rule,$(conv))))

$(foreach conv,$(CONVS),$(eval $(call conv.orig.rule,$(conv))))

$(foreach conv,$(CONVS),$(eval $(call conv.both.exe.rule,$(conv))))

$(foreach conv,$(CONVS),$(eval $(call test.rule,$(conv))))

.PHONY:$(CONVS:%=%_result)
$(foreach conv,$(CONVS),$(eval $(call result.rule,$(conv))))

.PHONY:clean
clean:
	rm -f $(FILES)
