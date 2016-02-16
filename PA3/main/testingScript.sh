#!/bin/bash

echo "Compiling..."
make clean
make

echo "First test with standard input"
./PA3 Testing/testcase1_standardinput.txt output.txt
if [ $? -eq 1 ]; then
  echo "Test passed"
else
  echo "Test Failed"
fi

echo "Second test with novel input"
./PA3 Testing/testcase2_novelinput.txt output.txt
if [ $? -eq 1 ]; then
  echo "Test passed"
else
  echo "Test Failed"
fi

echo "Third test with single pose input"
./PA3 Testing/testcase3_SinglePoseInput.txt output.txt
if [ $? -eq 1 ]; then
  echo "Test passed"
else
  echo "Test Failed"
fi

echo "Fourth test with empty input"
./PA3 Testing/testcase4_emptyInput.txt output.txt
if [ $? -eq 1 ]; then
  echo "Test passed"
else
  echo "Test Failed"
fi

echo "Fifith test with extra spaces input"
./PA3 Testing/testcase5_ExtraSpaces.txt output.txt
if [ $? -eq 1 ]; then
  echo "Test passed"
else
  echo "Test Failed"
fi

echo "First Invalid test with 150 values input"
./PA3 Testing/testcase_Invalid_150values.txt output.txt
if [ $? -ne 1 ]; then
  echo "Test passed"
else
  echo "Test Failed"
fi

echo "Second Invalid test with off line number (74 76) input"
./PA3 Testing/testcase_Invalid_7476.txt output.txt
if [ $? -ne 1 ]; then
  echo "Test passed"
else
  echo "Test Failed"
fi

echo "Thrid Invalid test with emtpyline input"
./PA3 Testing/testcase_Invalid_emptyline.txt output.txt
if [ $? -ne 1 ]; then
  echo "Test passed"
else
  echo "Test Failed"
fi

echo "Fourth Invalid test with letter in double input"
./PA3 Testing/testcase_Invalid_letter_A.txt output.txt
if [ $? -ne 1 ]; then
  echo "Test passed"
else
  echo "Test Failed"
fi

echo "Fifth  Invalid test with 73 values at end input"
./PA3 Testing/testcase_Invalid_truncatelast3.txt output.txt
if [ $? -ne 1 ]; then
  echo "Test passed"
else
  echo "Test Failed"
fi

echo "First test with excessively large input"
./PA3 Testing/OtherTests/Excessively_Large.txt output.txt
if [ $? -eq 1 ]; then
  echo "Test passed"
else
  echo "Test Failed"
fi

echo "Second test with excessively small input"
./PA3 Testing/OtherTests/Excessively_Small.txt output.txt
if [ $? -eq 1 ]; then
  echo "Test passed"
else
  echo "Test Failed"
fi

echo "Third test with Shifted_All_Negative  input"
./PA3 Testing/OtherTests/Shifted_All_Negative.txt output.txt
if [ $? -eq 1 ]; then
  echo "Test passed"
else
  echo "Test Failed"
fi

echo "Fourth test with Shifted_All  input"
./PA3 Testing/OtherTests/Shifted_All.txt output.txt
if [ $? -eq 1 ]; then
  echo "Test passed"
else
  echo "Test Failed"
fi

echo "Fifth test with Shifted_Large input"
./PA3 Testing/OtherTests/Shifted_Large.txt output.txt
if [ $? -eq 1 ]; then
  echo "Test passed"
else
  echo "Test Failed"
fi

echo "Sixth test with Shifted_Small input"
./PA3 Testing/OtherTests/Shifted_Small.txt output.txt
if [ $? -eq 1 ]; then
  echo "Test passed"
else
  echo "Test Failed"
fi

echo "Seventh test with Shifted_X input"
./PA3 Testing/OtherTests/Shifted_X.txt output.txt
if [ $? -eq 1 ]; then
  echo "Test passed"
else
  echo "Test Failed"
fi

echo "Eigth test with Unmoved_Large input"
./PA3 Testing/OtherTests/Unmoved_Large.txt output.txt
if [ $? -eq 1 ]; then
  echo "Test passed"
else
  echo "Test Failed"
fi

echo "nnith test with Unmoved_Small input"
./PA3 Testing/OtherTests/Unmoved_Small.txt output.txt
if [ $? -eq 1 ]; then
  echo "Test passed"
else
  echo "Test Failed"
fi

echo "10th test with no file input"
./PA3
if [ $? -ne 1 ]; then
  echo "Test passed"
else
  echo "Test Failed"
fi

echo "11th test with wrong file input"
./PA3 Testing/OtherTests/Excesssssively_Large.txt output.txt
if [ $? -ne 1 ]; then
  echo "Test passed"
else
  echo "Test Failed"
fi
