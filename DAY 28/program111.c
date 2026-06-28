#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_SEATS 20

struct Ticket {
    int seatNumber;
    char passengerName[50];
    char trainName[50];
    float price;
};

void displayMenu();
void viewAvailableSeats(int seats[]);
void bookTicket(int seats[]);
void cancelTicket(int seats[]);
void viewBookings();

int main() {
    int seats[TOTAL_SEATS] = {0};
    int choice;

    do {
        displayMenu();
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                viewAvailableSeats(seats);
                break;
            case 2:
                bookTicket(seats);
                break;
            case 3:
                cancelTicket(seats);
                break;
            case 4:
                viewBookings();
                break;
            case 5:
                printf("\nExiting system. Thank you!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    printf("\n==========================================");
    printf("\n         TICKET BOOKING SYSTEM           ");
    printf("\n==========================================");
    printf("\n1. View Available Seats");
    printf("\n2. Book a Ticket");
    printf("\n3. Cancel a Booking");
    printf("\n4. View All Bookings");
    printf("\n5. Exit");
    printf("\n==========================================");
}

void viewAvailableSeats(int seats[]) {
    printf("\n\n--- SEAT STATUS ---\n");
    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (seats[i] == 0) {
            printf("[ Seat %2d: AVAILABLE ]\n", i + 1);
        } else {
            printf("[ Seat %2d: BOOKED    ]\n", i + 1);
        }
    }
}

void bookTicket(int seats[]) {
    struct Ticket t;
    FILE *fp;
    int seatNum;

    printf("\n--- BOOK A TICKET ---\n");
    printf("Enter Passenger Name: ");
    scanf(" %[^\n]s", t.passengerName);
    
    printf("Enter Train/Movie Name: ");
    scanf(" %[^\n]s", t.trainName);

    printf("Enter Ticket Price: ");
    scanf("%f", &t.price);

    viewAvailableSeats(seats);
    printf("\nSelect a seat number (1 to %d): ", TOTAL_SEATS);
    scanf("%d", &seatNum);

    if (seatNum < 1 || seatNum > TOTAL_SEATS) {
        printf("Invalid seat number. Booking failed!\n");
        return;
    }

    if (seats[seatNum - 1] == 1) {
        printf("Seat %d is already booked! Please choose another.\n", seatNum);
    } else {
        seats[seatNum - 1] = 1;
        t.seatNumber = seatNum;

        fp = fopen("bookings.txt", "a");
        if (fp != NULL) {
            fprintf(fp, "%d %s %s %.2f\n", t.seatNumber, t.passengerName, t.trainName, t.price);
            fclose(fp);
            printf("\nTicket successfully booked! Seat No: %d\n", seatNum);
        } else {
            printf("Error opening file to save booking.\n");
        }
    }
}

void cancelTicket(int seats[]) {
    FILE *fp, *tempFp;
    struct Ticket t;
    int seatToCancel, found = 0;

    printf("\n--- CANCEL A TICKET ---\n");
    printf("Enter seat number to cancel: ");
    scanf("%d", &seatToCancel);

    if (seatToCancel < 1 || seatToCancel > TOTAL_SEATS) {
        printf("Invalid seat number.\n");
        return;
    }

    if (seats[seatToCancel - 1] == 0) {
        printf("Seat %d is not currently booked.\n", seatToCancel);
        return;
    }

    fp = fopen("bookings.txt", "r");
    tempFp = fopen("temp.txt", "w");

    if (fp == NULL || tempFp == NULL) {
        printf("Error opening files!\n");
        return;
    }

    while (fscanf(fp, "%d %s %s %f", &t.seatNumber, t.passengerName, t.trainName, &t.price) != EOF) {
        if (t.seatNumber == seatToCancel) {
            found = 1;
            seats[seatToCancel - 1] = 0; 
        } else {
            fprintf(tempFp, "%d %s %s %.2f\n", t.seatNumber, t.passengerName, t.trainName, t.price);
        }
    }

    fclose(fp);
    fclose(tempFp);

    remove("bookings.txt");
    rename("temp.txt", "bookings.txt");

    if (found) {
        printf("Seat %d has been successfully canceled.\n", seatToCancel);
    } else {
        printf("No booking found for Seat %d in the database.\n", seatToCancel);
    }
}

void viewBookings() {
    FILE *fp;
    struct Ticket t;
    int count = 0;

    printf("\n--- ALL BOOKINGS ---\n");
    fp = fopen("bookings.txt", "r");

    if (fp == NULL) {
        printf("No bookings found or file does not exist.\n");
        return;
    }

    printf("%-10s %-20s %-20s %-10s\n", "Seat", "Passenger", "Trip/Movie", "Price");
    printf("-------------------------------------------------------------\n");
    
    while (fscanf(fp, "%d %s %s %f", &t.seatNumber, t.passengerName, t.trainName, &t.price) != EOF) {
        printf("%-10d %-20s %-20s %-10.2f\n", t.seatNumber, t.passengerName, t.trainName, t.price);
        count++;
    }

    fclose(fp);
    if (count == 0) {
        printf("No active reservations.\n");
    }
}
