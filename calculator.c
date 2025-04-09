#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int is_hex(const char *str) {
    return (strlen(str) > 2 && str[0] == '0' && (str[1] == 'x' || str[1] == 'X'));
}

int parse_number(const char *str) {
    if (is_hex(str)) {
        return (int)strtol(str, NULL, 16);
    } else {
        return atoi(str);
    }
}

void print_result(int result, const char *output_format) {
    if (strcmp(output_format, "hex") == 0) {
        printf("Result (Hex): 0x%X\n", result);
    } else {
        printf("Result (Decimal): %d\n", result);
    }
}

int main() {
    char num1_str[20], num2_str[20], operator;
    char output_format[10];

    printf("Enter first number (e.g., 10 or 0xA): ");
    scanf("%s", num1_str);

    printf("Enter operator (+, -, *, /, ^): ");
    scanf(" %c", &operator);

    printf("Enter second number (e.g., 5 or 0x5): ");
    scanf("%s", num2_str);

    printf("Output format (dec/hex): ");
    scanf("%s", output_format);

    int a = parse_number(num1_str);
    int b = parse_number(num2_str);
    int result;

    switch (operator) {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '/':
            if (b == 0) {
                printf("Error: Division by zero\n");
                return 1;
            }
            result = a / b;
            break;
        case '^': result = (int)pow(a, b); break;
        default:
            printf("Error: Invalid operator\n");
            return 1;
    }

    print_result(result, output_format);

    return 0;
}

