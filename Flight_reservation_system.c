// Project Name: Flight Reservation System
// Project Author: Rudraksh

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Flight
{
    char flight_num[10]; // Declaring a structure for storing the info related to flight!
    char destination[40];
    int available_seats;
};

void View_Available_flight(FILE *file_ptr);
void Book_a_flight(FILE *file_ptr);
void View_current_booking(FILE *file_ptr);
void Cancel_Reservation(FILE *file_ptr);

int main()
{
    int choice;
    FILE *file_ptr = fopen("Flights.txt", "r+");

    if (file_ptr == NULL)
    {
        file_ptr = fopen("Flights.txt", "w+");
        if (file_ptr == NULL)
        {
            printf("File does not exist, and it can't be created!\n");
            exit(1);
        }
        struct Flight initial_flights[] = {
            {"LA01", "Los Angeles", 54},
            {"SK02", "Sri Lanka", 52},
            {"NK03", "North Korea", 69}, // Writing some random data into the file
            {"NY04", "New York", 25},
            {"UK05", "United Kingdom", 20},
            {"IN98", "New Delhi", 15}};

        ftruncate(fileno(file_ptr), 0); // Writing initial data and ensuring that there is no residual data left in the file.
        fwrite(initial_flights, sizeof(struct Flight), sizeof(initial_flights) / sizeof(struct Flight), file_ptr);
        fflush(file_ptr); // Ensuring that data is properly added in the file!
        fclose(file_ptr);
        file_ptr = fopen("Flights.txt", "r+");
    }

    do
    {
        printf("Flight-Reservation-System");
        printf("\n___________________________\n");

        printf("Choose an option:\n");
        printf("\n1. View Available Seats");
        printf("\n2. View all Current Bookings");
        printf("\n3. Book a Flight");
        printf("\n4. Cancel the Reservation");
        printf("\n5. Exit");

        printf("\nInput the Choice(1-5):\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            View_Available_flight(file_ptr);
            break;
        case 2: // A menu-based user-friendly interface using switch case
            View_current_booking(file_ptr);
            break;
        case 3:
            Book_a_flight(file_ptr);
            break;
        case 4:
            Cancel_Reservation(file_ptr);
            break;
        default:
            printf("Thank you for using the Flight-Reservation-System!\n");
            break;
        }
    } while (choice != 5);

    fclose(file_ptr);
    return 0;
}

// Function for Viewing all the available flights!

void View_Available_flight(FILE *file_ptr)
{
    struct Flight flight;

    printf("Available Flights:\n");
    printf("Flight Number\tDestination\tAvailable seats\n");

    fseek(file_ptr, 0, SEEK_SET); // Reseting the file pointer at the beggining of the file

    while (fread(&flight, sizeof(struct Flight), 1, file_ptr) == 1)
    {
        if (strlen(flight.flight_num) > 0) // Ensuring that valid data gets print
        {
            printf("%s\t\t%s\t\t%d\n", flight.flight_num, flight.destination, flight.available_seats);
        }
    }

    fseek(file_ptr, 0, SEEK_SET);
    printf("\n");
}

// Function for viewing all the current booking!

void View_current_booking(FILE *file_ptr)
{
    struct Flight flight;

    printf("Current Flights:\n");
    printf("Flight number\tDestination\tBooked Seats\n");

    fseek(file_ptr, 0, SEEK_SET); // Again Reseting the file pointer to the beggining of the file!

    while (fread(&flight, sizeof(struct Flight), 1, file_ptr) == 1)
    {
        if (strlen(flight.flight_num) > 0)
        {
            // Booked seats = maximum capacity(80) - available seats!

            int booked_seats = 80 - flight.available_seats;

            printf("%-12s %-20s %-15d\n", flight.flight_num, flight.destination, booked_seats);
        }
    }
}

// Function for Booking a flight

void Book_a_flight(FILE *file_ptr)
{
    char flight_number[10];
    struct Flight flight;
    int found = 0;

    printf("Enter the Flight Number for booking the seat:\n");
    scanf("%s", flight_number);

    fseek(file_ptr, 0, SEEK_SET);

    while (fread(&flight, sizeof(struct Flight), 1, file_ptr) == 1)
    {
        if (strcmp(flight.flight_num, flight_number) == 0) // Comparing two strings!
        {
            if (flight.available_seats > 0)
            {
                printf("Booking Successful for Flight Number %s to destination %s\n", flight.flight_num, flight.destination);
                flight.available_seats--;
                found = 1;                                         // If the seat is booked then decrementing the available seats with a count of -1
                fseek(file_ptr, -sizeof(struct Flight), SEEK_CUR); // reseting the file pointer
                fwrite(&flight, sizeof(struct Flight), 1, file_ptr);
                fflush(file_ptr);
                break;
            }
            else
            {
                printf("Sorry, The Flight %s you are looking for is fully booked!\n", flight.flight_num);
                break;
            }
        }
    }
    if (!found)
    {
        printf("The Flight %s your are looking for doesnot exist!\n", flight_number);
    }
}

// Function for Cancelling the Reservation!

void Cancel_Reservation(FILE *file_ptr)
{
    char flight_number[10];
    struct Flight flight;
    int found = 0;

    printf("Enter the Flight Number for Cancelling the booking:\n");
    scanf("%s", flight_number);

    fseek(file_ptr, 0, SEEK_SET); // reseting the file pointer to beggining of the file!

    while (fread(&flight, sizeof(struct Flight), 1, file_ptr) == 1)
    {
        if (strcmp(flight.flight_num, flight_number) == 0) // Comparing two strings!
        {
            printf("Cancellation Successful for Flight Number %s to destination %s\n", flight.flight_num, flight.destination);
            flight.available_seats++;
            found = 1;
            fseek(file_ptr, -sizeof(struct Flight), SEEK_CUR);
            fwrite(&flight, sizeof(struct Flight), 1, file_ptr);
            fflush(file_ptr);
            break;
        }
    }
    if (!found)
    {
        printf("The Flight %s your are looking for doesnot exist!\n", flight_number);
    }
}
