import sqlite3

# Connect to the database
conn = sqlite3.connect(r'c:\Users\sdb46\Desktop\Main Programe\login_data.db')
cursor = conn.cursor()

# Query the data from the user_entries table
cursor.execute('SELECT * FROM user_entries')
rows = cursor.fetchall()

# Print the saved data
for row in rows:
    print(row)

# Close the connection
conn.close()
