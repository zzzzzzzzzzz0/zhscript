cflags1=-Dver_64_ -Wall -c -fmessage-length=0 -fPIC -MMD -MP

ifeq ($(o),d)
out=Debug
tag=../../new_o/l4.so
cflags2=-O0 -g3
endif

ifeq ($(o),r)
out=Release
tag=../../new_o/l4.so
cflags3=-O3
cflags4=-O0
endif

ifeq ($(o),rlc)
out=release-liucheng
tag=../../new_o/l4-d.so
cflags2=-Ddebug_liucheng_
cflags3=-O3
cflags4=-O0
endif

ifeq ($(o),nr)
out=release-n
tag=../../new_o/l4.so
cflags2=-Dver_no_asm_
cflags3=-O3
cflags4=-O0
endif

ifeq ($(o),nrlc)
out=release-n-liucheng
tag=../../new_o/l4-d.so
cflags2=-Ddebug_liucheng_ -Dver_no_asm_
cflags3=-O3
cflags4=-O0
#748536 -O3
#605176 3 4
#1690416 -O0 -g3
#745568 -O0
#698672 -Os
endif

ifeq ($(o),a)
out=debug-a
tag=../../new_o/l4-a.so
cflags2=-Dver_64a_ -O0 -g3
endif

ifeq ($(o),ar)
out=release-a
tag=../../new_o/l4.so
cflags2=-Dver_64a_
cflags3=-O3
cflags4=-O0
endif

ifeq ($(o),arlc)
out=release-a-liucheng
tag=../../new_o/l4-d.so
cflags2=-Ddebug_liucheng_ -Dver_64a_
cflags3=-O3
cflags4=-O0
endif

ifndef o
$(error  o={d | r | rlc | nr | nrlc | a | ar | arlc} [x])
endif

all: $(tag)
	g++ -shared -o $(tag) $(out)/*.o

$(tag): \
$(out)/args___.o \
$(out)/call_ex___.o \
$(out)/call_func.o \
$(out)/call_func2.o \
$(out)/err___.o \
$(out)/errinfo___.o \
$(out)/file___.o \
$(out)/jieshiqi___.o \
$(out)/jieshiqi_call___.o \
$(out)/jieshiqi_for___.o \
$(out)/jieshiqi_if___.o \
$(out)/jieshiqi_load___.o \
$(out)/jieshiqi_var___.o \
$(out)/l4___.o \
$(out)/path.o \
$(out)/qu___.o \
$(out)/syn___.o \
$(out)/util.o \
$(out)/var___.o \
$(out)/var_val___.o \
$(out)/zhi___.o

$(out)/%.o: %.cpp
	@mkdir -p $(out)
	g++ $(cflags3) $(cflags2) $(cflags1) -MF"$(@:%.o=%.d)" -MT"$(@)" -o"$@" "$<"
$(out)/call_func.o: call_func.cpp
	g++ $(cflags4) $(cflags2) $(cflags1) -MF"$(@:%.o=%.d)" -MT"call_func.d" -o"$@" "$<"

x:
	-rm $(tag) $(out)/*.o $(out)/*.d
