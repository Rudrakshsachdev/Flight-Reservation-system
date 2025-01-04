<h2>Flight-Reservation-System</h2>
<h3>Overview:</h3>
The Flight Reservation System is a comprehensive application designed to manage flight schedules, facilitate ticket bookings, enable cancellations, and provide a seamless experience for users. This system ensures efficient management of flight reservations, from browsing available flights to booking tickets or canceling reservations, and helps travelers interact with the system effortlessly.<br>

<h3>Objective:</h3>
The main objective of this system is to allow users to view available flights, book tickets, cancel reservations, and view current bookings. By storing flight data in files and providing simple menu-driven options, the system ensures smooth management of flight reservations and ticket bookings.

<h3>Functionalities:</h3> <br>
<b>1. View Available Flights: </b>
Description: Users can view a list of available flights along with essential information such as the flight number, destination, and the number of available seats.
Implementation: The flight information is stored in a file or an array. The system reads this data and displays the relevant flight details to the user.
<b>2. Book a Flight:</b>
Description: Users can book tickets for a specific flight by providing the flight number. The system checks the availability of seats and confirms the booking if seats are available.
Implementation: Upon receiving a valid flight number, the system searches for the corresponding flight, checks the availability of seats, and decreases the available seats by one. The booking is recorded in the file to ensure data persistence.
<b>3. Cancel Reservation:</b>
Description: Users can cancel their existing flight reservations by providing the flight number. The system verifies the reservation and updates the available seats accordingly.
Implementation: The system locates the booking based on the flight number, and if the flight has been booked, it increases the available seats by one. The updated information is then written back to the file.
<b>4. View Current Bookings:</b>
Description: Users can check their current bookings, including the flight number, destination, and the number of booked seats.
Implementation: The system reads the reservation data stored in the file and displays the current bookings to the user.

<h3>Features:</h3>
File Handling: The system uses file handling techniques to store and retrieve flight information, booking details, and reservation status. This ensures data persistence, meaning the system maintains flight and booking details even after the program terminates.

Menu-Driven Interface: The system features a simple, user-friendly, menu-driven interface, allowing users to select options from a menu to view flights, book a seat, cancel a reservation, or check current bookings.

Data Validation: The system incorporates basic input validation to handle invalid entries, such as incorrect flight numbers or attempts to book when no seats are available. Appropriate error messages are displayed to the user to guide them through the process.

Efficient Booking and Cancellation: The booking and cancellation processes are optimized to update the available seat count efficiently and ensure accurate records. When a booking is made or a cancellation occurs, the file is updated immediately, ensuring the data is always current.


