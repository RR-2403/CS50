def main():
    while True:
        try:
            height = int(input("HEIGHT= "))
            if 1 <= height <= 8:
                break
        except ValueError:
            pass  # Ignore invalid input and re-prompt

    for row in range(height):
        print(" " * (height - row - 1) + "#" * (row + 1))

if __name__ == "__main__":
    main()
