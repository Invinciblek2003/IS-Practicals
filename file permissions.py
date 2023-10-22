

'''

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

'''
import os
import stat
import pwd
import grp

def print_file_permissions(file_stat):
    print("File Permissions:")
    print(f"User: {'Read' if file_stat.st_mode & stat.S_IRUSR else '-'}")
    print(f"     {'Write' if file_stat.st_mode & stat.S_IWUSR else '-'}")
    print(f"     {'Execute' if file_stat.st_mode & stat.S_IXUSR else '-'}")
    print(f"Group: {'Read' if file_stat.st_mode & stat.S_IRGRP else '-'}")
    print(f"     {'Write' if file_stat.st_mode & stat.S_IWGRP else '-'}")
    print(f"     {'Execute' if file_stat.st_mode & stat.S_IXGRP else '-'}")
    print(f"Other: {'Read' if file_stat.st_mode & stat.S_IROTH else '-'}")
    print(f"     {'Write' if file_stat.st_mode & stat.S_IWOTH else '-'}")
    print(f"     {'Execute' if file_stat.st_mode & stat.S_IXOTH else '-'}")
    print()

def print_user_info(file_stat):
    owner = pwd.getpwuid(file_stat.st_uid).pw_name
    group = grp.getgrgid(file_stat.st_gid).gr_name
    print(f"Owner: {owner}")
    print(f"Group: {group}")
    print()

def check_file_existence(filename):
    if os.path.exists(filename):
        print(f"File {filename} exists.")
    else:
        print(f"File {filename} does not exist.")
    print()

def check_file_read_permission(filename):
    if os.access(filename, os.R_OK):
        print(f"File {filename} is readable.")
    else:
        print(f"File {filename} is not readable.")
    print()

def check_file_write_permission(filename):
    if os.access(filename, os.W_OK):
        print(f"File {filename} is writable.")
    else:
        print(f"File {filename} is not writable.")
    print()

def check_file_execute_permission(filename):
    if os.access(filename, os.X_OK):
        print(f"File {filename} is executable.")
    else:
        print(f"File {filename} is not executable.")
    print()

def main():
    filename = input("Enter the filename: ")

    try:
        file_stat = os.stat(filename)
        print_file_permissions(file_stat)
        print_user_info(file_stat)
        check_file_existence(filename)
        check_file_read_permission(filename)
        check_file_write_permission(filename)
        check_file_execute_permission(filename)
    except FileNotFoundError:
        print(f"File {filename} not found.")

if __name__ == "__main__":
    main()


