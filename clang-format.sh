#!/bin/bash

find . -name *.c -o -name *.cpp -o -name *.h -o -name *.hpp \
    | xargs clang-format -style=file -i -fallback-style=none

exit 0