// C Program to Read Name and Marks of 5 Students and Store Them in a File

#include <stdio.h>

struct Student {
    char name[50];
    int marks;
};

int main() {
    struct Student students[5];
    FILE *file = fopen("students.txt", "w");

    for (int i = 0; i < 5; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &students[i].marks);
        fprintf(file, "%s %d\n", students[i].name, students[i].marks);
    }

    fclose(file);
    printf("Data successfully saved to file.\n");
    return 0;
}

//c Program to Read Name and Marks of n Students and Store Them in a File (Appending if File Exists)

#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int marks;
};

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student *students = malloc(n * sizeof(struct Student));
    FILE *file = fopen("students.txt", "a");

    if (!file) {
        printf("Error opening file.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &students[i].marks);
        fprintf(file, "%s %d\n", students[i].name, students[i].marks);
    }

    fclose(file);
    free(students);
    printf("Data successfully appended to file.\n");
    return 0;
}

//c Program to Write an Array of Structures to a File Using fwrite() and Read It Back Using fread()

#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int marks;
};

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student *students = malloc(n * sizeof(struct Student));
    FILE *file = fopen("students.dat", "wb");

    for (int i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &students[i].marks);
    }

    fwrite(students, sizeof(struct Student), n, file);
    fclose(file);

    // Reading back the data
    file = fopen("students.dat", "rb");
    fread(students, sizeof(struct Student), n, file);
    fclose(file);

    printf("\nStudent Data from File:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Marks: %d\n", students[i].name, students[i].marks);
    }

    free(students);
    return 0;
    }

