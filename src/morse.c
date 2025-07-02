/*
 * morse.c
 *
 *  Created on: 2 ���. 2025 �.
 *      Author:
 */
#include "main.h"
#include "morse.h"
#include "morse_table.h"

/*Constant Definitions*/
// ������������ �������� (� ��)
#define DOT_DUR 	150
#define DASH_DUR 	(2 * DOT_DUR)
#define SYMB_GAP 	DOT_DUR
#define LET_GAP 	(2 * DOT_DUR - SYMB_GAP)
#define WORD_GAP 	(6 * DOT_DUR - LET_GAP)
/*Variable*/
// ������� ����� ����� (������ ����� � �����)


// ������� ��� ����� � ����
void morse_dot(void) {
    ld_on();
    delay_ms(DOT_DUR);
    ld_off();
    delay_ms(SYMB_GAP);
}

void morse_dash(void) {
    ld_on();
    delay_ms(DASH_DUR);
    ld_off();
    delay_ms(SYMB_GAP);
}

// ����� ����� ������� � �������
void morse_let_gap(void) {
    delay_ms(LET_GAP);
}

void morse_word_gap(void) {
    delay_ms(WORD_GAP);
}


// �������� ������� �����
void morse_send_char(char c) {
    if (c >= 'a' && c <= 'z') {
        c -= 'a' - 'A'; // ��������� � ������� �������
    }

    const char* morse_code = NULL;

    if (c >= 'A' && c <= 'Z') {
        morse_code = morse_table[c - 'A'];
    } else if (c >= '0' && c <= '9') {
        morse_code = morse_table[c - '0' + 26];
    } else if (c == ' ') {
        morse_word_gap();
        return;
    } else {
        return; // ���������������� ������
    }

// �������� �����/����
    while (*morse_code) {
        if (*morse_code == '.') {
            morse_dot();
        } else if (*morse_code == '-') {
            morse_dash();
        }
        morse_code++;
    }

    morse_let_gap();
}

// �������� ������
void morse_send_string(const char* str) {
    while (*str) {
        morse_send_char(*str++);
    }
}
