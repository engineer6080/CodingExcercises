#!/bin/bash


echo "1. Condition variable, mutex lock, and semaphore example"
echo -n "Choose option:"
read input

case "$input" in

        1)  echo "1"
                gcc multi.c -lpthread
                ./a.out
                ;;
        2)  echo  "Sending SIGINT signal"
                kill -SIGINT $2
                ;;
        3)  echo  "Sending SIGQUIT signal"
                kill -SIGQUIT $2
                ;;
        9) echo  "Sending SIGKILL signal"
                kill -SIGKILL $2
                ;;
        *) echo "Signal number $1 is not processed"
                ;;
esac

rm a.out
