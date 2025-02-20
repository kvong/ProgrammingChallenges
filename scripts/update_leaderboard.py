import os
import re

# Define the path to the problems directory
PROBLEMS_DIR = "leetcode/problems"

# Initialize counters
leaderboard = {}

# Regular expression to extract username from solution files
solution_pattern = re.compile(r'solution_([^.]+)\.\w+')

# Collect solution counts
for difficulty in ['Easy', 'Medium', 'Hard']:
    difficulty_path = os.path.join(PROBLEMS_DIR, difficulty)
    if not os.path.exists(difficulty_path):
        continue
    for problem_dir in os.listdir(difficulty_path):
        problem_path = os.path.join(difficulty_path, problem_dir)
        if os.path.isdir(problem_path):
            for file in os.listdir(problem_path):
                match = solution_pattern.match(file)
                if match:
                    username = match.group(1)
                    if username not in leaderboard:
                        leaderboard[username] = {'Easy': 0, 'Medium': 0, 'Hard': 0, 'Total': 0}
                    leaderboard[username][difficulty] += 1
                    leaderboard[username]['Total'] += 1

# Generate Markdown table
table = "| Participant | Easy | Medium | Hard | Total |\n"
table += "|-------------|------|--------|------|-------|\n"
for user, counts in sorted(leaderboard.items()):
    table += f"| {user.capitalize()} | {counts['Easy']} | {counts['Medium']} | {counts['Hard']} | {counts['Total']} |\n"

# Update README.md with markers
readme_path = "README.md"
if os.path.exists(readme_path):
    with open(readme_path, "r") as file:
        content = file.read()
    
    # Define markers
    start_marker = "<!-- Leaderboard Start -->"
    end_marker = "<!-- Leaderboard End -->"

    # Define the new leaderboard content
    new_leaderboard = f"{start_marker}\n## 🏆 Leaderboard\n\n{table}\n{end_marker}"

    # Use regex to replace the existing leaderboard section
    if re.search(f"{start_marker}.*?{end_marker}", content, re.DOTALL):
        content = re.sub(f"{start_marker}.*?{end_marker}", new_leaderboard, content, flags=re.DOTALL)
    else:
        # Append the leaderboard at the end if markers are not found
        content += f"\n{new_leaderboard}\n"

    with open(readme_path, "w") as file:
        file.write(content)
    
    print("✅ Leaderboard updated successfully!")
else:
    print("❌ README.md not found. Please ensure you're running the script from the repository's root directory.")
