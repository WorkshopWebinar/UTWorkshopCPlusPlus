#!/usr/bin/env bash


#Store the binary names
INSTRUMENTED_BINARY_NAME=ParameterizedTestExamples


#Run initial/baseline lcov
lcov --capture --rc lcov_branch_coverage=1 --initial --directory .  --output-file base.info

#Execute the tests
../build/$INSTRUMENTED_BINARY_NAME

## Move gcno files to current dir
find ../build -iname "*.gcno" -exec mv "{}" . \;

## Move gcda files to current dir
find ../build/ -iname "*.gcda" -exec mv "{}" . \;

#Run lcov again after executing tests
lcov --capture --rc lcov_branch_coverage=1 --directory .  --output-file test.info

#Combine lcov tracefiles
lcov --rc lcov_branch_coverage=1 --add-tracefile base.info --add-tracefile test.info --output-file total.info

#Remove / filter out remaining unwanted stuff from tracefile
lcov --rc lcov_branch_coverage=1 --remove total.info '/usr/include/*' -o filtered.info

#Generate the report 
mkdir report
genhtml --rc genhtml_branch_coverage=1  filtered.info -o report

#clean residual
rm -rf *.gcov *.info *.gcno *.gcda
