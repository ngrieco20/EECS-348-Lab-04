#include <stdio.h>

float celsius_to_fahrenheit(float celsius) { // uses formula from rubric 
    return (9.0 / 5.0) * celsius + 32;
}

float fahrenheit_to_celsius(float fahrenheit) { // uses formula from rubric
    return (5.0 / 9.0) * (fahrenheit - 32);
}

float fahrenheit_to_kelvin(float fahrenheit) { 
    return (fahrenheit - 32) * 5.0 / 9.0 + 273.15; // uses formula from rubric
}

float kelvin_to_fahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32; // uses formula from rubric
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15; // uses formula from rubric
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15; // uses formula from rubric
}

void categorize_temperature(float celsius) {  // categorizes the temps based on celsius range 
    if (celsius < 0) {  // freezing requirements
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: BRRR... Wear warm clothes!\n");
    } else if (celsius >= 0 && celsius <= 10) { // cold requirements
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket!\n"); 
    } else if (celsius > 10 && celsius <= 25) { // comfortable requirements 
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: It's pretty comfortable outside.\n"); 
    } else if (celsius > 25 && celsius <= 35) { // hot requirements
        printf("Temperature category: Hot\n");
        printf("Weather advisory: It's decently hot outside. Stay hydrated!\n"); 
    } else { // extremely hot requirements
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: EXTREMELY HOT! Stay indoors and stay cool!\n"); 
    }
}

int validate_temperature(float temperature, int scale) { // error checking 
    if (scale == 3 && temperature < 0) {  // invalidates kelvin input 
        printf("Invalid temperature: Kelvin cannot be negative.\n"); 
        return 0;
    } else if (scale == 2 && temperature < -459.67) { // invalidates fahrenheit input
        printf("Invalid temperature: Fahrenheit cannot be below absolute zero (-459.67°F).\n"); 
        return 0;
    } else if (scale == 1 && temperature < -273.15) { // invalidates celsius input 
        printf("Invalid temperature: Celsius cannot be below absolute zero (-273.15°C).\n"); 
        return 0;
    }
    return 1;
}

int validate_conversion_choice(int from_choice, int to_choice) {
    if ((from_choice < 1 || from_choice > 3) || (to_choice < 1 || to_choice > 3)) {  // checks if choice is valid 
        printf("Invalid choice. Try again.\n");
        return 0;
    }
    if (from_choice == to_choice) { // prevents conversion choices being the same 
        printf("Cannot convert from the same scale. Try again.\n"); 
        return 0;
    }
    return 1;
}

int main() {
    float temperature;
    int from_temp_scale, to_temp_scale;
    int valid_input = 0; // checks for valid input

    // loops until valid input is provided for the temperature using a loop 
    while (!valid_input) {
        printf("Enter the temperature value: ");
        if (scanf("%f", &temperature) != 1) { // scans the float number / temp 
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n'); // clear the input 
        } else {
            valid_input = 1; // validates input and exits the loop
        }
    }

    valid_input = 0; // check for valid input 
 // loops until valid input is provided for the temperature using a loop 
    while (!valid_input) {
        printf("Choose the current temperature scale: (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        if (scanf("%d", &from_temp_scale) != 1 || !validate_temperature(temperature, from_temp_scale)) {
            printf("Invalid input. Please enter a valid choice (1, 2, or 3).\n");
            while (getchar() != '\n'); // Clear the input 
        } else {
            valid_input = 1; // validates input and exits the loop 
        }
    }

    valid_input = 0; // check for valid input 
     // loops until valid input is provided for the temperature using a loop 
    while (!valid_input) {
        printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        if (scanf("%d", &to_temp_scale) != 1 || !validate_conversion_choice(from_temp_scale, to_temp_scale)) {
            printf("Invalid input. Please enter a valid choice (1, 2, or 3).\n");
            while (getchar() != '\n'); // clear the input 
        } else {
            valid_input = 1; // validates input and exits the loop
        }
    }

    // conversion based on user input 
    float converted_temp;
    if (from_temp_scale == 1) { // from celsius
        if (to_temp_scale == 2) {
            converted_temp = celsius_to_fahrenheit(temperature); // converts from celsius to fahrenheit calling function
            printf("Converted temperature: %.2f°F\n", converted_temp);
        } else if (to_temp_scale == 3) {
            converted_temp = celsius_to_kelvin(temperature); // converts from celsius to kelvin calling function
            printf("Converted temperature: %.2fK\n", converted_temp);
        }
    } else if (from_temp_scale == 2) { // from fahrenheit
        if (to_temp_scale == 1) {
            converted_temp = fahrenheit_to_celsius(temperature); // converts from fahrenheit to celsius calling function
            printf("Converted temperature: %.2f°C\n", converted_temp);
        } else if (to_temp_scale == 3) {
            converted_temp = fahrenheit_to_kelvin(temperature); // converts from fahrenheit to kelvin calling function
            printf("Converted temperature: %.2fK\n", converted_temp);
        }
    } else if (from_temp_scale == 3) { // from kelvin
        if (to_temp_scale == 1) {
            converted_temp = kelvin_to_celsius(temperature);  // converts from kelvin to celsius calling function
            printf("Converted temperature: %.2f°C\n", converted_temp);
        } else if (to_temp_scale == 2) {
            converted_temp = kelvin_to_fahrenheit(temperature); // converts from kelvin to fahrenheit calling function
            printf("Converted temperature: %.2f°F\n", converted_temp);
        }
    }

    // categorize temperature using celsius
    if (to_temp_scale == 1) {
        categorize_temperature(converted_temp); // uses celsius to categorize temperature
    } else if (to_temp_scale == 2) {
        categorize_temperature(fahrenheit_to_celsius(converted_temp)); // converts fahrenheit to celsius for categorization
    } else {
        categorize_temperature(kelvin_to_celsius(converted_temp)); // converts kelvin to celsius for categorization
    }

    return 0;
}
