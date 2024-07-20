# Airlines Reservation System

## Overview

The Program is a C++ application designed to manage customer details, book flights, and generate tickets with a user-friendly interface.

## Features

- Add and store customer details.
- Book flights to various destinations.
- Generate and display tickets with flight details and costs.


## Getting Started

### Prerequisites

- C++ Compiler (e.g., GCC, Clang, MSVC)
- Makefile or a suitable build system (optional)


## File Handling

The application uses file handling to store and retrieve customer details and flight ticket information. This ensures data persistence across different sessions of the application.

### Storing Data

The `bill` function in the `Ticket` class uses an `ofstream` object to write customer and flight details to a file named `data.txt`. This includes customer ID, name, gender, destination, and flight cost, formatted for readability.


## Inheritance Overview

Inheritance is used to create a hierarchical structure for the classes, promoting code reuse and logical organization. The system comprises three main classes that utilize inheritance to extend functionalities:

### Classes

- **CustomerDetails**: Stores and manages customer-related information such as ID, name, age, gender, and address.
- **FlightRegisaction**: Manages flight booking, allowing users to select and book flights.
- **Ticket**: Inherits from both `CustomerDetails` and `FlightRegisaction` to combine customer and flight booking functionalities. This class is responsible for generating and displaying tickets.

### Inheritance Structure

The `Ticket` class inherits from both `CustomerDetails` and `FlightRegisaction`, enabling it to access and utilize the methods and attributes of both parent classes. This demonstrates the concept of multiple inheritance in C++, where a single class can inherit from more than one base class.


## Usage

Upon running the program, you will be presented with a main menu:

### Main Menu Options

1. **Add Customer Details**
   - Enter customer ID, name, age, gender, and address.

2. **Flight Registration**
   - Choose a flight destination and book a flight.

3. **Ticket and Charges**
   - Generate and display a ticket with flight details and cost.

4. **Exit**
   - Exit the application