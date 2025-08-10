# Simple Makefile for Lesson 1
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c17 -O0 -g

all: ptr_lab1

ptr_lab1: ptr_lab1.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f ptr_lab1
