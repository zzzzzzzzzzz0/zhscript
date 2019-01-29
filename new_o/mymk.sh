#!/bin/bash
# "" gxx_lib_ gjke4
export o_dir_=/tmp/zhscript$1
mkdir -p $o_dir_/lib $o_dir_/gtkmmsh-plugin
shift
./mk64.sh "$@"
