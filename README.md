Ticket Queue Management System

This project implements a simple queue-based ticket management system using C. It allows users to add people to a queue, remove them in order, search for a person, display the total tickets sold, and view the current queue.

Features

Add Person to Queue: Users can enter their name and the number of tickets they want to buy.

Remove First Person: The first person in the queue gets their tickets and is removed.

Search for a Person: Check if a specific person is in the queue.

Display Total Tickets Sold: Track the number of tickets sold.

Show Queue: Display all people currently in the queue.

How to Run

# Clone the repository
git clone https://github.com/yourusername/ticket-queue.git

# Navigate to the project directory
cd ticket-queue

# Compile the program
gcc ticket_queue.c -o ticket_queue

# Run the program
./ticket_queue

Example Usage

Menaxhimi i Radhes se Biletave:
1. Shto person ne radhe
2. Hiq personin e pare
3. Kerko nje person
4. Shfaq biletat e shitura
5. Shfaq radhen
6. Dil

Code Structure

ticket_queue.c: Main program implementing the queue operations.

Functions Used:

shto(char emer[], int bileta): Adds a person to the queue.

hiq(): Removes the first person from the queue.

kerko(char emer[]): Searches for a person in the queue.

biletaShitura(): Displays total tickets sold.

shfaqRadhen(): Displays the queue.
