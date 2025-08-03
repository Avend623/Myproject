            }
            cout << "equal = " << x << endl;
        }
        if (symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
        {
            long num1, num2;
            cout << "Enter your first number: ";
            cin >> num1;
            cout << "Enter your second number: ";
            cin >> num2;
            switch (symbol)
            {
            case '+':
                cout << "Result: " << add(num1, num2) << ".." << endl;
                break;
            case '/':
                cout << "Result: " << divide(num1, num2) << ".." << endl;
                break;
            case '*':
                cout << "Result: " << multiply(num1, num2) << ".." << endl;
                break;
            case '-':
                cout << "Result: " << subtruct(num1, num2) << ".." << endl;
                break;
            default:
                if (symbol != 'f' && symbol != 'F')
                {
                    cout << "Invalid symbol. Please try again." << endl;

                    cout << "write any charecter to exit. . .";
                }
            }
        }
        else
        {
        }
        bool another;
        cout << "Do you want another calculate.. ";
        cin >> another;
        if(another)
        {
        }
        else
        {
            break;
        }