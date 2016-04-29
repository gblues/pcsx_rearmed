#!/bin/sh

[ -p /tmp/pcsx_jit ] || mkfifo /tmp/pcsx_jit
[ -p /tmp/pcsx_int ] || mkfifo /tmp/pcsx_int

LD_LIBRARY_PATH=. ./pcsx -lightrec-interpreter -lightrec-debug $* > /tmp/pcsx_int &
LD_LIBRARY_PATH=. ./pcsx -lightrec-debug $* > /tmp/pcsx_jit &

exec python ./big_ass_debugger.py
