#!/usr/bin/python

# This program accepts a positive integer, and determines whether it is
# prime or happy.

def isPrime(number):
    return all(number % i for i in xrange(2, number/2))

def isHappy(number, cycle):
    # cast our number to a string
    number_str = str(number)
    sum = 0
    # iterate over the "string", cast each number to int for the calculation
    for char in number_str:
        sum += int(char) * int(char)
    if sum == 1:
        return True
    elif sum in cycle:
        return False
    elif len(cycle) < 20:
        cycle.append(sum)
    # this is recursion, a topic we'll cover later
    return isHappy(sum, cycle)

def main():
    number = input("Enter a number ")
    cycle = []
    prime = isPrime(number)
    happy = isHappy(number, cycle)
    if prime and happy:
        print "Yay, a Happy Prime number"
    elif prime:
        print "Aww...a Sad Prime"
    elif happy:
        print "Well, the number is happy anyways"
    else:
        print "Shucks, a Sad Non-Prime"

if __name__ == "__main__":
        main()
