#!/usr/bin/python

def fibo():
    result = []
    result.append(1)
    result.append(1)
    curr = 0
    i = 0
    while curr < 4000000:
            curr = result[i] + result[i+1]
            result.append(curr)
            i = i + 1
    return result

def main():
    list = fibo()
    sum = 0
    for element in list:
        if element % 2 == 0:
            sum += element
    print sum

if __name__ == "__main__":
    main()
