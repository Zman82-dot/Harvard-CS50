from cs50 import get_int
def main():
            while True:
                    n = get_int("Height")
                    if n > 0 and n < 9:
                         break
            for i in range(n):


                print((n - 1 - i) * " ", end="")
                print((i + 1) * "#")
main()