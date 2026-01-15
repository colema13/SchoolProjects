#include "AccountManager.hpp"
#include <iostream>
using namespace std;

int main() {
    // Test 1: Create AccountManager
    cout << "=== Test 1: Creating AccountManager ===" << endl;
    AccountManager manager;
    cout << "Initial account count: " << manager.getNumAccounts() << endl;
    
    // Test 2: Add accounts
    cout << "\n=== Test 2: Adding Accounts ===" << endl;
    manager.addAccount("alice");
    manager.addAccount("bob");
    manager.addAccount("charlie");
    cout << "Account count after adding 3: " << manager.getNumAccounts() << endl;
    
    // Test 3: Try adding duplicate account
    cout << "\n=== Test 3: Adding Duplicate Account ===" << endl;
    manager.addAccount("alice"); // Should fail
    
    // Test 4: Display accounts
    cout << "\n=== Test 4: Displaying Accounts ===" << endl;
    manager.displayAccount("alice");
    manager.displayAccount("bob");
    
    // Test 5: Make deposits
    cout << "\n=== Test 5: Making Deposits ===" << endl;
    manager.makeDeposit("alice", 100.0);
    manager.makeDeposit("bob", 50.0);
    manager.displayAccount("alice");
    manager.displayAccount("bob");
    
    // Test 6: Make withdrawals
    cout << "\n=== Test 6: Making Withdrawals ===" << endl;
    manager.makeWithdrawal("alice", 30.0);
    manager.makeWithdrawal("bob", 60.0); // Should fail (insufficient funds)
    manager.displayAccount("alice");
    manager.displayAccount("bob");
    
    // Test 7: Add interest
    cout << "\n=== Test 7: Adding Interest ===" << endl;
    manager.addInterest();
    
    // Test 8: Write check
    cout << "\n=== Test 8: Writing Check ===" << endl;
    manager.writeCheck("alice", "bob", 20.0);
    manager.displayAccount("alice");
    manager.displayAccount("bob");
    
    // Test 9: Delete account
    cout << "\n=== Test 9: Deleting Account ===" << endl;
    manager.deleteAccount("charlie");
    cout << "Account count after delete: " << manager.getNumAccounts() << endl;
    
    // Test 10: Try operations on deleted account
    cout << "\n=== Test 10: Operations on Deleted Account ===" << endl;
    manager.displayAccount("charlie");
    manager.makeDeposit("charlie", 100.0);
    
    cout << "\n=== All Tests Complete ===" << endl;
    return 0;
}