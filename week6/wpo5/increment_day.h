// https://dodona.be/en/courses/5451/series/63963/activities/1803930309
struct date {
	int year, month, day;
};

void increment_day(struct date *date) {
	int max_days_in_current_month;
	switch (date->month) {
		case 2: max_days_in_current_month = 28; break;
		case 4: case 6: case 9: case 11: max_days_in_current_month = 30; break;
		default: max_days_in_current_month = 31; break;
	}
	if (date->day < max_days_in_current_month) {
		date->day = date->day + 1;
	} else if (date->month != 12) {
		date->day = 1;
		date->month = date->month + 1;
	} else {
		date->day = 1;
		date->month = 1;
		date->year = date->year + 1;
	}
}