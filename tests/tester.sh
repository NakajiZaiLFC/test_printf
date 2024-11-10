#!/bin/bash

# Color definitions
BLUE='\033[34m'
GREEN='\033[32m'
RED='\033[31m'
RESET='\033[0m'

# Function to check if command exists
check_command() {
    if ! command -v $1 &> /dev/null; then
        echo -e "${RED}Error: $1 is not installed${RESET}"
        exit 1
    fi
}

# Check for required commands
check_command valgrind
check_command make

# Print header
echo -e "${BLUE}=== ft_printf Tester with Valgrind ===${RESET}"

# Clean previous builds
echo -e "\n${BLUE}Cleaning previous builds...${RESET}"
make fclean

# Compile with debug symbols
echo -e "\n${BLUE}Compiling tester...${RESET}"
make

# Run tests with valgrind
echo -e "\n${BLUE}Running tests with Valgrind...${RESET}"
make test

# Check if valgrind found any errors
if grep -q "ERROR SUMMARY: 0 errors" valgrind-out.txt; then
    echo -e "${GREEN}No memory errors found!${RESET}"
else
    echo -e "${RED}Memory errors detected. Check valgrind-out.txt for details.${RESET}"
fi

# Display detailed memory information
echo -e "\n${BLUE}=== Memory Analysis ===${RESET}"
echo "For detailed information, check valgrind-out.txt"

# Cleanup
echo -e "\n${BLUE}Cleaning up...${RESET}"
make clean

echo -e "\n${BLUE}=== Test Complete ===${RESET}"
