// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract SimpleBank {
    // Mapping to store the balance of each account
    mapping(address => uint256) private balances;

    // Event to notify that a deposit has been made
    event Deposit(address indexed account, uint256 amount);

    // Event to notify that a withdrawal has been made
    event Withdrawal(address indexed account, uint256 amount);

    // Function to deposit money into the bank account
    function deposit() public payable {
        require(msg.value > 0, "Deposit amount must be greater than zero");

        balances[msg.sender] += msg.value;

        emit Deposit(msg.sender, msg.value);
    }

    // Function to withdraw money from the bank account
    function withdraw(uint256 _amount) public {
        require(_amount > 0, "Withdrawal amount must be greater than zero");
        require(balances[msg.sender] >= _amount, "Insufficient balance");

        balances[msg.sender] -= _amount;

        payable(msg.sender).transfer(_amount);

        emit Withdrawal(msg.sender, _amount);
    }

    // Function to check the balance of the bank account
    function getBalance() public view returns (uint256) {
        return balances[msg.sender];
    }
}
