#!/bin/bash
# Create a problem directory based on ID and short name and name


username=$(git config user.name | tr '[:upper:]' '[:lower:]' | tr ' ' '-')

# Interactive prompt to add a new problem
echo "Add a New LeetCode Problem"
echo "-------------------------"
read -p "Enter Difficulty (Easy/Medium/Hard): " difficulty
read -p "Enter Problem ID: " id
read -p "Enter Shortened Problem Name (use hyphens instead of spaces): " short_name


dir_name=$(printf "%03d-%s" "$id" "$short_name")
  
# Create the problem directory
mkdir -p "problems/$difficulty/$dir_name"

# Create essential files
touch "problems/$difficulty/$dir_name/README.md"
touch "problems/$difficulty/$dir_name/solution_$username.py"

echo "Created directory: problems/$difficulty/$dir_name"
to ./problems/$difficulty/$dir_name
