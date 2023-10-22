'''

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

'''
import hashlib

def calculate_hash(data):
    # Create a new SHA-256 hash object
    sha256_hash = hashlib.sha256()

    # Update the hash object with the data
    sha256_hash.update(data.encode('utf-8'))

    # Calculate the digest (hash value) of the data
    hash_value = sha256_hash.hexdigest()

    # Return the hash value
    return hash_value

def verify_integrity(data, hash_value):
    # Calculate the hash of the data
    calculated_hash = calculate_hash(data)
    print("cal hash::",calculated_hash)
    # Compare the calculated hash with the provided hash value
    if calculated_hash == hash_value:
        print("Data integrity verified.")
    else:
        print("Data integrity compromised.")

# Example usage
data = "Hello, world!"
#hash_value = "2ef7bde608ce5404e97d5f042f95f89f1c232871"
hash_value = "315f5bdb76d078c43b8ac0064e4a0164612b1fce77c869345bfc94c75894edd3"

# Verify the integrity of the data
verify_integrity(data, hash_value)