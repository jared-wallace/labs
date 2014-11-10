#!/usr/bin/python
import sys

def repeat(name):
    result = name * 10
    return result


def main():
    name = sys.argv[1]
    if name == "Guido":
        print repeeet(name) + '!!!'
    else:
        print repeat(name)

# Standard boilerplate to call the main() function to begin
# the program.
if __name__ == '__main__':
    main()
