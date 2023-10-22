'''

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

'''
def rail_fence_encrypt(plaintext, rails):
    fence = [['\n' for _ in range(len(plaintext))] for _ in range(rails)]
    direction = -1
    row, col = 0, 0

    for char in plaintext:
        fence[row][col] = char
        if row == 0 or row == rails - 1:
            direction *= -1
        row += direction
        col += 1

    ciphertext = ''
    for i in range(rails):
        for j in range(len(plaintext)):
            if fence[i][j] != '\n':
                ciphertext += fence[i][j]

    return ciphertext


def rail_fence_decrypt(ciphertext, rails):
    fence = [['\n' for _ in range(len(ciphertext))] for _ in range(rails)]
    direction = -1
    row, col = 0, 0

    for _ in range(len(ciphertext)):
        if row == 0 or row == rails - 1:
            direction *= -1
        fence[row][col] = '*'
        row += direction
        col += 1

    index = 0
    for i in range(rails):
        for j in range(len(ciphertext)):
            if fence[i][j] == '*' and index < len(ciphertext):
                fence[i][j] = ciphertext[index]
                index += 1

    plaintext = ''
    row, col = 0, 0
    for _ in range(len(ciphertext)):
        if row == 0 or row == rails - 1:
            direction *= -1
        plaintext += fence[row][col]
        row += direction
        col += 1

    return plaintext


# Example usage
plaintext = "HELLO WORLD"
rails = 3

encrypted_text = rail_fence_encrypt(plaintext, rails)
print("Encrypted text:", encrypted_text)

decrypted_text = rail_fence_decrypt(encrypted_text, rails)
print("Decrypted text:", decrypted_text)