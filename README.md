📌 Overview
The Arbitrary Precision Calculator (APC) is a C project that performs arithmetic operations on very large numbers using linked lists instead of standard data types.This allows handling numbers beyond the limit of built-in types like int or long.

⚙️ Features
➕ Addition
➖ Subtraction
✖️ Multiplication
➗ Division
🔍 Comparison of numbers
🧱 Dynamic number creation
🧹 Memory management
🚫 Leading zero removal

🧠 Concepts Used
Doubly Linked List (DLL) → Stores large numbers digit by digit
Singly Linked List (SLL) → Stores results like quotient
Manual arithmetic operations (digit-by-digit processing)

📂 Project Structure
.
├── a.c                         # Main driver file
├── addition.c                  # Addition logic
├── subtraction.c               # Subtraction logic
├── multiplication.c            # Multiplication logic
├── division.c                  # Division logic
├── compare_list.c              # Compare two numbers
├── create_list.c               # Convert string to list
├── delete_list.c               # Free memory
├── insert_at_first_dll.c       # Insert at beginning (DLL)
├── insert_at_last_dll.c        # Insert at end (DLL)
├── insert_at_first_sll.c       # Insert at beginning (SLL)
├── print_list_dll.c            # Print DLL number
├── print_list_sll.c            # Print SLL number
├── remove_zeros.c              # Remove leading zeros
├── APC.h                       # Header file

🔧 How It Works

🔢 Number Representation
Each digit is stored in a node:
Example:
1234 → 1 ⇄ 2 ⇄ 3 ⇄ 4

➕ Addition
Starts from tail (least significant digit)
Adds digits with carry
Stores result using insert_at_first_dll

➖ Subtraction
Performs digit-by-digit subtraction
Handles borrow
Removes leading zeros

✖️ Multiplication
Uses repeated addition or digit multiplication
Stores intermediate results

➗ Division
Uses repeated subtraction
Counts how many times divisor fits
Stores quotient in SLL

🔍 Comparison
First compares length
If equal → compares digit by digit

🛠️ Compilation & Execution
gcc *.c -o apc
./apc

📌 Function Modules
Core Operations
addition()
subtraction()
multiplication()
division()

List Utilities
create_list()
delete_list()
remove_zeros()

Insert Functions
insert_at_first_dll()
insert_at_last_dll()
insert_at_first_sll()

Display Functions
print_list_dll()
print_list_sll()

Helper
compare_list()
