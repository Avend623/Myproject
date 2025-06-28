import sqlite3

# Connect to the database
conn = sqlite3.connect(r'c:\Users\sdb46\Desktop\Main Programe\login_data.db')
cursor = conn.cursor()

# Create a new table to save user entries if it doesn't exist
cursor.execute('''
CREATE TABLE IF NOT EXISTS user_entries (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    user_data TEXT
)
''')

# Reset the user_entries table
cursor.execute('DELETE FROM user_entries')

# Query the data
cursor.execute('SELECT * FROM login_logs')
rows = cursor.fetchall()

# Save the data into the user_entries table
for row in rows:
    cursor.execute('INSERT INTO user_entries (user_data) VALUES (?)', (str(row),))

# Commit the changes to save the data permanently
conn.commit()

# Print the data
for row in rows:
    print(row)

# Close the connection
conn.close()