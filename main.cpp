/**
 * Brief: Interactive console controller for the Bank of Modesto account management system.
 * Author: Henoc Kabeya
 * Date: October 5, 2026
 *
 * Purpose:
 *   - Encapsulate individual account state within a BankAccount class.
 *   - Manage a dynamic list of BankAccount objects using std::vector.
 *   - Provide an interactive, menu-driven CLI for account creation,
 *     deposits, withdrawals, and account record retrieval.
 */


#include <iostream>
#include <vector>
#include <limits>
#include "BankAccount.h"
using namespace std;

/**
 * @brief Main entry point of the banking application.
 *        Executes a loop-driven interactive CLI allowing users to create accounts,
 *        deposit/withdraw money, and display individual account records.
 * @return Exit status integer (0 for successful termination).
 */
int main() {
    // Dynamic array to store multiple customer accounts
    vector<BankAccount> accounts;
    int choice = 0;
    do {
        // Display Menu Options
        cout << "\n=========================================\n";
        cout << "               Bank of Modesto             \n";
        cout << "===========================================\n";
        cout << "1. Create a New Account" << endl;
        cout << "2. Deposit Funds" << endl;
        cout << "3. Withdraw Funds" << endl;
        cout << "4. Display Account Details " << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice(1-5): ";

        // Menu choice validation
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number between 1 and 3." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (choice) {
            // Case 1 for accounts creation
            case 1: {
                accounts.push_back(BankAccount::createAccountFromInput());
                cout << "Your account has been successfully created." << endl;
                break;
            }
            // Case2 for funds deposit
            case 2: {
                string searchAccNum;
                cout << "Enter account number: ";
                cin >> searchAccNum;

                bool found = false;
                for (auto & account : accounts) {
                    if (account.getAccountNumber() == searchAccNum) {
                        found = true;
                        double amount;
                        cout << "Enter amount to deposit: ";
                        cin >> amount;
                        account += amount;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account number not found. Please try again." << endl;
                }
                break;
            }
            // Case 3 for the funds withdrawal
            case 3: {
                string searchAccNum;
                cout << "Enter account number: ";
                cin >> searchAccNum;

                bool found = false;

                for (auto & account : accounts) {
                    if (account.getAccountNumber() == searchAccNum) {
                        found = true;
                        double amount;
                        cout << "Enter amount to withdraw: ";
                        cin >> amount;
                       account -= amount;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account number not found. Please try again." << endl;
                }
                break;
            }
            // Case 4 for showing the account's details
            case 4: {
                string searchAccNum;
                cout << "Enter account number: ";
                cin >> searchAccNum;

                bool found = false;
                for (const auto & account : accounts) {
                    if (account.getAccountNumber() == searchAccNum) {
                        found = true;
                        BankAccount::printAccount(account);
                        break;
                    }
                }

                if (!found) {
                    cout << "Account not found." << endl;
                }
                break;
            }
            // Exit the program
            case 5:
                cout << "Thank you for choosing Bank of Modesto." << endl;
                break;
            default:
            cout << "Invalid input. Please enter a number between 1 and 5." << endl;
            break;
        }
        } while (choice != 5);
            return 0;
}



