## Creator: AbdulHameed Ahmed
## Course:  CSCI 274 Computer Architecture
## Instructor: Professor Aftab Ahmad
## Final Project
## Prgroam: ahmed.asm -- The purpose of this program is to ask the user to enter some numbers and store them inside an array. 
## (I choose the array size to be 16 bytes which will allow the user to store 4 numbers for simplicity.) The initial
## input will be printed from array1 to the console. The second array will contain the numbers sorted in ascending order.
## That array will also be printed to the console. Finally the third array will print all the values in descending order.

.data
array1:  .space 16    # array1 is stored with 16 bytes of space.
array2:  .space 16    # array2 is stored with 16 bytes of space.
array3:  .space 16    # array3 is stored with 16 bytes of space.
newline: .asciiz "\n" # Use assembly directive asciiz to print a newline character.
msg1:    .asciiz "Hello and welcome to the ahmed.asm program!!! (c)."
msg2:    .asciiz "\nPlease enter four numbers:\n"
msg3:    .asciiz "\nPrinting initial array output:\n"
msg4:    .asciiz "\nNow printing Ascending array:\n"
msg5:    .asciiz "\nNow printing Descending array:\n"
msg6:    .asciiz "\nThank you and have a nice day!!!\n"


.text
main:  # Start of the program.

# Greets the user!    
Greeting:       
        la      $a0, msg1   # Load address of msg1 into $a0.
        li      $v0, 4      # Load 4 into $v0 to print a string.
        syscall
        
# Displays a message to ask the user to enter 4 numbers to store inside array1.
Input:          
        la      $a0, msg2   # Load address of msg2 into $a0.
        li      $v0, 4      # Load 4 into $v0 to print a string.
        syscall
        
        # Now requesting the user to enter four numbers!
        li      $v0, 5      # Load 5 into $v0 for user input at the console.
        syscall
        move    $s1, $v0    # The first number is stored inside $s1
        
        li      $v0, 5      # Load 5 into $v0 for user input at the console.
        syscall
        move    $s2, $v0    # The second number is stored inside $s2
        
        li      $v0, 5      # Load 5 into $v0 for user input at the console.
        syscall
        move    $s3, $v0    # The third number is stored inside $s3
        
        li      $v0, 5      # Load 5 into $v0 for user input at the console.
        syscall
        move    $s4, $v0    # The fourth number is stored inside $s4
        
        # Now storing the input in array1. $t0 will be used as an index to keep track of the position being stored.
       
        addi    $t0, $zero, 0       # Add zero to register $t0.
        
        sw      $s1, array1($t0)    # Store content of $s1 inside array1[0]
        addi    $t0, $t0, 4         # Add 4 to register $t0.
        
        sw      $s2, array1($t0)    # Store content of $s2 inside array1[1]
        addi    $t0, $t0, 4         # Add 4 to register $t0.
        
        sw      $s3, array1($t0)    # Store content of $s3 inside array1[2]
        addi    $t0, $t0, 4         # Add 4 to register $t0.
        
        sw      $s4, array1($t0)    # Store content of $s4 inside array1[3]
        
        la      $a0, msg3           # Load address of msg3 to $a0
        li      $v0, 4              # Load 4 into $v0 to print a string
        syscall
        
        # Clear $t0 to 0
        addi    $t0, $zero, 0
        
while:
        beq     $t0, 16, Sort       # Compare register $t0 to the number 16. This while loop will iterate 4 times.
                                    # Once completed it will branch to the Sort label.
        lw      $t5, array1($t0)    # Load word (array1[i]) into $t5.
        
        addi    $t0, $t0, 4         # Add 4 to register $t0 to move to the next position in the array.
        
        # Print current number.
        li      $v0, 1              # Load 1 into register $v0 to print an integer. 
        move    $a0, $t5            # Copy the content inside register $t5 to register $a0.
        syscall
        
        # Print a newline.
        li      $v0, 4              # Load 4 into $v0 to print a string.
        la      $a0, newline        # Load the address of newline into $a0.
        syscall
        
        j while

# This sort segment extracts the numbers stored inside array1 and stores them inside registers $t1, $t2, $t3, $t4 respectively.
Sort:
        addi    $t0, $zero, 0       # Adds 0 and stores it inside $t0.
        
        lw      $t1, array1($t0)    # Load a word to register $t1.
        addi    $t0, $t0, 4         # Add 4 to register $t0.
        
        lw      $t2, array1($t0)    # Load a word to register $t2.
        addi    $t0, $t0, 4         # Add 4 to register $t0.
        
        lw      $t3, array1($t0)    # Load a word to register $t3.
        addi    $t0, $t0, 4         # Add 4 to register $t0.
        
        lw      $t4, array1($t0)    # Load a word to register $t4.
        
        addi    $t0, $zero, 0       # Clear register $t0 back to zero.
        
        j Swap                      # Jump to Swap segment.

