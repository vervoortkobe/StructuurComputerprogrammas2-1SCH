// https://dodona.be/en/courses/5451/series/63962/activities/724580696

char *string_span(char *string, char *accepted, int *span_size) {
    char *max_start = string;
    int max_len = 0;
    char *current = string;

    while (*current != '\0') {
        char *a = accepted;
        int is_accepted = 0;
        while (*a != '\0') {
            if (*current == *a) {
                is_accepted = 1;
                break;
            }
            a++;
        }

        if (is_accepted) {
            char *span_start = current;
            int span_len = 0;

            while (*current != '\0') {
                char *b = accepted;
                int ok = 0;
                while (*b != '\0') {
                    if (*current == *b) {
                        ok = 1;
                        break;
                    }
                    b++;
                }
                if (!ok) break;
                span_len++;
                current++;
            }

            if (span_len > max_len) {
                max_len = span_len;
                max_start = span_start;
            }
        } else {
            current++;
        }
    }

    *span_size = max_len;

    if (max_len == 0) {
        while (*string != '\0') string++;
        return string;
    }

    return max_start;
}