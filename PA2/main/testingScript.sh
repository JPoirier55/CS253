#!/bin/bash

echo "Compiling..."
make clean
make

echo "First test with standard input"
./PA2 Testing/testcase1_standardinput.txt output.txt
if [ $? -eq 1 ]; then
  echo "Test passed"
else
  echo "Test Failed"
fi

echo "Second test with novel input"
./PA2 Testing/testcase2_novelinput.txt output.txt
if [ $? -eq 1 ]; then
  echo "Test passed"
else
  echo "Test Failed"
fi

echo "Third test with single pose input"
./PA2 Testing/testcase3_SinglePoseInput.txt output.txt
if [ $? -eq 1 ]; then
  echo "Test passed"
else
  echo "Test Failed"
fi

echo "Fourth test with empty input"
./PA2 Testing/testcase4_emptyInput.txt output.txt
if [ $? -eq 1 ]; then
  echo "Test passed"
else
  echo "Test Failed"
fi

echo "Fifith test with extra spaces input"
./PA2 Testing/testcase5_ExtraSpaces.txt output.txt
if [ $? -eq 1 ]; then
  echo "Test passed"
else
  echo "Test Failed"
fi

echo "First Invalid test with 150 values input"
./PA2 Testing/testcase_Invalid_150values.txt output.txt
if [ $? -ne 1 ]; then
  echo "Test passed"
else
  echo "Test Failed"
fi

echo "Second Invalid test with off line number (74 76) input"
./PA2 Testing/testcase_Invalid_7476.txt output.txt
if [ $? -ne 1 ]; then
  echo "Test passed"
else
  echo "Test Failed"
fi

echo "Thrid Invalid test with emtpyline input"
./PA2 Testing/testcase_Invalid_emptyline.txt output.txt
if [ $? -ne 1 ]; then
  echo "Test passed"
else
  echo "Test Failed"
fi

echo "Fourth Invalid test with letter in double input"
./PA2 Testing/testcase_Invalid_letter_A.txt output.txt
if [ $? -ne 1 ]; then
  echo "Test passed"
else
  echo "Test Failed"
fi

echo "Fifth  Invalid test with 73 values at end input"
./PA2 Testing/testcase_Invalid_truncatelast3.txt output.txt
if [ $? -ne 1 ]; then
  echo "Test passed"
else
  echo "Test Failed"
fi
