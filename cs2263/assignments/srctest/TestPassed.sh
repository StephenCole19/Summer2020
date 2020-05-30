#!/bin/bash

##########################
#
# Created by Jean-Philippe Legault
# 
# This script compares two file to see if they differ from each other
# using the `diff` command.
#
##########################

# get the two files to compare via the arguments to this script
FILE_ONE="$1"
FILE_TWO="$2"

# verify two files passed via the arguments for this script are equal using the `diff` command
diff ${FILE_ONE} ${FILE_TWO} > /dev/null

# get the exit code of diff 
RETURN_CODE="$?"

# 0 indicates no differences were found
if [ "${RETURN_CODE}" == "0" ]
then
    echo -e "\n######   Passed   ###### ${FILE_ONE} is equal to ${FILE_TWO} \n"
    exit 0
else
    echo -e "\n######   Failed   ###### ${FILE_ONE} is NOT equal to ${FILE_TWO} \n"
    exit 1
fi