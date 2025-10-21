// https://dodona.be/en/courses/5451/series/63963/activities/398722079
struct Timestamp {
	int hour;
	int minute;
	int second;
};

struct Timestamp calc_difference(struct Timestamp t1, struct Timestamp t2) {
    int s1 = t1.hour * 3600 + t1.minute * 60 + t1.second;
    int s2 = t2.hour * 3600 + t2.minute * 60 + t2.second;
    int diff = s1 - s2;


    struct Timestamp result;
    result.hour = diff / 3600;
    diff %= 3600;
    result.minute = diff / 60;
    result.second = diff % 60;

    return result;
}