Kisu's Finance Tracker - Project Explanation

🛠 How I Made It:
- I used the C programming language.
- The project is fully terminal-based.
- It saves and reads data from a local file (kisu_expenses.txt).
- The code is modular and broken into functions:
    1. addExpense() - to record a new expense.
    2. viewSummary() - to see all expenses and total.
    3. checkBudget() - to compare expenses against budget.
    4. generateReport() - to create a printable report (kisu_report.txt).

💡 Project Logic:
- Expenses are stored in a text file using fprintf().
- The file is read using fgets() and parsed using sscanf().
- Budget is checked by summing all expenses.
- Output is shown cleanly in the terminal.

🎯 Why It's Useful:
- Helps users manage spending.
- Simple to run even on low-end systems.
- Beginner-friendly C project with real-world utility.

🧑‍💻 Developer Signature:
- Coded with clean logic and personal style by Kisu.

