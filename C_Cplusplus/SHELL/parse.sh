#!/bin/bash

remove_file()
{
    rm $1
}

# Step 1: Check number of parameters
if [ $# != 2 ]
then
    echo "Invalid parameter. Have to [./parse.sh input.txt output.txt]"
    exit 0
fi
file_input=$1
file_output=$2
# Step 2: Check if the input file is existing
if [ -f $file_input ]
then
    echo "Input file existing" >/dev/null
else
    echo "Input file is not existing"
    exit 0
fi
# Step 3: Remove output file if existing
if [ -f $file_output ]
then
    remove_file $file_output
fi
# Step 4: Read in line and writing to output file
while read line
do
    echo $line>temp.txt
    for ((i=1;i<6;i++))
    do
        case $i
        in
            1) Mr=$(awk 'BEGIN{FS=":"}{print $1}' temp.txt);;
            2) Year=$(awk 'BEGIN{FS=":"}{print $2}' temp.txt);;
            3) Sex=$(awk 'BEGIN{FS=":"}{print $3}' temp.txt);;
            4) Company=$(awk 'BEGIN{FS=":"}{print $4}' temp.txt);;
            5) Phone=$(awk 'BEGIN{FS=":"}{print $5}' temp.txt);;
            *) echo "error"
                exit 0
        esac
    done
    Str="Mr $Mr, $Year years old, sex is $Sex, work in $Company company, telephone number is $Phone"
    echo $Str
    # save to file_output.txt
    echo $Str >> $file_output
    rm -rf temp.txt
done <$file_input
echo "Data saved! Please check file_output.txt"