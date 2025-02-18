# CodeAlpha_LoginAndRegistrationSystem
This is a Login and Registration System implemented in C++. It allows users to register with a username and password, stores their credentials in a file (users.txt), and enables them to log in later. The system checks if a username already exists and ensures passwords meet basic security requirements.
Features: User Registration – Users can register with a unique username and a secure password. Login System – Users can log in using their registered credentials. File-Based Storage – Credentials are stored in users.txt. Input Validation – Ensures valid usernames and passwords.  User-Friendly Interface – Uses Windows Console Colors for better UI experience.
Technologies Used: C++ for logic implementation. File Handling (fstream) for storing user data. Windows.h for colored console output.
How to Run? Compile the Code using a C++ compiler (like MinGW g++ on Windows): g++ login_system.cpp -o login_system.exe  Run the Program: ./login_system.exe
Follow the on-screen menu: Select 1 to Register. Select 2 to Login. Select 3 to Exit.
