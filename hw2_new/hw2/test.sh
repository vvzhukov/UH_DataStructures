#Compile the code
# if the file densemult exits then remove it
if [ -f ListOperation ]; then
    rm ListOperation
fi
g++ -std=c++11 *.cpp -o ListOperation
# if the file densemult does not exit then exit the test
if [ ! -f ListOperation ]; then
    echo -e "\033[1;91mCompile FAILED.\033[0m"
    exit
fi
# clean
if [ -f *.out ]; then
    rm *.out
fi
if [ -f *.stderr ]; then
    rm *.stderr
fi
if [ -f *.stdcout ]; then
    rm *.stdcout
fi
#rm *.out *.stderr *.stdcout
# For test case 1
# input 1.txt and output 1.out
./ListOperation "input=input21.txt;command=command21.txt;output=output21.txt" 1>1.stdcout 2>1.stderr
# compare 1.out with 1.ans, output the difference to 1.diff
diff -iEBwu ans21.txt output21.txt > 1.diff
# if diff returns nothing, it means you pass the test case (Your ourput file 1.out is correct)
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case 1    \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e "Test case 1    \033[1;92mPASSED.\033[0m"
    # remove the file 1.diff
    rm -f 1.diff
fi
# For test case 2
./ListOperation "input=input22.txt;command=command22.txt;output=output22.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans22.txt output22.txt > 2.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 2    \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 2    \033[1;92mPASSED.\033[0m"
    rm -f 2.diff
fi
# For test case 3
./ListOperation "input=input23.txt;command=command23.txt;output=output23.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans23.txt output23.txt > 3.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 3    \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 3    \033[1;92mPASSED.\033[0m"
    rm -f 3.diff
fi



