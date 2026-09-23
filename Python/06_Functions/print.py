import sys
def myprint(prompt = '\n'):
    try:
        sys.stdout.write(prompt)
        sys.stdout.write('\n')
        sys.stdout.flush()
    except BaseException:
        sys.stdout.write("Error with the entered value")

myprint("Hello World")