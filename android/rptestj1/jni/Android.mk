LOCAL_PATH := $(call my-dir)


include $(CLEAR_VARS)

LOCAL_MODULE    := zhscript

LOCAL_SRC_FILES := zhscript.cpp \
new_l4/l432_so/call_func.cpp \
new_l4/l432_so/err___.cpp \
new_l4/l432_so/var_val___.cpp \
new_l4/l432_so/zhi___.cpp \
new_l4/l432_so/jieshiqi_for___.cpp \
new_l4/l432_so/call_ex___.cpp \
new_l4/l432_so/path.cpp \
new_l4/l432_so/util.cpp \
new_l4/l432_so/jieshiqi___.cpp \
new_l4/l432_so/jieshiqi_call___.cpp \
new_l4/l432_so/errinfo___.cpp \
new_l4/l432_so/var___.cpp \
new_l4/l432_so/jieshiqi_var___.cpp \
new_l4/l432_so/qu___.cpp \
new_l4/l432_so/syn___.cpp \
new_l4/l432_so/jieshiqi_if___.cpp \
new_l4/l432_so/jieshiqi_load___.cpp \
new_l4/l432_so/call_func2.cpp \
new_l4/l432_so/l4___.cpp \
new_l4/l432_so/file___.cpp \
new_l4/l432_so/args___.cpp \

LOCAL_CFLAGS += -Dver_android_ -Dver_no_asm_16_ 
LOCAL_LDLIBS := -ldl -llog -landroid 

include $(BUILD_SHARED_LIBRARY)


include $(CLEAR_VARS)
LOCAL_MODULE    := calcu
LOCAL_SRC_FILES := calcu.c
include $(BUILD_SHARED_LIBRARY)
