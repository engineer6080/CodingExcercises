#!/bin/bash

clear
./comp

input=y

while [ "$input" != "z" ]
do
        echo " "
        echo "1. Remove Duplicates from Unsorted Linked List"
        echo "2. Pointer Example in C"
        echo "3. Check if string contains unique characters"
        echo "4. Check if a string is a permutation of a palindrome"
        echo "5. Check if 2 strings are one edit away from each other"
        echo -n "Choose option:"
        read input

        case "$input" in

                1)  echo "1"
                        ./p.out
                        ;;
                2)  echo  "2"
                        ./point.out
                        ;;
                3)  echo  "3"
                        ./a.out
                        ;;
                4) echo  "4"
                        ./b.out
                        ;;
                5) echo  "5"
                        ./c.out
                        ;;
                *) echo "Bye"
                        break
                        ;;
        esac
done

rm *.out
