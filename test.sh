#!/bin/bash

if [ `./randall 100 | wc -c` -eq 100 ]; \
then echo "vanilla test     -> ./randall 100                    | PASS"; \
else echo "vanilla test     -> ./randall 100                    | FAIL"; \
fi
if [ `./randall -i rdrand 50 | wc -c` -eq 50 ]; \
then echo "rdrand test      -> ./randall -i rdrand 50           | PASS"; \
else echo "rdrand test      -> ./randall -i rdrand 50           | FAIL"; \
fi
if [ `./randall -i mrand48_r 25 | wc -c` -eq 25 ]; \
then echo "mrand48_r test   -> ./randall -i mrand48_r 25        | PASS"; \
else echo "mrand48_r test   -> ./randall -i mrand48_r 25        | FAIL"; \
fi
if [ `./randall -i /dev/urandom 500 | wc -c` -eq 500 ]; \
then echo "file test        -> ./randall -i /dev/urandom 500    | PASS"; \
else echo "file test        -> ./randall -i /dev/urandom 500    | FAIL"; \
fi
if [ `./randall -o stdout 200 | wc -c` -eq 200 ]; \
then echo "stdout default   -> ./randall -o stdio 200           | PASS"; \
else echo "stdout default   -> ./randall -o stdio 200           | FAIL"; \
fi
if [ `./randall -o 1 1200 | wc -c` -eq 1200 ]; \
then echo "N KB block       -> ./randall -o 1 1200              | PASS"; \
else echo "N KB block       -> ./randall -o 1 1200              | FAIL"; \
fi
