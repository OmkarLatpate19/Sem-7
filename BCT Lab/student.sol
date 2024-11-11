// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StudentManagement {
    // Structure to represent a student
    struct Student {
        uint256 id;
        string name;
        uint8 age;
        string course;
    }

    // Array to store the list of students
    Student[] public students;

    // Mapping to quickly access a student by their ID
    mapping(uint256 => uint256) private studentIndexById;

    // Event to notify when a new student is added
    event StudentAdded(uint256 id, string name, uint8 age, string course);

    // Function to add a new student to the array
    function addStudent(uint256 _id, string memory _name, uint8 _age, string memory _course) public {
        require(studentIndexById[_id] == 0, "Student ID already exists.");

        Student memory newStudent = Student({
            id: _id,
            name: _name,
            age: _age,
            course: _course
        });

        students.push(newStudent);
        studentIndexById[_id] = students.length; // Save the student's position in the array

        emit StudentAdded(_id, _name, _age, _course);
    }

    // Function to get student data by ID
    function getStudent(uint256 _id) public view returns (string memory name, uint8 age, string memory course) {
        require(studentIndexById[_id] != 0, "Student ID does not exist.");

        uint256 index = studentIndexById[_id] - 1;
        Student storage student = students[index];

        return (student.name, student.age, student.course);
    }

    // Receive function to handle plain Ether transfers
    receive() external payable {
        revert("Direct Ether transfers are not allowed.");
    }

    // Fallback function to handle unknown function calls or Ether sent with data
    fallback() external payable {
        revert("Fallback function called. No direct payments allowed.");
    }

    // Function to get the total number of students
    function getTotalStudents() public view returns (uint256) {
        return students.length;
    }
}
