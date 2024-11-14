#!/bin/bash

# Factorial without recursion
factorial_non_recursive() {
    num=$1
    fact=1
    for ((i = 2; i <= num; i++)); do
        fact=$((fact * i))
    done
    echo "Factorial of $num (non-recursive) is $fact"
}

# Factorial with recursion
factorial_recursive() {
    if (( $1 <= 1 )); then
        echo 1
    else
        echo $(( $1 * $(factorial_recursive $(( $1 - 1 ))) ))
    fi
}

# Check if a number is a palindrome
check_palindrome_number() {
    read -p "Enter a number: " num
    original=$num
    reverse=0
    while [ $num -gt 0 ]; do
        remainder=$((num % 10))
        reverse=$((reverse * 10 + remainder))
        num=$((num / 10))
    done

    if [ $original -eq $reverse ]; then
        echo "$original is a palindrome."
    else
        echo "$original is not a palindrome."
    fi
}

# Check if a string is a palindrome
check_palindrome_string() {
    read -p "Enter a string: " str
    reversed_str=$(echo $str | rev)
    if [ "$str" == "$reversed_str" ]; then
        echo "$str is a palindrome."
    else
        echo "$str is not a palindrome."
    fi
}

# Bubble sort an array
bubble_sort() {
    read -p "Enter numbers separated by space: " -a array
    n=${#array[@]}
    for ((i = 0; i < n; i++)); do
        for ((j = 0; j < n - i - 1; j++)); do
            if (( array[j] > array[j + 1] )); then
                # Swap
                temp=${array[j]}
                array[j]=${array[j + 1]}
                array[j + 1]=$temp
            fi
        done
    done
    echo "Sorted array: ${array[@]}"
}

# Count occurrences of a substring
count_substring_occurrences() {
    read -p "Enter the main string: " main_string
    read -p "Enter the substring to count: " substring
    count=$(grep -o "$substring" <<< "$main_string" | wc -l)
    echo "Occurrences of '$substring': $count"
}

# Sum of digits
sum_of_digits() {
    read -p "Enter a number: " num
    sum=0
    while [ $num -gt 0 ]; do
        sum=$((sum + num % 10))
        num=$((num / 10))
    done
    echo "Sum of digits is $sum"
}

# Reverse digits of a number
reverse_digits() {
    read -p "Enter a number: " num
    reverse=0
    while [ $num -gt 0 ]; do
        remainder=$((num % 10))
        reverse=$((reverse * 10 + remainder))
        num=$((num / 10))
    done
    echo "Reversed number is $reverse"
}

# Check if a number is an Armstrong number
check_armstrong() {
    read -p "Enter a number: " num
    sum=0
    temp=$num
    while [ $temp -gt 0 ]; do
        digit=$((temp % 10))
        sum=$((sum + digit * digit * digit))
        temp=$((temp / 10))
    done
    if [ $sum -eq $num ]; then
        echo "$num is an Armstrong number."
    else
        echo "$num is not an Armstrong number."
    fi
}

# Main menu
while true; do
    echo -e "\nSelect an operation:"
    echo "1. Factorial (Non-Recursive)"
    echo "2. Factorial (Recursive)"
    echo "3. Check Palindrome (Number)"
    echo "4. Check Palindrome (String)"
    echo "5. Bubble Sort"
    echo "6. Count Occurrences of Substring"
    echo "7. Sum of Digits"
    echo "8. Reverse Digits"
    echo "9. Check Armstrong Number"
    echo "0. Exit"
    read -p "Enter your choice: " choice

    case $choice in
        1)
            read -p "Enter a number: " number
            factorial_non_recursive $number
            ;;
        2)
            read -p "Enter a number: " number
            echo "Factorial of $number (recursive) is $(factorial_recursive $number)"
            ;;
        3)
            check_palindrome_number
            ;;
        4)
            check_palindrome_string
            ;;
        5)
            bubble_sort
            ;;
        6)
            count_substring_occurrences
            ;;
        7)
            sum_of_digits
            ;;
        8)
            reverse_digits
            ;;
        9)
            check_armstrong
            ;;
        0)
            echo "Exiting..."
            break
            ;;
        *)
            echo "Invalid choice, please try again."
            ;;
    esac
done
