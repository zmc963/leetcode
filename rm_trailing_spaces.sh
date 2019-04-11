#!/bin/bash

cd cpp && find . -type f -name "*.cpp" -print0 | xargs -0 sed -i "s/[[:blank:]]*$//"
