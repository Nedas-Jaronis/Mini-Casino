#include <iostream>
#include <ctime>
#include <random>
#include <string>

void deposit(double& bank, double& current_Money);
void withdraw(double& bank, double& current_Money);
void takeLoan(double& bank, double& current_Money, double& loan);
void repayLoan(double& bank, double& current_Money, double& loan);
void coinTossGame(double& current_Money);
void BlackJack(double& current_Money);
void diceRoll(double& current_Money);
void higherOrLower(double& current_Money);

// Function to get a random integer within a range
int getRandomInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to deposit money
void deposit(double& bank, double& current_Money) {
    double deposit_Amount;
    std::cout << "How much would you like to deposit? ";
    std::cin >> deposit_Amount;

    if (deposit_Amount <= 0) {
        std::cout << "Deposit amount must be positive.\n";
        return;
    }
    bank += deposit_Amount;
    current_Money += deposit_Amount;
    std::cout << "You have deposited $" << deposit_Amount << ". New bank balance: $" << bank << "\n";
}

// Function to withdraw money
void withdraw(double& bank, double& current_Money) {
    double withdraw_Amount;
    std::cout << "How much would you like to withdraw? ";
    std::cin >> withdraw_Amount;

    if (withdraw_Amount > current_Money || withdraw_Amount <= 0) {
        std::cout << "Invalid withdrawal amount.\n";
        return;
    }
    bank -= withdraw_Amount;
    current_Money -= withdraw_Amount;
    std::cout << "You have withdrawn $" << withdraw_Amount << ". New bank balance: $" << bank << "\n";
}

// Function to take a loan
void takeLoan(double& bank, double& current_Money, double& loan) {
    double loan_Amount;
    std::cout << "How much would you like to borrow? ";
    std::cin >> loan_Amount;

    if (loan_Amount <= 0) {
        std::cout << "Loan amount must be positive.\n";
        return;
    }

    loan += loan_Amount;
    bank += loan_Amount; // Loan amount added to bank's total
    current_Money += loan_Amount; // Available money increases
    std::cout << "You have taken a loan of $" << loan_Amount << ". Current loan balance: $" << loan << "\n";
}

// Function to repay a loan
void repayLoan(double& bank, double& current_Money, double& loan) {
    if (loan <= 0) {
        std::cout << "You have no loan to repay.\n";
        return;
    }

    double repayment_Amount;
    std::cout << "How much would you like to repay? ";
    std::cin >> repayment_Amount;

    if (repayment_Amount > current_Money || repayment_Amount <= 0) {
        std::cout << "Invalid repayment amount.\n";
        return;
    }

    loan -= repayment_Amount;
    current_Money -= repayment_Amount; // Deduct from current money
    bank -= repayment_Amount; // Deduct from bank's total as the money goes back
    std::cout << "You have repaid $" << repayment_Amount << ". Remaining loan balance: $" << loan << "\n";
}

// Function to simulate coin toss
void coinTossGame(double& current_Money) {
    std::cout << "Welcome to Coin Toss! Enter your bet: ";
    double bet;
    std::cin >> bet;

    if (bet > current_Money || bet <= 0) {
        std::cout << "Invalid bet amount.\n";
        return;
    }

    std::cout << "Choose heads (0) or tails (1): ";
    int choice;
    std::cin >> choice;

    int result = getRandomInt(0, 1);
    if (choice == result) {
        std::cout << "You won! Your bet is doubled.\n";
        current_Money += bet;
    } else {
        std::cout << "You lost! Better luck next time.\n";
        current_Money -= bet;
    }
    std::cout << "Current money: $" << current_Money << "\n";
}

// Function to play Blackjack
void BlackJack(double& current_Money) {
    std::cout << "Welcome to Blackjack! Enter your bet: ";
    double bet;
    std::cin >> bet;

    if (bet > current_Money || bet <= 0) {
        std::cout << "Invalid bet amount.\n";
        return;
    }

    int playerTotal = getRandomInt(15, 21);
    int dealerTotal = getRandomInt(17, 23);

    std::cout << "Your total: " << playerTotal << "\nDealer's total: " << dealerTotal << "\n";

    if (playerTotal > 21) {
        std::cout << "You busted! You lose the bet.\n";
        current_Money -= bet;
    } else if (dealerTotal > 21 || playerTotal > dealerTotal) {
        std::cout << "You win! You doubled your bet.\n";
        current_Money += bet;
    } else if (playerTotal < dealerTotal) {
        std::cout << "Dealer wins. You lose your bet.\n";
        current_Money -= bet;
    } else {
        std::cout << "It's a draw! You keep your bet.\n";
    }
    std::cout << "Current money: $" << current_Money << "\n";
}

