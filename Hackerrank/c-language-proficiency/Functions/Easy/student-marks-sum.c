

//Complete the following function.

int marks_summation(int* marks, int number_of_students, char gender) {
    int sum = 0;
    int p;
    if (gender == 'g') {
        p = 1;
    }
    else {
        p = 0;
    }

    while (p < number_of_students) {
        sum += *(marks+p);
        p+=2;
    }
    return sum;
}

