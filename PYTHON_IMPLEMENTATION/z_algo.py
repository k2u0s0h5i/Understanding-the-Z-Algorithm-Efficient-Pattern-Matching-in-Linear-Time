def getZarr(string):
    n = len(string)
    z = [0] * n
    l, r = 0, 0
    for i in range(1, n):
        if i > r:
            l = r = i
            while r < n and string[r - l] == string[r]:
                r += 1
            z[i] = r - l
            r -= 1
        else:
            k = i - l
            if z[k] < r - i + 1:
                z[i] = z[k]
            else:
                l = i
                while r < n and string[r - l] == string[r]:
                    r += 1
                z[i] = r - l
                r -= 1
    return z

def search(text, pattern):
    text_length = len(text)
    pattern_length = len(pattern)
    concat = pattern + "$" + text
    z = getZarr(concat)
    pattern_found = False
    for i in range(len(concat)):
        if z[i] == pattern_length:
            print("Pattern found at index:", i - pattern_length - 1)
            pattern_found = True
    if not pattern_found:
        print("Pattern Not Found")

def main():
    filename = input("Enter the filename: ")
    try:
        with open(filename, 'r') as file:
            text = file.readline().rstrip('\n')
    except FileNotFoundError:
        print("Error opening file.")
        return

    pattern = input("Enter the pattern: ")
    if len(pattern) == 0:
        print("Empty Pattern")
        return

    search(text, pattern)

if __name__ == "__main__":
    main()