// Function to roll dice game
void diceRoll(double& current_Money) {
    std::cout << "Welcome to Dice Roll! Enter your bet: ";
    double bet;
    std::cin >> bet;

    if (bet > current_Money || bet <= 0) {
        std::cout << "Invalid bet amount.\n";
        return;
    }

    int playerRoll = getRandomInt(1, 6);
    int computerRoll = getRandomInt(1, 6);

    std::cout << "You rolled a " << playerRoll << ". Computer rolled a " << computerRoll << ".\n";

    if (playerRoll > computerRoll) {
        std::cout << "You win! Your bet is doubled.\n";
        current_Money += bet;
    } else if (playerRoll < computerRoll) {
        std::cout << "You lose. Better luck next time!\n";
        current_Money -= bet;
    } else {
        std::cout << "It's a tie! You keep your bet.\n";
    }
    std::cout << "Current money: $" << current_Money << "\n";
}

// Function to play Higher or Lower
void higherOrLower(double& current_Money) {
    std::cout << "Welcome to Higher or Lower! Enter your bet: ";
    double bet;
    std::cin >> bet;

    if (bet > current_Money || bet <= 0) {
        std::cout << "Invalid bet amount.\n";
        return;
    }

    int firstCard = getRandomInt(1, 13);
    int secondCard = getRandomInt(1, 13);

    std::cout << "First card: " << firstCard << "\nWill the next card be higher (1) or lower (0)? ";
    int choice;
    std::cin >> choice;

    std::cout << "Second card: " << secondCard << "\n";

    if ((choice == 1 && secondCard > firstCard) || (choice == 0 && secondCard < firstCard)) {
        std::cout << "You guessed correctly! Your bet is doubled.\n";
        current_Money += bet;
    } else {
        std::cout << "You guessed wrong. You lose your bet.\n";
        current_Money -= bet;
    }
    std::cout << "Current money: $" << current_Money << "\n";
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    double bank = 10000.0;
    double userBank = 1000.0;
    double current_Money;
    double loan = 0.0;

    std::cout << "How much money do you currently have in hand? ";
    std::cin >> current_Money;
    std::cout << "In your bank, you currently have: $" << userBank << "\n";

    char mainMenuChoice = 'y';

    while (mainMenuChoice == 'y') {
        std::cout << "\nWould you like to access the bank (b) or the gamble menu (g)? (e to exit): ";
        char menuChoice;
        std::cin >> menuChoice;

        if (menuChoice == 'b') {
            char bankMenuChoice = 'y';
            while (bankMenuChoice == 'y') {
                std::cout << "\n--- Bank Menu ---\n";
                std::cout << "1. Deposit Money\n2. Withdraw Money\n3. Take/Repay Loan\n4. Exit Bank Menu\n";
                int choice;
                std::cin >> choice;

                switch (choice) {
                    case 1: deposit(userBank, current_Money); break;
                    case 2: withdraw(userBank, current_Money); break;
                    case 3: {
                        std::cout << "1. Take Loan\n2. Repay Loan\n";
                        int loanChoice;
                        std::cin >> loanChoice;
                        if (loanChoice == 1) {
                            takeLoan(userBank, current_Money, loan);
                        } else if (loanChoice == 2) {
                            repayLoan(userBank, current_Money, loan);
                        } else {
                            std::cout << "Invalid choice.\n";
                        }
                        break;
                    }
                    case 4: bankMenuChoice = 'n'; break; // Exit bank menu
                    default: std::cout << "Invalid choice. Please try again.\n"; break;
                }
            }
        } else if (menuChoice == 'g') {
            char gambleMenuChoice = 'y';
            while (gambleMenuChoice == 'y') {
                std::cout << "\n--- Gamble Menu ---\n";
                std::cout << "1. Coin Toss\n2. Blackjack\n3. Dice Roll\n4. Higher or Lower\n5. Exit Gamble Menu\n";
                int gameChoice;
                std::cin >> gameChoice;

                switch (gameChoice) {
                    case 1: coinTossGame(current_Money); break;
                    case 2: BlackJack(current_Money); break;
                    case 3: diceRoll(current_Money); break;
                    case 4: higherOrLower(current_Money); break;
                    case 5: gambleMenuChoice = 'n'; break; // Exit gamble menu
                    default: std::cout << "Invalid game choice. Please try again.\n"; break;
                }
            }
        } else if (menuChoice == 'e') {
            std::cout << "Goodbye! Come back Soon!\n";
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
