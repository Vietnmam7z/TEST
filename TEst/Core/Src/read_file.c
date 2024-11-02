/*
 * read_file.c
 *
 *  Created on: Nov 1, 2024
 *      Author: Genki
 */

#include <stdio.h>
#include <read_file.h>
int number = 0;
char string[50];
void openFileAndReadData() {
    FILE *file;
    file = fopen("data.txt", "r"); // Mở file data.txt ở chế độ đọc
    if (file == NULL) {
        return;
    }
    // Thực hiện các thao tác với file
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        sscanf(buffer, "%d %s", &number, string);
        // Lưu dữ liệu vào biến hoặc xử lý dữ liệu
    }
    fclose(file); // Đóng file

}