# The Swap segments below basically compares two registers at a time until all registers are sorted in ascending order.
Swap:
        bgt     $t1, $t2, Swap1     # $t1 > $t2, if so then branch to Swap1.
        bgt     $t2, $t3, Swap2     # $t2 > $t3, if so then branch to Swap2.
        bgt     $t3, $t4, Swap3     # $t3 > $t4, if so then branch to Swap3.
        
        j Ascend                    # Jump to Ascend label.
        
Swap1:
        move    $t7, $t2            # $t7 = $t2
        move    $t2, $t1            # $t2 = $t1
        move    $t1, $t7            # $t1 = $t7
        
        j Swap                      # Jump to Swap

Swap2:  
        move    $t7, $t3            # $t7 = $t3
        move    $t3, $t2            # $t3 = $t2
        move    $t2, $t7            # $t2 = $t7
        
        j Swap                      # Jump to Swap

Swap3:  
        move    $t7, $t4            # $t7 = $t4
        move    $t4, $t3            # $t4 = $t3
        move    $t3, $t7            # $t3 = $t7
        
        j Swap                      # Jump to Swap
        
# Once the sort is complete the numbers are stored inside array2 and await the process to be printed.
Ascend:
        addi    $t0, $zero, 0       # Clear register $t0 to zero.
        
        sw      $t1, array2($t0)    # Store content of $t1 in array2[0]
        addi    $t0, $t0, 4         # Add 4 to register $t0 to move to next position in array2.
        
        sw      $t2, array2($t0)    # Store content of $t2 in array2[1]
        addi    $t0, $t0, 4         # Add 4 to register $t0 to move to next position in array2.
        
        sw      $t3, array2($t0)    # Store content of $t3 in array2[2]
        addi    $t0, $t0, 4         # Add 4 to register $t0 to move to next position in array2.
        
        sw      $t4, array2($t0)    # Store content of $t4 in array2[3]
        
        # Print Message 4 
        la      $a0, msg4           # Load address of msg4 inside $a0
        li      $v0, 4              # Load 4 into $v0 to print a string.
        syscall
        
        addi    $t0, $zero, 0       # Clear $t0 back to zero.

# This second while loop prints array2 which contains the values in ascending order.
while2:
        beq     $t0, 16, Sort2      # Compare register $t0 to the number 16. This while2 loop will iterate 4 times.
                                    # Once completed it will branch to the Sort2 label.
        lw      $t6, array2($t0)    # Load word (array2[i]) into $t6.
        
        addi    $t0, $t0, 4         # Add 4 to register $t0.
        
        # Print current number.
        li      $v0, 1              # Load 1 into register $v0 to print a integer.
        move    $a0, $t6            # Copy the content inside register $t6 to register $a0.
        syscall
        
        # Print a newline.
        li      $v0, 4              # Load 4 inside $v0 to print a string.
        la      $a0, newline        # Load address of newline into $a0.
        syscall
        
        j while2                    # Jump to while2

# Sort2 segment stores the values of array2 backwards inside array3
Sort2:
        addi    $t0, $zero, 0       # Clear $t0 to zero.
        
        sw      $t4, array3($t0)    # Store content of $t4 in array3[0]
        addi    $t0, $t0, 4         # Add 4 to register $t0.
        
        sw      $t3, array3($t0)    # Store content of $t3 in array3[1]
        addi    $t0, $t0, 4         # Add 4 to register $t0.
        
        sw      $t2, array3($t0)    # Store content of $t2 in array3[2]
        addi    $t0, $t0, 4         # Add 4 to register $t0.
        
        sw      $t1, array3($t0)    # Store content of $t1 in array3[3]
        
        la      $a0, msg5           # Load address of msg5 inside $a0.
        li      $v0, 4              # Load 4 inside $v0 to print a string.
        syscall
        
        addi    $t0, $zero, 0       # Clear $t0 to zero.

# The third while loop prints array3 which has the values stored in descending order.  
while3:
        beq     $t0, 16, Exit       # Compare register $t0 to the number 16. The while3 loop will iterate 4 times.
                                    # Once completed it will branch to the Exit label.
        lw      $t6, array3($t0)    # Load word (array3[i]) inside $t6.
        
        addi    $t0, $t0, 4         # Add 4 to register to $t0.
        
        # Print current number.
        li      $v0, 1              # Load 1 to register $v0. To print an integer.
        move    $a0, $t6            # Copy content of $t6 into $a0.
        syscall
        
        # Print a newline.
        li      $v0, 4              # Load 4 to $v0. To print a string.
        la      $a0, newline        # Load address of newline into $a0.
        syscall
        
        j while3                    # Jump to while3

# Prints a thank you message and exits the program.
Exit:
        la      $a0, msg6           # Load address of msg6 to $a0.
        li      $v0, 4              # Load 4 to $v0. To print a string.
        syscall
        
        li      $v0, 10             # Load 10 to $v0. To exit the program.
        syscall
